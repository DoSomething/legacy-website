<?php
/**
 * @file
 * dosomething_fact.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_fact_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fact content'.
  $permissions['create fact content'] = array(
    'name' => 'create fact content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any fact content'.
  $permissions['delete any fact content'] = array(
    'name' => 'delete any fact content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own fact content'.
  $permissions['delete own fact content'] = array(
    'name' => 'delete own fact content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any fact content'.
  $permissions['edit any fact content'] = array(
    'name' => 'edit any fact content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own fact content'.
  $permissions['edit own fact content'] = array(
    'name' => 'edit own fact content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
