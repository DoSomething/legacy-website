<?php
/**
 * @file
 * dosomething_signup.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dosomething_signup_user_default_roles() {
  $roles = array();

  // Exported role: communications team.
  $roles['communications team'] = array(
    'name' => 'communications team',
    'weight' => 4,
  );

  return $roles;
}
