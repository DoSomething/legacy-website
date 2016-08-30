<?php
/**
 * @file
 * dosomething_campaign.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_campaign_field_group_info() {
  $field_groups = array();

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
    'weight' => '2',
    'children' => array(
      0 => 'field_call_to_action',
      1 => 'field_confirmation_doc',
      2 => 'field_image_campaign_cover',
      3 => 'field_campaign_type',
      4 => 'field_campaign_status',
      5 => 'field_current_run',
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
  $field_groups['group_basic_info|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_campaign_additional_info|node|campaign|form';
  $field_group->group_name = 'group_campaign_additional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Info',
    'weight' => '16',
    'children' => array(
      0 => 'field_latest_news_copy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-campaign-additional-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_campaign_additional_info|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_confirmation|node|campaign|form';
  $field_group->group_name = 'group_confirmation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Confirmation',
    'weight' => '10',
    'children' => array(
      0 => 'field_reportback_confirm_msg',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Confirmation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-confirmation field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_confirmation|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_created|node|campaign|form';
  $field_group->group_name = 'group_created';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Creator Info',
    'weight' => '14',
    'children' => array(
      0 => 'field_created_by',
      1 => 'field_created_copy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Creator Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-created field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_created|node|campaign|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_image_step_gallery',
      1 => 'field_photo_step',
      2 => 'field_post_step_copy',
      3 => 'field_post_step_header',
      4 => 'field_pre_step_copy',
      5 => 'field_pre_step_header',
      6 => 'field_step_post',
      7 => 'field_step_pre',
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
  $field_groups['group_do_it|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_incentives|node|campaign|form';
  $field_group->group_name = 'group_incentives';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Incentives',
    'weight' => '11',
    'children' => array(
      0 => 'field_official_rules',
      1 => 'field_scholarship_amount',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Incentives',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-incentives field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_incentives|node|campaign|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_fact_problem',
      1 => 'field_fact_solution',
      2 => 'field_facts',
      3 => 'field_faq',
      4 => 'field_image_psa_replacement',
      5 => 'field_solution_support',
      6 => 'field_solution_copy',
      7 => 'field_video',
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
  $field_groups['group_know_it|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_finder|node|campaign|form';
  $field_group->group_name = 'group_location_finder';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_prep_it';
  $field_group->data = array(
    'label' => 'Location Finder',
    'weight' => '18',
    'children' => array(
      0 => 'field_location_finder',
      1 => 'field_location_finder_copy',
      2 => 'field_location_finder_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Location Finder',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-location-finder field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_location_finder|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partners|node|campaign|form';
  $field_group->group_name = 'group_partners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsors and Partners',
    'weight' => '13',
    'children' => array(
      0 => 'field_partners',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sponsors and Partners',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-partners field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_partners|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pitch_additional_info|node|campaign|form';
  $field_group->group_name = 'group_pitch_additional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pitch Page Additional Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_secondary_call_to_action',
      1 => 'field_value_proposition',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pitch Page Additional Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-pitch-additional-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_pitch_additional_info|node|campaign|form'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'field_items_needed',
      1 => 'field_promoting_tips',
      2 => 'field_time_and_place',
      3 => 'field_vips',
      4 => 'field_action_guide',
      5 => 'field_downloads',
      6 => 'group_location_finder',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Plan It',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'This section describes what a user needs to do BEFORE they can start taking the action (i.e. things they\'ll need, people to talk to, etc.).  You MUST fill out AT LEAST TWO of Stuff You Need, Time and Place, VIPs, and Hype.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_prep_it|node|campaign|form'] = $field_group;

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
    'weight' => '9',
    'children' => array(
      0 => 'field_reportback_copy',
      1 => 'field_reportback_noun',
      2 => 'field_reportback_verb',
      3 => 'field_helpful_tips',
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
  $field_groups['group_report_back|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_starter_statement|node|campaign|form';
  $field_group->group_name = 'group_starter_statement';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Starter Statement',
    'weight' => '6',
    'children' => array(
      0 => 'field_starter_statement',
      1 => 'field_starter_statement_header',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Starter Statement',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-starter-statement field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_starter_statement|node|campaign|form'] = $field_group;

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
    'weight' => '12',
    'children' => array(
      0 => 'field_action_type',
      1 => 'field_active_hours',
      2 => 'field_cause',
      3 => 'field_issue',
      4 => 'field_primary_action_type',
      5 => 'field_primary_cause',
      6 => 'field_staff_pick',
      7 => 'field_tags',
      8 => 'field_staff_pick_label',
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
  $field_groups['group_taxonomy|node|campaign|form'] = $field_group;

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
  $field_groups['group_timing|node|campaign|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Info');
  t('Basic Info');
  t('Confirmation');
  t('Creator Info');
  t('Do It');
  t('Incentives');
  t('Know It');
  t('Location Finder');
  t('Pitch Page Additional Info');
  t('Plan It');
  t('Prove It');
  t('Sponsors and Partners');
  t('Starter Statement');
  t('Taxonomy and Discovery');
  t('Timing');

  return $field_groups;
}
