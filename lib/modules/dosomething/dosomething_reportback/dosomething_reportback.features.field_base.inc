<?php
/**
 * @file
 * dosomething_reportback.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dosomething_reportback_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_flagged_reason'
  $field_bases['field_flagged_reason'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_flagged_reason',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'inappropriate' => 'Inappropriate',
        'irrelevant' => 'Irrelevant',
        'unrealistic' => 'Unrealistic quantity',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
