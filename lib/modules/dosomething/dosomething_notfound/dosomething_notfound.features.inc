<?php
/**
 * @file
 * dosomething_notfound.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_notfound_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_notfound_node_info() {
  $items = array(
    'notfound' => array(
      'name' => t('Not Found'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
      ),
    );
  return $items;
}
