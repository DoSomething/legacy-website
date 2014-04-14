<?php


/**
 * Settings form UPS integration.
 */
function dosomething_user_ups_api_settings($form, &$form_state) {
  $form['dosomething_user_ups_test_integration'] = array(
    '#type' => 'checkbox',
    '#title' => t('Development integration?'),
    '#description' => t('Check if NOT on a production environment'),
    '#default_value' =>variable_get('dosomething_user_ups_test_integration'),
  );

  $form['dosomething_user_ups_access_license_number'] = array(
    '#type' => 'textfield',
    '#title' => t('UPS access license number'),
    '#default_value' => variable_get('dosomething_user_ups_access_license_number'),
  );

  $form['dosomething_user_ups_username'] = array(
    '#type' => 'textfield',
    '#title' => t('UPS username'),
    '#default_value' => variable_get('dosomething_user_ups_username'),
  );

  $form['dosomething_user_ups_password'] = array(
    '#type' => 'textfield',
    '#title' => t('UPS password'),
    '#default_value' => variable_get('dosomething_user_ups_password'),
  );

  return system_settings_form($form);
}

/**
 * Page callback to validate user address.
 *
 * @param int $uid
 *  User ID
 *
 */
function dosomething_user_validate_address($uid) {
  $user = user_load($uid);
  $address = $user->field_address[LANGUAGE_NONE][0];
  $first_name = $user->field_first_name[LANGUAGE_NONE][0]['value'];

  // Do we have all the variables we need, if not, fail out.
  if (!dosomething_user_pre_ups_request_check() && is_null($address)) { return; }

  $xml = dosomething_user_compile_ups_xml($first_name, $address);

  $results = dosomething_user_make_request_to_ups_api($xml);

  // For now, print results from request.
  print_r($results);
}
/**
 * Makes a post request to UPS api.
 *
 * @return mixed
 *  If request was successful, returns the data object from the http request, else null.
 */
function dosomething_user_make_request_to_ups_api($xml) {
  // Send requests to the developemnt envrironment for testing/stage.
  $dev_environment = variable_get('dosomething_user_ups_test_integration');
  if ($dev_environment) {
    $url = 'https://wwwcie.ups.com/ups.app/xml/XAV';
  }
  else {
    $url = 'https://onlinetools.ups.com/ups.app/xml/XAV';
  }

  // Options array for drupal_http_request.
  $options = array(
    'headers' => array('Content-Type: text/xml'),
    'method' => 'POST',
    'data' => $xml,
  );

  $results = drupal_http_request($url, $options);
  if ($results) {
    return $results->data;
  }
  else {
    //@TODO: Error logging.
    return NULL;
  }

}


/**
 * Compiles XML according to UPS standards.
 *
 * This function calls other fuctions to format the XML
 * It is made up of two different XML documents.
 * The first contains UPS user infoformation, the second
 * is the actual address validation request.
 *
 * @return string
 *   XML string
 */
function dosomething_user_compile_ups_xml($first_name, $address) {
  $out = dosomething_user_compile_xml_access_request();
  $out .= '<?xml version="1.0" ?>';
  $out .= '<AddressValidationRequest  xml:lang="en-US">';
  $out .= dosomething_user_compile_xml_request_options();
  $out .= dosomething_user_compile_xml_address($first_name, $address);
  $out .= '</AddressValidationRequest>';

  return $out;
}

/**
 * Compile the address portion of the XML.
 *
 * @return string
 *   XML string
 */
function dosomething_user_compile_xml_address($first_name, $address) {

  $addr_xml = array(
    'ConsigneeName' => $first_name, // Name
    'AddressLine' => $address['thoroughfare'] . ' ' . $address['premise'], // Addr
    'PoliticalDivision2' => $address['locality'], // City
    'PoliticalDivision1' => $address['administrative_area'], // State
    'PostcodePrimaryLow' => $address['postal_code'],
    'CountryCode' => 'US',
  );

  $out .= '<AddressKeyFormat>';
  $out .= format_xml_elements($addr_xml);
  $out .= '</AddressKeyFormat>';

  return $out;
}

/**
 * Compile the 'request' portion of the XML.
 *
 * @return string
 *   XML string
 */
function dosomething_user_compile_xml_request_options() {
  /* Type of UPS requests.
   * 1 - Address Validation
   * 2 - Address Classification
   * 3 - Address Validation and Address Classification.
   */
  $request_xml = array(
    'RequestAction' => 'XAV',
    'RequestOption' => '1',  // The type of request.
  );


  $out .= '<Request>';
  $out .= format_xml_elements($request_xml);
  $out .= '</Request>';

  return $out;
}

/**
 * Compile the access request portion of the XML.
 *
 * @return string
 *   XML string
 */
function dosomething_user_compile_xml_access_request() {
  $user_xml = array(
    'AccessLicenseNumber' => variable_get('dosomething_user_ups_access_license_number'),
    'UserId' => variable_get('dosomething_user_ups_username'),
    'Password' => variable_get('dosomething_user_ups_password'),
  );

  // Add XML head and foot.
  $out = '<?xml version="1.0" ?>';
  $out .= '<AccessRequest xml:lang="en-US">';
  $out .=  format_xml_elements($user_xml);
  $out .= '</AccessRequest>';

  return $out;
}
/**
 * Run this check before we make a request to UPS.
 *
 * This ensures we have the user variables needed.
 *
 * @return bool
 *  If we have all the correct keys, return true, else false.
 */
function dosomething_user_pre_ups_request_check() {
  $access_license = variable_get('dosomething_user_ups_access_license_number');
  $username = variable_get('dosomething_user_ups_username');
  $pass = variable_get('dosomething_user_ups_password');
  if (!is_null($access_license) && !is_null($username) && !is_null($pass)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}