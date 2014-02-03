<?php
/**
 * @file
 * dosomething_image.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_image_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create image content'.
  $permissions['create image content'] = array(
    'name' => 'create image content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image content'.
  $permissions['edit any image content'] = array(
    'name' => 'edit any image content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image content'.
  $permissions['edit own image content'] = array(
    'name' => 'edit own image content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
