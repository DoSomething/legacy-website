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
  $field_group->identifier = 'group_call_to_action|node|campaign_group|form';
  $field_group->group_name = 'group_call_to_action';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call to Action',
    'weight' => '3',
    'children' => array(
      0 => 'field_cta_link',
      1 => 'field_call_to_action',
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
  $export['group_call_to_action|node|campaign_group|form'] = $field_group;

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
    'weight' => '2',
    'children' => array(
      0 => 'field_intro',
      1 => 'field_intro_title',
      2 => 'field_faq',
      3 => 'field_partners',
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
    'weight' => '6',
    'children' => array(
      0 => 'field_post_signup_title',
      1 => 'field_signup_confirm_msg',
      2 => 'field_post_signup_body',
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
  $field_group->identifier = 'group_pre_signup|node|campaign_group|form';
  $field_group->group_name = 'group_pre_signup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pre Signup',
    'weight' => '4',
    'children' => array(
      0 => 'field_additional_text',
      1 => 'field_additional_text_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pre-signup field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pre_signup|node|campaign_group|form'] = $field_group;

  return $export;
}
