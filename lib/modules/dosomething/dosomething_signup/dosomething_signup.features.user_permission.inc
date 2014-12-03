<?php
/**
 * @file
 * dosomething_signup.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_signup_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer third party communication'.
  $permissions['administer third party communication'] = array(
    'name' => 'administer third party communication',
    'roles' => array(
      'administrator' => 'administrator',
      'communications team' => 'communications team',
    ),
    'module' => 'dosomething_signup',
  );

  // Exported permission: 'edit any signup'.
  $permissions['edit any signup'] = array(
    'name' => 'edit any signup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dosomething_signup',
  );

  // Exported permission: 'view any signup'.
  $permissions['view any signup'] = array(
    'name' => 'view any signup',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'member support' => 'member support',
    ),
    'module' => 'dosomething_signup',
  );

  return $permissions;
}
