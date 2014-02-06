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

  // Exported permission: 'create fact'.
  $permissions['create fact'] = array(
    'name' => 'create fact',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'dosomething_fact',
  );

  // Exported permission: 'create fact content'.
  $permissions['create fact content'] = array(
    'name' => 'create fact content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any fact content'.
  $permissions['delete any fact content'] = array(
    'name' => 'delete any fact content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete fact'.
  $permissions['delete fact'] = array(
    'name' => 'delete fact',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dosomething_fact',
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

  // Exported permission: 'edit fact'.
  $permissions['edit fact'] = array(
    'name' => 'edit fact',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'dosomething_fact',
  );

  // Exported permission: 'edit own fact content'.
  $permissions['edit own fact content'] = array(
    'name' => 'edit own fact content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view fact'.
  $permissions['view fact'] = array(
    'name' => 'view fact',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'dosomething_fact',
  );

  return $permissions;
}
