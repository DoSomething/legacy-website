<?php

/**
 * Implementation of hook_drush_command().
 */
function dosomething_campaign_drush_command() {
  $items = array();
  // Name of the drush command.
  $items['campaign-create'] = array(
    'description' => 'Creates a campaign node from given JSON file.',
    'arguments' => array(
      'filename' => 'Name of the JSON file to read.',
    ),
    'required-arguments' => TRUE,
    'callback' => 'dosomething_campaign_drush_campaign_create',
    'examples' => array(
      'drush campaign-create ../tests/campaign/campaign.json' => 'Creates a campaign node from contents of campaign.json.',
    ),
  );
  return $items;
}

/**
 * Callback for campaign-create command.
 */
function dosomething_campaign_drush_campaign_create($filename) {
  if ($string = file_get_contents($filename)) {
    $node = dosomething_campaign_create_node_from_json($string);
    $message = "Created node nid " . $node->nid . ".";
    return $message;
  }
  else {
    return "Invalid filename.";
  }
}
