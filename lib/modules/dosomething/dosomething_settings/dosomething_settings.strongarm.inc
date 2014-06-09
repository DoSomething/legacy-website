<?php
/**
 * @file
 * dosomething_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_file_pattern';
  $strongarm->value = 'file/[file:fid]';
  $export['pathauto_file_pattern'] = $strongarm;

  return $export;
}
