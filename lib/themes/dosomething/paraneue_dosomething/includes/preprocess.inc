<?php

/**
 * Implements theme_preprocess_html().
 */
function paraneue_dosomething_preprocess_html(&$vars) {
  // Add theme stylesheet
  drupal_add_css(PARANEUE_PATH . '/dist/app.css', [
    'group' => CSS_THEME,
    'weight' => 0,
    'every_page' => TRUE,
    'preprocess' => FALSE
  ]);

  // Used to print current tagged version in page source
  $vars['ds_version'] = variable_get('ds_version', '[dev]');

  // Checks if current site is an international affiliate
  $vars['is_affiliate'] = dosomething_settings_is_affiliate();
  $member_count = dosomething_user_get_member_count(TRUE);
  $vars['head_title'] = token_replace($vars['head_title'], ['member-count-readable' => $member_count]);

  $update_url = variable_get('dosomething_settings_realtimefeed_update_url');
  if (!empty($update_url)) {
    drupal_add_js(
      array('dosomethingSetting' =>
        array(
          'globeUrl' => $update_url,
          'countryCode' => dosomething_settings_get_geo_country_code(),
        )
      ),
      'setting'
    );
  }
}

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
  $modifier_classes = '-white -floating';
  if(isset($vars['use_black_navigation']) && $vars['use_black_navigation'] == 1) {
    $modifier_classes = '-floating';
  }

  // Override with environment-specific logo if on staging or local dev:
  $host = $_SERVER['HTTP_HOST'];
  if(strpos($host, 'staging.') !== FALSE) {
    $vars['logo'] = '/' . PARANEUE_PATH . '/images/logo-staging.png';
  }
  else if(strpos($host, 'dev.') !== FALSE) {
    $vars['logo'] = '/' . PARANEUE_PATH . '/images/logo-dev.png';
  }

  $navigation_vars = [
    'base_path'        => $vars['base_path'],
    'modifier_classes' => $modifier_classes,
    'logo'             => $vars['logo'],
    'front_page'       => $vars['front_page'],
    'logged_in'        => $vars['logged_in'],
    'search_box'       => $vars['search_box'],
    'user_identifier'  => $vars['user_identifier'],
    'who_we_are'       => [
      'text' => t(theme_get_setting('header_who_we_are_text')),
      'subtext' => t(theme_get_setting('header_who_we_are_subtext')),
      'link' => theme_get_setting('header_who_we_are_link_' . dosomething_global_get_current_country_code()),
    ],
    'explore_campaigns'=> [
      'text' => t(theme_get_setting('header_explore_campaigns_text')),
      'subtext' => t(theme_get_setting('header_explore_campaigns_subtext')),
      // 'link' => theme_get_setting('header_explore_campaigns_link'),
    ],
  ];

  $vars['navigation'] = theme('navigation', $navigation_vars);

  // Only display tabs for Staff and regional admins.
  if (isset($vars['tabs'])) {
    if (!dosomething_user_is_staff() && !dosomething_global_is_regional_admin()) {
      unset($vars['tabs']);
    }
    // Display edited admin tabs for regional admins.
    else if (dosomething_global_is_regional_admin()) {
      $vars['tabs'] = paraneue_dosomething_edit_regional_admin_tabs($vars['tabs']);
    }
  }

  /**
   * Determine Page template.
   */
  $full_width = FALSE;
  // Node types to render in the full width page:
  $full_width_types = array(
    'campaign',
    'campaign_group',
    'fact_page',
    'notfound',
    'home',
  );
  if (isset($vars['node']->type) && in_array($vars['node']->type, $full_width_types)) {
    $full_width = TRUE;
  }
  elseif ($vars['theme_hook_suggestions'][0] === 'page__notfound'){
    $full_width = TRUE;
  }
  elseif ($vars['theme_hook_suggestions'][0] === 'page__taxonomy') {
    $full_width = TRUE;
  }
  elseif ($vars['theme_hook_suggestions'][0] === 'page__reportback') {
    $full_width = TRUE;
  }

  // Check for User Profile:
  else {
    $is_profile = FALSE;
    if (isset($vars['theme_hook_suggestions'][1])) {
      // Check if page is user/%.
      $is_profile = ($vars['theme_hook_suggestions'][1] === 'page__user__%');
    }
    if ($is_profile) {
      // User profile page does not contain anymore suggestions than
      // 0 => page__user, 1 => page__user__%, and 2=> page__user__[uid].
      if (!isset($vars['theme_hook_suggestions'][3])) {
        // Profile should be full width.
        $full_width = TRUE;
      }
      // Else If this is the Edit Profile page:
      elseif ($vars['theme_hook_suggestions'][3] === 'page__user__edit') {
        // Override the title (which is set to the username by default).
        drupal_set_title(t("Edit Profile"));
      }
    }
  }

  if ($full_width) {
    $vars['theme_hook_suggestions'][] = 'page__full_width';
  }
  else {
    $header_vars = array(
      'title' => drupal_get_title(),
    );

    // If there's a subtitle field on this node, send it to the header
    global $user;

    if ($user->uid) {
      $language = $user->language;
    }
    else {
      $code = dosomething_global_get_current_country_code();
      $language = dosomething_global_convert_country_to_language($code);
    }

    $field_data = dosomething_helpers_extract_field_data($vars['node']->field_subtitle, $language);
    if (isset($field_data)) {
      $header_vars['subtitle'] = $field_data;
    }

    $field_data = dosomething_helpers_extract_field_data($vars['node']->field_partners, $language);
    if (isset($field_data)) {
      $vars['partners'] = dosomething_taxonomy_get_partners_data($field_data);
      $vars['sponsor_logos'] = paraneue_dosomething_get_sponsor_logos($vars['partners']);

      // Output sponsor, if it exists.
      if ($vars['sponsor_logos']) {
        $header_vars['promotions'] = $vars['sponsor_logos'];

        $header_vars['promotions'] = '<div class="promotions">' . $header_vars['promotions'] . '</div>';
      }

      // Add class to header if promotions will be included in display.
      if (isset($vars['promotions'])) {
        $vars['classes_array'][] = 'has-promotions';
      }
    }

    // Add global header.
    $vars['header'] = theme('header', $header_vars);
  }

  /**
   * Global Page Footer
   */
  $country = dosomething_global_get_current_country_code();
  $columns = array('first', 'second', 'third');
  $footer_links = array();

  foreach($columns as $column) {
    $prefix = "footer_links_" . $country . '_' . $column . "_column_";
    $footer_links[$column] = array();

    // Get new country code setting if it exists, if not fallback to old setting.
    // @TODO: Remove this after we've updated theme settings everywhere.
    $heading_setting = theme_get_setting($prefix . 'heading');
    if($heading_setting === NULL) {
      $heading_setting = theme_get_setting('footer_links_' . $column . '_column_heading');
    }
    $footer_links[$column]['heading'] = $heading_setting;

    // Get new country code setting if it exists, if not fallback to old setting.
    // @TODO: Remove this after we've updated theme settings everywhere.
    $links_setting = theme_get_setting($prefix . 'links');
    if($links_setting === NULL) {
      $links_setting = theme_get_setting('footer_links_' . $column . '_column_links');
    }
    $links = explode("\n", trim($links_setting));
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
    'privacy' => dosomething_user_get_link_privacy_policy(),
    'terms' => dosomething_user_get_link_terms_service(),
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

  /**
   * Search page.
   */
  if (isset($vars['theme_hook_suggestions'][0])) {
    if ($vars['theme_hook_suggestions'][0] == 'page__search' ) {
      // If there are no results.
      if (empty($vars['page']['content']['system_main']['search_results']['search_results']['#results'])) {
        // Set copy.
        $vars['noresults_copy'] = t(variable_get('dosomething_search_copy_no_results', 'No results found'));
        // Recommended campaigns.
        $vars['recommended_campaigns_gallery'] = paraneue_dosomething_get_recommended_campaign_gallery(NULL, NULL, 3);
      }
    }
  }
}


