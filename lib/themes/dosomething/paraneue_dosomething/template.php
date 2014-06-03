<?php

// Define theme directory path
define('PARANEUE_DS_PATH', drupal_get_path('theme', 'paraneue_dosomething'));

// If ds_version is set, use CDN assets
if(theme_get_setting('asset_path')) {
  $cdn_path = theme_get_setting('asset_path');
  $cdn_path = str_replace('{ds_version}', variable_get('ds_version', 'latest'), $cdn_path);
  define('DS_ASSET_PATH', $cdn_path);
} else {
  define('DS_ASSET_PATH', '/' . PARANEUE_DS_PATH . '/dist');
}

// Determine whether to use minified script or not
if(theme_get_setting('use_minified_assets')) {
  define('DS_STYLE_PATH', DS_ASSET_PATH . '/app.min.css');
  define('DS_JAVASCRIPT_PATH', DS_ASSET_PATH . '/app.min.js');
} else {
  define('DS_STYLE_PATH', DS_ASSET_PATH . '/app.css');
  define('DS_JAVASCRIPT_PATH', DS_ASSET_PATH . '/app.js');
}

// Define asset directory paths
define('LIB_ASSET_PATH', DS_ASSET_PATH . '/bower_components');
define('NEUE_ASSET_PATH', LIB_ASSET_PATH . '/neue');

// Theme includes
require_once PARANEUE_DS_PATH . '/includes/bootstrap.inc';
require_once PARANEUE_DS_PATH . '/includes/theme.inc';
require_once PARANEUE_DS_PATH . '/includes/preprocess.inc';
require_once PARANEUE_DS_PATH . '/includes/helpers.inc';
require_once PARANEUE_DS_PATH . '/includes/form.inc';
require_once PARANEUE_DS_PATH . '/includes/auth/login.inc';
require_once PARANEUE_DS_PATH . '/includes/auth/register.inc';

/**
 * We use our own asset pipeline (through Grunt), so we want to bypass most
 * of Drupal's included assets.
 *
 * Implements hook_css_alter().
 */
function paraneue_dosomething_css_alter(&$css) {
  // Load excluded CSS files from theme.
  $excludes = _paraneue_dosomething_alter(paraneue_dosomething_theme_get_info('exclude'), 'css');
  $css = array_diff_key($css, $excludes);

  // Force removal of files we can't seem to kill with exclude[css] array
  // @TODO: Figure out why this is necessary.
  unset($css[drupal_get_path('module', 'date') . '/date_api/date.css']);
  unset($css[drupal_get_path('module', 'ctools') . '/css/ctools.css']);
  unset($css[drupal_get_path('module', 'views') . '/css/views.css']);
}

/**
 * We use our own asset pipeline (through Grunt), so we want to bypass most
 * of Drupal's included assets.
 *
 * Implements hook_js_alter().
 */
function paraneue_dosomething_js_alter(&$js) {
  // Load excluded JS files from theme.
  $excludes = _paraneue_dosomething_alter(paraneue_dosomething_theme_get_info('exclude'), 'js');
  $js = array_diff_key($js, $excludes);

  // Force removal of files that we can't seem to kill with exclude[js] array
  unset($js['profiles/dosomething/modules/contrib/devel/devel_krumo_path.js']);
}


/**
 * Implements hook_page_alter().
 */
function paraneue_dosomething_page_alter(&$page) {
  // Ensure we have a 'page_bottom' region
  if (!isset($page['page_bottom'])) {
    $page['page_bottom'] = array('region' => 'page_bottom');
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
