<?php
/**
 * @file
 * dosomething_home.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_home_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_home';
  $strongarm->value = '0';
  $export['language_content_type_home'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_home';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_home'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_home';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_home'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_home';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_home'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_home';
  $strongarm->value = '0';
  $export['node_preview_home'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_home';
  $strongarm->value = 0;
  $export['node_submitted_home'] = $strongarm;

  return $export;
}
