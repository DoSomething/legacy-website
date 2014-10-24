<?php
/**
 * @file
 * dosomething_fact_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_fact_page_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dosomething_fact_page_node_info() {
  $items = array(
    'fact_page' => array(
      'name' => t('Fact Page'),
      'base' => 'node_content',
      'description' => t('"11 Facts" page type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
