<?php
/**
 * @file
 * dosomething_static_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_static_content_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_text|node|static_content|form';
  $field_group->group_name = 'group_additional_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'static_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Text',
    'weight' => '8',
    'children' => array(
      0 => 'field_additional_text',
      1 => 'field_additional_text_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-additional-text field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_additional_text|node|static_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_call_to_action|node|static_content|form';
  $field_group->group_name = 'group_call_to_action';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'static_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call to Action',
    'weight' => '5',
    'children' => array(
      0 => 'field_call_to_action',
      1 => 'field_cta_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-call-to-action field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_call_to_action|node|static_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|static_content|form';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'static_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lead in',
    'weight' => '3',
    'children' => array(
      0 => 'field_hero_image',
      1 => 'field_subtitle',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-header field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_header|node|static_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_intro|node|static_content|form';
  $field_group->group_name = 'group_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'static_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Intro',
    'weight' => '4',
    'children' => array(
      0 => 'field_intro',
      1 => 'field_intro_image',
      2 => 'field_intro_title',
      3 => 'field_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-intro field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_intro|node|static_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_list|field_collection_item|field_optional_blocks|form';
  $field_group->group_name = 'group_section_list';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_optional_blocks';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section List',
    'weight' => '5',
    'children' => array(
      0 => 'field_list_item',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-section-list field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_section_list|field_collection_item|field_optional_blocks|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Text');
  t('Call to Action');
  t('Intro');
  t('Lead in');
  t('Section List');

  return $field_groups;
}
