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
    // @TODO_RBv2 - temp theme function; remove when RBv2 launched to Prod.
    'old_reportback_submitted_images' => array(
      'template' => 'old-reportback-submitted-images',
      'path' => drupal_get_path('module', 'dosomething_reportback') . '/theme',
      'variables' => array(
        'updated' => NULL,
        'images' => NULL,
      ),
    ),
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
      'variables' => array(
        'rb_image' => NULL,
        'reportback' => NULL,
        'node' => NULL,
        'user' => NULL,
        'copy_vars' => NULL,
        ),
      )
    );
}