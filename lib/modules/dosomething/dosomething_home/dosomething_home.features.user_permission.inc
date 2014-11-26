<?php
/**
 * @file
 * dosomething_home.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_home_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create home content'.
  $permissions['create home content'] = array(
    'name' => 'create home content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any home content'.
  $permissions['delete any home content'] = array(
    'name' => 'delete any home content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own home content'.
  $permissions['delete own home content'] = array(
    'name' => 'delete own home content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any home content'.
  $permissions['edit any home content'] = array(
    'name' => 'edit any home content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own home content'.
  $permissions['edit own home content'] = array(
    'name' => 'edit own home content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
