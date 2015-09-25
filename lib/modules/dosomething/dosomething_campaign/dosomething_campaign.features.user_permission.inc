<?php
/**
 * @file
 * dosomething_campaign.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_campaign_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create campaign content'.
  $permissions['create campaign content'] = array(
    'name' => 'create campaign content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign content'.
  $permissions['delete any campaign content'] = array(
    'name' => 'delete any campaign content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign content'.
  $permissions['delete own campaign content'] = array(
    'name' => 'delete own campaign content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign content'.
  $permissions['edit any campaign content'] = array(
    'name' => 'edit any campaign content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit campaign overrides'.
  $permissions['edit campaign overrides'] = array(
    'name' => 'edit campaign overrides',
    'roles' => array(
      'administrator' => 'administrator',
      'creative team' => 'creative team',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'site admin' => 'site admin',
    ),
    'module' => 'dosomething_campaign',
  );

  // Exported permission: 'edit own campaign content'.
  $permissions['edit own campaign content'] = array(
    'name' => 'edit own campaign content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'global admin' => 'global admin',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
