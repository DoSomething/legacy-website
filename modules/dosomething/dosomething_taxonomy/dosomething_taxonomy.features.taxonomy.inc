<?php
/**
 * @file
 * dosomething_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dosomething_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'action_type' => array(
      'name' => 'Action Type',
      'machine_name' => 'action_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'cause' => array(
      'name' => 'Cause',
      'machine_name' => 'cause',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