/**
 * Implements theme_preprocess_node().
 */
function paraneue_dosomething_preprocess_node(&$vars) {
  $regional_url_data = paraneue_dosomething_get_regional_url_data($vars['node']);

  if ($regional_url_data) {
    foreach ($regional_url_data as $language => $url) {
      drupal_add_html_head_link(['rel' => 'alternate', 'hreflang' => $language, 'href' => $url]);
    }
  }


  switch($vars['node']->type) {

    case "campaign":
      paraneue_dosomething_preprocess_node_campaign($vars);
      break;

    case "campaign_group":
      paraneue_dosomething_preprocess_node_campaign_group($vars);
      paraneue_dosomething_preprocess_field_partners($vars);
      break;

    case "fact_page":
      // Return facts as two arrays.
      // Allow CTAs to be properly embedded in between.
      $vars['first_fact_group'] = array_slice($vars['facts'], 0, 5);
      $vars['second_fact_group'] = array_slice($vars['facts'], 5);
      paraneue_dosomething_preprocess_field_partners($vars);
      break;

    case "home":
      // Set these here to remove db calls from tpl files:
      $vars['show_campaign_finder'] = theme_get_setting('show_campaign_finder');
      $vars['show_sponsors'] = theme_get_setting('show_sponsors');
      break;

    case "static_content":
      // Preprocess field_gallery.
      paraneue_dosomething_preprocess_node_field_gallery($vars);
      break;

    case "notfound":
      paraneue_dosomething_preprocess_node_notfound($vars);
      break;

  }

  // Add $info_bar for all nodes.
  paraneue_dosomething_add_info_bar($vars);
}

