<?php

/**
 * Implementation of hook_drush_command().
 */
function dosomething_campaign_drush_command() {
  $items = array();
  // Name of the drush command.
  $items['create-campaign'] = array(
    'description' => 'Creates a campaign node from given JSON file.',
    'arguments' => array(
      'filename' => 'Name of the file to read.'
    ),
    'callback' => 'dosomething_campaign_drush_create_campaign',
  );
  return $items;
}

/**
 * Callback for create-campaign command.
 */
function dosomething_campaign_drush_create_campaign($filename) {
  if ($string = file_get_contents($filename)) {
    $node = dosomething_campaign_create_node_from_json($string);
    $message = "Created node nid " . $node->nid . ".";
    return $message;
  }
  else {
    return "Invalid filename.";
  }
}
