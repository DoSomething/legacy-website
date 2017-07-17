<?php

/**
 * @file
 * Code for dosomething_signup forms.
 */

/**
 * Implements hook_forms().
 *
 * Allows dosomething_signup_form to render multiple times on auth pitch page.
 */
function dosomething_signup_forms($form_id, $args) {
  // If this is one of multiple signup forms rendered on the page:
  if (strpos($form_id, 'dosomething_signup_form_') === 0) {
    // Set its callback and callback arguments:
    $forms[$form_id] = array(
      // Set the callback as dosomething_signup_form.
      'callback' => 'dosomething_signup_form',
      // Pass the relevant $args to it.
      'callback arguments' => $args,
    );
    return $forms;
  }
}

/**
 * Form constructor for user signup form.
 *
 * Displayed for an authenticated user to signup for a node.
 *
 * @param int $nid
 *   The node nid to signup for.
 * @param string $label
 *   The label to display on the form submit button.
 */
function dosomething_signup_form($form, &$form_state, $nid, $label = "Sign Up") {
  $affiliate_data = dosomething_campaign_get_affiliate_data($nid);

  $form['nid'] = [
    '#type' => 'hidden',
    '#value' => $nid,
    '#access' => FALSE,
  ];

  // Check query string for signup source value.
  if ($source = dosomething_signup_get_query_source()) {
    $form['source'] = [
      '#type' => 'hidden',
      '#value' => $source,
      '#access' => FALSE,
    ];
  }

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t($label),
    '#attributes' => [
      'class' => ['button'],
      'data-track-category' => 'Link',
      'data-track-action' => 'Click',
      'data-track-label' => 'Signup (Authenticated)',
    ],
  ];

  $affiliate_messaging_form = dosomething_signup_get_affiliate_form_component($nid);

  if ($affiliate_messaging_form) {
    $form = array_merge($form, $affiliate_messaging_form);
  }

  return $form;
}

/**
 * Form submission handler for dosomething_signup_form().
 *
 * @see dosomething_signup_form()
 */
function dosomething_signup_form_submit($form, &$form_state) {
  // Shouldn't be able to submit form as anonymous user, but check.
  if (!user_is_logged_in()) {
    drupal_set_message(t("Please sign in first."));
    return;
  }

  $params = [];

  $nid = $form_state['values']['nid'];

  $source = NULL;
  if (isset($form_state['values']['source'])) {
    $source = $form_state['values']['source'];
  }

  if (isset($form_state['values']['affiliate_messaging_opt_in'])) {
    $params['affiliate_messaging_opt_in'] = (bool) $form_state['values']['affiliate_messaging_opt_in'];
  }

  // Create signup for logged in user.
  dosomething_signup_user_signup($nid, NULL, $source, $params, $form_state['values']);

  // if (variable_get('rogue_collection', FALSE)) {
  //   $rogue_signup = dosomething_rogue_send_signup_to_rogue($form_state['values']);

  //   // Make sure the signup exists before using it
  //   if ($rogue_signup) {
  //     $node = node_load($rogue_signup['data']['campaign_id']);
  //     dosomething_signup_set_signup_message($node->title);
  //   }
  // } else {
  //   // Create signup for logged in user.
  //   dosomething_signup_user_signup($nid, NULL, $source, $params);
  // }
}

/**
 * Form constructor for unathenticated user signup form.
 * Displayed for an unathenticated user to signup for a node,
 * requiring them first to login via Northstar.
 *
 * @param  array $form
 * @param  array $form_state
 * @param  string $nid
 * @param  string $label
 * @return array
 */
function dosomething_signup_unauthenticated_form($form, &$form_state, $nid, $label = "Sign Up") {
  $campaign = Campaign::get($nid);

  $form['#method'] = 'get';

  $form['#action'] = url('user/authorize');

  $form['action'] = array(
    '#type' => 'hidden',
    '#value' => 'signup',
    '#access' => TRUE,
  );

  $form['node'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
    '#access' => TRUE,
  );

  $form['title'] = array(
    '#type' => 'hidden',
    '#value' => $campaign->title,
    '#access' => TRUE,
  );

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t($label),
    '#attributes' => [
      'id' => 'link--openid-connect-campaign-signup-login',
      'class' => ['button'],
      'data-track-category' => 'Link',
      'data-track-action' => 'Click',
      'data-track-label' => 'Signup (Unauthenticated)',
    ],
  ];

  $affiliate_messaging_form = dosomething_signup_get_affiliate_form_component($nid);

  if ($affiliate_messaging_form) {
    $form = array_merge($form, $affiliate_messaging_form);
  }

  return $form;
}

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
        'button',
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
}

