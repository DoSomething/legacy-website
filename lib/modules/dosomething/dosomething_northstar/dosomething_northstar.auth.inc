<?php

module_load_include('php', 'openid_connect', 'includes/OpenIDConnectClientInterface.class');
module_load_include('php', 'openid_connect', 'includes/OpenIDConnectClientBase.class');

include_once('plugins/openid_connect_client/northstar/OpenIDConnectClientNorthstar.class.php');

/**
 * Create an OpenID Connect authorization URL.
 *
 * @return string
 */
function dosomething_northstar_openid_authorize_url() {
  /** @var $client OpenIDConnectClientNorthstar */
  $client = openid_connect_get_client('northstar');
  $scopes = openid_connect_get_scopes();

  return $client->getAuthorizeUrl($scopes);
}

/**
 * Create an Northstar authorization link and redirect to it. (This way we don't
 * have to make a state token every time we have a page with a login link).
 *
 * GET /user/authorize
 *
 * @return void
 */
function dosomething_northstar_openid_authorize() {
  // If a Drupal session already exists, reset it from Northstar.
  if (user_is_logged_in()) {
    session_destroy();
  }

  $authorize_url = dosomething_northstar_openid_authorize_url();
  $url_options = ['absolute' => TRUE];

  // If we specify a mode, append that to the authorization URL.
  if (isset($_GET['mode'])) {
    $url_options['query'] = ['mode' => $_GET['mode']];
  }

  if (isset($_GET['action']) && isset($_GET['node'])) {
    $campaign = dosomething_campaign_load(node_load($_GET['node']));
    $params = [];

    if (isset($_GET['affiliate_messaging_opt_in'])) {
      $params['affiliate_messaging_opt_in'] = (bool) $_GET['affiliate_messaging_opt_in'];
    }

    dosomething_northstar_set_authorization_action($_GET['action'], $_GET['node'], $params);

    $url_options['query'] = [
      'destination' => $campaign->title,
      'title' => $campaign->title,
      'callToAction' => $campaign->call_to_action,
      'coverPhoto' => $campaign->image_cover['url']['landscape']['raw'],
    ];
  }

  drupal_goto($authorize_url, $url_options);
}

/**
 * Register our custom OpenID Connect provider.
 *
 * Implements hook_ctools_plugin_directory().
 */
function dosomething_northstar_ctools_plugin_directory($module, $plugin) {
  if ($module === 'openid_connect') {
    return 'plugins/' . $plugin;
  }
}


/**
 * Adjust scopes requested for OpenID Connect authentication.
 *
 * Implements hook_openid_connect_claims_alter().
 *
 * @param array $claims
 */
function dosomething_northstar_openid_connect_claims_alter(&$claims) {
  foreach ($claims as &$claim) {
    $claim['scope'] = 'profile';
  }
}

/**
 * Post-authorize hook for OpenID Connect authentication. We use this to persist
 * the user's access and refresh tokens so they can be used in future requests.
 *
 * Implements hook_openid_connect_post_authorize().
 *
 * @param array $tokens - Array with id_token/access_token, refresh_token, access token expiration
 * @param stdClass $account - The Drupal user account
 * @param array $userinfo - Response from Northstar's user info endpoint
 * @param string $provider - The provider used to authenticate
 */
function dosomething_northstar_openid_connect_post_authorize($tokens, $account, $userinfo, $provider) {
  // Determine the user's language code if possible.
  $language_code = dosomething_global_get_language($account);

  // Make sure the user's email address is up to date.
  $account->mail = $userinfo['email'];

  $edit = [];
  dosomething_user_set_fields($edit, [
    'access_token' => $tokens['access_token'],
    'refresh_token' => $tokens['refresh_token'],
    'access_token_expiration' => $tokens['expire'],
    'language' => $language_code ? $language_code : 'en-global',
    'timezone' => 'UTC',
  ]);
  user_save($account, $edit);

  // Make sure the user's Northstar ID is set in the field_data_field_northstar_id table.
  if (!dosomething_user_get_northstar_id($account->uid)) {
    dosomething_northstar_save_id_field($account->uid, ['data' => $userinfo]);
  }

  // HACK: Was this account registered just now (last 15s)? If so, fire
  // a Registration analytics event. Otherwise, fire Login event.
  if ($userinfo['created_at'] > time() - 15) {
    dosomething_helpers_add_analytics_event('Authentication', 'Register');
  } else {
    dosomething_helpers_add_analytics_event('Authentication', 'Login');
  }

  // If we saved a "post-authorization" action, do it now.
  dosomething_northstar_perform_authorization_actions();
}

/**
 * Save a post-authorization destination in the session (e.g. for signing
 * up for a campaign).
 *
 * @param string $action
 * @param string $nid
 * @param array $params
 */
function dosomething_northstar_set_authorization_action($action, $nid, $params = []) {
  if ($action !== 'signup') {
    return;
  }

  $_SESSION['openid_connect_action'] = [
    'signup' => [
      'nid' => $nid,
      'params' => [
        'affiliate_messaging_opt_in' => isset($params['affiliate_messaging_opt_in']) ? $params['affiliate_messaging_opt_in'] : FALSE,
      ],
    ],
  ];
}

/**
 * Perform any post-authorization actions (e.g. signups) queued in the session.
 *
 * @return void
 */
function dosomething_northstar_perform_authorization_actions() {
  global $user;

  if (! isset($_SESSION['openid_connect_action'])) {
    return;
  }

  $actions = $_SESSION['openid_connect_action'];

  foreach ($actions as $action => $target) {
    if ($action === 'signup') {
      $source = dosomething_signup_get_query_source();
      dosomething_signup_user_signup((int) $target['nid'], $user, $source, $target['params']);

      drupal_goto('node/' . $target['nid']);
    }
  }
}

/**
 * Redirect to destroy a Northstar single-sign-on session if one exists.
 *
 * Implements hook_user_logout().
 *
 * @param $account
 */
function dosomething_northstar_user_logout($account) {
  $user = user_load($account->uid);

  // Destroy the current session, and reset $user to the anonymous user.
  session_destroy();

  // Clear out token information to track that SSO session will be revoked.
  // @TODO: Actually revoke the refresh token in Northstar on logout.
  $edit = [];
  dosomething_user_set_fields($edit, [
    'access_token' => NULL,
    'access_token_expiration' => NULL,
    'refresh_token' => NULL,
  ]);
  user_save($user, $edit);

  // And redirect to SSO logout to prevent users from automatically
  // logging in to the same account again.
  $northstar_logout_url = url(NORTHSTAR_URL . '/logout', [
    'query' => ['redirect' => url('/', ['absolute' => TRUE])],
  ]);

  drupal_goto($northstar_logout_url);
}
