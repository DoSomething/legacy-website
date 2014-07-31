<?php
/**
 * @file
 * dosomething_sms.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_sms_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer dosomething_sms'.
  $permissions['administer dosomething_sms'] = array(
    'name' => 'administer dosomething_sms',
    'roles' => array(
      'administrator' => 'administrator',
      'communications team' => 'communications team',
    ),
    'module' => 'dosomething_sms',
  );

  return $permissions;
}
