<?php
/**
 * Script to export user information from drupal into Northstar.
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-users-to-northstar.php
 */

include_once('../lib/modules/dosomething/dosomething_northstar/dosomething_northstar.module');

$last_saved = variable_get('dosomething_northstar_last_user_migrated', NULL);
if ($last_saved) {
  $users = db_query("SELECT u.uid
            FROM users u
            WHERE uid > $last_saved");
}
else {
  // Get all the users!
  $users = db_query('SELECT u.uid
                   FROM users u');
}

foreach ($users as $user) {
  // Create json object
  $user = user_load($user->uid);
  $ns_user = build_northstar_user($user);

  // Don't "forward" the anonymous user.
  if($user->uid == 0) {
    continue;
  }

  // Use old drupal_http_request method.
  $client = _dosomething_northstar_build_http_client();
  $response = drupal_http_request($client['base_url'] . '/users', [
    'headers' => $client['headers'],
    'method' => 'POST',
    'data' => json_encode($ns_user),
  ]);

  // Output progress to stdout & log request details for later review.
  dosomething_northstar_log_request('migrate', $user, json_encode($ns_user), $response);
  echo 'Migrated user ' . $user->uid . ' to Northstar [' . $response->code . ']' . PHP_EOL;

  // Store the returned Northstar ID on the user's Drupal profile.
  dosomething_northstar_save_id_field($user, json_decode($response->data));

  // If the script fails, we can use this to start the script from a previous person.
  variable_set('dosomething_northstar_last_user_migrated', $user->uid);
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
    'last_name'    => 'field_last_name',
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
    'created_at'       => $user->created,
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

  // If user has a "1234565555@mobile" placeholder username, don't send
  // that to Northstar (since it will cause a validation error and Northstar
  // doesn't require every account to have an email like Drupal does).
  if(preg_match('/^[0-9]+@mobile$/', $ns_user['email'])) {
    unset($ns_user['email']);
  }

  // Set the "source" for this user to Phoenix if they weren't
  // programmatically created through the API.
  if(empty($ns_user['source'])) {
    $ns_user['source'] = 'phoenix';
  }

  return $ns_user;
}
