<?php

/**
 * @file
 * Code for dosomething_signup forms.
 */

/**
 * Form constructor for an Alpha/Beta signup form.
 *
 * @param int $num_betas
 *   Number of inputs to provide for beta numbers.
 * @param int $alpha_opt_in
 *   Opt-in code for the alpha (user submitting form).
 * @param object $wrapper
 *   Opt-in code for the beta (other mobile numbers provided).
 */
function dosomething_signup_alpha_beta_form($form, &$form_state, $num_betas = 3, $alpha_opt_in = NULL, $beta_opt_in = NULL) {
  $form['alpha_first_name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => dosomething_user_get_field('field_first_name'),
    '#attributes' => array(
      'data-validate' => 'fname',
      'data-validate-required' => '',
      'placeholder' => t('First Name'),
    ),
  );
  $form['alpha_mobile'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => dosomething_user_get_mobile(),
    '#attributes' => array(
      'data-validate' => 'phone',
      'data-validate-required' => '',
      'placeholder' => t('Enter your mobile number'),
    ),
  );
  for ($i = 0; $i < $num_betas; $i++) {
    $form['beta_mobile_' .$i] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#attributes' => array(
        'data-validate' => 'phone',
        'data-validate-required' => '',
        'placeholder' => t('Enter someone else\'s number'),
      ),
    );
  }
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Start'),
    ),
  );
  return $form;
}
