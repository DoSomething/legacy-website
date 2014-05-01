<?php
/**
 * @file
 * Code for dosomething_signup_data_form functionality.
 */
define('DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN', '[submitted]');

/**
 * Returns the dosomething_signup_data_form values for a given $nid.
 *
 * @param int $nid
 *   The node nid of the signup_data_form record to check.
 *
 * @return mixed
 *   An array of the signup data form values if exists, NULL if doesn't exist.
 */
function dosomething_signup_get_signup_data_form_info($nid) {
  return db_select('dosomething_signup_data_form', 's')
    ->fields('s')
    ->condition('nid', $nid)
    ->execute()
    ->fetchAssoc();
}

/**
 * Adds form elements to given node $form to store nid signup_data_form values.
 *
 * Note there is no submit form element returned.
 * This function is always called from within a node edit form.
 */
function _dosomething_signup_node_signup_data_form(&$form, &$form_state) {
  $nid = $form['nid']['#value'];
  $values = dosomething_signup_get_signup_data_form_info($nid);
  $fieldset = 'signup_data_form';
  $prefix = $fieldset . '_';
  // Set an additional submit handler to save the signup_data_form values.
  $form['#submit'][] = 'dosomething_signup_node_signup_data_form_submit';
  $form['#validate'][] = 'dosomething_signup_node_signup_data_form_validate';
  // Create fieldset to collect signup data form values.
  $form[$fieldset] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup Data Form'),
    '#weight' => 60,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form[$fieldset][$prefix . 'status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect additional signup data'),
    '#default_value' => $values['status'],
  );
  $form[$fieldset]['config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration'),
    '#weight' => 60,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    // Config fieldset should only be visible if the status field is checked.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'status"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config'][$prefix . 'required'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prompt after signup'),
    '#default_value' => $values['required'],
    '#description' => t('If checked, the form modal will be displayed after the user first signs up.'),
  );
  $form[$fieldset]['config'][$prefix . 'required_allow_skip'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow skip'),
    '#default_value' => $values['required_allow_skip'],
    '#description' => t('If checked, the form modal will provide a Skip button when the user is first prompted.'),
    // Should only be visible if form is required.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'required"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config'][$prefix . 'link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => $values['link_text'],
    '#description' => t('This is label of the link in "Stuff You Need" which opens the form modal.'),
  );
  $form[$fieldset]['config'][$prefix . 'form_header'] = array(
    '#type' => 'textfield',
    '#title' => t('Form header'),
    '#default_value' => $values['form_header'],
    '#description' => t('This is the headline that appears in the form modal.'),
  );
  $form[$fieldset]['config'][$prefix . 'form_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Form copy'),
    '#default_value' => $values['form_copy'],
    '#description' => t('This is the copy that appears above the form elements.'),
  );
  // Create fieldset to group configuration of the actual form elements.
  $form[$fieldset]['config']['elements'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form Elements'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form[$fieldset]['config']['elements'] [$prefix . 'collect_user_address'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect user address'),
    '#default_value' => $values['collect_user_address'],
    '#description' => t('If checked, collect the user address and save to profile.'),
  );
  $form[$fieldset]['config']['elements'] [$prefix . 'collect_why_signedup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect signup reason'),
    '#default_value' => $values['collect_why_signedup'],
    '#description' => t('If checked, collect the reason why the user signed up for the campaign.'),
  );
  $form[$fieldset]['config']['elements'][$prefix . 'why_signedup_label'] = array(
    '#type' => 'textarea',
    '#title' => t('Signup Reason Label'),
    '#default_value' => $values['why_signedup_label'],
    '#description' => t('This is the label for the field which collects the signup reason. e.g. <em>Tell us why you would like to receive Thumb Socks for Thumb Wars</em>.'),
    // Why_signedup label should only be visible if collect_why_signedup is checked.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'collect_why_signedup"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config'][$prefix . 'confirm_msg'] = array(
    '#type' => 'textarea',
    '#title' => t('Confirmation message'),
    '#default_value' => $values['confirm_msg'],
    '#description' => t('This is the message displayed after the user submits the form.'),
  );
  $form[$fieldset]['config'][$prefix . 'form_submitted_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Form submitted copy'),
    '#default_value' => $values['form_submitted_copy'],
    '#description' => t('This is the copy that will appear if a user views the form again after submitting. <p>You can use ' . DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN .' to display the time the user submitted the form, e.g. <em>You submitted this form on ' . DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN . ', your banner should arrive within 2 weeks from then!</em></p>'),
  );
}

/**
 * Validates node signup_data_form values.
 */
function dosomething_signup_node_signup_data_form_validate(&$form, &$form_state) {
  $values = $form_state['values'];
  $prefix = 'signup_data_form_';
  // If signup data form is enabled:
  if ($values[$prefix . 'status'] == 1) {
    // Link text is mandatory.
    $link_text = $prefix . 'link_text';
    if (empty($values[$link_text])) {
      form_set_error($link_text, t('Signup Data Form Link text is mandatory.'));
    }
    // Confirm_msg is mandatory.
    $confirm_msg = $prefix . 'confirm_msg';
    if (empty($values[$confirm_msg])) {
      form_set_error($confirm_msg, t('Signup Data Form Confirmation message is mandatory.'));
    }
  }
}

