<?php

/**
 * @file
 * dosomething_helpers.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_helpers_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dosomething_helpers_modules';
  $strongarm->value = array(
    'static_content',
    'fact_page',
    'action_guide',
  );
  $export['dosomething_helpers_modules'] = $strongarm;

  return $export;
}
