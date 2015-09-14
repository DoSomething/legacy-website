<?php
/**
 * @file
 * dosomething_action_guide.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_action_guide_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create action_guide content'.
  $permissions['create action_guide content'] = array(
    'name' => 'create action_guide content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any action_guide content'.
  $permissions['delete any action_guide content'] = array(
    'name' => 'delete any action_guide content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own action_guide content'.
  $permissions['delete own action_guide content'] = array(
    'name' => 'delete own action_guide content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any action_guide content'.
  $permissions['edit any action_guide content'] = array(
    'name' => 'edit any action_guide content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own action_guide content'.
  $permissions['edit own action_guide content'] = array(
    'name' => 'edit own action_guide content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
