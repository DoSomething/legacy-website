<?php

/**
 * @file
 * Code for dosomething_signup forms.
 */

/**
 * Form constructor for an Alpha/Beta signup form.
 *
 * @param int $nid
 *   Loaded $node that the form is being rendered on.
 * @param int $num_betas
 *   Number of inputs to provide for beta numbers.
 * @param int $alpha_opt_in
 *   Opt-in code for the alpha (user submitting form).
 * @param object $wrapper
 *   Opt-in code for the beta (other mobile numbers provided).
 */
function dosomething_signup_alpha_beta_form($form, &$form_state, $node, $num_betas = 3) {
  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => $node->nid,
    '#access' => FALSE,
  );
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
      '#attributes' => array(
        'data-validate' => 'phone',
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

/**
 * Form submission handler for dosomething_signup_alpha_beta_form().
 *
 * Redirects user to the reportback confirmation page for given node.
 */
function dosomething_signup_alpha_beta_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $nid = $values['nid'];
  // If user is logged in:
  if (user_is_logged_in()) {
    // Create a signup.
    dosomething_signup_create($nid);
    // @todo: If we don't have your number and/or first name yet, save it.
  }
  // Redirect to the reportback confirmation page.
  $confirmation_path = 'node/' . $values['nid'] . '/confirmation';
  $form_state['redirect'] = $confirmation_path;
}
