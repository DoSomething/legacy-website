<?php
/**
 * Script to export reportbacks from drupal into Rogue.
 *
 * to run:
 * drush --script-path=../scripts/ php-script export-reportbacks-to-rogue.php
 */

include_once('../lib/modules/dosomething/dosomething_rogue/dosomething_rogue.module');

$last_saved = variable_get('dosomething_rogue_last_rbi_migrated', NULL);
if ($last_saved) {
  $rbis = db_query("SELECT *
            FROM dosomething_reportback_file rbf
            WHERE rbf.fid > $last_saved
            ORDER BY rbf.fid");
}
else {
  // Get all the users!
  $rbis = db_query('SELECT *
                   FROM dosomething_reportback_file rbf
                   ORDER BY rbf.fid');
}

  $client = dosomething_rogue_client();
  echo 'Client ' . $client;

foreach ($rbis as $rbi) {
  // Get the reportback item and info

  // Get the reportback continer info

  // Transform Reviewer to NS id
  // Transform user to NS id
  // Transform status to the rogue status

  echo $rbi->fid . "\n";

  // $response = $client->postReportback($data);

  // Output progress to stdout so we can see our good work.


  // Save any failed requests to the request log for debugging.


  // Store the info in dosomething_rogue_reportbacks.

  // If the script fails, we can use this to start the script from a previous person.
  // variable_set('dosomething_rogue_last_rbi_migrated', $user->uid);
}
