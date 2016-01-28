<?php
/*
 * Script to remove duplicate rows in the dosomething_signup table with null or zero values
 * in the run_nid col.
 *
 * drush --script-path=../scripts/ php-script remove-null-zero-duplicate-signups.php
 *
 */

$duplicates = db_query("SELECT s.uid, s.nid, group_concat(s.sid) as sids, group_concat(ifnull(s.run_nid, 0)) as run_nids, COUNT(*) c
                        FROM dosomething_signup s
                        GROUP BY s.uid, s.nid
                        HAVING c > 1
                        ORDER BY s.nid;");

foreach ($duplicates as $duplicate) {
  $sids = explode(',', $duplicate->sids);
  $run_nids = explode(',', $duplicate->run_nids);
  foreach ($sids as $key => $sid) {
    if ($run_nids[$key] == 0) {
      // Remove that row.
      db_delete('dosomething_signup')->condition('sid', $sid)->execute();
      echo "removed row: " . $sid . "\n";
    }
  }
}