/**
 * Preprocesses an info_bar based on given $vars.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_add_info_bar(&$vars) {
  $info_bar_vars = array();

  if (isset($vars['formatted_partners'])) {
    $info_bar_vars['formatted_partners'] = $vars['formatted_partners'];
  }

  if (module_exists('dosomething_global')) {
    $country_code = dosomething_settings_get_geo_country_code();

    $country_contact_emails = array(
      'br' => 'ajuda@dosomething.org',
      'mx' => 'ayuda@dosomething.org',
    );

    // For the countries in $country_contact_emails, use a contact email address instead of zendesk form.
    if (array_key_exists($country_code, $country_contact_emails)) {
      $info_bar_vars['contact_us_email'] = '<a href="mailto:' . $country_contact_emails[$country_code] .'">'. $country_contact_emails[$country_code] . '</a>';
    // All other countries get the zendesk form.
    }
    else {
      $zendesk_form_header = t(variable_get('dosomething_zendesk_form_header'));
      $info_bar_vars['zendesk_form_header'] = $zendesk_form_header;

      if (isset($vars['zendesk_form'])) {
        $info_bar_vars['zendesk_form'] = $vars['zendesk_form'];
      }
    }
  }

  $vars['info_bar'] = theme('info_bar', $info_bar_vars);
}

/**
 * Preprocesses a campaign node's $vars.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_campaign(&$vars) {

  // List of partials to add as $vars.
  $partials = array(
    'campaign_creator',
    'campaign_headings',
    'sponsor_logos',
    'promotions',
  );
  // Initialize to NULL.
  foreach ($partials as $partial) {
    $vars[$partial] = NULL;
  }

  // Check for campaign class:
  // @see dosomething_campaign_preprocess_node().
  if (isset($vars['campaign'])) {

    $campaign = $vars['campaign'];

    // Add $campaign_scholarship variable.
    paraneue_dosomething_preprocess_node_campaign_scholarship($vars);

    // Construct the proper end date text
    $end_date = new DateTime($vars['field_high_season'][0]['value2']);
    // $vars['campaign_end_date'] = $end_date->format('F') . ' ' . $end_date->format('j') . $end_date->format('S');
    $vars['campaign_end_date'] = $end_date->format('F jS');

    // Set campaign headings.
    $vars['campaign_headings'] = theme('campaign_headings', $vars);

    // If creator property has been set:
    if ($creator = $campaign->creator) {
      // Pass $campaign->creator array to the campaign_creator theme function.

      $file = file_load($creator['picture']['fid']);
      $creator['picture']['src_square'] = image_style_url('300x300', $file->uri);
      $vars['campaign_creator'] = theme('campaign_creator', $creator);
    }

    // Check for sponsors.
    $vars['sponsor_logos'] = paraneue_dosomething_get_sponsor_logos($campaign->partners);

    // Output sponsors and creator in promotions module.
    if ($vars['sponsor_logos'] || $vars['campaign_creator']) {
      $classes = NULL;

      if ($vars['sponsor_logos'] && $vars['campaign_creator']) {
        $classes = ' -dual';
        $vars['promotions'] = $vars['sponsor_logos'] . $vars['campaign_creator'];
      }
      elseif ($vars['sponsor_logos']) {
        $vars['promotions'] = $vars['sponsor_logos'];
      }
      elseif ($vars['campaign_creator']) {
        $vars['promotions'] = $vars['campaign_creator'];
      }

      $vars['promotions'] = '<div class="promotions' . $classes . '">' . $vars['promotions'] . '</div>';

    }
  }

  // Add class to header if promotions will be included in display.
  if ($vars['promotions']) {
    $vars['classes_array'][] = 'has-promotions';
  }

  // If the campaign requires a signup modal to display:
  if (isset($vars['node']->required_signup_data_form)) {
    // Add JS to open the signup data form modal.
    $id = 'modal-signup-data-form';
    $closeButton = 'false';
    $skipForm = '#dosomething-signup-user-skip-signup-data-form';

    // Add skip button if setting is enabled
    if (isset($vars['node']->skippable_signup_data_form)) {
      $closeButton = 'skip';
    }

    $js = 'jQuery(document).ready(function() { DSModal.open( jQuery("#' . $id . '"), {animated: false, closeButton: "' . $closeButton . '", skipForm: "' . $skipForm . '"}); });';
    drupal_add_js($js, 'inline');
  }

  // Setup the reportback showcase.
  paraneue_dosomething_preprocess_reportback_showcase($vars);

  // If this is not the pitch page:
  if (!isset($vars['is_pitch_page'])) {
    // Set the number of files to display in initial gallery.
    $vars['reportbacks_gallery']['desired_count'] = 6;
    // Adds themed Reportback Files.
    paraneue_dosomething_preprocess_reportback_gallery($vars);
  }

  if (isset($vars['is_pitch_page'])) {
    $vars['show_persistent_signup'] = theme_get_setting('show_persistent_signup');
  }
}


/**
 * Expands $reportbacks_gallery array with themed Reportback items and data for given node preprocess $vars.
 */
