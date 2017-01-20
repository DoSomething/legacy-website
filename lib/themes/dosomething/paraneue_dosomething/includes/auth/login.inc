<?php

/**
 * Custom afterbuild on password reset form.
 *
 * @param array - $form
 *  A drupal form array.
 * @param array - $form_state
 *  A drupal form_state array.
 *
 * @return - array - $form
 *  Modified drupal form.
 */
function paraneue_dosomething_pass_reset_after_build($form, &$form_state) {
  $form['name']['#title'] = t('Email address');
  return $form;
}

/**
 * Custom validation handler on the password reset form.
 *
 * Sets the neutral message when user is not found.
 *
 * @see paraneue_dosomething_pass_set_message()
 */
function paraneue_dosomething_pass_validate($form, &$form_state) {
  if (!empty($form_state['values']['name']) && form_get_error($form['name'])) {
    // Hide previous errors.
    form_clear_error();
    drupal_get_messages('error');

    // Set the neutral message.
    paraneue_dosomething_pass_set_message();

    // Behave same as in the submit callback.
    drupal_goto('user');
  }
}

/**
 * Custom submit handler on the password reset form.
 *
 * Sets the neutral message after the form submission.
 *
 * @see paraneue_dosomething_pass_set_message()
 */
function paraneue_dosomething_pass_submit($form, &$form_state) {
  paraneue_dosomething_pass_set_message();
}

/**
 * Helper function for the password reset form.
 *
 * Designed to set the neutral message that would not expose whether the
 * email is registered in our DB.
 *
 * @see https://www.owasp.org/index.php/Authentication_Cheat_Sheet#Authentication_and_Error_Messages
 */
function paraneue_dosomething_pass_set_message() {
  $default_msg = 'If your email address exists in our database, you will receive a password recovery link at your email address in a few minutes.';
  $msg = variable_get('dosomething_user_reset_password_copy', $default_msg);

  drupal_set_message(t($msg));
}

/**
 * Custom afterbuild on login form.
 *
 * @param array - $form
 *  A drupal form array.
 * @param array - $form_state
 *  A drupal form_state array.
 *
 * @return - array - $form
 *  Modified drupal form.
 */
function paraneue_dosomething_login_after_build($form, &$form_state) {
  // Customize field elements.
  $form['name']['#title'] = t('Email address or cell number');
  unset($form['name']['#description']);

  unset($form['pass']['#description']);

  return $form;
}
