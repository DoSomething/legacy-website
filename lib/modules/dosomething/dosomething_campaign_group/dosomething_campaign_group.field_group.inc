<?php
/**
 * @file
 * dosomething_campaign_group.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_campaign_group_field_group_info() {
  $export = array();

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
    'label' => 'Header',
    'weight' => '0',
    'children' => array(
      0 => 'field_call_to_action',
      1 => 'field_image_campaign_cover',
      2 => 'title',
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
  $export['group_header|node|campaign_group|form'] = $field_group;

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
      2 => 'field_intro_title',
      3 => 'field_partners',
      4 => 'field_video',
      5 => 'field_intro_image',
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
  $export['group_intro|node|campaign_group|form'] = $field_group;

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
    'label' => 'Post Sign Up',
    'weight' => '7',
    'children' => array(
      0 => 'field_post_signup_body',
      1 => 'field_signup_confirm_msg',
      2 => 'field_post_signup_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-post-sign-up field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_post_signup|node|campaign_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pre_live|node|campaign_group|form';
  $field_group->group_name = 'group_pre_live';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pre-Live',
    'weight' => '6',
    'children' => array(
      0 => 'field_additional_text',
      1 => 'field_additional_text_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pre-live field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pre_live|node|campaign_group|form'] = $field_group;

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
    'label' => 'Signup Form',
    'weight' => '5',
    'children' => array(
      0 => 'field_display_signup_form',
      1 => 'field_signup_form_button_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-signup-form field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_signup_form|node|campaign_group|form'] = $field_group;

  return $export;
}
