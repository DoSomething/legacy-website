<?php
/**
 * Script to export reportbacks from drupal into Rogue.
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-reportbacks-to-rogue.php
 */

include_once('../lib/modules/dosomething/dosomething_rogue/dosomething_rogue.module');
include_once('../lib/modules/dosomething/dosomething_northstar/dosomething_northstar.module');


$last_saved = variable_get('dosomething_rogue_last_rbi_migrated', NULL);
if ($last_saved) {
  $rbis = db_query("SELECT rb.uid
            FROM dosomething_reportback_file rbf
            INNER JOIN dosomething_reportback rb on rbf.rbid = rb.rbid
            WHERE rbf.fid > $last_saved
            ORDER BY rbf.fid
            LIMIT 1");
}
else {
  // Get all the things!
  $rbis = db_query('SELECT *
                   FROM dosomething_reportback_file rbf
                   INNER JOIN dosomething_reportback rb on rbf.rbid = rb.rbid
                   ORDER BY rbf.fid
                   LIMIT 15');
}

$client = dosomething_rogue_client();


foreach ($rbis as $rb) {

  $data = [
    'northstar_id' => dosomething_northstar_get_user($rb->uid, 'drupal_id')->id,
    'campaign_id' => $rb->nid,
    'campaign_run_id' => $rb->run_nid,
    'quantity' => $rb->quantity,
    'why_participated' => $rb->why_participated,
    'file' => dosomething_helpers_get_data_uri_from_fid($rb->fid),
    'caption' => $rb->caption,
    'source' => $rb->source,
    'remote_addr' => $rb->remote_addr,
    'status' => dosomething_rogue_transform_status($rb->status),
  ];


  // Transform Reviewer to NS id
  // Transform user to NS id
  // Transform status to the rogue status

  print_r($data) . "\n";

  // $response = $client->postReportback($data);

  // Output progress to stdout so we can see our good work.


  // Save any failed requests to the request log for debugging.


  // Store the info in dosomething_rogue_reportbacks.

  // If the script fails, we can use this to start the script from a previous person.
  // variable_set('dosomething_rogue_last_rbi_migrated', $user->uid);
}
