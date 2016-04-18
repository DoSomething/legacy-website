<?php
/**
 * @file
 * dosomething_fact.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dosomething_fact_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_source_copy'.
  $field_bases['field_source_copy'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_source_copy',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
