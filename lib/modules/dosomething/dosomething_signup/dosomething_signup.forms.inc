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
 */
function dosomething_signup_alpha_beta_form($form, &$form_state, $node, $num_betas = 3) {
  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => $node->nid,
    '#access' => FALSE,
  );
  $form['num_betas'] = array(
    '#type' => 'hidden',
    '#default_value' => $num_betas,
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
 * Form validation handler for dosomething_signup_alpha_beta_form().
 */
function dosomething_signup_alpha_beta_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $msg = t("Please provide a valid telephone number.");
  // If alpha_mobile is not a valid number:
  if (!dosomething_user_clean_mobile_number($values['alpha_mobile'])) {
    form_set_error('alpha_mobile', $msg);
  }
  // Loop through beta form values.
  for ($i = 0; $i < $values['num_betas']; $i++) {
    $beta = 'beta_mobile_' . $i;
    // If a value exists and it is not a valid number:
    if (!empty($values[$beta]) && !dosomething_user_clean_mobile_number($values[$beta])) {
      form_set_error($beta, $msg);
    }
  }
}

/**
 * Form submission handler for dosomething_signup_alpha_beta_form().
 *
 * Redirects user to the reportback confirmation page for given node.
 */
function dosomething_signup_alpha_beta_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $nid = $values['nid'];
  if (user_is_logged_in()) {
    // Create a signup.
    dosomething_signup_create($nid);
  }
  // Redirect to the reportback confirmation page.
  $confirmation_path = 'node/' . $values['nid'] . '/confirmation';
  $form_state['redirect'] = $confirmation_path;
}
