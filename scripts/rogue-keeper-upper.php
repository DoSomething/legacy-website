<?php
/**
 * Keeper-Upper Script to export Signups, Reportbacks, and whatever else from drupal into Rogue.
 * This is to be run on a recurring basis after the big migration has completed. 
 *
 * to run:
 * drush --script-path=../scripts/ php-script rogue-keeper-upper.php
 */

// 1. New signups
// Pick up from where we left off, if we want to
$last_saved = variable_get('dosomething_rogue_last_signup_kept_up', NULL);

if ($last_saved) {
  $signups = db_query("SELECT signups.sid, signups.uid, signups.nid, signups.run_nid, signups.source, signups.timestamp, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.updated
                      FROM dosomething_signup signups
                      LEFT JOIN dosomething_reportback rb ON signups.uid = rb.uid AND signups.nid = rb.nid AND signups.run_nid = rb.run_nid
                      WHERE signups.sid > $last_saved AND signups.sid NOT IN (SELECT sid FROM dosomething_rogue_signups)
                      ORDER BY signups.sid");
}
else {
  $signups = db_query('SELECT signups.sid, signups.uid, signups.nid, signups.run_nid, signups.source, signups.timestamp, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.updated
                      FROM dosomething_signup signups
                      LEFT JOIN dosomething_reportback rb ON signups.uid = rb.uid AND signups.nid = rb.nid AND signups.run_nid = rb.run_nid
                      WHERE signups.sid NOT IN (SELECT sid FROM dosomething_rogue_signups)
                        AND signups.sid NOT IN (SELECT sid FROM dosomething_rogue_failed_migrations)
                      ORDER BY signups.sid');
}

$client = dosomething_rogue_client();

foreach ($signups as $signup) {
  $data = [];

  echo 'Trying sid ' . $signup->sid . '...' . PHP_EOL;
  echo 'for uid ' . $signup->uid . PHP_EOL;

  $northstar_id = dosomething_user_get_northstar_id($signup->uid);

  // Skip this signup if there is no Northstar ID
  if (is_null($northstar_id)) {
    echo 'No northstar id, that is terrible ' . $signup->sid . PHP_EOL;

    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $signup->sid);

    // Set where we left off so we don't keep trying this one forever
    variable_set('dosomething_rogue_last_signup_kept_up', $signup->sid);

    continue;
  }

  // Match Rogue's timestamp format
  $created_at = date('Y-m-d H:i:s', $signup->timestamp);

  // Format signup data
  $data = [
    'northstar_id' => $northstar_id,
    'campaign_id' => $signup->nid,
    'campaign_run_id' => $signup->run_nid,
    'do_not_forward' => TRUE,
    'source' => $signup->source,
    'created_at' => $created_at,
    'updated_at' => $created_at, // Set updated same as created, will be overwritten if there was a RB submitted
  ];

  // Include all the Reportback data and files if they exist
  if ($signup->rbid) {
    // Pull the quantity and why
    $data['quantity'] = $signup->quantity;
    $data['why_participated'] = $signup->why_participated;

    // Match Rogue's timestamp format
    $updated_at = date('Y-m-d H:i:s', $signup->updated);
    $data['updated_at'] = $updated_at;
  }

  // Send the request to Rogue
  try {
    $response = $client->postSignup($data);

    // Make sure we get a successful response
    if ($response) {
      // Store signup reference
      dosomething_rogue_store_rogue_signup_references($signup->sid, $response);

      echo 'Migrated signup ' . $signup->sid . ' to Rogue.' . PHP_EOL;

      // Send to StatHat
      if (module_exists('stathat')) {
        stathat_send_ez_count('drupal - Rogue - signup migrated - count', 1);
      }
    }
    // Handle getting a 404
    else {
      echo '404' . PHP_EOL;
      // Put request in failed table for future investigation
      dosomething_rogue_handle_migration_failure($data, $signup->sid, $signup->rbid, $fids);
    }
  }
  catch (GuzzleHttp\Exception\ServerException $e) {
    echo 'server exception' . PHP_EOL;

    // These aren't yet caught by Gateway

    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $signup->sid, $signup->rbid, $fids);
  }
  catch (DoSomething\Gateway\Exceptions\ApiException $e) {
    echo 'api exception' . PHP_EOL;

    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $signup->sid, $signup->rbid, $fids);
  }

  // Set where we left off so we don't keep trying this one forever
  variable_set('dosomething_rogue_last_signup_kept_up', $signup->sid);
}

// 2. Quantity and why participated updates with no new file
$last_timestamp = variable_get('dosomething_rogue_last_timestamp_sent', 0);

