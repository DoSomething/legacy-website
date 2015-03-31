<?php

/**
 * @file
 * Provides cron job/drush command for dosomething_reportback.module.
 */

/**
 * Implements hook_cron().
 */
function dosomething_reportback_cron() {
  // Get all reportbacks updated in the past hour.
  $results = db_query("SELECT nid, sum(quantity) as quantity
                     FROM dosomething_reportback
                     WHERE from_unixtime(updated) >= date_add(now(), INTERVAL '-1' hour)
                     GROUP BY nid;");

  // Updated reportback counts accordingly.
  foreach ($results as $result) {
    $previous_progress = dosomething_helpers_get_variable('node', $result->nid, 'sum_rb_quanity');
    $updated_progress = (int) $previous_progress + (int) $result->quantity;
    dosomething_helpers_set_variable('node', $result->nid, 'sum_rb_quanity', $updated_progress);
  }

}
