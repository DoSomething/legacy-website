<?php
/**
 * @file
 * Helper functions for dosomething_fact functionality.
 */

/**
 * Creates and returns a fact node from given JSON string.
 */
function dosomething_fact_create_node_from_json($string) {
  $data = json_decode($string);
  $node = new stdClass();

  // We'll use this as a flag to find test nodes.
  $node->created = '-1'; 

  $node->type = 'fact';
  $node->title = $data->title;
  
  foreach ($data->sources as &$source) {
    $node->field_source_copy[LANGUAGE_NONE][] = array(
      'value' => $source,
      'format' => 'markdown'
    );
  }

  node_save($node);
  return $node;
}
