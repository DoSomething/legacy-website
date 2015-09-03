<?php
/**
 * @file
 * dosomething_reportback.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_reportback_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete any reportback'.
  $permissions['delete any reportback'] = array(
    'name' => 'delete any reportback',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dosomething_reportback',
  );

  // Exported permission: 'delete own reportback'.
  $permissions['delete own reportback'] = array(
    'name' => 'delete own reportback',
    'roles' => array(),
    'module' => 'dosomething_reportback',
  );

  // Exported permission: 'edit any reportback'.
  $permissions['edit any reportback'] = array(
    'name' => 'edit any reportback',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'member support' => 'member support',
      'site admin' => 'site admin',
    ),
    'module' => 'dosomething_reportback',
  );

  // Exported permission: 'edit own reportback'.
  $permissions['edit own reportback'] = array(
    'name' => 'edit own reportback',
    'roles' => array(),
    'module' => 'dosomething_reportback',
  );

  // Exported permission: 'view any reportback'.
  $permissions['view any reportback'] = array(
    'name' => 'view any reportback',
    'roles' => array(
      'administrator' => 'administrator',
      'brazil admin' => 'brazil admin',
      'communications team' => 'communications team',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'member support' => 'member support',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'dosomething_reportback',
  );

  // Exported permission: 'view own reportback'.
  $permissions['view own reportback'] = array(
    'name' => 'view own reportback',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'dosomething_reportback',
  );

  return $permissions;
}
