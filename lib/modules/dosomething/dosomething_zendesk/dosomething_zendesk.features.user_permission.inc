<?php
/**
 * @file
 * dosomething_zendesk.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_zendesk_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer zendesk'.
  $permissions['administer zendesk'] = array(
    'name' => 'administer zendesk',
    'roles' => array(
      'administrator' => 'administrator',
      'member support' => 'member support',
    ),
    'module' => 'dosomething_zendesk',
  );

  return $permissions;
}
