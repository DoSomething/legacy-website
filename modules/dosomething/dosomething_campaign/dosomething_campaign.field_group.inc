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
  $field_group->identifier = 'group_basic_info|node|campaign|form';
  $field_group->group_name = 'group_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_call_to_action',
      1 => 'field_confirmation_doc',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basic-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_basic_info|node|campaign|form'] = $field_group;

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
    'weight' => '4',
    'children' => array(
      0 => 'field_step_post',
      1 => 'field_step_pre',
      2 => 'field_pre_baby_steps',
      3 => 'field_post_baby_steps',
      4 => 'field_photo_step',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Do It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'Tips for when the campaign action starts. For example, if running a drive, this section is what to do while your drive is active and taking donations. If running "Meatless Monday" this section is once the Meatless Monday event starts.',
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
    'weight' => '8',
    'children' => array(
      0 => 'field_image_campaign_cover',
      1 => 'field_psa',
      2 => 'field_image_psa_replacement',
      3 => 'field_image_do_it',
      4 => 'field_image_prove_it',
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
    'weight' => '2',
    'children' => array(
      0 => 'field_fact_problem',
      1 => 'field_fact_solution',
      2 => 'field_facts',
      3 => 'field_faq',
      4 => 'field_solution_support',
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
    'label' => 'Plan It',
    'weight' => '3',
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
      'label' => 'Plan It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'This section describes what a user needs to do BEFORE they can start taking the action (i.e. things they\'ll need, people to talk to, etc.). The Campaign Starter Statement is required. All other fields are optional however you MUST fill out AT LEAST TWO of Stuff You Need, Time and Place, VIPs, and Hype.',
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
    'label' => 'Prove It',
    'weight' => '5',
    'children' => array(
      0 => 'field_report_back_noun',
      1 => 'field_report_back_verb',
      2 => 'field_scholarship_amount',
      3 => 'field_official_rules',
      4 => 'field_confirmation_sentence',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Prove It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'We want to quantify the impact of each campaign. When people report back we will ask them for the number of jeans they collected or senior citizens they educated.',
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
    'label' => 'Sponsors and Partners',
    'weight' => '7',
    'children' => array(
      0 => 'field_sponsor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sponsors and Partners',
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
    'label' => 'Taxonomy and Discovery',
    'weight' => '6',
    'children' => array(
      0 => 'field_action_type',
      1 => 'field_active_hours',
      2 => 'field_cause',
      3 => 'field_staff_pick',
      4 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taxonomy and Discovery',
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
    'weight' => '1',
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
        'description' => 'Each of these fields is optional. Only fill each out if you feel like it\'s really needed.
<br/>
Also just because you give something a high season, doesn\'t mean it needs a low season, and vice versa.
<br/>
However, if you give something a High Season Start Date, make sure you give it a High Season End Date.
<br/>
Campaigns that are in high season will have higher priority than non-seasonal campaigns, and campaigns that are in low season will have lower priority than non-seasonal campaigns.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_timing|node|campaign|form'] = $field_group;

  return $export;
}
