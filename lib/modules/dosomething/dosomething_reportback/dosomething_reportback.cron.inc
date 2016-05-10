<?php

/**
 * @file
 * Provides cron job/drush command for dosomething_reportback.module.
 */

/**
 * Implements hook_cron().
 */
function dosomething_reportback_cron() {
  // Query for the total quantity for all active campaigns, for the current run
  $results = db_query("SELECT n.nid, SUM(rb.quantity) as total, run.field_current_run_target_id as run_nid
                       FROM node n
                       INNER JOIN field_data_field_campaign_status s on n.nid = s.entity_id AND n.language = s.language
                       INNER JOIN dosomething_reportback rb on n.nid = rb.nid
                       INNER JOIN field_data_field_current_run run on n.nid = run.entity_id
                       WHERE n.type = 'campaign'
                       AND s.field_campaign_status_value = 'active'
                       AND rb.flagged = 0
                       AND rb.run_nid = run.field_current_run_target_id
                       GROUP BY n.nid;");

  // Query for the total quantity for all active campaigns, for all the runs
  $results = db_query("SELECT n.nid, SUM(rb.quantity) as total
                       FROM node n
                       INNER JOIN field_data_field_campaign_status s on n.nid = s.entity_id AND n.language = s.language
                       INNER JOIN dosomething_reportback rb on n.nid = rb.nid
                       WHERE n.type = 'campaign'
                       AND s.field_campaign_status_value = 'active'
                       AND rb.flagged = 0
                       GROUP BY n.nid;");

  // Updated reportback counts accordingly.
  foreach ($results as $result) {
    dosomething_helpers_set_variable('node', $result->nid, 'sum_rb_all_quantity', (int) $result->total);
  }
}
