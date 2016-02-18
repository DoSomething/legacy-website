<?php
/**
 * @file
 * dosomething_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
      'creative team' => 'creative team',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'creative team' => 'creative team',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'creative team' => 'creative team',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'use text format markdown'.
  $permissions['use text format markdown'] = array(
    'name' => 'use text format markdown',
    'roles' => array(
      'administrator' => 'administrator',
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
