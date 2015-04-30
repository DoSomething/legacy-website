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
                      GROUP BY nid;");

  // Updated reportback counts accordingly.
  foreach ($results as $result) {
    dosomething_helpers_set_variable('node', $result->nid, 'web_signup_count', $result->total_signups);
  }
}

