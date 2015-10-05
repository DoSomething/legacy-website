<?php
/**
 * @file
 * dosomething_taxonomy.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_taxonomy_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in partners'.
  $permissions['add terms in partners'] = array(
    'name' => 'add terms in partners',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in action_type'.
  $permissions['delete terms in action_type'] = array(
    'name' => 'delete terms in action_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in cause'.
  $permissions['delete terms in cause'] = array(
    'name' => 'delete terms in cause',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in image_tags'.
  $permissions['delete terms in image_tags'] = array(
    'name' => 'delete terms in image_tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in issue'.
  $permissions['delete terms in issue'] = array(
    'name' => 'delete terms in issue',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in partners'.
  $permissions['delete terms in partners'] = array(
    'name' => 'delete terms in partners',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in action_type'.
  $permissions['edit terms in action_type'] = array(
    'name' => 'edit terms in action_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in cause'.
  $permissions['edit terms in cause'] = array(
    'name' => 'edit terms in cause',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in image_tags'.
  $permissions['edit terms in image_tags'] = array(
    'name' => 'edit terms in image_tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in issue'.
  $permissions['edit terms in issue'] = array(
    'name' => 'edit terms in issue',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in partners'.
  $permissions['edit terms in partners'] = array(
    'name' => 'edit terms in partners',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