function paraneue_dosomething_preprocess_reportback_gallery(&$vars) {
  $reportbacks_gallery = &$vars['reportbacks_gallery'];

  if (!isset($reportbacks_gallery['desired_count'])) {
    $reportbacks_gallery['desired_count'] = 6;
  }
  $desired_count = $reportbacks_gallery['desired_count'];

  $reportbacks_gallery['campaign_id'] = $vars['nid'];
  $reportbacks_gallery['items'] = array();


  // Promoted Reportbacks:
  $reportbacks_gallery['items'] = paraneue_dosomething_get_themed_reportbacks_by_status($vars['nid'], 'promoted', $desired_count, TRUE);
  $reportbacks_gallery['total_promoted'] = count($reportbacks_gallery['items']);

  // Approved Reportbacks:
  $reportbacks_gallery['total_approved'] = dosomething_reportback_get_reportback_total_by_status($vars['nid'], 'approved');

  // Collect Reportbacks to fulfill desired amount.
  if ($reportbacks_gallery['total_promoted'] < $desired_count) {
    $reportbacks_gallery = paraneue_dosomething_build_reportbacks_gallery_collection($reportbacks_gallery, TRUE);
  }

  // Enough Total Promoted Reportbacks to fulfill the required initial count.
  else {
    $reportbacks_gallery['prefetched'] = 0;
  }

  // Pass admin access boolean for JS purposes.
  $reportbacks_gallery['admin_access'] = user_access('view any reportback') ? 'true' : 'false';
}


