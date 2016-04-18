<?php
/**
 * @file
 * dosomething_campaign_group.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_campaign_group_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_text|node|campaign_group|form';
  $field_group->group_name = 'group_additional_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Info',
    'weight' => '5',
    'children' => array(
      0 => 'field_gallery',
      1 => 'field_additional_text',
      2 => 'field_additional_text_title',
      3 => 'field_scholarship_amount',
      4 => 'field_additional_text_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-additional-text field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_additional_text|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|campaign_group|form';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_call_to_action',
      1 => 'field_campaigns',
      2 => 'field_image_campaign_cover',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basic Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-header field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_header|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_intro|node|campaign_group|form';
  $field_group->group_name = 'group_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Intro',
    'weight' => '1',
    'children' => array(
      0 => 'field_faq',
      1 => 'field_intro',
      2 => 'field_intro_image',
      3 => 'field_intro_title',
      4 => 'field_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Intro',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-intro field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_intro|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partners|node|campaign_group|form';
  $field_group->group_name = 'group_partners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsors and Partners',
    'weight' => '9',
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
  $field_groups['group_partners|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_post_signup|node|campaign_group|form';
  $field_group->group_name = 'group_post_signup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Post Signup',
    'weight' => '3',
    'children' => array(
      0 => 'field_post_signup_title',
      1 => 'field_post_signup_copy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Post Signup',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-post-sign-up field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_post_signup|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pre_launch|node|campaign_group|form';
  $field_group->group_name = 'group_pre_launch';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pre Launch',
    'weight' => '4',
    'children' => array(
      0 => 'field_pre_launch_copy',
      1 => 'field_pre_launch_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pre Launch',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-pre-launch field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_pre_launch|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_signup_form|node|campaign_group|form';
  $field_group->group_name = 'group_signup_form';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Signup Configuration',
    'weight' => '2',
    'children' => array(
      0 => 'field_signup_confirm_msg',
      1 => 'field_display_signup_form',
      2 => 'field_transactional_email_copy',
      3 => 'field_automatic_parent_signup',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Signup Configuration',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-signup-form field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_signup_form|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|campaign_group|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomy and Discovery',
    'weight' => '8',
    'children' => array(
      0 => 'field_cause',
      1 => 'field_action_type',
      2 => 'field_active_hours',
      3 => 'field_staff_pick',
      4 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taxonomy and Discovery',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-taxonomy field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_taxonomy|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_timing|node|campaign_group|form';
  $field_group->group_name = 'group_timing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Timing',
    'weight' => '6',
    'children' => array(
      0 => 'field_display_end_date',
      1 => 'field_high_season',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Timing',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-timing field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_timing|node|campaign_group|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Info');
  t('Basic Info');
  t('Intro');
  t('Post Signup');
  t('Pre Launch');
  t('Signup Configuration');
  t('Sponsors and Partners');
  t('Taxonomy and Discovery');
  t('Timing');

  return $field_groups;
}
