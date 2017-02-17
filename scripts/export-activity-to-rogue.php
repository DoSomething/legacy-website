<?php
/**
 * Script to export Signups, Reportbacks, and whatever else from drupal into Rogue.
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-activity-to-rogue.php
 */

include_once('../lib/modules/dosomething/dosomething_rogue/dosomething_rogue.module');
include_once('../lib/modules/dosomething/dosomething_northstar/dosomething_northstar.module');

// Pick up from where we left off, if we want to
// $last_saved = variable_get('dosomething_rogue_last_rbi_migrated', NULL);

// Pick up getting ALL the things from where we left off!
if ($last_saved) {
  $signups = db_query("SELECT signups.sid, signups.uid, signups.nid, signups.run_nid, signups.source, signups.timestamp, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.updated
                      FROM dosomething_signup signups
                      LEFT JOIN dosomething_reportback rb ON signups.uid = rb.uid AND signups.nid = rb.nid AND signups.run_nid = rb.run_nid
                      WHERE signups.sid NOT IN (SELECT sid FROM dosomething_rogue_signups)
                      ORDER BY signups.sid
                      LIMIT 1");
}
else {
  // Get ALL the things!
  $signups = db_query('SELECT signups.sid, signups.uid, signups.nid, signups.run_nid, signups.source, signups.timestamp, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.updated
                      FROM dosomething_signup signups
                      LEFT JOIN dosomething_reportback rb ON signups.uid = rb.uid AND signups.nid = rb.nid AND signups.run_nid = rb.run_nid
                      WHERE signups.sid NOT IN (SELECT sid FROM dosomething_rogue_signups)
                      ORDER BY signups.sid
                      LIMIT 1')->fetchAll();
}

$client = dosomething_rogue_client();

foreach ($signups as $signup) {
  echo 'Trying sid ' . $signup->sid . '...' . PHP_EOL;

  $northstar_id = dosomething_northstar_get_user($signup->uid, 'drupal_id');

  // Only try to send to Rogue if we have a Northstar ID
  if (isset($northstar_id)) {
    // Match Rogue's timestamp format
    $created_at = date('Y-m-d H:i:s', $signup->timestamp);

    // Format data as Rogue expects
    $data = [
      // signup
      'northstar_id' => $northstar_id->id,
      'campaign_id' => $signup->nid,
      'campaign_run_id' => $signup->run_nid,
      'do_not_forward' => TRUE,
      'created_at' => $created_at,
      'updated_at' => $created_at, // Set updated same as created, will be overwritten if there was a RB submitted
    ];

    $fids = [];

    // Include all the Reportback data and files if they exist
    if ($signup->rbid) {
      $data['quantity'] = $signup->quantity;
      $data['why_participated'] = $signup->why_participated;

      // Match Rogue's timestamp format
      $updated_at = date('Y-m-d H:i:s', $signup->updated);
      $data['updated_at'] = $signup->updated; // @TODO: this doesn't seem right, double check when this updates

      // Get the files for the Reportback
      $photos = db_query('SELECT rbf.fid, rbf.remote_addr, rbf.caption, rbf.status, rbf.reviewed, rbf.reviewer, rbf.source, rblog.timestamp
                          FROM dosomething_reportback_file rbf
                          INNER JOIN dosomething_reportback_log rblog ON rbf.fid = substring_index(rblog.files, \',\',-1)
                          WHERE rbf.rbid = ' . $signup->rbid . '
                          GROUP BY rbf.fid')->fetchAll();

      // Format the photos to send to Rogue
      foreach ($photos as $key=>$photo) {
        echo "\t" . 'Trying fid ' . $photo->fid . '...' . PHP_EOL;
        array_push($fids, $photo->fid);

        // Match Rogue's timestamp format
        $photo_created_at = date('Y-m-d H:i:s', $photo->timestamp);

        $data['photo'][$key] = [
          'source' => $photo->source,
          'remote_addr' => $photo->remote_addr,
          'caption' => $photo->caption,
          'event_type' => 'post_photo',
          'northstar_id' => $northstar_id->id,
          'do_not_forward' => TRUE,
          'file' => dosomething_helpers_get_data_uri_from_fid($photo->fid),
          // @TODO: figure out timestamp situation
          'created_at' => $photo_created_at,
        ];
      }

    }
  echo 'Request:' . PHP_EOL . json_encode($data) . PHP_EOL;

    // catch GuzzleHttp\Exception\ServerException? make sure Rogue is handling null images first
    // Send the request to Rogue
    $response = $client->postSignup($data);

    // Make sure we get a successful response
    if ($response) {
      echo 'Migrated signup ' . $signup->sid . ' reportback ' . $signup->rbid . ' to Rogue.' . PHP_EOL;

      // Store signup reference
      // function dosomething_rogue_store_rogue_signup_references($sid, $rogue_signup) {
      dosomething_rogue_store_rogue_signup_references($signup->sid, $response);

      // Store reportback reference
      // @TODO: new helper/rework current one to work with the response we get back from Rogue when posting a signup
      // should be able to just grab each post since I don't think /signups response change the format of that
      echo '$response[\'data\'][\'post\'] - ' . json_encode($response['data']['post']) . PHP_EOL;

      if ($signup->rbid) {
        foreach ($response['data']['post']['data'] as $post) {
          echo 'Rogue event_id: ' . $post['event']['data']['event_id'] . PHP_EOL;
          // echo 'Post data: ' . json_encode($post) . PHP_EOL;
          // dosomething_rogue
          // echo json_encode(dosomething_rogue_store_rogue_references($signup->rbid, array_shift($fids), $post)) . PHP_EOL;
          $current_fid = array_shift($fids);

          if (! dosomething_rogue_get_by_file_id($current_fid)) {

            // Store references to rogue IDs.
            db_insert('dosomething_rogue_reportbacks')
            ->fields([
              'fid' => $current_fid,
              'rogue_event_id' => $post['event']['data']['event_id'],
              'rbid' => $signup->rbid,
              'rogue_signup_id' => $post['signup_id'],
              'created_at' => REQUEST_TIME,
              ])
            ->execute();
          }
        }
      }
      // echo json_encode($response) . PHP_EOL;
    }
  }
  else {
    echo 'No northstar id, that is terrible ' . $rb->uid . PHP_EOL;
  }
}
