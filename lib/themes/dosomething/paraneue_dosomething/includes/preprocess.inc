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
  $columns = array('first', 'second', 'third');
  $footer_links = array();

  foreach($columns as $column) {
    $prefix = "footer_links_" . $column . "_column_";
    $footer_links[$column] = array();
    $footer_links[$column]['heading'] = theme_get_setting($prefix . "heading");

    $links = explode("\n", trim(theme_get_setting($prefix . "links")));
    $links = array_filter($links); // Remove empty items

    foreach($links as &$link) {
      list($text, $url) = explode('|', $link);
      $link = l(trim($text), trim($url));
    }

    $footer_links[$column]['links'] = $links;
    $footer_links[$column]['class'] = theme_get_setting($prefix . "class");
  }

  $vars['footer'] = theme(
    'footer',
    array(
      'social' => theme_get_setting('footer_social'),
      'links' => $footer_links
    )
  );
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
