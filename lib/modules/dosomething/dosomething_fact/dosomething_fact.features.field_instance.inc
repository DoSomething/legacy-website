<?php
/**
 * @file
 * dosomething_fact.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dosomething_fact_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-fact-field_source_copy'.
  $field_instances['node-fact-field_source_copy'] = array(
    'bundle' => 'fact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_source_copy',
    'label' => 'Source',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 42,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Source');

  return $field_instances;
}