$postless_updates = db_query("SELECT rblog.rbid, rblog.quantity, rblog.why_participated, rb.nid, rb.run_nid, rb.uid, rblog.timestamp, signup.sid
                              FROM dosomething_reportback_log rblog
                              JOIN dosomething_reportback rb ON rb.rbid = rblog.rbid
                              JOIN dosomething_signup signup ON signup.uid = rb.uid
                                AND signup.nid = rb.nid
                                AND signup.run_nid = rb.run_nid
                              WHERE rblog.timestamp>$last_timestamp
                              AND substring_index(rblog.files, ',',-1) IN (Select fid from dosomething_rogue_reportbacks)");

foreach ($postless_updates as $update) {
  echo 'Trying to update rbid ' . $update->rbid . '...' . PHP_EOL;

  // Get the Northstar ID
  $northstar_id = dosomething_user_get_northstar_id($signup->uid);

  // Skip this post if there is no Northstar user
  if (is_null($northstar_id)) {
    echo 'No northstar id, that is terrible ' . $post->fid . PHP_EOL;

    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $update->sid, $update->rbid, $update->fid);

    // Update the timestamp so we only check for updates after where we left off
    variable_set('dosomething_rogue_last_timestamp_sent', $update->timestamp);

    continue;
  }

  $updated_at = date('Y-m-d H:i:s', $update->timestamp);

  $data = [
    'northstar_id' => $northstar_id,
    'campaign_id' => $update->nid,
    'campaign_run_id' => $update->run_nid,
    'quantity' => $update->quantity,
    'why_participated' => $update->why_participated,
    'do_not_forward' => TRUE,
    'updated_at' => $updated_at,
  ];

  // Try to send the request to Rogue, catch unsuccessful responses
   try {
      $response = $client->postReportback($data);

      // Make sure we get a successful response
      if ($response) {
        echo 'Updated rbid ' . $update->rbid . '...' . PHP_EOL;

        // Send to StatHat
        if (module_exists('stathat')) {
          stathat_send_ez_count('drupal - Rogue - post migrated - count', 1);
        }
      }
      // Handle getting a 404
      else {
        echo '404' . PHP_EOL;

        // Put request in failed table for future investigation
        dosomething_rogue_handle_migration_failure($data, $update->sid, $update->rbid, $update->fid, $response);
      }
    }
    catch (GuzzleHttp\Exception\ServerException $e) {
        echo 'server exception' . PHP_EOL;
      // These aren't yet caught by Gateway

      // Put request in failed table for future investigation
      // @TODO: only put in this table if it's not already there
      dosomething_rogue_handle_migration_failure($data, $update->sid, $update->rbid, $update->fid, $response, $e);
    }
    catch (DoSomething\Gateway\Exceptions\ApiException $e) {
      echo 'api exception' . PHP_EOL;
      // Put request in failed table for future investigation
      dosomething_rogue_handle_migration_failure($data, $update->sid, $update->rbid, $update->fid, $response, $e);
    }

    // Update the timestamp so we only check for updates after where we left off
    variable_set('dosomething_rogue_last_timestamp_sent', $update->timestamp);
}

// 3. Send all new posts
// Get all posts that are not in Rogue, but belong to a signup that IS in Rogue
// Do not include posts that are already in the failed table
$posts = db_query('SELECT rbf.fid, rb.rbid, rb.flagged, rbf.source, rbf.remote_addr, rbf.caption, rbf.status, rb.nid, rb.run_nid, signup.sid, rblog.timestamp, rb.uid, rb.nid, rb.run_nid, rb.quantity, rb.why_participated
                  FROM dosomething_reportback_file rbf
                  LEFT JOIN dosomething_reportback rb ON rbf.rbid = rb.rbid
                  JOIN dosomething_signup signup ON signup.uid = rb.uid
                    AND signup.nid = rb.nid
                    AND signup.run_nid = rb.run_nid
                  JOIN dosomething_reportback_log rblog ON rbf.fid = substring_index(rblog.files, \',\',-1)
                  WHERE rbf.fid NOT IN (SELECT fid FROM dosomething_rogue_reportbacks)
                    AND rbf.fid NOT IN (SELECT fid FROM dosomething_rogue_failed_migrations WHERE fid IS NOT NULL)
                    AND signup.sid IN (SELECT sid from dosomething_rogue_signups)
                  GROUP BY rbf.fid');

// Prepare client to send to Rogue
$client = dosomething_rogue_client();

// Iterate through all the new posts and send them off
foreach ($posts as $post) {
  $data = [];

  echo 'Trying fid ' . $post->fid . ' sid ' . $post->sid . '...' . PHP_EOL;

  // Get the Northstar ID
  $northstar_id = dosomething_user_get_northstar_id($signup->uid);

  if (is_null($northstar_id)) {
    echo 'No northstar id, that is terrible ' . $post->fid . PHP_EOL;

    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $post->sid, $post->rbid, $post->fid);

    continue;
  }

  // Format the Post data to send to Rogue
  // Get the status as a Rogue status
  $rogue_status = dosomething_rogue_transform_status($post->status);

  // Match Rogue's timestamp format
  $photo_created_at = date('Y-m-d H:i:s', $post->timestamp);

  // Format the photo data
  $data = [
    // Post
    'northstar_id' => $northstar_id,
    'campaign_id' => $post->nid,
    'campaign_run_id' => $post->run_nid,
    'caption' => $post->caption,
    'source' => $post->source,
    'remote_addr' => $post->remote_addr,
    'status' => $rogue_status, //can you send this? not in docs
    'do_not_forward' => TRUE,
    'file' => dosomething_helpers_get_data_uri_from_fid($post->fid),
    'created_at' => $photo_created_at,

    // Signup (but /posts will update)
    // @TODO: will this respect timestamps?
    'why_participated' => $post->why_participated,
    'quantity' => $post->quantity,
    'updated_at' => $photo_created_at,
  ];

  // Send to Rogue
  try {
    $response = $client->postReportback($data);

    // Make sure we get a successful response
    if ($response) {
      // Store Post reference
      dosomething_rogue_store_rogue_references($post->rbid, $post->fid, $response);

      // Send to StatHat
      if (module_exists('stathat')) {
        stathat_send_ez_count('drupal - Rogue - post migrated - count', 1);
      }

      echo 'Migrated file ' . $post->fid . ' to Rogue.' . PHP_EOL;
    }
    // Handle getting a 404
    else {
      echo '404' . PHP_EOL;

      // Put request in failed table for future investigation
      dosomething_rogue_handle_migration_failure($data, $post->sid, $post->rbid, $post->fid, $response);
    }
  }
  catch (GuzzleHttp\Exception\ServerException $e) {
      echo 'server exception' . PHP_EOL;

    // These aren't yet caught by Gateway

    // Put request in failed table for future investigation
    // @TODO: only put in this table if it's not already there
    dosomething_rogue_handle_migration_failure($data, $post->sid, $post->rbid, $post->fid, $response, $e);
  }
  catch (DoSomething\Gateway\Exceptions\ApiException $e) {
    echo 'api exception' . PHP_EOL;
    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $post->sid, $post->rbid, $post->fid, $response, $e);
  }
}

