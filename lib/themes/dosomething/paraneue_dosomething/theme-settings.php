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

}
