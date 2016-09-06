<?php

/**
 * @file
 * Rogue admin settings.
 */

/**
 * System settings form for Rogue configuration.
 */
function dosomething_rogue_config_form($form, &$form_state) {
  $form = array();

  $form['rogue'] = [
    '#type' => 'fieldset',
    '#title' => t('Rogue Settings.')
  ];

  $form['rogue']['dosomething_rogue_url'] = [
    '#type' => 'textfield',
    '#title' => t('Rogue URL'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_rogue_url', 'https://qa-rogue.dosomething.org'),
  ];

  $form['rogue']['dosomething_rogue_api_version'] = [
    '#type' => 'textfield',
    '#title' => t('Rogue API version number'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_rogue_api_version', 'v1'),
  ];

  $form['rogue']['dosomething_rogue_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('Rogue API Key'),
    '#required' => FALSE,
    '#default_value' => variable_get('dosomething_rogue_api_key', ''),
  ];

  return system_settings_form($form);
}
