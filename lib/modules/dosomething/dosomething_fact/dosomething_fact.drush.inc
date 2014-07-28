<?php

/**
 * Implementation of hook_drush_command().
 */
function dosomething_fact_drush_command() {
  $items = array();
  // Name of the drush command.
  $items['fact-create'] = array(
    'description' => 'Creates a fact node from given JSON file.',
    'arguments' => array(
      'filename' => 'Name of the JSON file to read.',
    ),
    'required-arguments' => TRUE,
    'callback' => 'dosomething_fact_drush_fact_create',
    'examples' => array(
      'drush fact-create ../tests/fixtures/fact.json' => 'Creates a fact node from contents of fact.json.',
    ),
  );
  return $items;
}

/**
 * Callback for fact-create command.
 */
function dosomething_fact_drush_fact_create($filename) {
  if ($string = file_get_contents($filename)) {
    $node = dosomething_fact_create_node_from_json($string);
    $message = "Created node nid " . $node->nid . ".";
    return $message;
  }
  else {
    return "Invalid filename.";
  }
}