/**
 * Form constructor for a SMS Game signup form.
 *
 * @param int $nid
 *   Loaded $node that the form is being rendered on.
 * @param int $num_friends
 *   Number of inputs to provide for friends' numbers.
 */
function dosomething_signup_sms_game_form($form, &$form_state, $node, $num_friends = 3) {
  $nid = $node->nid;
  // Add relevant configuration form elements.
  dosomething_signup_sms_game_form_config($form, $nid);

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
  $form['num_betas'] = array(
    '#type' => 'hidden',
    '#default_value' => $num_friends,
    '#access' => FALSE,
  );
  $form['#attributes'] = array(
    'class' => ['sms-campaign-form'],
  );
  // Load "all participants" copy.
  $all_participants_copy = t(variable_get('dosomething_campaign_sms_game_all_participants_copy'));
  $form['all_participants_copy'] = array(
    '#prefix' => '<div class="message-callout -above"><div class="message-callout__copy"><p>',
    '#markup' => $all_participants_copy,
    '#suffix' => '</p></div></div>',
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
  $form['alpha_mobile'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => 'Your Cell Number',
    '#default_value' => dosomething_user_get_field('field_mobile'),
    '#attributes' => array(
      'data-validate' => 'phone',
      'data-validate-required' => '',
      'placeholder' => t('(555) 555-5555'),
      'autocomplete' => 'off',
    ),
  );
  for ($i = 0; $i < $num_friends; $i++) {
    $form['beta_mobile_' .$i] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => 'Friend\'s Cell Number',
      '#attributes' => array(
        'data-validate' => 'phone',
        'data-validate-required' => '',
        'placeholder' => t('(555) 555-5555'),
        'autocomplete' => 'off',
      ),
    );
  }
  // Check if variable is set for the Friends Form submit button label.
  $label = t(variable_get('dosomething_campaign_sms_game_signup_friends_form_button_copy', 'Share'));

  // Get scholarship amount.
  $amount = dosomething_campaign_get_scholarship($node->nid);

  if ($amount) {
    $scholarship = array(
      '#markup' => theme('campaign_scholarship', array(
        'amount' => $amount,
        'classes' => array('-right'),
      )),
    );
  }

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => $label,
    ),
    'scholarship' => (isset($scholarship)) ? $scholarship : NULL,
  );

  return $form;
}

/**
 * Add hidden form elements for SMS Game $nid, or set message if not configured.
 *
 * @param array $form
 *   A Form API form to add the elements to.
 * @param int $nid
 *   The node $nid to check configuration values for.
 */
function dosomething_signup_sms_game_form_config(&$form, $nid) {
  $vars = dosomething_helpers_get_variables('node', $nid);

  $sms_game_type = NULL;

  // Single-player variables:
  $opt_in_path = $vars['mobilecommons_opt_in_path'];
  $friends_opt_in_path = $vars['mobilecommons_friends_opt_in_path'];

  // Multi-player variables:
  $mp_story_id = $vars['sms_game_mp_story_id'];
  $mp_story_type = $vars['sms_game_mp_story_type'];

  $has_single_player_config = $opt_in_path && $friends_opt_in_path;
  $has_multiplayer_config = $mp_story_id && $mp_story_type;

  // Check for single-player variables:
  if ($has_single_player_config && !$has_multiplayer_config) {
    $sms_game_type = 'single_player';
    $form['opt_in_path'] = array(
      '#type' => 'hidden',
      '#default_value' => $opt_in_path,
    );
    $form['friends_opt_in_path'] = array(
      '#type' => 'hidden',
      '#default_value' => $friends_opt_in_path,
    );
  }
  // Else check for multi-player variables:
  elseif ($has_multiplayer_config && !$has_single_player_config) {
    $sms_game_type = 'multi_player';
    $form['story_id'] = array(
      '#type' => 'hidden',
      '#default_value' => $mp_story_id,
    );
    $form['story_type'] = array(
      '#type' => 'hidden',
      '#default_value' => $mp_story_type,
    );
  }
  else {
    // Else set a warning message to inform staff to not expect any texts.
    drupal_set_message(t("This SMS Game is not properly configured."), "error");
  }

  if ($sms_game_type) {
    $form['sms_game_type'] = array(
      '#type' => 'hidden',
      '#default_value' => $sms_game_type,
      '#access' => FALSE,
    );
  }
}

/**
 * Form validation handler for dosomething_signup_sms_game_form().
 *
 * Provides server-side checks for valid and duplicate numbers, cleans input format.
 */
