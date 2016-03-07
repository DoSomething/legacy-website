<?php
/**
 * System settings form for northstar config.
 */
function dosomething_gladiator_config_form($form, &$form_state) {
  $form = array();

  $form['gladiator'] = array(
    '#type' => 'fieldset',
    '#title' => t('Gladiator Settings'),
  );
  $form['gladiator']['dosomething_gladiator_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Gladiator URL'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_gladiator_url', 'http://gladiator.app:8000/api'),
  );
  $form['gladiator']['dosomething_gladiator_version'] = array(
    '#type' => 'textfield',
    '#title' => t('Gladiator API version number'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_gladiator_version', 'v1'),
  );
  return system_settings_form($form);
}
