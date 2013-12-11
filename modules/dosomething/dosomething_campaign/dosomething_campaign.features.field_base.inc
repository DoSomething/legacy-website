<?php
/**
 * @file
 * dosomething_campaign.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dosomething_campaign_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_faq'
  $field_bases['field_faq'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faq',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'dosomething_compoundtext',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'dosomething_compoundtext',
  );

  // Exported field_base: 'field_image_campaign_cover'
  $field_bases['field_image_campaign_cover'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_image_campaign_cover',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_image_campaign_gallery'
  $field_bases['field_image_campaign_gallery'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_image_campaign_gallery',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_step_post'
  $field_bases['field_step_post'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_step_post',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'dosomething_compoundtext',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'dosomething_compoundtext',
  );

  // Exported field_base: 'field_step_pre'
  $field_bases['field_step_pre'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_step_pre',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'dosomething_compoundtext',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'dosomething_compoundtext',
  );

  return $field_bases;
}
