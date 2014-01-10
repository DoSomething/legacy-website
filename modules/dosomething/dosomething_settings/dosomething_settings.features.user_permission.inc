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

  // Exported permission: 'use text format markdown'.
  $permissions['use text format markdown'] = array(
    'name' => 'use text format markdown',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
