<?php

/*
 * Script to import signup data from old world into new world.
 *
 * to run:
 * grab the latest signup data from production.
 *  SELECT uid, nid, timestamp, data from dosomething_campaign_signups
 *  WHERE nid = 731234
 *  OR nid = 731098;
 *
 * Insert data into temporary table '_signups_old_world'.
 * drush --script-path=../scripts/ php-script import-signups.php
 *
 */

// Mind on my Money = 731098 = 850
// PB Jam Slam = 731234 = 955
define('MONEY_OLD', 731098);
define('MONEY', 850);
define('PBJ_OLD', 731234);
define('PBJ', 955);

$signups = '_signups_old_world';


$result = db_query('SELECT * FROM {' . $signups . '}');


foreach ($result as $signup) {
  if ($signup->nid == MONEY_OLD) {
    $nid = MONEY;
  }
  else if ($signup->nid = PBJ_OLD) {
    $nid = PBJ;
  }
  dosomething_signup_create($nid, $signup->uid, NULL, $signup->timestamp);
}
