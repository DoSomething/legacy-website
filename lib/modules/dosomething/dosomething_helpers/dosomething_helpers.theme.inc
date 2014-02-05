<?php

/**
 * Implements hook_theme_registry_alter()
 *
 * Modules registered in dosomething_helpers_modules will 
 * have their paths added to the theme registry so that they
 * can store reference entity type templates within the module.
**/
function dosomething_helpers_theme_registry_alter(&$theme_registry) {
  $modules = variable_get('dosomething_helpers_modules', array());
  if (!empty($modules)) {
    foreach ($modules as $module) {
      $mod_path = drupal_get_path('module', 'dosomething_' . $module);
      $theme_registry_copy = $theme_registry;
      _theme_process_registry($theme_registry_copy, 'phptemplate', 'theme_engine', 'paraneue_dosomething', $mod_path);
      $theme_registry += array_diff_key($theme_registry_copy, $theme_registry);
      $hooks = array('node');
      foreach ($hooks as $h) {
        _dosomething_helpers_insert_after_first_element($theme_registry[$h]['theme paths'], $mod_path);
      }
    }
  }
}

/**
 * Helper function for re-ordering arrays (needed by theme_registry_alter)
*/
function _dosomething_helpers_insert_after_first_element(&$a, $element) {
  if (is_array($a)) {
    $first_element = array_shift($a);
    array_unshift($a, $first_element, $element);
  }
  else {
    $a = $element;
  }
}