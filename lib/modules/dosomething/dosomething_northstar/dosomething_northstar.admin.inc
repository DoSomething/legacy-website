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
    '#default_value' => variable_get('dosomething_northstar_url', 'http://northstar-qa.dosomething.org'),
  ];
  $form['northstar']['dosomething_northstar_app_id'] = [
    '#type' => 'textfield',
    '#title' => t('Client ID (Client Credentials)'),
    '#description' => t('The OAuth client to use for machine requests.'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_app_id', 'trusted-test-client'),
  ];
  $form['northstar']['dosomething_northstar_app_key'] = [
    '#type' => 'textfield',
    '#title' => t('Client Secret (Client Credentials)'),
    '#description' => t('The top-secret key for this OAuth client.'),
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