/**
 * Expands $reportbacks_showcase array with themed Reportback items and data for given node preprocess $vars.
 */
function paraneue_dosomething_preprocess_reportback_showcase(&$vars) {
  $reportbacks_showcase = &$vars['reportbacks_showcase'];

  $reportbacks_showcase['desired_count'] = $desired_count = 4;
  $reportbacks_showcase['campaign_id'] = $vars['nid'];
  $reportbacks_showcase['items'] = array();


  // Promoted Reportbacks:
  $reportbacks_showcase['items'] = paraneue_dosomething_get_themed_reportbacks_by_status($vars['nid'], 'promoted', $desired_count, TRUE);
  $reportbacks_showcase['total_promoted'] = count($reportbacks_showcase['items']);

  // Approved Reportbacks:
  $reportbacks_showcase['total_approved'] = dosomething_reportback_get_reportback_total_by_status($vars['nid'], 'approved');

  // Collect Reportbacks to fulfill desired amount.
  if ($reportbacks_showcase['total_promoted'] < $desired_count) {
    $reportbacks_showcase = paraneue_dosomething_build_reportbacks_gallery_collection($reportbacks_showcase);
  }

  // Enough Total Promoted Reportbacks to fulfill the required initial count.
  else {
    $reportbacks_showcase['prefetched'] = 0;
  }
}


/**
 * Preprocesses a Campaign Group node.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_campaign_group(&$vars) {
  // Source to append to Campaign Gallery links.
  $source = 'node/' . $vars['nid'];
  $vars['campaign_gallery'] = paraneue_dosomething_get_campaign_gallery($vars['campaigns'], $source);
}


/**
 * Sets a $campaign_scholarship variable based on $vars.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_campaign_scholarship(&$vars) {
  // Initialize to NULL to avoid isset checks in the tpl.
  $vars['campaign_scholarship'] = NULL;
  $vars['prove_scholarship'] = NULL;

  // If a campaign class exists and it has a scholarship:
  if ($vars['campaign'] && $vars['campaign']->scholarship) {
    $campaign = $vars['campaign'];
    $amount = $campaign->scholarship;

    // SMS Game classes:
    if ($campaign->type == 'sms_game') {
      $classes = array('-right');
    }
    // Pitch page classes:
    elseif (isset($campaign->is_pitch_page)) {
      // Values for pitch page:
      $classes = array('-below', '-white',  '-dynamic-right');
    }
    // Else action page classes:
    else {
      // Default classes.
      $classes = array('-above',  '-white');
      // Prove it section classes.
      $prove_classes = array('-below', '-white');
      $vars['prove_scholarship'] = theme('campaign_scholarship', array(
        'amount' => $amount,
        'classes' => $prove_classes,
      ));
    }
    // Default $campaign_scholarship for campaign templates.
    $vars['campaign_scholarship'] = theme('campaign_scholarship', array(
      'amount' => $amount,
      'classes' => $classes,
    ));
  }
}

/**
 * Preprocesses the $vars['galleries'] if exists.
 *
 * @see dosomething_static_content_preprocess_galleries().
 *
 * @param array $vars
 *   Vars passed from a hook_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_field_gallery(&$vars) {

  if (!isset($vars['galleries'])) return;

  // Loop through each gallery:
  foreach ($vars['galleries'] as $delta => &$gallery) {
    // Get the class to apply based on gallery style.
    $gallery_class = paraneue_dosomething_get_gallery_style($gallery['style']);
    // Sets $vars['galleries'][$delta]['class'] to $gallery_class.
    $gallery['class'] = $gallery_class;
  }

}

/**
 * Preprocesses the field_partners variable, if exists.
 */
function paraneue_dosomething_preprocess_field_partners(&$vars) {
  $vars['partners'] = dosomething_taxonomy_get_partners_data($vars['field_partners']);
  $vars['sponsor_logos'] = paraneue_dosomething_get_sponsor_logos($vars['partners']);
}

