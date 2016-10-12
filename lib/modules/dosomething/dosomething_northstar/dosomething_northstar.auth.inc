<?php

module_load_include('php', 'openid_connect', 'includes/OpenIDConnectClientInterface.class');
module_load_include('php', 'openid_connect', 'includes/OpenIDConnectClientBase.class');

include_once('plugins/openid_connect_client/northstar/OpenIDConnectClientNorthstar.class.php');

/**
 * Create an OpenID Connect authorization URL.
 *
 * @return array
 */
function dosomething_northstar_openid_authorize_url() {
  /** @var $client OpenIDConnectClientNorthstar */
  $client = openid_connect_get_client('northstar');
  $scopes = openid_connect_get_scopes();

  return $client->getAuthorizeUrl($scopes);
}

/**
 * Render the view for OpenID Connect login. Displayed standalone
 * at `/user/openid` and (with feature flag enabled) in the modal.
 *
 * @return array
 */
function dosomething_northstar_openid_login_view() {
  $authorize_url = dosomething_northstar_openid_authorize_url();

  return theme('openid_login', ['url' => $authorize_url]);
}

/**
 * Create an authorization link and redirect to it. (This way we don't
 * have to make a state token every time we have a page with a login link).
 *
 * @return void
 */
function dosomething_northstar_openid_authorize() {
  $authorize_url = dosomething_northstar_openid_authorize_url();

  drupal_goto($authorize_url, ['absolute' => TRUE]);
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
  $edit = [];
  dosomething_user_set_fields($edit, [
    'access_token' => $tokens['access_token'],
    'refresh_token' => $tokens['access_token'],
    'access_token_expiration' => $tokens['expire'],
  ]);

  // Let's remember that this is a OpenID Connect session.
  $_SESSION['DOSOMETHING_NORTHSTAR_OPENID_CONNECT'] = true;

  user_save($account, $edit);
}

/**
 * Redirect to destroy a Northstar single-sign-on session if one exists.
 *
 * Implements hook_user_logout().
 *
 * @param $account
 */
function dosomething_northstar_user_logout($account) {
  $is_openid_login = ! empty($_SESSION['DOSOMETHING_NORTHSTAR_OPENID_CONNECT']);
  $northstar_logout_url = url(NORTHSTAR_URL . '/logout', [
    'query' => ['redirect' => url('/', ['absolute' => TRUE])],
  ]);

  // Destroy the current session, and reset $user to the anonymous user.
  session_destroy();

  drupal_goto($is_openid_login ? $northstar_logout_url : '/');
}
