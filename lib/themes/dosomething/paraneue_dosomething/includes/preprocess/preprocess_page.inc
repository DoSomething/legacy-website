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
    'log_in_link'      => dosomething_user_get_login_link('Log In', 'secondary-nav-item'),
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
    if (isset($vars['node']->field_subtitle) && isset($vars['node']->field_partners)) {
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
      $exploded_string = explode('|', $link);
      if (count($exploded_string) > 1) {
        list($text, $url) = $exploded_string;
        $link = l(trim($text), trim($url));
      }
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
