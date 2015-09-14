<?php
/**
 * @file
 * dosomething_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dosomething_user_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: brazil admin.
  $roles['brazil admin'] = array(
    'name' => 'brazil admin',
    'weight' => 10,
  );

  // Exported role: communications team.
  $roles['communications team'] = array(
    'name' => 'communications team',
    'weight' => 4,
  );

  // Exported role: creative team.
  $roles['creative team'] = array(
    'name' => 'creative team',
    'weight' => 7,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  // Exported role: member support.
  $roles['member support'] = array(
    'name' => 'member support',
    'weight' => 5,
  );

  // Exported role: mexico admin.
  $roles['mexico admin'] = array(
    'name' => 'mexico admin',
    'weight' => 11,
  );

  // Exported role: org friend.
  $roles['org friend'] = array(
    'name' => 'org friend',
    'weight' => 6,
  );

  // Exported role: site admin.
  $roles['site admin'] = array(
    'name' => 'site admin',
    'weight' => 8,
  );

  return $roles;
}
