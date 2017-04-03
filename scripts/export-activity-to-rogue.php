<?php
/**
 * Script to export Signups, Reportbacks, and whatever else from drupal into Rogue.
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-activity-to-rogue.php
 */

// Pick up from where we left off, if we want to
$last_saved = variable_get('dosomething_rogue_last_signup_migrated', NULL);

// Pick up getting ALL the things from where we left off!
if ($last_saved) {
  $signups = db_query("SELECT signups.sid, signups.uid, signups.nid, signups.run_nid, signups.source, signups.timestamp, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.updated
                      FROM dosomething_signup signups
                      LEFT JOIN dosomething_reportback rb ON signups.uid = rb.uid AND signups.nid = rb.nid AND signups.run_nid = rb.run_nid
                      WHERE signups.sid > $last_saved AND signups.sid NOT IN (SELECT sid FROM dosomething_rogue_signups)
                      ORDER BY signups.sid");
}
else {
  // Get ALL the things!
  $signups = db_query('SELECT signups.sid, signups.uid, signups.nid, signups.run_nid, signups.source, signups.timestamp, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.updated
                      FROM dosomething_signup signups
                      LEFT JOIN dosomething_reportback rb ON signups.uid = rb.uid AND signups.nid = rb.nid AND signups.run_nid = rb.run_nid
                      WHERE signups.sid NOT IN (SELECT sid FROM dosomething_rogue_signups)
                      ORDER BY signups.sid');
}

$client = dosomething_rogue_client();

foreach ($signups as $signup) {
  $data = [];

  echo 'Trying sid ' . $signup->sid . '...' . PHP_EOL;

  $northstar_user = dosomething_northstar_get_user($signup->uid, 'drupal_id');

  // Only try to send to Rogue if we have a Northstar ID
  if (isset($northstar_user)) {
    // Match Rogue's timestamp format
    $created_at = date('Y-m-d H:i:s', $signup->timestamp);

    // Format signup data
    $data = [
      'northstar_id' => $northstar_user->id,
      'campaign_id' => $signup->nid,
      'campaign_run_id' => $signup->run_nid,
      'do_not_forward' => TRUE,
      'source' => $signup->source,
      'created_at' => $created_at,
      'updated_at' => $created_at, // Set updated same as created, will be overwritten if there was a RB submitted
    ];

    $fids = [];

    // Include all the Reportback data and files if they exist
    if ($signup->rbid) {
      // Pull the quantity and why
      $data['quantity'] = $signup->quantity;
      $data['why_participated'] = $signup->why_participated;

      // Match Rogue's timestamp format
      $updated_at = date('Y-m-d H:i:s', $signup->updated);
      $data['updated_at'] = $updated_at;

      // Get the files for the Reportback
      $photos = db_query('SELECT rbf.fid, rbf.remote_addr, rbf.caption, rbf.status, rbf.reviewed, rbf.reviewer, rbf.source, rbf.status, rblog.timestamp
                          FROM dosomething_reportback_file rbf
                          INNER JOIN dosomething_reportback_log rblog ON rbf.fid = substring_index(rblog.files, \',\',-1)
                          WHERE rbf.rbid = ' . $signup->rbid . '
                          GROUP BY rbf.fid')->fetchAll();

      // Format the photos to send to Rogue
      foreach ($photos as $key=>$photo) {
        echo "\t" . 'Trying fid ' . $photo->fid . '...' . PHP_EOL;
        array_push($fids, $photo->fid);

        // If any of the Reportback files are not approved, send the quantity to Rogue as quantity_pending
        $rogue_status = dosomething_rogue_transform_status($photo->status);
        if ($rogue_status !== 'accepted') {
          $data['quantity_pending'] = $signup->quantity;
          $data['quantity'] = NULL;
        }

        // Match Rogue's timestamp format
        $photo_created_at = date('Y-m-d H:i:s', $photo->timestamp);

        // Format the photo data
        $data['photo'][$key] = [
          'source' => $photo->source,
          'remote_addr' => $photo->remote_addr,
          'caption' => $photo->caption,
          'event_type' => 'post_photo',
          'northstar_id' => $northstar_user->id,
          'status' => $rogue_status,
          'do_not_forward' => TRUE,
          'submission_type' => 'user',
          'file' => dosomething_helpers_get_data_uri_from_fid($photo->fid),
          'created_at' => $photo_created_at,
        ];
      }
    }

    // Send the request to Rogue
    try {
      $response = $client->postSignup($data);

      // Make sure we get a successful response
      if ($response) {
        echo 'Migrated signup ' . $signup->sid . ' reportback ' . $signup->rbid . ' to Rogue.' . PHP_EOL;

        // Store signup reference
        dosomething_rogue_store_rogue_signup_references($signup->sid, $response);

        if ($signup->rbid) {
          foreach ($response['data']['posts']['data'] as $post) {
            echo 'Rogue event_id: ' . $post['id'] . PHP_EOL;
            $current_fid = array_shift($fids);

            if (! dosomething_rogue_get_by_file_id($current_fid)) {
              // Store reportback reference
              db_insert('dosomething_rogue_reportbacks')
              ->fields([
                'fid' => $current_fid,
                'rogue_event_id' => $post['post_event_id'],
                'rbid' => $signup->rbid,
                'rogue_signup_id' => $response['data']['signup_id'],
                'created_at' => REQUEST_TIME,
                ])
              ->execute();
            }
          }
        }
        // Set where we left off in case we crash/have to stop
        variable_set('dosomething_rogue_last_signup_migrated', $signup->sid);
      }

      // Handle getting a 404
      if (!$response) {
        // Put request in failed table for future investigation
        dosomething_rogue_handle_migration_failure($data, $signup->sid, $signup->rbid, $fids);

        // Set where we left off so we don't keep trying this one forever
        variable_set('dosomething_rogue_last_signup_migrated', $signup->sid);

      }
    }
    catch (GuzzleHttp\Exception\ServerException $e) {
      // These aren't yet caught by Gateway

      // Put request in failed table for future investigation
      dosomething_rogue_handle_migration_failure($data, $signup->sid, $signup->rbid, $fids);

      // Set where we left off so we don't keep trying this one forever
      variable_set('dosomething_rogue_last_signup_migrated', $signup->sid);
    }
    catch (DoSomething\Gateway\Exceptions\ApiException $e) {
      // Put request in failed table for future investigation
      dosomething_rogue_handle_migration_failure($data, $signup->sid, $signup->rbid, $fids);

      // Set where we left off so we don't keep trying this one forever
      variable_set('dosomething_rogue_last_signup_migrated', $signup->sid);
    }
  }
  else {
    echo 'No northstar id, that is terrible ' . $signup->sid . PHP_EOL;

    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $signup->sid);

    // Set where we left off so we don't keep trying this one forever
    variable_set('dosomething_rogue_last_signup_migrated', $signup->sid);

  }
}
