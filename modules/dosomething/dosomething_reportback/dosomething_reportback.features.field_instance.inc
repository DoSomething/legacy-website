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

  // Exported field_instance: 'reportback-reportback-field_image_user_reportback'
  $field_instances['reportback-reportback-field_image_user_reportback'] = array(
    'bundle' => 'reportback',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'reportback',
    'field_name' => 'field_image_user_reportback',
    'label' => 'Pictures',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'reportback',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Pictures');

  return $field_instances;
}
