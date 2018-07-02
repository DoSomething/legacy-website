<?php

// Include helpers.
if (!defined('PARANEUE_PATH')) {
  define('PARANEUE_PATH', drupal_get_path('theme', 'paraneue_dosomething'));
}
require_once PARANEUE_PATH . '/includes/helpers.inc';

function paraneue_dosomething_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['feature_flags'] = [
      '#type'        => 'fieldset',
      '#title'       => t('Feature Flags'),
      '#description' => t('Allows features to be toggled on or off in different environments.'),
      '#collapsible' => FALSE,
      '#collapsed'   => FALSE,
      '#weight'      => -19
  ];

  $flags = [
    'show_campaign_finder' => [
      '#title' => t('Campaign Finder'),
      '#description' => t('Toggles campaign finder on homepage/expore campaigns page.')
    ],
    'show_sponsors' => [
      '#title' => t('Show sponsors'),
      '#description' => t('Toggles the sponsors block on the home page when finder is enabled.')
    ],
    'show_problem_shares' => [
      '#title' => t('Show problem statement share buttons'),
      '#description' => t('Toggles the display of problem statement share buttons on the action page.')
    ],
    'use_facebook_pixel' => [
      '#title' => t('Use the Facebook Pixel event tracking script'),
      '#description' => t('Toggles including the Facebook Pixel event tracking script on all pages.'),
    ],
    'use_google_tag_manager' => [
      '#title' => t('Use the Google Tag Manager event tracking script'),
      '#description' => t('Toggles including the Google Tag Manager event tracking script on all pages.'),
    ],
  ];

  foreach ($flags as $name => $flag) {
    $form['feature_flags'][$name] = $flag;
    $form['feature_flags'][$name]['#type'] = 'checkbox';
    $form['feature_flags'][$name]['#default_value'] = theme_get_setting($name);
  }

  // Lets break this up a little.
  _paraneue_dosomething_theme_settings_header($form, $form_state);
  _paraneue_dosomething_theme_settings_footer($form, $form_state);
  _paraneue_dosomething_theme_settings_user($form, $form_state);

  // Work-around for this bug: https://drupal.org/node/1862892.
  $theme_settings_path = drupal_get_path('theme', 'paraneue_dosomething') . '/theme-settings.php';
  if (!in_array($theme_settings_path, $form_state['build_info']['files'])) {
    $form_state['build_info']['files'][] = $theme_settings_path;
  }
}

