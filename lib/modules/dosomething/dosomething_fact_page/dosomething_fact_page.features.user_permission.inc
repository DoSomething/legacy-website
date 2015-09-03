<?php
/**
 * @file
 * dosomething_fact_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_fact_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fact_page content'.
  $permissions['create fact_page content'] = array(
    'name' => 'create fact_page content',
    'roles' => array(
      'editor' => 'editor',
      'global admin' => 'global admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any fact_page content'.
  $permissions['delete any fact_page content'] = array(
    'name' => 'delete any fact_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own fact_page content'.
  $permissions['delete own fact_page content'] = array(
    'name' => 'delete own fact_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any fact_page content'.
  $permissions['edit any fact_page content'] = array(
    'name' => 'edit any fact_page content',
    'roles' => array(
      'editor' => 'editor',
      'global admin' => 'global admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own fact_page content'.
  $permissions['edit own fact_page content'] = array(
    'name' => 'edit own fact_page content',
    'roles' => array(
      'editor' => 'editor',
      'global admin' => 'global admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
