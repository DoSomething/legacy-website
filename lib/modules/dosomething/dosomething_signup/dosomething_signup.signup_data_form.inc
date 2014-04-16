<?php
/**
 * @file
 * Code for dosomething_signup_data_form functionality.
 */

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
  $form[$fieldset]['config'][$prefix . 'collect_user_address'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect user address'),
    '#default_value' => $values['collect_user_address'],
  );
  $form[$fieldset]['config'][$prefix . 'link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => $values['link_text'],
  );
  $form[$fieldset]['config'][$prefix . 'form_header'] = array(
    '#type' => 'textfield',
    '#title' => t('Form header'),
    '#default_value' => $values['form_header'],
  );
  $form[$fieldset]['config'][$prefix . 'form_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Form copy'),
    '#default_value' => $values['form_copy'],
  );
  $form[$fieldset]['config'][$prefix . 'confirm_msg'] = array(
    '#type' => 'textarea',
    '#title' => t('Confirmation message'),
    '#default_value' => $values['confirm_msg'],
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
        'link_text' => $values[$prefix . 'link_text'],
        'form_header' => $values[$prefix . 'form_header'],
        'form_copy' => $values[$prefix . 'form_copy'],
        'confirm_msg' => $values[$prefix . 'confirm_msg'],
        'collect_user_address' => $values[$prefix . 'collect_user_address'],
    ))
    ->execute();
}

/**
 * Form constructor for a user signup data form.
 *
 * @param int $nid
 *   The node which the signup data form is rendered on.
 */
function dosomething_signup_user_signup_data_form($form, &$form_state, $nid) {
  $config = dosomething_signup_get_signup_data_form_info($nid);
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );
  $form['header'] = array(
    '#prefix' => '<h2 class="banner">',
    '#markup' => $config['form_header'],
    '#suffix' => '</h2>',
  );
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

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#attributes' => array(
      'class' => array(
        'btn',
        'large',
      ),
    ),
  );

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
 */
function dosomething_signup_update_signup_data($values) {
  // Find the relevant signup sid to update.
  $sid = dosomething_signup_exists($values['nid']);
  try {
    db_update('dosomething_signup')
    ->fields(array(
      'signup_data_form_timestamp' => REQUEST_TIME,
    ))
    ->condition('sid', $sid)
    ->execute();
    return TRUE;
  }
  catch (Exception $e) {
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
  return FALSE;
}
