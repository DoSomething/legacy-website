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
            WHERE uid > $last_saved
            ORDER BY u.uid");
}
else {
  // Get all the users!
  $users = db_query('SELECT u.uid
                   FROM users u
                   ORDER BY u.uid');
}

foreach ($users as $user) {
  // Create json object
  $user = user_load($user->uid);
  $northstar_user = dosomething_northstar_transform_user($user);

  // Don't "forward" the anonymous user.
  if($user->uid == 0) {
    continue;
  }

  // Use old drupal_http_request method.
  $client = _dosomething_northstar_build_http_client();
  $response = drupal_http_request($client['base_url'] . '/users', [
    'headers' => $client['headers'],
    'method' => 'POST',
    'data' => json_encode($northstar_user),
  ]);

  // Output progress to stdout so we can see our good work.
  echo 'Migrated user ' . $user->uid . ' to Northstar [' . $response->code . ']' . PHP_EOL;
  $response_data = json_decode($response->data, TRUE);

  // Save any failed requests to the request log for debugging.
  if(! in_array($response->code, [200, 201])) {
    dosomething_northstar_log_request('migrate', $user, $northstar_user, $response_data);
  }

  // If a user cannot be migrated due to a Drupal ID index conflict, we should delete the conflicting Northstar record.
  if ($response->code == 400 && !empty($response_data->error->context->id)) {
    db_insert('dosomething_northstar_delete_queue')->fields(['uid' => $user->uid, 'northstar_id' => $response_data['error']['context']['id']])->execute();
  }

  // Store the returned Northstar ID on the user's Drupal profile.
  dosomething_northstar_save_id_field($user->uid, $response_data);

  // If the script fails, we can use this to start the script from a previous person.
  variable_set('dosomething_northstar_last_user_migrated', $user->uid);
}
