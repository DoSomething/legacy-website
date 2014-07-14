<?php

/**
 * Implements theme_preprocess_page().
 */
function paraneue_dosomething_preprocess_page(&$vars) {
  // Add theme suggestion for page template based on node.
  if (isset($vars['node']->type)) {
    // If the content type's machine name is "my_machine_name" the file
    // name will be "page--my-machine-name.tpl.php".
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
  }

  /**
   * User Info
   */

  $user_info = user_load($vars['user']->uid);

  if (isset($user_info->field_first_name['und'][0]['safe_value'])) {
    $vars['user_identifier'] = $user_info->field_first_name['und'][0]['safe_value'];
  } else if (isset($user_info->name)) {
    $vars['user_identifier'] = $user_info->name;
  } else {
    $vars['user_identifier'] = $user_info->mail;
  }

  /**
   * Global Main Navigation
   */

  $modifier_classes = 'white floating';
  if(isset($vars['use_black_navigation']) && $vars['use_black_navigation'] == 1) {
    $modifier_classes = 'black floating';
  }

  $navigation_vars = array(
    'base_path'        => $vars['base_path'],
    'modifier_classes' => $modifier_classes,
    'logo'             => NEUE_ASSET_PATH . '/assets/images/ds-logo.png',
    'front_page'       => $vars['front_page'],
    'logged_in'        => $vars['logged_in'],
    'search_box'       => $vars['search_box'],
    'user_identifier'  => dosomething_helpers_text_truncate($vars['user_identifier'], 8),
    'who_we_are'       => array(
      'text' => theme_get_setting('header_who_we_are_text'),
      'link' => theme_get_setting('header_who_we_are_link'),
    ),
  );

  $vars['navigation'] = theme('navigation', $navigation_vars);


  /**
   * Global Page Header
   */

  $header_vars = array(
    'title' => drupal_get_title(),
  );

  // If there's a subtitle field on this node, send it to the header
  if(isset( $vars['node']->field_subtitle[LANGUAGE_NONE][0]['safe_value'] )) {
    $header_vars['subtitle'] =  $vars['node']->field_subtitle[LANGUAGE_NONE][0]['safe_value'];
  }

  $vars['header'] = theme('header', $header_vars);


  /**
   * Global Page Footer
   */

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


  /**
   * Miscellaneous
   */

  // Show Hunt MCC form confirmation if query string exists
  $node_type = menu_get_object()->type;
  if ($node_type == 'campaign_group' && array_key_exists('submitted_mcc', $_GET)) {
    drupal_set_message(t('Thanks! We\'ll be in touch soon with next steps. If you\'d like to submit more than one campaign idea, go for it!'));
  }
}


/**
 * Implements theme_preprocess_node().
 */
function paraneue_dosomething_preprocess_node(&$vars) {

  $type = isset($vars['node']->type) ? $vars['node']->type : null;
  if ($type == "campaign") {
    // If the campaign requires a signup modal to display:
    if (isset($vars['node']->required_signup_data_form)) {
      // Add JS to open the signup data form modal.
      $id = 'modal-signup-data-form';
      $js = 'require(["neue/modal"], function(Modal) { Modal.open( jQuery("#' . $id . '"), {animated: false, closeButton: "skip", skipForm: "#dosomething-signup-user-skip-signup-data-form"}); });';
      drupal_add_js($js, 'inline');
    }
  }

  elseif ($type == "home") {
    // Set these here to remove db calls from tpl files
    $vars['show_campaign_finder'] = theme_get_setting('show_campaign_finder');
    $vars['show_sponsors'] = theme_get_setting('show_sponsors');
  }

  elseif ($type == 'fact_page') {
    // Return facts as a chunked array to allow cta's to be properly embedded in between
    $vars['facts_chunked'] = array_chunk($vars['facts'], 5);
  }


  /**
   * Info Bar
   */

  // Initialize info_bar_vars with variable that will always be set:
  $zendesk_form_header = t(variable_get('dosomething_zendesk_form_header'));
  $info_bar_vars = array(
    'zendesk_form_header' => $zendesk_form_header,
  );
  // List $vars variable names to pass to info bar:
  $info_var_names = array(
    'formatted_partners',
    'sponsors',
    'zendesk_form',
  );
  // Loop through the variable names:
  foreach ($info_var_names as $variable) {
    // If the vars is set for this variable name:
    if (isset($vars[$variable])) {
      // Store its value.
      $value = $vars[$variable];
    }
    else {
      $value = NULL;
    }
    $info_bar_vars[$variable] = $value;
  }
  $vars['info_bar'] = theme('info_bar', $info_bar_vars);
}

