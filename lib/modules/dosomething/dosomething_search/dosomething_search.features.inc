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
