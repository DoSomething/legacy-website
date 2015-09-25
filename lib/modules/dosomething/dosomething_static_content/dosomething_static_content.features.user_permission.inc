<?php
/**
 * @file
 * dosomething_static_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_static_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create static_content content'.
  $permissions['create static_content content'] = array(
    'name' => 'create static_content content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any static_content content'.
  $permissions['delete any static_content content'] = array(
    'name' => 'delete any static_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own static_content content'.
  $permissions['delete own static_content content'] = array(
    'name' => 'delete own static_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any static_content content'.
  $permissions['edit any static_content content'] = array(
    'name' => 'edit any static_content content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own static_content content'.
  $permissions['edit own static_content content'] = array(
    'name' => 'edit own static_content content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
