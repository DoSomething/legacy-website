<?php
/**
 * @file
 * dosomething_campaign.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dosomething_campaign_taxonomy_default_vocabularies() {
  return array(
    'issue' => array(
      'name' => 'Issue',
      'machine_name' => 'issue',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
