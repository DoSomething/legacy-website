<?php
/**
 * @file
 * dosomething_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_search_views_api($module = NULL, $api = NULL) {
  return array(
 	"api" => "3.0",
	'template path' => drupal_get_path('module', 'dosomething_search'),
  );
}
