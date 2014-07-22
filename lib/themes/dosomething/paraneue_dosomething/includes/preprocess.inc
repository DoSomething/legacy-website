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

  $logo = NEUE_ASSET_PATH . '/assets/images/ds-logo.png';
  if (theme_get_setting('header_logo_override')) {
    $file = file_load(theme_get_setting('header_logo_override'));
    if (!empty($file->uri)) {
      $logo = file_create_url($file->uri);
    }
  }
  $navigation_vars = array(
    'base_path'        => $vars['base_path'],
    'modifier_classes' => $modifier_classes,
    'logo'             => $logo,
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

  // Footer social networks menu.
  $social = paraneue_dosomething_get_social_networks();
  foreach ($social as $id => &$network) {
    $setting_key     = 'footer_social_' . $id;
    $setting_enabled = theme_get_setting($setting_key . '_enabled');
    $setting_url     = theme_get_setting($setting_key . '_url');
    $setting_alt     = theme_get_setting($setting_key . '_alt');

    // Skip disabled and with no URL:
    if (empty($setting_enabled) || empty($setting_enabled)) {
      unset($social[$id]);
      continue;
    }

    // Extend $social array with url and alt text.
    $network['url'] = $setting_url;
    $network['alt'] = t($setting_alt);
  }

  $footer_vars = array(
    'social' => $social,
    'links'  => $footer_links,
  );

  // Footer affiliate logo.
  $footer_logo_enabled = theme_get_setting('footer_affiliate_logo');
  $footer_logo_file    = theme_get_setting('footer_affiliate_logo_file');
  if ($footer_logo_enabled && $footer_logo_file) {
    $file = file_load(theme_get_setting('footer_affiliate_logo_file'));
    if (!empty($file->uri)) {
      $footer_logo = &$footer_vars['affiliate_logo'];
      $footer_logo['file'] = $file->uri;
      $footer_logo['text'] = theme_get_setting('footer_affiliate_logo_text');
    }
  }
  // Render footer.
  $vars['footer'] = theme('footer', $footer_vars);
}


/**
 * Implements theme_preprocess_node().
 */
function paraneue_dosomething_preprocess_node(&$vars) {

  $type = isset($vars['node']->type) ? $vars['node']->type : null;
  if ($type == "campaign") {
    // List of theme functions to display.
    $partials = array(
      'campaign_creator',
      'campaign_headings',
    );
    // Initialize to NULL.
    foreach ($partials as $partial) {
      $vars[$partial] = NULL;
    }
    // Check for campaign class:
    // @see dosomething_campaign_preprocess_node().
    if (isset($vars['campaign'])) {
      // Add $campaign_scholarship variable.
      paraneue_dosomething_preprocess_node_campaign_scholarship($vars);
      // Set campaign headings.
      $vars['campaign_headings'] = theme('campaign_headings', $vars);
      // If creator property has been set:
      if ($creator = $vars['campaign']->creator) {
        // Pass $campaign->creator array to the campaign_creator theme function.
        $vars['campaign_creator'] = theme('campaign_creator', $creator);
      }
    }
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
    $info_bar_vars[$variable] = NULL;
    // If the vars is set for this variable name:
    if (isset($vars[$variable])) {
      // Store its value.
      $info_bar_vars[$variable] = $vars[$variable];
    }
  }
  $vars['info_bar'] = theme('info_bar', $info_bar_vars);
}

/**
 * Sets a $campaign_scholarship variable based on $vars.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_campaign_scholarship(&$vars) {
  // Initialize to NULL to avoid isset checks in the tpl.
  $vars['campaign_scholarship'] = NULL;

  // If a campaign class exists and it has a scholarship:
  if ($vars['campaign'] && $vars['campaign']->scholarship) {
    $campaign = $vars['campaign'];

    // Default to action page classes.
    $classes = array('-above',  '-white');

    // Pitch page classes:
    if (isset($campaign->is_pitch_page)) {
      // Values for pitch page:
      $classes = array('-below', '-white',  '-dynamic-right');
    }

    // SMS Game classes:
    elseif ($campaign->type == 'sms_game') {
      $classes = array('-right');
    }

    $vars['campaign_scholarship'] = theme('campaign_scholarship', array(
      'amount' => $campaign->scholarship,
      'classes' => $classes,
    ));
  }
}