/**
 * Saves node signup_data_form values into dosomething_signup_data_form.
 */
function dosomething_signup_node_signup_data_form_submit(&$form, &$form_state) {
  $nid = $form['nid']['#value'];
  $values = $form_state['values'];
  $prefix = 'signup_data_form_';
  // Use db_merge to either insert or update existing record for $nid.
  db_merge('dosomething_signup_data_form')
    ->key(array('nid' => $nid))
    ->fields(array(
        'status' => $values[$prefix . 'status'],
        'required' => $values[$prefix . 'required'],
        'required_allow_skip' => $values[$prefix . 'required_allow_skip'],
        'link_text' => $values[$prefix . 'link_text'],
        'form_header' => $values[$prefix . 'form_header'],
        'form_copy' => $values[$prefix . 'form_copy'],
        'form_submitted_copy' => $values[$prefix . 'form_submitted_copy'],
        'confirm_msg' => $values[$prefix . 'confirm_msg'],
        'collect_user_address' => $values[$prefix . 'collect_user_address'],
        'collect_why_signedup' => $values[$prefix . 'collect_why_signedup'],
        'why_signedup_label' => $values[$prefix . 'why_signedup_label'],
    ))
    ->execute();
}

/**
 * Form constructor for a user signup data form.
 *
 * @param int $nid
 *   The node which the signup data form is rendered on.
 */
function dosomething_signup_user_signup_data_form($form, &$form_state, $signup) {
  // Load signup data form config to determine what form elements we need.
  $config = dosomething_signup_get_signup_data_form_info($signup->nid);
  $form['sid'] = array(
    '#type' => 'hidden',
    '#value' => $signup->sid,
    '#access' => FALSE,
  );
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $signup->nid,
    '#access' => FALSE,
  );
  $form['header'] = array(
    '#prefix' => '<h2 class="banner">',
    '#markup' => $config['form_header'],
    '#suffix' => '</h2>',
  );
  // If the user has submitted form already:
  if ($timestamp = $signup->signup_data_form_timestamp && $signup->response) {
    // Get filtered form_submitted_copy.
    $copy = dosomething_signup_filter_form_submitted_copy($config['form_submitted_copy'], $timestamp);
    // Display the form submitted copy:
    $form['submitted_copy'] = array(
      '#prefix' => '<p>',
      '#markup' => $copy,
      '#suffix' => '</p>',
    );
    // Return form as is (without a submit button).
    return $form;
  }
  $form['copy'] = array(
    '#prefix' => '<p>',
    '#markup' => $config['form_copy'],
    '#suffix' => '</p>',
  );
  if ($config['collect_user_address']) {
    global $user;
    // Load user to get relevant field values as form default_values.
    $account = user_load($user->uid);
    $form['user_first_name'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('First Name'),
      '#default_value' => isset($account->field_first_name[LANGUAGE_NONE][0]['value']) ? $account->field_first_name[LANGUAGE_NONE][0]['value'] : '',
      '#attributes' => array(
        'class' => array('js-validate', 'required'),
        'data-validate' => array('fname'),
        'data-validate-required' => '',
      ),
    );
    $form['user_last_name'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Last Name'),
      '#default_value' => isset($account->field_last_name[LANGUAGE_NONE][0]['value']) ? $account->field_last_name[LANGUAGE_NONE][0]['value'] : '',
      '#attributes' => array(
        'class' => array('js-validate', 'required'),
        'data-validate' => array('lname'),
        'data-validate-required' => '',
      ),
    );
    $form['user_address'] = array(
      '#type' => 'addressfield',
      '#handlers' => array(
        'address' => 'address',
        'address-hide-country' => 'address-hide-country',
      ),
      '#required' => TRUE,
      '#context' => array('countries' => array('US')),
      '#default_value' => isset($account->field_address[LANGUAGE_NONE][0]) ? $account->field_address[LANGUAGE_NONE][0] : '',
    );
    // If we are collecting an address, run address validation.
    $form['#validate'][] = 'dosomething_signup_data_validate_address';
  }
  // If we are collecting why_signedup:
  if ($config['collect_why_signedup']) {
    // Add it as a form element.
    $form['why_signedup'] = array(
      '#type' => 'textarea',
      // @todo: This needs to be conditional. Can't be required if you skip.
      //'#required' => TRUE,
      '#title' => $config['why_signedup_label'],
    );
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#attributes' => array(
      'class' => array(
        'btn',
        'large',
      ),
    ),
  );
  // If form is set to include a skip button, and user has never submitted:
  if ($config['required_allow_skip'] && !$signup->signup_data_form_timestamp) {
    // Include a Skip button.
    $form['actions']['skip'] = array(
      '#type' => 'submit',
      '#value' => t('Skip'),
      '#submit' => array('dosomething_signup_user_signup_data_form_skip'),
      '#attributes' => array(
        'class' => array(
          'btn',
          'secondary',
        ),
      ),
    );
  }

  $form['#action'] = "#modal-signup-data-form";
  $form['#after_build'][] = 'dosomething_user_remove_extra_values_from_address_field';

  return $form;
}

