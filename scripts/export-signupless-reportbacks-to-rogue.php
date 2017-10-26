<?php
/**
 * Script to export Reportbacks that do not have a corresponding Signup from drupal into Rogue.
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-signupless-reportbacks-to-rogue.php
 */

// Get all the signupless reportbacks
$reportbacks = db_query("SELECT rb.rbid, rb.nid, rb.run_nid, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.uid, rb.created
  FROM dosomething.dosomething_reportback rb
  LEFT JOIN dosomething.dosomething_signup ds on rb.uid = ds.uid AND rb.run_nid = ds.run_nid
  WHERE ds.sid IS NULL
  AND rb.rbid NOT IN (SELECT rbid from dosomething_rogue_reportbacks)");

$client = dosomething_rogue_client();

if (!$reportbacks) {
  echo 'Nothing to migrate!';
}

// For each reportback, send a request for each reportback file to POST /posts and Rogue will automatically create the signup
foreach ($reportbacks as $reportback) {
  echo 'On rbid ' . $reportback->rbid . '...' . PHP_EOL;
  $sent_at = date('Y-m-d H:i:s');

  // Try to get Northstar ID
  $northstar_id = dosomething_user_get_northstar_id($reportback->uid, 'drupal_id');

  if (!$northstar_id) {
    echo "\t" . 'No northstar id, that is terrible ' . $reportback->rbid . PHP_EOL;

    continue;
  }

  // Get reportback files
  $photos = db_query('SELECT rbf.fid, rbf.remote_addr, rbf.caption, rbf.status, rbf.reviewed, rbf.reviewer, rbf.source, rbf.status, rblog.timestamp
                          FROM dosomething_reportback_file rbf
                          INNER JOIN dosomething_reportback_log rblog ON rbf.fid = substring_index(rblog.files, \',\',-1)
                          WHERE rbf.rbid = '. $reportback->rbid . '
                          AND rbf.fid NOT IN (SELECT fid from dosomething_rogue_reportbacks)
                          GROUP BY rbf.fid')->fetchAll();

  // Just send a signup if there are no photos (there are about 25 of these)
  if (!$photos) {
    echo "\t" . 'Reportback ' . $reportback->rbid . ' has no files, sending just a signup' . PHP_EOL;

    // Match Rogue's timestamp format
    $rb_created_at = date('Y-m-d H:i:s', $reportback->timestamp);

    $data = [
      'northstar_id' => $northstar_id,
      'campaign_id' => $reportback->nid,
      'campaign_run_id' => $reportback->run_nid,
      'created_at' => $rb_created_at,
      'updated_at' => $sent_at,
      'quantity' => $reportback->quantity,
      'why_participated' => $reportback->why_participated,
      'dont_send_to_blink' => true,
    ];

    try {
      // We do not need to worry about keeping track of these because sening them to Rogue multiple times will not create multiple signups
      $response = $client->postSignup($data);

      if ($response) {
        echo "\t\t" . 'Migrated data on reportback ' . $reportback->rbid . ' to Rogue.' . PHP_EOL;
        echo "\t\t\t" . 'Rogue Signup ID: ' . $response['data']['signup_id'] . PHP_EOL;
      }

      // Handle getting a 404
      if (!$response) {
        echo '***ERROR: 404 on reportback ' . $reportback->rbid . PHP_EOL;
      }
    }
    catch (GuzzleHttp\Exception\ServerException $e) {
      // These aren't yet caught by Gateway
      echo '***ERROR: SERVER EXCEPTION on reportback ' . $reportback->rbid . PHP_EOL;
    }
    catch (DoSomething\Gateway\Exceptions\ApiException $e) {
      echo '***ERROR: API EXCEPTION on reportback ' . $reportback->rbid . PHP_EOL;
    }

    continue;
  }

  foreach ($photos as $photo) {
    $data = [];

    echo "\t" . 'Trying fid ' . $photo->fid . '...' . PHP_EOL;

    // Match Rogue's timestamp format
    $photo_created_at = date('Y-m-d H:i:s', $photo->timestamp);

    // We want to print this out so we can tell the data team when to start looking
    echo "\t\t" . 'Sending at approximately ' . $sent_at . PHP_EOL;

    $data = [
      'northstar_id' => $northstar_id,
      'campaign_id' => $reportback->nid,
      'campaign_run_id' => $reportback->run_nid,
      'created_at' => $photo_created_at,
      'updated_at' => $sent_at,
      'quantity' => $reportback->quantity,
      'why_participated' => $reportback->why_participated,
      'caption' => $photo->caption,
      'status' => dosomething_rogue_transform_status($photo->status),
      // This will also be the signup source
      'source' => $photo->source,
      'remote_addr' => $photo->remote_addr,
      'file' => dosomething_helpers_get_data_uri_from_fid($photo->fid),
      'dont_send_to_blink' => true,
    ];

    // Send the request to Rogue
    try {
      $response = $client->postPost($data);
      // Make sure we get a successful response
      if ($response) {
        echo "\t\t" . 'Migrated reportback ' . $reportback->rbid . ' file ' . $photo->fid . ' to Rogue.' . PHP_EOL;
        echo "\t\t\t" . 'Rogue Signup ID: ' . $response['data']['signup_id'] . PHP_EOL;
        echo "\t\t\t" . 'Rogue Post ID: ' . $response['data']['id'] . PHP_EOL;


        // Store reference to reportback so we don't try to send repeats upon further runs of the script
        db_insert('dosomething_rogue_reportbacks')
              ->fields([
                'fid' => $photo->fid,
                'rogue_post_id' => $response['data']['id'],
                'rbid' => $reportback->rbid,
                'rogue_signup_id' => $response['data']['signup_id'],
                'created_at' => REQUEST_TIME,
                ])
              ->execute();

      }
      // Handle getting a 404
      if (!$response) {
        echo '***ERROR: 404 on reportback ' . $reportback->rbid . ' file ' . $photo->fid . PHP_EOL;
      }
    }
    catch (GuzzleHttp\Exception\ServerException $e) {
      // These aren't yet caught by Gateway
      echo '***ERROR: SERVER EXCEPTION on reportback ' . $reportback->rbid . ' file ' . $photo->fid . ' to Rogue.' . PHP_EOL;
    }
    catch (DoSomething\Gateway\Exceptions\ApiException $e) {
      echo '***ERROR: API EXCEPTION on reportback ' . $reportback->rbid . ' file ' . $photo->fid . ' to Rogue.' . PHP_EOL;
    }
  }
}

echo 'All finished!' . PHP_EOL;
