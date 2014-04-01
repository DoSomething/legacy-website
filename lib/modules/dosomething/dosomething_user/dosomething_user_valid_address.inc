<?php

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
  $xml = dosomething_user_compile_xml($address);
  // Get the results from USPS api.
  // file_get_contents('http://SERVERNAME/ShippingAPITest.dll?API=Verify&XML=<AddressValidateRequest%20USERID="XXXXXX"><Address ID="0"><Address1></Address1>
  //   <Address2>6406 Ivy Lane</Address2><City>Greenbelt</City><State>MD</State>
  //   <Zip5></Zip5><Zip4></Zip4></Address></AddressValidateRequest>');
  //@TODO: Parse results and validate.
  print $xml;
}


/**
 * Compiles XML according to USPS standards.
 */
function dosomething_user_compile_xml($address) {
  $xml = array(
    'Address1' => $address['thoroughfare'],
    'Address2' => $address['premise'],
    'City' => $address['locality'],
    'State' => $address['administrative_area'],
    'Zip5' => $address['postal_code'],
    'Zip4' => '',
  );
  // Add XML head and foot.
  $out = '<AddressValidateRequest USERID="xxxxxxx">';
  $out .= '<Address ID="0">';
  $out .= format_xml_elements($xml);
  $out .= '</Address>';
  $out .= '</AddressValidateRequest>';

  return $out;
}