<?php

/**
 * Implements theme_preprocess_page().
 */
function paraneue_dosomething_preprocess_page(&$vars) {
  $vars['logo'] = $vars['base_path'] . NEUE_PATH . '/assets/images/ds-logo.png';


  // Get User Information
  $user_info = user_load($vars['user']->uid);

  if (isset($user_info->field_first_name['und'][0]['safe_value'])) {
    $vars['user_identifier'] = $user_info->field_first_name['und'][0]['safe_value'];
  } else if (isset($user_info->name)) {
    $vars['user_identifier'] = $user_info->name;
  } else {
    $vars['user_identifier'] = $user_info->mail;
  }

  // krumo($vars['user_identifier']);

  // Navigation Output Setup
  $navigation_vars = array(
    'base_path'       => $vars['base_path'],
    'front_page'      => $vars['front_page'],
    'logged_in'       => $vars['logged_in'],
    'search_box'      => $vars['search_box'],
    'user_identifier' => dosomething_helpers_text_truncate($vars['user_identifier'], 8),
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
      $js = 'require(["neue/modal"], function(Modal) { Modal.open( jQuery("#' . $id . '"), {animated: false, closeButton: "skip", skipForm: "#dosomething-signup-user-skip-signup-data-form"}); });';
      drupal_add_js($js, 'inline');
    }
  }
}
