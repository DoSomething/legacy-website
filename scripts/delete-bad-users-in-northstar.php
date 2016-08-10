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
  $response = drupal_http_request($client['base_url'] . '/users/' . $record->northstar_id, [
    'headers' => $client['headers'],
    'method' => 'DELETE',
  ]);

  // Output progress to stdout & log request details for later review.
  dosomething_northstar_log_request('delete', $record, [], $response);
  echo 'Deleted Northstar user ' . $record->northstar_id . ' from ' . $record->uid . ' [' . $response->code . ']' . PHP_EOL;

  // If a user cannot be migrated due to an index conflict, add that Northstar ID to the delete queue.
  if ($response->code == '200') {
    db_delete('dosomething_northstar_delete_queue')->condition('id', $record->id)->execute();
  }
}
