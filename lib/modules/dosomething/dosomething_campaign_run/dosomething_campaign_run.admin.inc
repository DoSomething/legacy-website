<?php
/**
 * @file
 * Admin config form settings.
 */


/**
* Menu callback for campaign run default text config.
* @see dosomething_campaign_run_menu().
*/
function dosomething_campaign_run_default_copy_config($form, &$form_state) {
  $form = array();

  // The pre-signup button text.
  $form['dosomething_campaign_run_signup_button_copy'] = array(
    '#type' => 'textfield',
    '#title' => t('Signup Button Copy'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_campaign_run_signup_button_copy'),
  );

  // If there are no total number of X collected.
  $form['dosomething_campaign_run_no_total_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Waiting for total copy'),
    '#description' => t('Place [label] where you would like the label to be replaced.'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_campaign_run_no_total_copy'),
  );

   // No winners yet copy.
  $form['dosomething_campaign_run_no_winner_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Waiting for Winner Copy'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_campaign_run_no_winner_copy'),
  );

  return system_settings_form($form);
}
