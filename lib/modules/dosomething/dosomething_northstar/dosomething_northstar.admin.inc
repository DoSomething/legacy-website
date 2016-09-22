<?php

/**
 * @file
 * Northstar admin settings.
 */

/**
 * System settings form for northstar config.
 */
function dosomething_northstar_config_form($form, &$form_state) {
  $form = [];

  $form['northstar'] = [
    '#type' => 'fieldset',
    '#title' => t('Northstar Settings'),
  ];
  $form['northstar']['dosomething_northstar_url'] = [
    '#type' => 'textfield',
    '#title' => t('Northstar URL'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_url', 'http://northstar.dev:8000'),
  ];
  $form['northstar']['dosomething_northstar_version'] = [
    '#type' => 'textfield',
    '#title' => t('Northstar API version number'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_version', 'v1'),
  ];
  $form['northstar']['dosomething_northstar_app_id'] = [
    '#type' => 'textfield',
    '#title' => t('App id'),
    '#description' => t('The app id needed to connect to northstar (found in aurora).'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_app_id', 'trusted-test-client'),
  ];
  $form['northstar']['dosomething_northstar_app_key'] = [
    '#type' => 'textfield',
    '#title' => t('App key'),
    '#description' => t('The app key needed to connect to northstar (found in Aurora).'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_app_key', 'secret1'),
  ];

  $form['log'] = [
    '#type' => 'fieldset',
    '#title' => t('Logging'),
  ];
  $form['log']['dosomething_northstar_log'] = [
    '#type' => 'checkbox',
    '#title' => t('Log requests and responses.'),
    '#default_value' => variable_get('dosomething_northstar_log', FALSE),
    '#description' => t("Logs Northstar activity. This should be disabled on production."),
  ];

  return system_settings_form($form);
}