function dosomething_signup_data_validate_address($form, &$form_state) {
  // Validate address against UPS api.
  $address = $form_state['input']['user_address'];
  $first_name = $form_state['input']['user_first_name'];
  $last_name = $form_state['input']['user_last_name'];

  $formatted_address = dosomething_user_validate_any_address($first_name, $last_name, $address);

  // Did we not get any results?
  if (in_array('sorry', $formatted_address)) {
    form_set_error('dosomething_user_validate_address', t('Hmmm, we couldn’t find that address. Please try again.'));
  }
  // Did it come back from the api as ambiguous? -- Check with the user.
  elseif (in_array('ambiguous', $formatted_address)) {
    dosomething_signup_data_set_address_values($form, $form_state, $formatted_address);
    form_set_error('dosomething_user_ambiguous_address', t('Hmmm, we couldn’t find that address. Did you mean:'));
  }
  // We have a full address, save it!
  else {
    dosomething_signup_data_set_address_values($form, $form_state, $formatted_address);
  }
}

/**
 * Set the formatted address values in a form.
 *
 * @param array $form
 *  A drupal form.
 * @param array $form_state
 *  A drupal form_state.
 * @param array $address
 *  A validated drupal addressfield array.
 */
function dosomething_signup_data_set_address_values($form, &$form_state, $address) {
  form_set_value($form['user_address']['address']['street_block']['thoroughfare'],
      array('value' => $address['thoroughfare']), $form_state);
  form_set_value($form['user_address']['address']['street_block']['premise'],
      array('value' => $address['premise']), $form_state);
  form_set_value($form['user_address']['address']['locality_block']['locality'],
      array('value' => $address['locality']), $form_state);
  form_set_value($form['user_address']['address']['locality_block']['administrative_area'],
      array('value' => $address['administrative_area']), $form_state);
  form_set_value($form['user_address']['address']['locality_block']['postal_code'],
      array('value' => $address['postal_code']), $form_state);
}

/**
 * Form submit handler for dosomething_signup_user_signup_data_form().
 */
function dosomething_signup_user_signup_data_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  // Load signup_data_form record to gather relevant config and confirm_msg.
  $config = dosomething_signup_get_signup_data_form_info($values['nid']);
  if ($config['collect_user_address']) {
    // Update user data.
    dosomething_signup_update_user_data($values);
  }
  // Update signup record.
  dosomething_signup_update_signup_data($values);
  // Display the signup_data_form's confirm_msg field.
  drupal_set_message($config['confirm_msg']);
}

/*
 * Custom submit for the skip button in dosomething_signup_user_signup_data_form().
 */
function dosomething_signup_user_signup_data_form_skip($form, &$form_state) {
  // Update signup record with response = 0.
  dosomething_signup_update_signup_data($form_state['values'], 0);
}

/**
 * Saves signup_form_data to fields on the user.
 *
 * @param array $values
 *   The values passed from a user signup_data_form submission.
 */
function dosomething_signup_update_user_data($values) {
  global $user;
  $account = $user;
  $edit = array();
  if (isset($values['user_address'])) {
    $edit['field_address'] = array(
      LANGUAGE_NONE => array(
        0 => $values['user_address']
      ),
    );
  }
  if (isset($values['user_first_name'])) {
    $edit['field_first_name'] = array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $values['user_first_name'],
        ),
      ),
    );
  }
  if (isset($values['user_last_name'])) {
    $edit['field_last_name'] = array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $values['user_last_name'],
        ),
      ),
    );
  }
  user_save($account, $edit);
}

/**
 * Saves signup_form_data to the relevant signup record.
 *
 * @param array $values
 *   The values passed from a user signup_data_form submission.
 * @param int $response
 *   If 0, the user chose to skip the form. Else, should be 1.
 */
function dosomething_signup_update_signup_data($values, $response = 1) {
  try {
    // Load the signup entity to update.
    $entity = signup_load($values['sid']);
    $entity->signup_data_form_timestamp = REQUEST_TIME;
    $entity->signup_data_form_response = $response;
    // If non-skip, store any additional signup data:
    if ($response) {
      if (isset($values['why_signedup'])) {
        $entity->why_signedup = $values['why_signedup'];
      } 
    }
    $entity->save();
    return TRUE;
  }
  catch (Exception $e) {
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
  return FALSE;
}

/**
 * Wrapper for str_replace for usage with form_submitted_copy values.
 *
 * @param string $string
 *   The original string, which may contain the
 *   DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN string.
 * @param int $timestamp
 *   The timestamp to replace the token string with.
 *
 * @return string
 *   Original string, with token replaced with a readable $timestamp.
 */
function dosomething_signup_filter_form_submitted_copy($string, $timestamp) {
  // Custom format: January 1st.
  $submitted = format_date($timestamp, 'custom', 'F jS');
  return str_replace(DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN, $submitted, $string);
}
