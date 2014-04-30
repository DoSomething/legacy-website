<?php
/**
 * @file
 * dosomething_campaign_group.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_campaign_group_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create campaign_group content'.
  $permissions['create campaign_group content'] = array(
    'name' => 'create campaign_group content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_group content'.
  $permissions['delete any campaign_group content'] = array(
    'name' => 'delete any campaign_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_group content'.
  $permissions['delete own campaign_group content'] = array(
    'name' => 'delete own campaign_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_group content'.
  $permissions['edit any campaign_group content'] = array(
    'name' => 'edit any campaign_group content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_group content'.
  $permissions['edit own campaign_group content'] = array(
    'name' => 'edit own campaign_group content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
