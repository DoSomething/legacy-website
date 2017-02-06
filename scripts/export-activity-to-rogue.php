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

// Get ALL the things!
if ($last_saved) {
  $signups = db_query("SELECT signups.sid, signups.uid, signups.nid, signups.run_nid, signups.source, signups.timestamp, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.updated, rbf.fid, rbf.remote_addr, rbf.caption, rbf.status, rbf.reviewed, rbf.reviewer, rbf.source
                      FROM dosomething_signup signups
                      LEFT JOIN dosomething_reportback rb ON signups.uid = rb.uid AND signups.nid = rb.nid AND signups.run_nid = rb.run_nid
                      LEFT JOIN dosomething_reportback_file rbf on rbf.rbid = rb.rbid
                      ORDER BY signups.sid
                      LIMIT 30");
}
else {
  // Get all the things!
  $signups = db_query('SELECT signups.sid, signups.uid, signups.nid, signups.run_nid, signups.source, signups.timestamp, rb.quantity, rb.why_participated, rb.rbid, rb.flagged, rb.updated, rbf.fid, rbf.remote_addr, rbf.caption, rbf.status, rbf.reviewed, rbf.reviewer, rbf.source
                      FROM dosomething_signup signups
                      LEFT JOIN dosomething_reportback rb ON signups.uid = rb.uid AND signups.nid = rb.nid AND signups.run_nid = rb.run_nid
                      LEFT JOIN dosomething_reportback_file rbf on rbf.rbid = rb.rbid
                      ORDER BY signups.sid
                      LIMIT 30')->fetchAll();
}

// $client = dosomething_rogue_client();
$current_sid = 0;

foreach ($signups as $signup) {
  echo 'Trying sid ' . $signup->sid . ' and fid ' . $signup->fid . '...' . PHP_EOL;
  
  // If we have already started this signup, just add the new photo (all other data is already taken care of)
  if ($signup->sid == $current_sid) {
    // Increment the item counter
    $photo = $photo + 1;

    // Add the current item
    $data['photo'][$photo] = [
      'source' => $signup->source,
      'remote_addr' => $signup->remote_addr,
      'caption' => $signup->caption,
      'event_type' => 'post_photo',
      'northstar_id' => $northstar_id->id,
      'do_not_forward' => TRUE,
      'file' => dosomething_helpers_get_data_uri_from_fid($signup->fid),
    ];
  }
  else {
    // @TODO:
    // 1. send the current request to Rogue
    // for now I am just printing out the requests to see if they look okay before flooding crap data to my local Rogue
      echo 'Request for sid ' . $current_sid . PHP_EOL;
      echo json_encode($data) . PHP_EOL;
    // 2. wipe the current request
      $data = '';

    // 3. create new request
      $northstar_id = dosomething_northstar_get_user($signup->uid, 'drupal_id');

      // Only try to send to Rogue if we have a Northstar ID
      if (isset($northstar_id)) {
        // Format data as Rogue expects
        $data = [
          // signup
          'northstar_id' => $northstar_id->id,
          'campaign_id' => $signup->nid,
          'campaign_run_id' => $signup->run_nid,
          'do_not_forward' => TRUE,
          // @TODO: add timestamps
          'created_at' => $signups->timestamp,
          'updated_at' => $signups->updated,
        ];

        // Add the first photo (if there is one)
        if ($signup->fid) {
          $data['quantity'] = $signup->quantity;
          $data['why_participated'] = $signup->why_participated;

          // Item counter
          $photo = 0;

          // Add the current item
          $data['photo'][$photo] = [
            'source' => $signup->source,
            'remote_addr' => $signup->remote_addr,
            'caption' => $signup->caption,
            'event_type' => 'post_photo',
            'northstar_id' => $northstar_id->id,
            'do_not_forward' => TRUE,
            'file' => dosomething_helpers_get_data_uri_from_fid($signup->fid),
          ];
        }
      }
      else {
        echo 'No northstar id, that is terrible ' . $rb->uid . PHP_EOL;
      }

    // 4. set $current_sid to $signup->sid
      $current_sid = $signup->sid;
  }
}
