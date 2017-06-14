<?php
/**
 * @file
 * Code for DoSomething User Address functionality.
 *
 * Provides functions to add and validate a Address form element via Form API.
 */

/**
 * Adds an address form element to a given Form API $form.
 *
 * @param array $form
 *   A Form API array.
 * @param array $form_state
 *   A Form State Form API array.
 */
function dosomething_user_address_form_element(&$form, &$form_state) {
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
  $form['user_last_name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Last Name'),
    '#default_value' => isset($account->field_last_name[LANGUAGE_NONE][0]['value']) ? $account->field_last_name[LANGUAGE_NONE][0]['value'] : '',
    '#attributes' => array(
      'data-validate' => 'lname',
      'data-validate-required' => '',
    ),
  );
  $country = variable_get('dosomething_user_address_country', 'US');
  $form['user_address'] = array(
    '#type' => 'addressfield',
    '#handlers' => array(
      'address' => 'address',
      'address-hide-country' => 'address-hide-country',
    ),
    '#required' => TRUE,
    '#context' => array('countries' => array($country)),
    '#default_value' => isset($account->field_address[LANGUAGE_NONE][0]) ? $account->field_address[LANGUAGE_NONE][0] : '',
  );
  $form['#after_build'][] = 'dosomething_user_remove_extra_values_from_address_field';
  // Check if we should be validating addresses.
  if (variable_get('dosomething_user_validate_address')) {
    $form['user_address']['#prefix'] = '<div data-validate="ups_address" data-validate-required>';
    $form['user_address']['#suffix'] = '</div>';
    $form['#validate'][] = 'dosomething_user_address_form_element_validate';
    $form['#after_build'][] = 'dosomething_user_add_validation_attributes_to_address_fields';
  }
}

/**
 * Validation callback called by dosomething_user_address_form_element().
 */
function dosomething_user_address_form_element_validate($form, &$form_state) {
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
    dosomething_user_address_form_element_set_values($form, $form_state, $formatted_address);
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
function dosomething_user_address_form_element_set_values($form, &$form_state, $address) {
  form_set_value($form['user_address']['address']['street_block']['thoroughfare'],
      array('value' => $address['thoroughfare']), $form_state);
  if (isset($address['premise'])) {
   form_set_value($form['user_address']['address']['street_block']['premise'],
      array('value' => $address['premise']), $form_state);
  }
  form_set_value($form['user_address']['address']['locality_block']['locality'],
      array('value' => $address['locality']), $form_state);
  form_set_value($form['user_address']['address']['locality_block']['administrative_area'],
      array('value' => $address['administrative_area']), $form_state);
  form_set_value($form['user_address']['address']['locality_block']['postal_code'],
      array('value' => $address['postal_code']), $form_state);
}

/**
 * Saves signup_form_data to fields on the user.
 *
 * @param array $values
 *   The values passed from a user signup_data_form submission.
 */
function dosomething_user_save_address_values($values) {
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

function dosomething_user_save_address_values_to_northstar($user, $values) {
  $northstar_id = dosomething_user_get_northstar_id($user->uid);
  $profile = [];
  $submission = $values['user_address'];

  // Map Signup Data Form fields to Northstar profile fields.
  $address_fields = [
    'thoroughfare' => 'addr_street1',
    'premise' => 'addr_street2',
    'locality' => 'addr_city',
    'administrative_area' => 'addr_state',
    'postal_code' => 'addr_zip',
  ];

  foreach ($address_fields as $drupal_key => $northstar_key) {
    $field = $submission[$drupal_key];

    if ($field) {
      $profile[$northstar_key] = $field;
    }
  }

  dosomething_northstar_client()->asClient()->put('v1/users/id/' . $northstar_id, $profile);
}

/**
 * Returns options of Addressfield module's US States to remove.
 *
 * @see https://github.com/DoSomething/phoenix/issues/1807.
 */
function dosomething_user_get_us_states_to_remove() {
  return array(
    'AA', 'AE', 'AP', 'AS', 'FM', 'GU', 'MH', 'MP', 'PW', 'VI',
  );
}

/**
 * Removes extra values from given Addressfield Form API $options of US States.
 *
 * @see dosomething_user_get_us_states_to_remove().
 */
function dosomething_user_remove_extra_us_states(&$options) {
  $states_to_remove = dosomething_user_get_us_states_to_remove();
  // Unset the extra state options.
  foreach($states_to_remove as $state) {
    unset($options[$state]);
  }
}


/**
 * Returns list of administrative areas based on country.
 */
function dosomething_user_get_addressfield_administrative_area_options($country = 'US') {
  module_load_include('inc', 'addressfield', 'plugins/format/address');
  $format = array();
  $address['country'] = $country;
  // Initialize $context array to avoid addressfield PHP notices.
  // @see https://www.drupal.org/node/1678800.
  $context = array(
    'countries' => array(),
    'mode' => 'form',
  );
  addressfield_format_address_generate($format, $address, $context);
  $options = $format['locality_block']['administrative_area']['#options'];
  if ($country == 'US') {
    dosomething_user_remove_extra_us_states($options);
  }
  return array(
    'title' => $format['locality_block']['administrative_area']['#title'],
    'options' => $options,
  );
}

/**
 * Sets variable to use for Address adminstrative area options.
 */
function dosomething_user_set_address_administrative_area_options($country = 'US') {
  $options = dosomething_user_get_addressfield_administrative_area_options($country);
  variable_set('dosomething_user_address_administrative_area_options', $options);
}

/**
 * Gets Address adminstrative area options from variable.
 */
function dosomething_user_get_address_administrative_area_options() {
  $options = variable_get('dosomething_user_address_administrative_area_options', array());
  return $options;
}
