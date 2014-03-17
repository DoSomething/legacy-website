<?php

include 'includes/auth/login.php';
include 'includes/auth/register.php';

define('PARANEUE_DS_PATH', drupal_get_path('theme', 'paraneue_dosomething'));

/**
 * Implements hook_css_alter().
 */
function paraneue_dosomething_css_alter(&$css) {
  // Core
  $app_css = PARANEUE_DS_PATH . '/dist/app.css';
  $css['app']['data'] = $app_css;
  $css['app']['media'] = 'all';
  $css['app']['browsers'] = array('IE' => TRUE, '!IE' => TRUE);
  $css['app']['preprocess'] = FALSE;
  $css['app']['group'] = CSS_THEME;
  $css['app']['type'] = 'file';
  $css['app']['every_page'] = TRUE;
  $css['app']['weight'] = 1;

  $app_css_ie = PARANEUE_DS_PATH . '/dist/ie.css';
  $css['app-ie']['data'] = $app_css_ie;
  $css['app-ie']['media'] = 'all';
  $css['app-ie']['browsers'] = array('IE' => 'lte IE 8');
  $css['app-ie']['preprocess'] = FALSE;
  $css['app-ie']['group'] = CSS_THEME;
  $css['app-ie']['type'] = 'file';
  $css['app-ie']['every_page'] = TRUE;
  $css['app-ie']['weight'] = 1;
}

/**
 * Implements hook_js_alter().
 */
function paraneue_dosomething_js_alter(&$js) {
  $app_js = PARANEUE_DS_PATH . '/dist/app.js';
  $js['app'] = drupal_js_defaults();
  $js['app']['data'] = $app_js;
  $js['app']['group'] = -100;
  $js['app']['type'] = 'file';
  $js['app']['every_page'] = TRUE;
  $js['app']['weight'] = -10;
}


/**
 * Implements hook_page_alter().
 */
function paraneue_dosomething_page_alter(&$page) {
  // Ensure we have a 'page_bottom' region
  if (!isset($page['page_bottom'])) {
    $page['page_bottom'] = array('region' => $bottom_region);
  }
  
  paraneue_dosomething_page_alter_login($page);
  paraneue_dosomething_page_alter_register($page);
}

/**
 * Implements hook_form_alter();
 */
function paraneue_dosomething_form_alter(&$form, &$form_state, $form_id) {
  paraneue_dosomething_form_alter_login($form, $form_state, $form_id);
  paraneue_dosomething_form_alter_register($form, $form_state, $form_id);
}
