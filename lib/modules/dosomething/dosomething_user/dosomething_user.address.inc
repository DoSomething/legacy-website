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
  $form['user_address'] = array(
    '#prefix' => '<div data-validate="ups_address" data-validate-required>',
    '#suffix' => '</div>',
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
  $form['#validate'][] = 'dosomething_user_address_form_element_validate';
  $form['#after_build'][] = 'dosomething_user_remove_extra_values_from_address_field';
  $form['#after_build'][] = 'dosomething_user_add_validation_attributes_to_address_fields';
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

/**
 * Returns list of administrative areas based on country.
 */
function dosomething_user_get_administrative_area_options($country = 'US') {
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
  return $format['locality_block']['administrative_area']['#options'];
}
