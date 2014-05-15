<?php

/**
 * @file
 * Code for dosomething_signup forms.
 */

/**
 * Form constructor for the SMS Game form.
 */
function dosomething_signup_sms_game_form($form, &$form_state) {
  global $user;
  // Load user to get relevant field values as form default_values.
  $account = user_load($user->uid);
  $form['user_first_name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('First Name'),
    '#default_value' => isset($account->field_first_name[LANGUAGE_NONE][0]['value']) ? $account->field_first_name[LANGUAGE_NONE][0]['value'] : '',
    '#attributes' => array(
      'data-validate' => 'fname',
      'data-validate-required' => '',
    ),
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Start'),
    ),
  );
  return $form;
}