// 4. Get fresh reviews and send them over
$last_review_timestamp = variable_get('dosomething_rogue_last_review_sent', 0);

$reviews = db_query("SELECT rbf.fid, rbf.status, rbf.reviewer, rbf.reviewed, rb.rbid, signup.sid
                    FROM dosomething_reportback_file rbf
                    JOIN dosomething_reportback rb ON rb.rbid = rbf.rbid
                    JOIN dosomething_signup signup ON signup.uid = rb.uid
                      AND signup.nid = rb.nid
                      AND signup.run_nid = rb.run_nid
                    WHERE rbf.reviewed>$last_review_timestamp
                      AND rbf.fid IN (Select fid from dosomething_rogue_reportbacks)
                      AND rbf.fid NOT IN (SELECT fid FROM dosomething_rogue_failed_migrations WHERE fid IS NOT NULL)");

foreach ($reviews as $review) {
  echo 'Trying to send review of fid ' . $review->fid . '...' . PHP_EOL;

  // Get admin user Northstar id
  $northstar_id = dosomething_user_get_northstar_id($review->reviewer);

  // Don't send if there is no admin northstar user
  if (is_null($northstar_id)) {
    echo 'No northstar id, that is terrible ' . $review->fid . PHP_EOL;

    // TODO: handle this
    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $review->sid, $review->rbid, $review->fid);

    continue;
  }

  // Convert status to Rogue status
  $rogue_status = dosomething_rogue_transform_status($review->status);

  // Get Rogue post_id
  $rogue_post_id = dosomething_rogue_get_by_file_id($review->fid);

  // Format the data
  $data = [
    'admin_northstar_id' => $northstar_id,
    'status' => $rogue_status,
    'post_id' => $rogue_post_id,
  ];

  // Send to Rogue and handle failure
    // Send to Rogue
  try {
    $response = $client->postReview($data);

    // Make sure we get a successful response
    if ($response) {
      // Update timestamp of last sent
      variable_set('dosomething_rogue_last_review_sent', $review->reviewed);

      // Send to StatHat
      if (module_exists('stathat')) {
        stathat_send_ez_count('drupal - Rogue - review migrated - count', 1);
      }

      echo 'Migrated review of ' . $review->fid . ' to Rogue.' . PHP_EOL;
    }
    // Handle getting a 404
    else {
      echo '404' . PHP_EOL;

      // Put request in failed table for future investigation
      dosomething_rogue_handle_migration_failure($data, $review->sid, $review->rbid, $review->fid, $response);
    }
  }
  catch (GuzzleHttp\Exception\ServerException $e) {
      echo 'server exception' . PHP_EOL;

    // These aren't yet caught by Gateway

    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $review->sid, $review->rbid, $review->fid, $response, $e);
  }
  catch (DoSomething\Gateway\Exceptions\ApiException $e) {
    echo 'api exception' . PHP_EOL;

    // Put request in failed table for future investigation
    dosomething_rogue_handle_migration_failure($data, $review->sid, $review->rbid, $review->fid, $response, $e);
  }
}

// Done for now!
echo 'Nothing else to migrate!' . PHP_EOL;
