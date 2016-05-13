<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Shipment specific variables.
 */
function dosomething_shipment_admin_config_form($form, &$form_state) {
  $form['log'] = array(
    '#type' => 'fieldset',
    '#title' => t('Logging'),
  );
  $var_name = 'dosomething_shipment_log';
  $form['log'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Shipments.'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("Logs Shipment activity. This should be disabled on production."),
  );

  return system_settings_form($form);
}

