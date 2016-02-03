<?php

/**
 *  Implements hook_drush_command
 */
function dosomething_signup_drush_command() {
  return [
    'ds-signup-run-nid-fix' => [
      'description' => 'Gives every signup a run nid',
      'examples' => [
        'drush ds-signup-run-nid-fix'
          => 'Gives every signup a run nid',
      ],
    ],
  ];
}

/**
 * Callback for ds-signup-run-nid-fix command.
 */
function drush_dosomething_signup_ds_signup_run_nid_fix() {
  // First retrieve every campaign NID
  $nids = db_query("SELECT n.nid as nid
                    FROM node n
                    WHERE n.type = 'campaign'");

  // Loop through every NID
  $index = 0;
  foreach ($nids as $nid) {
    print_r($index . "\n");

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
      if (isset($run->end_date)) {

        // Get every signup that has a null or 0 run nid thats within this run's timeframe
        $results = db_query("SELECT n.nid, s.sid
                             FROM node n
                             INNER JOIN dosomething_signup s
                                ON s.nid = n.nid
                                AND (s.run_nid = 0 OR s.run_nid IS NULL)
                                AND from_unixtime(s.timestamp) BETWEEN '$run->start_date' AND '$run->end_date'
                             AND n.nid = $nid->nid");

        // For reach signup returned
        foreach($results as $result) {
          // Load the signup and change its run nid to the corresponding
          // one we've now discovered.
          $s = signup_load($result->sid);
          $s->run_nid = $run->run_nid;
          entity_save('signup', $s);
        }
      }
      // IF the end date doesnt exist we apply this logic to every signup
      else {
        $results = db_query("SELECT n.nid, s.sid
                             FROM node n
                             INNER JOIN dosomething_signup s
                                ON s.nid = n.nid
                                AND (s.run_nid = 0 OR s.run_nid IS NULL)
                             AND n.nid = $nid->nid");

        // For reach signup returned
        foreach($results as $result) {
          // Load the signup and change its run nid to the corresponding
          // one we've now discovered.
          $s = signup_load($result->sid);
          $s->run_nid = $run->run_nid;
          entity_save('signup', $s);
        }
      }
    }
    $index++;
  }
  print_r("All signups updated \n");
}
