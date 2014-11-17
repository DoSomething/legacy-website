<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Payment specific variables.
 */
function dosomething_payment_admin_config_form($form, &$form_state) {
  $form['donate'] = array(
    '#type' => 'fieldset',
    '#title' => t('Donate'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['donate']['dosomething_payment_donate_form_header'] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Form Header'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_payment_donate_form_header'),
  );
  $form['donate']['dosomething_payment_donate_confirm_msg'] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Confirmation Message'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_payment_donate_confirm_msg'),
  );
  $form['stripe'] = array(
    '#type' => 'fieldset',
    '#title' => t('Stripe'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['stripe']['dosomething_payment_stripe_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret API key'),
    '#default_value' => variable_get('dosomething_payment_stripe_api_key'),
  );
  $form['stripe']['dosomething_payment_stripe_api_key_publish'] = array(
    '#type' => 'textfield',
    '#title' => t('Publishable API key'),
    '#default_value' => variable_get('dosomething_payment_stripe_api_key_publish'),
  );
  return system_settings_form($form);
}
