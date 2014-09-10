<?php
/**
 * @file
 * dosomething_campaign_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_campaign_group_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dosomething_campaign_group_node_info() {
  $items = array(
    'campaign_group' => array(
      'name' => t('Campaign Collection'),
      'base' => 'node_content',
      'description' => t('A collection of campaigns, which can be configured to collect signups and pre-signups.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
