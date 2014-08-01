<?php

/**
 * @file
 * Module settings UI.
 */

/**
 * Configuration form
 */
function dosomething_mbp_config_form($form, &$form_state) {

  $form['campaign_api'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message Broker Campaign API')
  );
  $form['campaign_api']['dosomething_mbp_send_campaign_api'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send campaign details to Message Broker Campaign API'),
    '#default_value' => variable_get('dosomething_mbp_send_campaign_api', FALSE),
  );
  $form['dosomething_mbp_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Message Broker Producer requests.'),
    '#default_value' => variable_get('dosomething_mbp_log', FALSE),
    '#description' => t("This should be disabled on production."),
  );
  return system_settings_form($form);
}
