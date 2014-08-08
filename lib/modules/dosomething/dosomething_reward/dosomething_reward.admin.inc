<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Signup specific variables.
 */
function dosomething_reward_admin_config_form($form, &$form_state) {
  $form['copy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Copy'),
  );

  $var_name = 'dosomething_reward_redeem_form_link';
  $form['copy'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Redeem Form Link Text'),
    '#description' => t("Link text that opens the Redeem Form modal."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_header';
  $form['copy'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Redeem Form Header'),
    '#description' => t("Header text of the Redeem Form modal."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_copy';
  $form['copy'][$var_name] = array(
    '#type' => 'textarea',
    '#rows' => 4,
    '#title' => t('Redeem Form Copy'),
    '#description' => t("Copy displayed in the Redeem Form modal."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_button_text';
  $form['copy'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Redeem Form Button Label'),
    '#description' => t("Label displayed on the Redeem Form submit button."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_confirm_msg';
  $form['copy'][$var_name] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Redeem Form Confirmation Message'),
    '#description' => t("Message displayed after submitting the Redeem Form."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $form['log'] = array(
    '#type' => 'fieldset',
    '#title' => t('Logging'),
  );

  $var_name = 'dosomething_reward_log';
  $form['log'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Rewards.'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("Logs Reward activity. This should be disabled on production."),
  );
  return system_settings_form($form);
}
