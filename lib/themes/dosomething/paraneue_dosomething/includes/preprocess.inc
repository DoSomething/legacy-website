<?php

/**
 * Implements theme_preprocess_page().
 */
function paraneue_dosomething_preprocess_page(&$vars) {
  $vars['logo'] = $vars['base_path'] . NEUE_PATH . '/assets/images/ds-logo.png';


  // Navigation Output Setup
  $navigation_vars = array(
    'base_path' => $vars['base_path'],
    'front_page' => $vars['front_page'],
    'logged_in' => $vars['logged_in'],
    'search_box' => $vars['search_box'],
  );

  $vars['navigation'] = theme('navigation', $navigation_vars);


  // Footer Output Setup
  $vars['footer'] = theme('footer');
}


/**
 * Implements theme_preprocess_user_profile().
 */
function paraneue_dosomething_preprocess_user_profile(&$variables) {
  // krumo($variables);
  // May delete this function if processing output content in the module.
}
