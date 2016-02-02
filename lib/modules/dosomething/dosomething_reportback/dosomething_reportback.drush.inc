<?php

/**
 * Implements hook_drush_cache_clear().
 */
function dosomething_reportback_drush_cache_clear(&$types) {
  $types['dosomething reportback'] = 'dosomething_reportback_cache_clear_all';
}

function dosomething_reportback_drush_run_nid_fix(&$types) {
  // First retrieve every campaign NID
  $nids = db_query("SELECT n.nid as nid
                    FROM node n
                    WHERE n.type = 'campaign'");

  // Loop through every NID
  foreach ($nids as $nid) {

    // Get the runs for associated for this campaign & the timing
    $runs = db_query("SELECT DISTINCT c.entity_id as run_nid, d.field_run_date_value as start_date, d.field_run_date_value2 as end_date
                      FROM field_data_field_campaigns c
                      INNER JOIN field_data_field_run_date d ON d.entity_id = c.entity_id
                      WHERE c.bundle = 'campaign_run'
                      AND c.field_campaigns_target_id =" . $nid->nid ."
                      ORDER BY d.field_run_date_value2 ASC");

    // Loop through each run
    foreach($runs as $run) {

      // The query & logic applied is different depending on whether the end date exists.
      // If the end date does exist we use a query with BETWEEN logic applied
      if (isset($run->end_date)) {

        // Get every reportback that has a null or 0 run nid thats within this run's timeframe
        $results = db_query("SELECT n.nid, rb.rbid
                             FROM node n
                             INNER JOIN node run ON run.nid = $run->run_nid
                             INNER JOIN dosomething_reportback rb
                                ON rb.nid = n.nid
                                AND (rb.run_nid = 0 OR rb.run_nid IS NULL)
                                AND from_unixtime(rb.created) BETWEEN '" . $run->start_date . "' AND '" . $run->end_date . "'
                             AND n.nid = " . $nid->nid);

        // For reach reportback returned
        foreach($results as $result) {
          // Load the reportback and change its run nid to the corresponding
          // one we've now discovered.
          $rb = reportback_load($result->rbid);
          $rb->run_nid = $run->run_nid;
          entity_save('reportback', $rb);
        }
      }
      // IF the end date doesnt exist we apply this logic to every reportback
      else {
        $results = db_query("SELECT n.nid, rb.rbid
                             FROM node n
                             INNER JOIN node run ON run.nid = $run->run_nid
                             INNER JOIN dosomething_reportback rb
                                ON rb.nid = n.nid
                                AND (rb.run_nid = 0 OR rb.run_nid IS NULL)
                             AND n.nid = " . $nid->nid);

        // For reach reportback returned
        foreach($results as $result) {
          // Load the reportback and change its run nid to the corresponding
          // one we've now discovered.
          $rb = reportback_load($result->rbid);
          $rb->run_nid = $run->run_nid;
          entity_save('reportback', $rb);
        }
      }
    }
  }
}
