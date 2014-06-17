<?php

/**
 * @file
 * Code for dosomething_signup forms.
 */

/**
 * Form constructor for user presignup form.
 *
 * @param int $nid
 *   The node nid to presignup for.
 * @param string $label
 *   The label to display on the form submit button.
 */
function dosomething_signup_presignup_form($form, &$form_state, $nid, $label) {
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
    '#access' => FALSE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $label,
    '#attributes' => array(
      'class' => array(
        'btn',
        'medium',
      ),
    ),
  );
  return $form;
}

/**
 * Form submission handler for dosomething_signup_presignup_form().
 *
 * @see dosomething_signup_presignup_form()
 */
function dosomething_signup_presignup_form_submit($form, &$form_state) {
  $nid = $form_state['values']['nid'];
  // Handle user presignup.
  dosomething_signup_user_presignup($nid);
  // Assuming this form always just lives on the campaign.
  // Let's grab title this way instead of querying db.
  $title = drupal_get_title();
  drupal_set_message(dosomething_signup_get_presignup_confirm_msg($title));
}

/**
 * Returns the confirmation message after submitting presignup form.
 *
 * @param string $title
 *   The title of the presignup node.
 *
 * @return string
 */
function dosomething_signup_get_presignup_confirm_msg($title) {
  $link = l(t('find a campaign'), 'campaigns');
  return t("Sweet, we'll send you an email as soon as @title re-opens. In the meantime, !link you can do right now.", array(
    '@title' => $title,
    '!link' => $link,
  ));
}

/**
 * Form constructor for a Friends signup form.
 *
 * @param int $nid
 *   Loaded $node that the form is being rendered on.
 * @param int $num_friends
 *   Number of inputs to provide for friends' numbers.
 */
function dosomething_signup_friends_form($form, &$form_state, $node, $num_friends = 3) {
  $nid = $node->nid;
  $opt_in_path = dosomething_signup_variable_get($nid, 'mobilecommons_opt_in_path');
  $friends_opt_in_path = dosomething_signup_variable_get($nid, 'mobilecommons_friends_opt_in_path');
  // Load "all participants" copy.
  $all_participants_copy = variable_get('dosomething_campaign_sms_game_all_participants_copy');
 
  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => $nid,
    '#access' => FALSE,
  );
  $form['title'] = array(
    '#type' => 'hidden',
    '#default_value' => $node->title,
    '#access' => FALSE,
  );
  // If we have opt-in paths set:
  if ($opt_in_path && $friends_opt_in_path) {
    // Add as hidden form elements.
    $form['opt_in_path'] = array(
      '#type' => 'hidden',
      '#default_value' => $opt_in_path,
      '#access' => FALSE,
    );
    $form['friends_opt_in_path'] = array(
      '#type' => 'hidden',
      '#default_value' => $friends_opt_in_path,
      '#access' => FALSE,
    );
  }
  else {
    // Else set a warning message to inform staff to not expect any texts.
    drupal_set_message(t("The opt-in paths for this SMS Game have not been configured."), "error");
  }
  $form['num_betas'] = array(
    '#type' => 'hidden',
    '#default_value' => $num_friends,
    '#access' => FALSE,
  );
  $form['alpha_first_name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => 'Your First Name',
    '#default_value' => dosomething_user_get_field('field_first_name'),
    '#attributes' => array(
      'data-validate' => 'fname',
      'data-validate-required' => '',
      'placeholder' => t('First Name'),
    ),
  );
  // Add fieldsets to wrappers to various mobile form elements.
  $form['group1'] = array(
    '#type' => 'fieldset',
    '#attributes' => array(
      'class' => array('-columned first-group'),
    ),
  );
  $form['group2'] = array(
    '#type' => 'fieldset',
    '#prefix' => $all_participants_copy,
    '#attributes' => array(
      'class' => array('-columned second-group'),
    ),
  );
  $form['group1']['alpha_mobile'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => 'Your Cell Number',
    '#default_value' => dosomething_user_get_mobile(),
    '#attributes' => array(
      'data-validate' => 'phone',
      'data-validate-required' => '',
      'placeholder' => t('(555) 555-5555'),
    ),
  );
  for ($i = 0; $i < $num_friends; $i++) {
    // Default to second fieldset.
    $group = 'group2';
    if ($i == 0) {
      // Unless its the first beta.
      $group = 'group1';
    }
    $form[$group]['beta_mobile_' .$i] = array(
      '#type' => 'textfield',
      '#title' => 'Friend\'s Cell Number',
      '#attributes' => array(
        'data-validate' => 'phone',
        'placeholder' => t('(555) 555-5555'),
      ),
    );
  }
  // Check if varaible is set for the Friends Form submit button label.
  $label = variable_get('dosomething_campaign_sms_game_signup_friends_form_button_text', t('Share'));
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => $label,
    ),
  );
  return $form;
}

/**
 * Form validation handler for dosomething_signup_friends_form().
 *
 * Provides server-side checks for valid and duplicate numbers, cleans input format.
 */
function dosomething_signup_friends_form_validate($form, &$form_state) {
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
 * Form submission handler for dosomething_signup_friends_form().
 *
 * Redirects user to the reportback confirmation page for given node.
 */
function dosomething_signup_friends_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $nid = $values['nid'];

  if (user_is_logged_in()) {
    // Create a signup.
    dosomething_signup_create($nid);
    // @todo: Save mobile and first name to user if not set.
    // @see https://github.com/DoSomething/dosomething/issues/2274.
  }

  // Check if an account exists for the given alpha mobile.
  // An anonymous user is able to submit the form, but they may still have an account.
  if ($account = dosomething_user_get_user_by_mobile($values['alpha_mobile'])) {
    // Create a signup for the account.
    // If $account happens to be the logged in user, it's okay.
    // dosomething_signup_create will check if a signup exists before creating.
    dosomething_signup_create($nid, $account->uid);

  }

  
  // Send opt_in request to Mobilecommons API.
  dosomething_signup_mobilecommons_opt_in_friends($values);

  // Redirect to the reportback confirmation page.
  $confirmation_path = 'node/' . $values['nid'] . '/confirmation';
  $form_state['redirect'] = $confirmation_path;
}
