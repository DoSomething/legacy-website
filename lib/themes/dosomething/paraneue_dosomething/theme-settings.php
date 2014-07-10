<?php

function paraneue_dosomething_form_system_theme_settings_alter(&$form, $form_state) {
  $form['theme_settings'] = array(
      '#type'          => 'fieldset',
      '#title'         => t('Theme Settings'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#weight'=> -19
  );

  $form['theme_settings']['asset_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Asset Path'),
    '#description' => t('Path to load assets from. The <code>{ds_version}</code> string can be used to include the current <code>ds_version</code> value, or "latest" if not set. If left blank, assets will be loaded from the local theme folder.'),
    '#default_value' => theme_get_setting('asset_path')
  );

  $form['theme_settings']['use_minified_assets'] = array(
    '#type' => 'checkbox',
    '#title' => t('Minify Assets'),
    '#description' => t('Will use minified assets. Uncheck this if debugging in a browser without source maps. <strong>(Unminified assets are only created in production builds.)</strong>'),
    '#default_value' => theme_get_setting('use_minified_assets')
  );

  $form['feature_flags'] = array(
      '#type'          => 'fieldset',
      '#title'         => t('Feature Flags'),
      '#description'   => t('Allows features to be toggled on or off in different environments.'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#weight'=> -19
  );

  $flags = array(
    'show_campaign_finder' => array(
      '#title' => t('Campaign Finder'),
      '#description' => t('Toggles campaign finder on homepage/expore campaigns page.')
    ),
    'show_profile_link' => array(
      '#title' => t('User Profile Link'),
      '#description' => t('Toggles the user profile/create an account link in the main navigation.')
    ),
    'show_sponsors' => array(
      '#title' => t('Show sponsors'),
      '#description' => t('Toggles the sponsors block on the home page when finder is enabled.')
    )
  );

  foreach ($flags as $name => $flag) {
    $form['feature_flags'][$name] = $flag;
    $form['feature_flags'][$name]['#type'] = 'checkbox';
    $form['feature_flags'][$name]['#default_value'] = theme_get_setting($name);
  }

  // Lets break this up a little.
  _paraneue_dosomething_theme_settings_header($form, $form_state);
  _paraneue_dosomething_theme_settings_footer($form, $form_state);

}

function _paraneue_dosomething_theme_settings_header(&$form, $form_state) {
  $form['header'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Header'),
  );

  $form['header']['who_we_are'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Who We Are?'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  );
  $form['header']['who_we_are']['header_who_we_are_text'] = array(
    '#type'          => 'textfield',
    '#title'         => 'Text',
    '#default_value' => theme_get_setting('header_who_we_are_text'),
  );
  $form['header']['who_we_are']['header_who_we_are_link'] = array(
    '#type'          => 'textfield',
    '#title'         => 'Link to Page',
    '#default_value' => theme_get_setting('header_who_we_are_link'),
  );
}

function _paraneue_dosomething_theme_settings_footer(&$form, $form_state) {
  $form['footer'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer'),
  );

  $form['footer']['links'] = array(
    '#type' => 'fieldset',
    '#title' => 'Links',
    '#description' => t('Manage the links in each column of the footer')
  );

  // Stuffing these into smaller variables, because the nesting gets nasty
  $footer = &$form['footer'];
  $links = &$form['links'];

  $footer['footer_social'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Toggle Social Links'),
    '#options' => array(
      'facebook' => t('Facebook'),
      'twitter' => t('Twitter'),
      'tumblr' => t('Tumblr'),
      'instagram' => t('Instagram'),
      'youtube' => t('Youtube'),
    ),
    '#default_value' => theme_get_setting('footer_social')
  );

  $columns = array('first', 'second', 'third');

  foreach ($columns as $column) {
    $prefix = 'footer_links_' . $column;

    $links[$prefix] = array(
      '#type' => 'fieldset',
      '#title' => t(ucwords($column) .' column'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );

    $link_column = &$links[$prefix];

    $link_column[$prefix . '_column_heading'] = array(
      '#type' => 'textfield',
      '#title' => t(ucwords($column) . ' Column Heading'),
      '#default_value' => theme_get_setting('footer_links_' . $column . '_column_heading')
    );

    $link_column[$prefix . '_column_links'] = array(
      '#type' => 'textarea',
      '#title' => t(ucwords($column) . ' Column Links'),
      '#default_value' => theme_get_setting('footer_links_' . $column . '_column_links')
    );

    $link_column[$prefix. '_advanced'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advanced options'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );

    $link_column[$prefix . '_advanced'][$prefix . '_column_class'] = array(
      '#type' => 'textfield',
      '#title' => t(ucwords($column) . ' Column Class'),
      '#default_value' => theme_get_setting('footer_links_' . $column . '_column_class')
    );

  }

}
