<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Shipment specific variables.
 */
function dosomething_shipment_admin_config_form($form, &$form_state) {
  $var_name = 'dosomething_shipment_image_shirt_dope';
  $form[$var_name] = array(
    '#type' => 'entity_autocomplete',
    '#title' => t('Dope Shirt Image'),
    '#entity_type' => 'node',
    '#bundles' => array('image'),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_shipment_image_shirt_social_action';
  $form[$var_name] = array(
    '#type' => 'entity_autocomplete',
    '#title' => t('Social Action Shirt Image'),
    '#entity_type' => 'node',
    '#bundles' => array('image'),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

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

