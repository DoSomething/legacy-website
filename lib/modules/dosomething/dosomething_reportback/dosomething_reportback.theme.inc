<?php
/**
 * @file
 * Code for dosomething_reportback theme.
 */

/**
 * Implements hook_theme().
 */
function dosomething_reportback_theme($existing, $type, $theme, $path) {
  return array(
    'reportback_prior_submissions' => array(
      'template' => 'reportback-prior-submissions',
      'path' => drupal_get_path('module', 'dosomething_reportback') . '/theme',
      'variables' => array(
        'updated' => NULL,
        'images' => NULL,
      ),
    ),
    'reportback_latest_submission' => array(
      'template' => 'reportback-latest-submission',
      'path' => drupal_get_path('module', 'dosomething_reportback') . '/theme',
      'variables' => array(
        'image' => NULL,
      ),
    ),
    'dosomething_reportback_files_form' => array(
      'render element' => 'form',
      'file' => 'dosomething_reportback.admin.inc',
    ),
    'reportback_permalink' => array(
      'template' => 'reportback-permalink',
      'path' => drupal_get_path('module', 'dosomething_reportback') . '/theme',
    ),
    'reportback_rogue_fail_permalink' => array(
      'template' => 'reportback-rogue-fail-permalink',
      'path' => drupal_get_path('module', 'dosomething_reportback') . '/theme',
      )
    );
}