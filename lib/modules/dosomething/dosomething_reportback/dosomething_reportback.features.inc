<?php
/**
 * @file
 * dosomething_reportback.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dosomething_reportback_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function dosomething_reportback_flag_default_flags() {
  $flags = array();
  // Exported flag: "Promoted".
  $flags['promoted'] = array(
    'entity_type' => 'file',
    'title' => 'Promoted',
    'global' => 1,
    'types' => array(
      0 => 'image',
    ),
    'flag_short' => 'Add to gallery',
    'flag_long' => 'Adds to the Campaign Gallery',
    'flag_message' => 'Image added to the gallery.',
    'unflag_short' => 'Remove from gallery',
    'unflag_long' => 'Remove from the Campaign Gallery',
    'unflag_message' => 'Image removed from the gallery.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'teaser' => 'teaser',
      'full' => 'full',
      'preview' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'flag_confirmation' => 'Add to gallery',
    'unflag_confirmation' => 'Remove from gallery',
    'module' => 'dosomething_reportback',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
