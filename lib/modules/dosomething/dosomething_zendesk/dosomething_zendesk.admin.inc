<?php

/**
 * @file
 * Zendesk admin settings.
 */

/**
 * System settings form for auth settings.
 */
function dosomething_zendesk_config_form($form, &$form_state)  {
  $form['authentication'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication')
  );
  $form['authentication']['dosomething_zendesk_subdomain'] = array(
    '#type' => 'textfield',
    '#title' => t('Subdomain'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_zendesk_subdomain', ''),
  );
  $form['authentication']['dosomething_zendesk_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_zendesk_username', ''),
  );
  $form['authentication']['dosomething_zendesk_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Token'),
    '#required' => TRUE,
    '#description' => t('Do not share this token publicly.'),
    '#default_value' => variable_get('dosomething_zendesk_token', ''),
  );
  return system_settings_form($form);
}
