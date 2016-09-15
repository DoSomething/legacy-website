<?php

include_once('plugins/openid_connect_client/northstar/OpenIDConnectClientNorthstar.class.php');

/**
 * Register our custom OpenID Connect provider.
 *
 * Implements hook_ctools_plugin_directory().
 */
function dosomething_northstar_ctools_plugin_directory($module, $plugin) {
  if ($module == 'openid_connect') {
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