/**
 * Implements template_preprocess_taxonomy_term().
 */
function paraneue_dosomething_preprocess_taxonomy_term(&$vars) {
  // Source to append to Campaign Gallery links.
  $source = 'taxonomy/term/' . $vars['tid'];
  $vars['campaign_gallery'] = paraneue_dosomething_get_campaign_gallery($vars['campaigns'], $source, TRUE);

  // Adds sponsor logos.
  paraneue_dosomething_preprocess_field_partners($vars);
  // Adds $partner_info and $formatted_partners variables.
  dosomething_helpers_preprocess_partners_vars($vars);
  if (isset($vars['partner_info'])) {
    $vars['modals'] = theme('modal_links', array('modals' =>
      array(
        'partner_info' => $vars['partner_info'],
        'issue' => $vars['term']->name,
      ),
    ));
  }
  paraneue_dosomething_add_info_bar($vars);
}

/**
 * Preprocesses variables for user profiles.
 *
 * Themes the doing, reportback galleries.
 */
function paraneue_dosomething_preprocess_user_profile(&$vars) {
  global $base_url;
  global $user;
  $language = $user->language;

  if ($doing = $vars['doing']) {
    foreach ($doing as $delta => $value) {
      $image = dosomething_image_get_themed_image($value['nid_image'], 'landscape', '400x400');
      $item = array(
        'title' => $value['link'],
        'image' => $image,
        'description' => $value['call_to_action'],
        'url' => dosomething_global_node_url($value['nid'], $language, 'prove'),
        'button_text' => t("Prove It"),
      );
      $doing_items[$delta] = paraneue_dosomething_get_gallery_item($item, 'figure');
    }
    $vars['doing_gallery'] = paraneue_dosomething_get_gallery($doing_items, 'triad', array(), TRUE);
  }
  // Get an array of reportbacks.
  $reportbacks = $vars['reportbacks'];
  if (!empty($reportbacks)) {
    // Theme each reportback and create an array.
    foreach ($reportbacks as $delta => $rbid) {
      $reportback = reportback_load((int) $rbid);
      $impact = $reportback->quantity . ' ' . $reportback->noun . ' ' . $reportback->verb;
      if (user_access('view any reportback')) {
        // Link to the full reportback entity view.
        $impact = l($impact, 'admin/reportback/' . $rbid);
      }
      else {
        $impact = l($impact, 'reportback/' . $rbid);
      }
      $img = dosomething_image_get_themed_image_by_fid($reportback->fids[0], '300x300');
      // Media gallery template expects a full URL.
      $url = dosomething_global_url('node/' . $reportback->nid);
      $content = array(
        'url' => $url,
        'title' => $reportback->node_title,
        'image' => $img,
        'description' => $impact,
      );

      $reportback_items[$delta] = paraneue_dosomething_get_gallery_item($content, 'figure', TRUE, array('-left', '-medium'));
    }
  }
  // Theme a gallery of reportbacks, and give the user profile template access to it.
  $vars['reportback_gallery'] = paraneue_dosomething_get_gallery($reportback_items, 'duo', array(), TRUE);
}

/**
 * Themes the recommended campaigns for the notfound page
 */
function paraneue_dosomething_preprocess_node_notfound(&$vars) {
  if (isset($vars['raw_search_results']) && count($vars['raw_search_results']) != 0) {
    // Theme the set of results as duo gallery.
    $vars['search_results'] = paraneue_dosomething_get_search_gallery($vars['raw_search_results']);
  }
  else {
    $vars['campaign_results'] = paraneue_dosomething_get_recommended_campaign_gallery(NULL, NULL, 3);
  }
}

/**
 * Preprocesses variables for the search results page.
 */
function paraneue_dosomething_preprocess_search_results(&$vars) {
  if ($search_results = $vars['results']) {
    // Theme the set of results as duo gallery.
    $vars['search_results_gallery'] = paraneue_dosomething_get_search_gallery($search_results);
  }
}
