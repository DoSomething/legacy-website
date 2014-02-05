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

  // Exported permission: 'delete fact'.
  $permissions['delete fact'] = array(
    'name' => 'delete fact',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dosomething_fact',
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
