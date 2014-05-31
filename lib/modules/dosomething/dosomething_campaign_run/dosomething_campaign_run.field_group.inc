<?php
/**
 * @file
 * dosomething_campaign_run.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_campaign_run_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_totals|node|campaign_run|form';
  $field_group->group_name = 'group_totals';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_run';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Totals',
    'weight' => '3',
    'children' => array(
      0 => 'field_total_participants',
      1 => 'field_total_quantity',
      2 => 'field_total_quantity_label',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Totals',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-totals field-group-fieldset',
        'description' => 'If you do not want to display the Totals, leave these fields blank.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_totals|node|campaign_run|form'] = $field_group;

  return $export;
}
