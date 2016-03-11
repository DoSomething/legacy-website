<?php

/**
 * @file
 * Northstar admin settings.
 */

/**
 * System settings form for northstar config.
 */
function dosomething_northstar_config_form($form, &$form_state) {
  $form = array();

  $form['northstar'] = array(
    '#type' => 'fieldset',
    '#title' => t('Northstar Settings'),
  );
  $form['northstar']['dosomething_northstar_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Northstar URL'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_url', 'http://northstar.dev'),
  );
  $form['northstar']['dosomething_northstar_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Northstar port'),
    '#description' => t('This is most likely only needed on dev sites'),
    '#required' => FALSE,
    '#default_value' => variable_get('dosomething_northstar_port', '8000'),
  );
  $form['northstar']['dosomething_northstar_version'] = array(
    '#type' => 'textfield',
    '#title' => t('Northstar API version number'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_version', 'v1'),
  );
  $form['northstar']['dosomething_northstar_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('App id'),
    '#description' => t('The app id needed to connect to northstar (found in aurora).'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_app_id', '456'),
  );
  $form['northstar']['dosomething_northstar_app_key'] = array(
    '#type' => 'textfield',
    '#title' => t('App key'),
    '#description' => t('The app key needed to connect to northstar (found in aurora).'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_northstar_app_key', 'abc4324'),
  );

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
