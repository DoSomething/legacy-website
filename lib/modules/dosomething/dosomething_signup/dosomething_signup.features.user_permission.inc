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

  return $permissions;
}
