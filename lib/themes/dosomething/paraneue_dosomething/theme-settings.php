<?php

function paraneue_dosomething_form_system_theme_settings_alter(&$form, $form_state) {
  $form['feature_flags'] = array(
      '#type'          => 'fieldset',
      '#title'         => t('Feature Flags'),
      '#description'   => t('Allows features to be toggled on or off in different environments.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight'=> -19
  );

  $form['feature_flags']['show_campaign_finder'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Campaign Finder') ,
    '#description'   => t('Toggles campaign finder on homepage/expore campaigns page.'),
    '#default_value' => theme_get_setting('show_campaign_finder')
  );

  $form['feature_flags']['show_profile_link'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('User Profile Link') ,
    '#description'   => t('Toggles the user profile/create an account link in the main navigation.'),
    '#default_value' => theme_get_setting('show_profile_link')
  );
}
