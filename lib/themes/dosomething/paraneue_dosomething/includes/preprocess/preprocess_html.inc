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

