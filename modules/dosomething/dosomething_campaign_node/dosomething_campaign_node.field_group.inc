<?php
/**
 * @file
 * dosomething_campaign_node.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_campaign_node_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_do_it|node|campaign|form';
  $field_group->group_name = 'group_do_it';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Do It',
    'weight' => '5',
    'children' => array(
      0 => 'field_step_pre',
      1 => 'field_step_post',
      2 => 'field_step_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Do It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-do-it field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_do_it|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|campaign|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '9',
    'children' => array(
      0 => 'field_image_campaign_cover',
      1 => 'field_image_campaign_gallery',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Images',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-images field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_images|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_know_it|node|campaign|form';
  $field_group->group_name = 'group_know_it';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Know It',
    'weight' => '6',
    'children' => array(
      0 => 'field_fact_problem',
      1 => 'field_fact_solution',
      2 => 'field_faq',
      3 => 'field_facts',
      4 => 'field_confirmation_doc',
      5 => 'field_psa',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Know It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-know-it field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_know_it|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prep_it|node|campaign|form';
  $field_group->group_name = 'group_prep_it';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prep It',
    'weight' => '4',
    'children' => array(
      0 => 'field_starter_statement',
      1 => 'field_time_and_place',
      2 => 'field_vips',
      3 => 'field_items_needed',
      4 => 'field_promoting_tips',
      5 => 'field_location_finder',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Prep It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-prep-it field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_prep_it|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_report_back|node|campaign|form';
  $field_group->group_name = 'group_report_back';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Report Back',
    'weight' => '7',
    'children' => array(
      0 => 'field_report_back_noun',
      1 => 'field_report_back_verb',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Report Back',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-report-back field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_report_back|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsors|node|campaign|form';
  $field_group->group_name = 'group_sponsors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsors',
    'weight' => '10',
    'children' => array(
      0 => 'field_sponsor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sponsors',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-sponsors field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_sponsors|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|campaign|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '8',
    'children' => array(
      0 => 'field_action_type',
      1 => 'field_cause',
      2 => 'field_tags',
      3 => 'field_staff_pick',
      4 => 'field_active_hours',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taxonomy',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-taxonomy field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_taxonomy|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_timing|node|campaign|form';
  $field_group->group_name = 'group_timing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Timing',
    'weight' => '3',
    'children' => array(
      0 => 'field_high_season',
      1 => 'field_low_season',
      2 => 'field_display_end_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Timing',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-timing field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_timing|node|campaign|form'] = $field_group;

  return $export;
}
