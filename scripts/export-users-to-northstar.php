<?php
/**
 * Script to export user information from drupal into Northstar.
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-users-to-northstar.php
 */

include_once('../lib/modules/dosomething/dosomething_northstar/dosomething_northstar.module');

// Get all the users, with all the things!
$users = db_query('SELECT u.uid
                   FROM users u
                   LIMIT 3 OFFSET 1');

foreach ($users as $whatever) {
  // Create json object
  $user = user_load($whatever->uid);
  $ns_user = build_northstar_user($user);
  print_r($ns_user);
  $ns = new Northstar();
  $response = $ns->updateUser($ns_user);
}

/**
 *
 */
function build_northstar_user($user) {
  // Optional fields
  $optional = [
    'mobile'       => 'field_mobile',
    'birthdate'    => 'field_birthdate',
    'first_name'   => 'field_first_name',
    'source'       => 'field_user_registration_source',
    'school_id'    => 'field_school_id',
  ];

  // Address fields
  $address = [
    'country'        => 'country',
    'addr_street1'   => 'thoroughfare',
    'addr_street2'   => 'premise',
    'addr_city'      => 'locality',
    'addr_state'     => 'administrative_area',
    'addr_zip'       => 'postal_code',
  ];

  $ns_user = [
    'email'            => $user->mail,
    'drupal_id'        => $user->uid,
    'drupal_password'  => $user->pass,
  ];

  // Set values in ns_user if they are set.
  foreach ($optional as $ns_key => $drupal_key) {
   $field = $user->$drupal_key;
    if (!empty($field[LANGUAGE_NONE][0]['value'])) {
      $ns_user[$ns_key] = $field[LANGUAGE_NONE][0]['value'];
    }
  }
  // Set address values.
  foreach ($address as $ns_key => $drupal_key) {
    $field = $user->field_address[LANGUAGE_NONE][0];
    if (!empty($field[$drupal_key]['value'])) {
      $ns_user[$ns_key] = $field[$drupal_key]['value'];
    }
  }
  return $ns_user;
}
