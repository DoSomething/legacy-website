<?php
/**
 * @file
 * dosomething_reportback.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dosomething_reportback_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'flagging-flagged_reportback-field_flagged_reason'
  $field_instances['flagging-flagged_reportback-field_flagged_reason'] = array(
    'bundle' => 'flagged_reportback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select at least one.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'flagging',
    'field_name' => 'field_flagged_reason',
    'label' => 'Reasons',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'flagging-promoted-field_image_description'
  $field_instances['flagging-promoted-field_image_description'] = array(
    'bundle' => 'promoted',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'flagging',
    'field_name' => 'field_image_description',
    'label' => 'Editorial Caption',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial Caption');
  t('Please select at least one.');
  t('Reasons');

  return $field_instances;
}
