<?php
/**
 * @file
 * dosomething_taxonomy.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dosomething_taxonomy_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-sponsors-field_image_sponsor_logo'
  $field_instances['taxonomy_term-sponsors-field_image_sponsor_logo'] = array(
    'bundle' => 'sponsors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_image_sponsor_logo',
    'label' => 'Sponsor Logo',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Sponsor Logo');

  return $field_instances;
}
