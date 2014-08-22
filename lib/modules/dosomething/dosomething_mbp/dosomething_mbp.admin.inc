<?php

/**
 * @file
 * Module settings UI.
 */

/**
 * Configuration form
 */
function dosomething_mbp_config_form($form, &$form_state) {
  $form['dosomething_mbp_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Message Broker Producer requests.'),
    '#default_value' => variable_get('dosomething_mbp_log', FALSE),
    '#description' => t("This should be disabled on production."),
  );
  return system_settings_form($form);
}
