<?php

/**
 *  Implements hook_drush_command
 */
function dosomething_reportback_drush_command() {
  return [
    'ds-reportback-run-nid-fix' => [
      'description' => 'Gives every reportback a run nid',
      'examples' => [
        'drush ds-reportback-run-nid-fix'
          => 'Gives every reportback a run nid',
      ],
    ],
    'batch-exclude-reportbacks' => [
      'description' => 'Bulk exclude reportbacks to clear campaign inboxes',
      'arguments' => [
        'nid' => 'Campaign node id',
        'run_nid' => 'Campaign run node id',
        'quantity_limit' => 'Threshold for exclusion - reportback quantity will be less than this number'
      ],
      'examples' => [
        'drush batch-exclude-reportbacks 1173 1816 200'
          => 'Excludes all reportbacks for campaign node 1173, campaign run 1816, with the reportback quantity under 200',
      ],
    ],
  ];
}

/**
 * Implements hook_drush_cache_clear().
 */
function dosomething_reportback_drush_cache_clear(&$types) {
  $types['dosomething reportback'] = 'dosomething_reportback_cache_clear_all';
}

/**
 * Callback for ds-reportback-run-nid-fix command.
 */
function drush_dosomething_reportback_ds_reportback_run_nid_fix() {
  // First retrieve every campaign NID
  $nids = db_query("SELECT n.nid as nid
                    FROM node n
                    WHERE n.type = 'campaign'");

  // Loop through every NID
  foreach ($nids as $key => $nid) {
    print_r("NID: " . $nid->nid . ", " . $key . " out of " . $nids->rowCount() . "\n");

    // Get the runs for associated for this campaign & the timing
    $runs = db_query("SELECT DISTINCT c.entity_id as run_nid, d.field_run_date_value as start_date, d.field_run_date_value2 as end_date
                      FROM field_data_field_campaigns c
                      INNER JOIN field_data_field_run_date d ON d.entity_id = c.entity_id AND d.language = 'en'
                      WHERE c.bundle = 'campaign_run'
                      AND c.language = 'en'
                      AND c.field_campaigns_target_id = $nid->nid
                      ORDER BY d.field_run_date_value2 ASC");

    // Loop through each run
    foreach($runs as $run) {

      // The query & logic applied is different depending on whether the end date exists.
      // If the end date does exist we use a query with BETWEEN logic applied
      if (isset($run->end_date) && $run->start_date != $run->end_date) {
        $date = new DateTime($run->end_date);
        $date->setTime(23, 59, 59);
        $run->end_date = $date->format('Y-m-d H:i:s');

        // Get every reportback that has a null or 0 run nid thats within this run's timeframe
        $results = db_query("SELECT n.nid, rb.rbid
                             FROM node n
                             INNER JOIN dosomething_reportback rb
                                ON rb.nid = n.nid
                                AND (rb.run_nid = 0 OR rb.run_nid IS NULL)
                                AND from_unixtime(rb.created) BETWEEN '$run->start_date' AND '$run->end_date'
                             AND n.nid = $nid->nid");

        // For reach reportback returned
        foreach($results as $result) {
          // Load the reportback and change its run nid to the corresponding
          // one we've now discovered.
          $rb = reportback_load($result->rbid);
          $rb->run_nid = $run->run_nid;
          try {
            entity_save('reportback', $rb);
          }
          catch (Exception $e) {
            watchdog('dosomething_reportback', $e->getMessage(), array($result->rbid));
          }
        }
      }
      // IF the end date doesnt exist we apply this logic to every reportback
      else {
        $results = db_query("SELECT n.nid, rb.rbid
                             FROM node n
                             INNER JOIN dosomething_reportback rb
                                ON rb.nid = n.nid
                                AND (rb.run_nid = 0 OR rb.run_nid IS NULL)
                             AND n.nid = $nid->nid");

        // For reach reportback returned
        foreach($results as $result) {
          // Load the reportback and change its run nid to the corresponding
          // one we've now discovered.
          $rb = reportback_load($result->rbid);
          $rb->run_nid = $run->run_nid;
          try {
            entity_save('reportback', $rb);
          }
          catch (Exception $e) {
            watchdog('dosomething_reportback', $e->getMessage(), array($result->rbid));
          }
        }
      }
    }
  }
  print_r("All reportbacks updated \n");
}

/**
 * Callback for batch-exclude-reportbacks command.
 */
function drush_dosomething_reportback_batch_exclude_reportbacks($nid, $run_nid, $quantity_limit) {
    if (node_load($nid) && node_load($run_nid)) {
      // Find all the fids that should be marked as excluded, based on params passed through. 
      $fids_to_be_marked_as_excluded = db_query("SELECT rb.rbid, rb.nid, rb.run_nid, rb.quantity, rbf.status, rbf.fid, rbf.rbid
                                                 FROM dosomething_reportback rb
                                                 JOIN dosomething_reportback_file rbf on rb.rbid = rbf.rbid
                                                 WHERE rb.nid = :nid AND rb.run_nid = :run_nid AND rb.quantity < :quantity_limit AND rbf.status = 'pending'",
                                                 array(
                                                  ':nid' => $nid,
                                                  ':run_nid' => $run_nid,
                                                  ':quantity_limit' => $quantity_limit,
                                                 ));

      // Change fids status to excluded 
      foreach ($fids_to_be_marked_as_excluded as $fid) {
        dosomething_reportback_mark_reportback_as_excluded($fid);
      }
    } 
    else {
      drush_set_error('Invalid nid and/or run_nid.');
    }
}
