<?php
/**
 * Script to delete any Northstar users in the delete queue.
 *
 * to run:
 * drush --script-path=../scripts/ php-script delete-bad-users-in-northstar.php
 */

include_once('../lib/modules/dosomething/dosomething_northstar/dosomething_northstar.module');

$records = db_query('SELECT id, uid, northstar_id FROM dosomething_northstar_delete_queue');

foreach ($records as $record) {
  $client = _dosomething_northstar_build_http_client();

  // Delete the user with the provided conflicting Northstar ID.
  $response = drupal_http_request($client['base_url'] . '/users/' . $record->northstar_id, [
    'headers' => $client['headers'],
    'method' => 'DELETE',
  ]);

  // Output progress to stdout & log request details for later review.
  dosomething_northstar_log_request('delete', $record, [], $response);
  echo 'Deleted Northstar user ' . $record->northstar_id . ' from ' . $record->uid . ' [' . $response->code . ']' . PHP_EOL;

  // Remove the record from the delete queue if successfully deleted.
  if ($response->code == 200) {
    db_delete('dosomething_northstar_delete_queue')->condition('id', $record->id)->execute();
  }

  $user = user_load($record->uid);
  $ns_user = build_northstar_user($user);

  // Use old drupal_http_request method.
  $response = drupal_http_request($client['base_url'] . '/users', [
    'headers' => $client['headers'],
    'method' => 'POST',
    'data' => json_encode($ns_user),
  ]);

  // Output progress to stdout & log request details for later review.
  dosomething_northstar_log_request('migrate', $user, $ns_user, $response);
  echo 'Migrated user ' . $user->uid . ' to Northstar [' . $response->code . ']' . PHP_EOL;
  $response_data = json_decode($response->data);

  // If a user cannot be re-migrated due to a Drupal ID index conflict, we should add an entry for that Northstar ID.
  if ($response->code == 400 && !empty($response_data->error->context->id)) {
    db_insert('dosomething_northstar_delete_queue')->fields(['uid' => $user->uid, 'northstar_id' => $response_data->error->context->id])->execute();
  }

  // Store the returned Northstar ID on the user's Drupal profile.
  dosomething_northstar_save_id_field($user->uid, $response_data);
}

/**
 * Build a Northstar request from the $user variable.
 */
function build_northstar_user($user) {
  $northstar_user = dosomething_northstar_transform_user($user);

  // Since we're sending an existing user, we'll also attach their hashed password
  // (which Northstar can understand thanks to it's DrupalPasswordHash class), and
  // the created_at timestamp on the original account.
  $northstar_user['drupal_password'] = $user->pass;
  $northstar_user['created_at'] = $user->created;

  return $northstar_user;
}
