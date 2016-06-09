<?php

/**
 * @file
 * Organize admin settings.
 */

/**
 * System settings form for Organize config.
 */
function dosomething_organize_config_form($form, &$form_state) {
  $form = array();

  $form['organize'] = array(
    '#type' => 'fieldset',
    '#title' => t('Organize Settings'),
  );
  $form['organize']['dosomething_organize_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Organize URL'),
    '#description' => t('Without the trailing slash'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_organize_url', 'https://fiftythree-dev.organize.org/api'),
  );

  $form['organize']['dosomething_organize_auth_token'] = array(
    '#type' => 'textfield',
    '#title' => t('App key'),
    '#description' => t('The Auth key needed to connect to the organize API (just the number, we will add <strong> Token </strong> in code'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_organize_auth_token', ''),
  );

  return system_settings_form($form);
}
