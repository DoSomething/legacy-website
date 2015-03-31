<?php


/**
 * @file
 * Provides cron job/drush command for dosomething_signup.module.
 */

/**
 * Implements hook_cron().
 */
function dosomething_signup_cron() {
  // Get all reportbacks updated in the past hour.
  $results = db_query("SELECT nid, count(nid) as total_signups
                      FROM dosomething_signup
                      WHERE from_unixtime(timestamp) >= date_add(now(), INTERVAL '-1' hour)
                      GROUP BY nid;");

  // Updated reportback counts accordingly.
  foreach ($results as $result) {
    $previous_signups = dosomething_helpers_get_variable('node', $result->nid, 'signup_count');
    $updated_signups = (int) $previous_signups + (int) $result->total_signups;
    dosomething_helpers_set_variable('node', $result->nid, 'signup_count', $updated_signups);
  }
}

