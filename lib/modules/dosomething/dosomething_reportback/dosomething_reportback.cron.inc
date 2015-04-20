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
  $results = db_query("SELECT n.nid, SUM(rb.quantity) as total
                       FROM node n
                       INNER JOIN field_data_field_campaign_status s on n.nid = s.entity_id
                       INNER JOIN dosomething_reportback rb on n.nid = rb.nid
                       WHERE n.type = 'campaign'
                       AND s.field_campaign_status_value = 'active'
                       GROUP BY n.nid;");

  // Updated reportback counts accordingly.
  foreach ($results as $result) {
    dosomething_helpers_set_variable('node', $result->nid, 'sum_rb_quanity', (int) $result->total);
  }

}
