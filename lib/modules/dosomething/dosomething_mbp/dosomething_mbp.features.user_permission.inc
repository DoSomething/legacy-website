<?php
/**
 * @file
 * dosomething_mbp.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_mbp_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer message_broker_producer'.
  $permissions['administer message_broker_producer'] = array(
    'name' => 'administer message_broker_producer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_broker_producer',
  );

  return $permissions;
}
