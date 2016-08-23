<?php

// Define theme directory path
define('PARANEUE_PATH', drupal_get_path('theme', 'paraneue_dosomething'));

// Define asset directory paths
define('VENDOR_ASSET_PATH', PARANEUE_PATH . '/node_modules');
define('FORGE_ASSET_PATH', VENDOR_ASSET_PATH . '/@dosomething/forge');

// Theme includes
require_once PARANEUE_PATH . '/includes/bootstrap.inc';
require_once PARANEUE_PATH . '/includes/theme.inc';
require_once PARANEUE_PATH . '/includes/preprocess.inc';
require_once PARANEUE_PATH . '/includes/helpers.inc';
require_once PARANEUE_PATH . '/includes/patterns.inc';
require_once PARANEUE_PATH . '/includes/form.inc';
require_once PARANEUE_PATH . '/includes/auth/login.inc';
require_once PARANEUE_PATH . '/includes/auth/register.inc';

/**
 * We use our own asset pipeline (through Grunt), so we want to bypass most
 * of Drupal's included assets.
 *
 * Implements hook_css_alter().
 */
function paraneue_dosomething_css_alter(&$css) {
  // We add `app.css` in `paraneue_dosomething_preprocess_html`.
  // @see: includes/preprocess.inc

  // Load excluded CSS files from theme.
  $excludes = _paraneue_dosomething_alter(paraneue_dosomething_theme_get_info('exclude'), 'css');
  $css = array_diff_key($css, $excludes);

  // Force removal of files we can't seem to kill with exclude[css] array
  // @TODO: Figure out why this is necessary.
  unset($css[drupal_get_path('module', 'date') . '/date_api/date.css']);
  unset($css[drupal_get_path('module', 'ctools') . '/css/ctools.css']);
  unset($css[drupal_get_path('module', 'views') . '/css/views.css']);
  unset($css[drupal_get_path('module', 'field_group') . '/field_group.field_ui.css']);
  unset($css[drupal_get_path('module', 'addressfield') . '/addressfield.css']);
  unset($css[drupal_get_path('module', 'locale') . '/locale.css']);
}

/**
 * We use our own asset pipeline (through Grunt), so we want to bypass most
 * of Drupal's included assets.
 *
 * Implements hook_js_alter().
 */
function paraneue_dosomething_js_alter(&$js) {
  // Add lib.js and app.js using Drupal API:
  drupal_add_js(PARANEUE_PATH . '/dist/lib.js', [
    'group'      => JS_LIBRARY,
    'weight'     => -200,
    'every_page' => TRUE,
    'preprocess' => FALSE,
  ]);

  drupal_add_js(PARANEUE_PATH . '/dist/app.js', [
    'group'      => JS_LIBRARY,
    'weight'     => 200,
    'every_page' => TRUE,
    'preprocess' => FALSE,
  ]);

  // Force settings to be embedded after lib, before app scripts.
  if(isset($js['settings'])) {
    $inline_settings = [
        'type' => 'inline',
        'group' => JS_LIBRARY,
        'weight' => 999,
        'data' => 'jQuery.extend(Drupal.settings, ' . drupal_json_encode(drupal_array_merge_deep_array($js['settings']['data'])) . ');',
        'every_page' => TRUE,
      ] + drupal_js_defaults();

    // No need for drupal_get_js() to do this again.
    unset($js['settings']);

    $js['inline_settings'] = $inline_settings;
  }

  // Load excluded JS files from theme info file.
  $excludes = _paraneue_dosomething_alter(paraneue_dosomething_theme_get_info('exclude'), 'js');
  $js = array_diff_key($js, $excludes);

  // Force removal of files that we can't seem to kill with exclude[js] array
  unset($js['profiles/dosomething/modules/contrib/devel/devel_krumo_path.js']);
  unset($js['profiles/dosomething/modules/contrib/google_analytics/googleanalytics.js']);
}

/**
 * Implements hook_page_alter().
 */
function paraneue_dosomething_page_alter(&$page) {
  // Ensure we have a 'page_bottom' region
  if (!isset($page['page_bottom'])) {
    $page['page_bottom'] = [];
  }

  paraneue_dosomething_page_alter_login($page);
  paraneue_dosomething_page_alter_register($page);
}

/**
 * Implements hook_form_alter();
 */
function paraneue_dosomething_form_alter(&$form, &$form_state, $form_id) {
  paraneue_dosomething_form_alter_base($form, $form_state, $form_id);
  paraneue_dosomething_form_alter_login($form, $form_state, $form_id);
  paraneue_dosomething_form_alter_register($form, $form_state, $form_id);
}

/**
 * Implements hook_head_alter().
 */
function paraneue_dosomething_html_head_alter(&$head_elements) {
  foreach($head_elements as $key => $element) {
    switch($key) {
      case (preg_match('/^drupal_add_html_head_link*/', $key)) ? TRUE : FALSE:
        $shortcut_key = $key;
        break;
    }
  }

  if ($shortcut_key) {
    unset($head_elements[$shortcut_key]);
  }
}
