<?php
/**
 * @file
 * dosomething_campaign_run.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_campaign_run_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create campaign_run content'.
  $permissions['create campaign_run content'] = array(
    'name' => 'create campaign_run content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_run content'.
  $permissions['delete any campaign_run content'] = array(
    'name' => 'delete any campaign_run content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_run content'.
  $permissions['delete own campaign_run content'] = array(
    'name' => 'delete own campaign_run content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_run content'.
  $permissions['edit any campaign_run content'] = array(
    'name' => 'edit any campaign_run content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_run content'.
  $permissions['edit own campaign_run content'] = array(
    'name' => 'edit own campaign_run content',
    'roles' => array(
      'brazil admin' => 'brazil admin',
      'editor' => 'editor',
      'mexico admin' => 'mexico admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
