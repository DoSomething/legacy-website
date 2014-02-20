<?php
/**
 * @file
 * dosomething_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  return $permissions;
}
