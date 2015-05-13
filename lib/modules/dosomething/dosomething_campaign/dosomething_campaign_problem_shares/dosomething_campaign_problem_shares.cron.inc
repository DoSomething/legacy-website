<?php

/**
 * @file
 * Provides cron job command for dosomething_campaign_problem_shares.module.
 */

/**
 * Implements hook_cron().
 */
function dosomething_campaign_problem_shares_cron() {
  $results = db_query("SELECT n.nid, fn.title as problem
                       FROM node n
                       INNER JOIN field_data_field_fact_problem fp on n.nid = fp.entity_id
                       INNER JOIN node fn on fp.field_fact_problem_target_id = fn.nid
                       INNER JOIN field_data_field_campaign_status s on n.nid = s.entity_id
                       WHERE n.type ='campaign'
                       AND s.field_campaign_status_value = 'active'
                       GROUP BY n.nid;");
  // Each active campaign, call shell script to create problem share images.
  foreach($results as $result) {
    $problem = $result->problem;
    if (strpos($result->problem, '%') !== 0) {
      // Add another percent sign because of silly imagemagick rules.
      $problem = str_replace('%', '%%', $problem);
    }
    $nid = escapeshellarg($result->nid);
    $problem = escapeshellarg($problem);
    // Call shell script to create the image.
    shell_exec("/bin/bash /var/www/dev.dosomething.org/lib/modules/dosomething/dosomething_campaign/dosomething_campaign_problem_shares/create-images.sh $nid $problem");
  }

}
