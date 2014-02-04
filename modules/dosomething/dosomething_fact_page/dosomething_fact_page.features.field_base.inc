<?php
/**
 * @file
 * dosomething_fact_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dosomething_fact_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_intro_video'
  $field_bases['field_intro_video'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_intro_video',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'text',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'varchar',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  return $field_bases;
}
