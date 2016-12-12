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
  $rbis = db_query("SELECT rb.uid, rbf.fid, rb.nid, rb.run_nid, rb.quantity, rb.why_participated, rbf.caption, rbf.source, rbf.remote_addr, rbf.status, rb.rbid
            FROM dosomething_reportback_file rbf
            INNER JOIN dosomething_reportback rb on rbf.rbid = rb.rbid
            INNER JOIN file_managed fm on fm.fid = rbf.fid
            WHERE rbf.fid > $last_saved
            AND rbf.fid NOT IN (SELECT fid FROM dosomething_rogue_reportbacks)
            AND rbf.fid NOT IN (SELECT fid FROM _the_departed)
            ORDER BY rbf.fid");
}
else {
  // Get all the things!
  $rbis = db_query('SELECT rb.uid, rbf.fid, rb.nid, rb.run_nid, rb.quantity, rb.why_participated, rbf.caption, rbf.source, rbf.remote_addr, rbf.status, rb.rbid
                   FROM dosomething_reportback_file rbf
                   INNER JOIN dosomething_reportback rb on rbf.rbid = rb.rbid
                   INNER JOIN file_managed fm on fm.fid = rbf.fid
                   WHERE rbf.fid NOT IN (SELECT fid FROM dosomething_rogue_reportbacks)
                   AND rbf.fid NOT IN (SELECT fid FROM _the_departed)
                   ORDER BY rbf.fid');
}

$client = dosomething_rogue_client();

foreach ($rbis as $rb) {
  $northstar_id = dosomething_northstar_get_user($rb->uid, 'drupal_id');

  // Only try to send to Rogue if we have a Northstar ID and a file
  if (isset($northstar_id)) {
    $data = [
      'northstar_id' => $northstar_id->id,
      'drupal_id' => $rb->uid,
      'campaign_id' => $rb->nid,
      'campaign_run_id' => $rb->run_nid,
      'quantity' => $rb->quantity,
      'why_participated' => $rb->why_participated,
      'file' => dosomething_helpers_get_data_uri_from_fid($rb->fid),
      'caption' => $rb->caption,
      'source' => $rb->source,
      'remote_addr' => $rb->remote_addr,
      'status' => dosomething_rogue_transform_status($rb->status),
      // Tell rogue not to try to forward the reportback back to phoenix.
      'do_not_forward' => TRUE,
    ];

    try {
      $response = $client->postReportback($data);
      // Output progress to see what's going on.
      echo 'Migrated reportback ' . $rb->fid . ' to Rogue [' . $rb->caption . ']' . PHP_EOL;

      // Store the reference in dosomething_rogue_reportbacks.
      dosomething_rogue_store_rogue_references($rb->rbid, $rb->fid, $response);

      // If the script fails, we can use this to start the script from the last reportback migrated.
      variable_set('dosomething_rogue_last_rbi_migrated', $rb->fid);
    } catch (GuzzleHttp\Exception\ServerException $e) {
      // @todo do we care about this?
      echo 'Something guzzle and terrible ' . $rb->fid . PHP_EOL;

    }
  }
  else {
    echo 'No northstar id, that is terrible ' . $rb->uid . PHP_EOL;
  }

}
