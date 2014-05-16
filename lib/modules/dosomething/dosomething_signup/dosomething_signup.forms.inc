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
 *
 * Provides server-side checks for valid and duplicate numbers, cleans input format.
 */
function dosomething_signup_alpha_beta_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  // Text to display for invalid number format.
  $invalid_format_msg = t("Please provide a valid telephone number.");
  // Initialize array to store all inputted numbers, to check for duplicates.
  $numbers = array();

  // Check if alpha is a valid number:
  $alpha_value = dosomething_user_clean_mobile_number($values['alpha_mobile']);
  if (!$alpha_value) {
    form_set_error('alpha_mobile', $invalid_format_msg);
  }
  else {
    // Add to numbers inputted.
    $numbers[] = $alpha_value;
    // Update form_state value with the clean format.
    $form_state['values']['alpha_mobile'] = $alpha_value;
  }

  // Loop through beta form values.
  for ($i = 0; $i < $values['num_betas']; $i++) {
    $beta = 'beta_mobile_' . $i;
    // If a value exists:
    if (!empty($values[$beta])) {

      // Check if valid number.
      $beta_value = dosomething_user_clean_mobile_number($values[$beta]);
      if (!$beta_value) {
        form_set_error($beta, $invalid_format_msg);
      }
      // Check if the number is a duplicate value.
      elseif (in_array($beta_value, $numbers)) {
        form_set_error($beta, t("Hey, you entered this number already!"));
      }
      // Else store as an inputted number to check against later.
      else {
        $numbers[] = $beta_value;
        // Update form_state value with the clean format.
        $form_state['values'][$beta] = $beta_value;
      }

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