function dosomething_signup_sms_game_form_validate($form, &$form_state) {
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
 * Form submission handler for dosomething_signup_sms_game_form().
 *
 * Redirects user to the reportback confirmation page for given node.
 */
function dosomething_signup_sms_game_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $nid = $values['nid'];

  if (user_is_logged_in()) {
    // Create a signup.
    dosomething_signup_create($nid);
    // @todo: Save mobile and first name to user if not set.
    // @see https://github.com/DoSomething/phoenix/issues/2274.
  }

  // Check if an account exists for the given alpha mobile.
  // An anonymous user is able to submit the form, but they may still have an account.
  if ($account = dosomething_user_get_user_by_mobile($values['alpha_mobile'])) {
    // Create a signup for the account.
    // If $account happens to be the logged in user, it's okay.
    // dosomething_signup_create will check if a signup exists before creating.
    dosomething_signup_create($nid, $account->uid);
  }

  // Send request to relevant SMS Game endpoints.
  dosomething_signup_sms_game_signup_request($values['sms_game_type'], $values);

  // Redirect to the reportback confirmation page.
  $redirect = dosomething_campaign_get_confirmation_path($values['nid']);
  $form_state['redirect'] = $redirect;
}

/**
 * Form constructor for a node unsignup form.
 *
 * @param int $nid
 *   The node nid to remove signup from.
 *
 * @ingroup forms
 */
function dosomething_signup_node_unsignup_form($form, &$form_state, $node) {
  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => $node->nid,
  );
  $form['warning'] = array(
    '#markup' => t("Are you sure you want to remove this signup?  This cannot be undone."),
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Delete'),
    ),
  );
  return $form;
}

/**
 * Form submit handler for dosomething_signup_node_unsignup_form().
 */
function dosomething_signup_node_unsignup_form_submit($form, &$form_state) {
  $nid = $form_state['values']['nid'];
  if (dosomething_signup_delete_signup($nid)) {
    drupal_set_message("Signup removed.");
    $form_state['redirect'] = 'node/' . $nid;
    return;
  }
  drupal_set_message("There was an error with your request.");
}

/**
 * Form constructor for Reset Signup Data Form.
 *
 * Sets the given Signup's signup_data_form_timestamp to NULL.
 *
 * @param int $sid
 *   The Signup $sid.
 */
function dosomething_signup_reset_signup_data_form($form, &$form_state, $sid) {
  $form['sid'] = array(
    '#type' => 'hidden',
    '#value' => $sid,
    '#access' => FALSE,
  );
  $form['reset'] = array(
    '#type' => 'fieldset',
    '#title' => t("Reset Signup Data Form"),
  );
  $form['reset']['header'] = array(
    '#markup' => '<p>' . t("Submitting this form will allow the user to submit their Signup Data Form again.") . '</p><p>' . ("Warning: This cannot be done. Do not submit unless you really really mean it.") . '</p>',
  );
  $form['reset']['submit'] = array(
    '#type' => 'submit',
    '#value' => t("Reset"),
  );
  return $form;
}

/**
 * Form submit handler for dosomething_signup_reset_signup_data_form().
 */
function dosomething_signup_reset_signup_data_form_submit($form, &$form_state) {
  $signup = signup_load($form_state['values']['sid']);
  // Set all signup data form values back to NULL.
  $signup->signup_data_form_timestamp = NULL;
  $signup->signup_data_form_response = NULL;
  entity_save('signup', $signup);
  drupal_set_message(t("The Signup data form has been reset."));
}

/**
 * Get form structure for adding the affiliate messaging opt-in to
 * the sign up forms.
 *
 * @param  string $campaign_id
 * @return array
 */
function dosomething_signup_get_affiliate_form_component($campaign_id) {
  if (!$campaign_id) {
    return NULL;
  }

  $affiliate_data = dosomething_campaign_get_affiliate_data($campaign_id);

  if (!$affiliate_data['messaging_opt_in']['enabled']) {
    return NULL;
  }

  $messaging_opt_in = $affiliate_data['messaging_opt_in'];

  $form['affiliate_messaging'] = [
    '#type' => 'container',
    '#id' => 'messaging-opt-in',
    '#attributes' => [
      'class' => ['messaging-opt-in'],
    ],
  ];

  $form['affiliate_messaging']['affiliate_messaging_opt_in'] = [
    '#type' => 'checkbox',
    '#title' => t($messaging_opt_in['label']),
    '#default_value' => TRUE, // @TODO: eventually, this should be false so it's OPT-IN!
  ];

  if ($messaging_opt_in['info_label'] && $messaging_opt_in['info_message'])
  $form['affiliate_messaging']['info'] = [
    '#markup' => '<div class="opt-in-info footnote"><p class="info-toggle js-footnote-toggle">'.$messaging_opt_in['info_label'].'</p><div class="info-message js-footnote-hidden">'.$messaging_opt_in['info_message'].'</div></div>',
  ];

  return $form;

}
