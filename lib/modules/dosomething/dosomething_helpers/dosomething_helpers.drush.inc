<?php

/**
 * Implementation of hook_drush_command().
 */
function dosomething_helpers_drush_command() {
  $items = array();
  // Name of the drush command.
  $items['test-node-delete'] = array(
    'description' => 'Delete any nodes created by test fixtures.',
    'callback' => 'dosomething_helpers_drush_test_node_delete',
    'examples' => array(
      'drush test-node-delete' => 'Deletes any nodes created by test fixtures (for example, `drush campaign-create` or `drush fact-create`).',
    ),
  );
  return $items;
}

/**
 * Callback for campaign-create command.
 */
function dosomething_helpers_drush_test_node_delete() {
  $deleted_nids = dosomething_helpers_delete_test_nodes();

  $message = "Deleted " . count($deleted_nids) . " test nodes.";
  return $message;
}
