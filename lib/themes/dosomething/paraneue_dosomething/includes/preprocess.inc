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
 * Implements theme_preprocess_node().
 */
function paraneue_dosomething_preprocess_node(&$variables) {
  if ($variables['node']->type == "campaign") {
    // If the campaign requires a signup modal to display:
    if (isset($variables['node']->required_signup_data_form)) {
      // Add JS to open the signup data form modal.
      $id = 'modal-signup-data-form';
      $js = 'require(["neue/modal"], function(Modal) { Modal.open( $("#[' . $id . ']"), false); });';
      drupal_add_js($js, 'inline');
    }
  }
}