function _paraneue_dosomething_theme_settings_header(&$form, $form_state) {
  $form['header'] = [
    '#type'  => 'fieldset',
    '#title' => t('Header'),
  ];

  $form['header']['who_we_are'] = [
    '#type'        => 'fieldset',
    '#title'       => t('Who We Are?'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  ];

  $form_who_we_are = &$form['header']['who_we_are'];
  $form_who_we_are['header_who_we_are_text'] = [
    '#type'          => 'textfield',
    '#title'         => 'Text',
    '#default_value' => theme_get_setting('header_who_we_are_text'),
  ];
  $form_who_we_are['header_who_we_are_subtext'] = [
    '#type'          => 'textfield',
    '#title'         => 'Subtext',
    '#default_value' => theme_get_setting('header_who_we_are_subtext'),
  ];

  $form['header']['who_we_are']['header_who_we_are_links'] = [
    '#type'        => 'fieldset',
    '#title'       => t('Country-Specific Links'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  ];

  $countries = dosomething_global_get_countries();
  foreach($countries as $country) {
    $form['header']['who_we_are']['header_who_we_are_links']['header_who_we_are_link_' . $country] = [
      '#type'          => 'entity_autocomplete',
      '#title'         => 'Link (' . $country . ')',
      '#bundles'       => ['static_content'],
      '#default_value' => theme_get_setting('header_who_we_are_link_' . $country),
    ];
  }

  $form['header']['explore_campaigns'] = [
    '#type'        => 'fieldset',
    '#title'       => t('Explore Campaigns'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  ];

  $form_explore_campaigns = &$form['header']['explore_campaigns'];
  $form_explore_campaigns['header_explore_campaigns_text'] = [
    '#type'          => 'textfield',
    '#title'         => 'Text',
    '#default_value' => theme_get_setting('header_explore_campaigns_text'),
  ];
  $form_explore_campaigns['header_explore_campaigns_subtext'] = [
    '#type'          => 'textfield',
    '#title'         => 'Subtext',
    '#default_value' => theme_get_setting('header_explore_campaigns_subtext'),
  ];
}

function _paraneue_dosomething_theme_settings_footer(&$form, $form_state) {
  $form['footer'] = [
    '#type' => 'fieldset',
    '#title' => t('Footer'),
  ];
  $footer = &$form['footer'];

  // Social.
  // @todo: consider using drupal menu?
  $footer['social'] = [
    '#type'        => 'fieldset',
    '#title'       => t('Social'),
    '#collapsible' => TRUE,
  ];
  foreach (paraneue_dosomething_get_social_networks() as $id => $network) {
    $setting_key     = 'footer_social_' . $id;
    $setting_enabled = $setting_key . '_enabled';
    $setting_url     = $setting_key . '_url';
    $setting_alt     = $setting_key . '_alt';

    // Fieldset.
    $footer['social'][$setting_key] = [
      '#type'        => 'fieldset',
      '#title'       => $network['name'] . ': ' .
                        (theme_get_setting($setting_enabled) ? t('On') : t('Off')),
      '#collapsible' => TRUE,
      '#collapsed'   => TRUE
    ];

    // On/off checkbox.
    $form_social = &$footer['social'][$setting_key];
    $form_social[$setting_enabled] = [
      '#type'          => 'checkbox',
      '#title'         => t('Enabled'),
      '#default_value' => theme_get_setting($setting_enabled),
    ];
    $form_social[$setting_key . '_settings'] = [
      '#type' => 'container',
      '#states' => [
        'invisible' => [
          'input[name="' . $setting_enabled . '"]' => ['checked' => FALSE],
        ],
      ],
    ];

    // Settings: URL, Title Text, etc.
    $form_social_settings = &$form_social[$setting_key . '_settings'];
    $form_social_settings[$setting_url] = [
      '#type'          => 'textfield',
      '#title'         => t('URL'),
      '#default_value' => theme_get_setting($setting_url),
    ];
    $form_social_settings[$setting_alt] = [
      '#type'          => 'textfield',
      '#title'         => t('Title Text'),
      '#description'   => t('Optional') . '. ' .
          t('Title text is displayed when the image is hovered'),
      '#default_value' => theme_get_setting($setting_alt),
    ];
  }

  // Menu.
  // @todo: consider using drupal menu?
  $form['footer']['links'] = [
    '#type' => 'fieldset',
    '#title' => 'Links',
    '#description' => t('Manage the links in each column of the footer')
  ];

  $links = &$form['footer']['links'];

  // Set up theme settings for each country's footer
  $countries = dosomething_global_get_countries();
  foreach($countries as $country) {
    $links[$country . '_links'] = [
      '#type' => 'fieldset',
      '#title' => t('@country Links', ['@country' => $country]),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ];

    // Set up theme settings for each of the three columns
    $columns = ['first', 'second', 'third'];
    foreach ($columns as $column) {
      $prefix = 'footer_links_' . $country . '_' . $column;

      $links[$country . '_links'][$prefix] = [
        '#type' => 'fieldset',
        '#title' => t(ucwords($column) . ' column'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      ];

      $link_column = &$links[$country . '_links'][$prefix];

      // Get new country code setting if it exists, if not fallback to old setting.
      // @TODO: Remove this after we've updated theme settings everywhere.
      $heading_default = theme_get_setting('footer_links_' . $country . '_' . $column . '_column_heading');
      if($heading_default === NULL) {
        $heading_default = theme_get_setting('footer_links_' . $column . '_column_heading');
      }

      $link_column[$prefix . '_column_heading'] = [
        '#type' => 'textfield',
        '#title' => t(ucwords($country) . ' ' . ucwords($column) . ' Column Heading'),
        '#default_value' => $heading_default,
      ];

      // Get new country code setting if it exists, if not fallback to old setting.
      // @TODO: Remove this after we've updated theme settings everywhere.
      $links_default = theme_get_setting('footer_links_' . $country . '_' . $column . '_column_links');
      if($links_default === NULL) {
        $links_default = theme_get_setting('footer_links_' . $column . '_column_links');
      }

      $link_column[$prefix . '_column_links'] = [
        '#type' => 'textarea',
        '#title' => t(ucwords($country) . ' ' . ucwords($column) . ' Column Links'),
        '#default_value' => $links_default,
      ];
    }

  }
}

function _paraneue_dosomething_theme_settings_user(&$form, $form_state) {
  $form['user'] = [
    '#type' => 'fieldset',
    '#title' => t('User'),
  ];
  $form_user = &$form['user'];

  // Validations.
  $form_user['validations'] = [
    '#type'        => 'fieldset',
    '#title'       => t('JS Validations'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE
  ];
  $form_user['validations']['user_validate_js_postcode'] = [
    '#type'          => 'checkbox',
    '#title'         => t('Validate Post Code'),
    '#default_value' => theme_get_setting('user_validate_js_postcode'),
  ];

}
