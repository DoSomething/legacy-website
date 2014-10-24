<?php
/**
 * @file
 * dosomething_fact.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_fact_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_fact_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dosomething_fact_node_info() {
  $items = array(
    'fact' => array(
      'name' => t('Fact'),
      'base' => 'node_content',
      'description' => t('A Fact. Referenced by other content types such as Campaigns and Fact Pages.'),
      'has_title' => '1',
      'title_label' => t('Fact'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
