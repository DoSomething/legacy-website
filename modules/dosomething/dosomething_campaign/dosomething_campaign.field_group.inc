<?php
/**
 * @file
 * dosomething_campaign.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_campaign_field_group_info() {
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
    'weight' => '6',
    'children' => array(
      0 => 'field_step_photo',
      1 => 'field_step_post',
      2 => 'field_step_pre',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Do It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'weight' => '10',
    'children' => array(
      0 => 'field_image_campaign_cover',
      1 => 'field_image_campaign_gallery',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Images',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'weight' => '7',
    'children' => array(
      0 => 'field_fact_problem',
      1 => 'field_fact_solution',
      2 => 'field_facts',
      3 => 'field_faq',
      4 => 'field_psa',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Know It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'weight' => '5',
    'children' => array(
      0 => 'field_items_needed',
      1 => 'field_location_finder',
      2 => 'field_promoting_tips',
      3 => 'field_starter_statement',
      4 => 'field_time_and_place',
      5 => 'field_vips',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Prep It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'weight' => '8',
    'children' => array(
      0 => 'field_report_back_noun',
      1 => 'field_report_back_verb',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Report Back',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'weight' => '11',
    'children' => array(
      0 => 'field_sponsor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sponsors',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'weight' => '9',
    'children' => array(
      0 => 'field_action_type',
      1 => 'field_active_hours',
      2 => 'field_cause',
      3 => 'field_staff_pick',
      4 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taxonomy',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'weight' => '4',
    'children' => array(
      0 => 'field_display_end_date',
      1 => 'field_high_season',
      2 => 'field_low_season',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Timing',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_timing|node|campaign|form'] = $field_group;

  return $export;
}
