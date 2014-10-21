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
    'image_tags' => array(
      'name' => 'Image Tags',
      'machine_name' => 'image_tags',
      'description' => 'additional metadata on image nodes',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'issue' => array(
      'name' => 'Issue',
      'machine_name' => 'issue',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'partners' => array(
      'name' => 'Partners',
      'machine_name' => 'partners',
      'description' => 'Organizations, companies who are partners and/or sponsors.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
