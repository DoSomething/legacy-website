<?php
/**
 * @file
 * dosomething_metatag.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_metatag_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
