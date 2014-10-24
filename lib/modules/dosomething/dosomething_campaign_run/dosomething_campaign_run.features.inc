<?php
/**
 * @file
 * dosomething_campaign_run.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_campaign_run_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_campaign_run_node_info() {
  $items = array(
    'campaign_run' => array(
      'name' => t('Campaign Run'),
      'base' => 'node_content',
      'description' => t('Contains content for a specific run of a Campaign, e.g. <em>Comeback Clothes 2014.</em>'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
