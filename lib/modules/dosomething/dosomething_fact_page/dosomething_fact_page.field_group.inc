<?php
/**
 * @file
 * dosomething_fact_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_fact_page_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_call_to_action|node|fact_page|form';
  $field_group->group_name = 'group_call_to_action';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fact_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call to Action',
    'weight' => '3',
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
  $export['group_call_to_action|node|fact_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lead_in|node|fact_page|form';
  $field_group->group_name = 'group_lead_in';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fact_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lead in',
    'weight' => '0',
    'children' => array(
      0 => 'field_hero_image',
      1 => 'field_intro_title',
      2 => 'field_subtitle',
      3 => 'field_intro',
      4 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-lead-in field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_lead_in|node|fact_page|form'] = $field_group;

  return $export;
}
