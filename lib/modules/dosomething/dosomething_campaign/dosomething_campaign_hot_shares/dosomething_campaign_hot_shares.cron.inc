<?php

/**
 * @file
 * Provides cron job command for dosomething_campaign_hot_shares.module.
 */

/**
 * Implements hook_cron().
 */
function dosomething_campaign_hot_shares_cron() {

  $results = db_query("SELECT n.nid FROM node n
                       INNER JOIN field_data_field_campaign_status s on n.nid = s.entity_id
                       WHERE n.type ='campaign'
                       AND s.field_campaign_status_value = 'active'
             ");

  // Get the relevant paths
  $path = dosomething_helpers_application_path('/lib/modules/dosomething/dosomething_campaign/dosomething_campaign_hot_shares');
  $font_path = dosomething_helpers_application_path('/lib/modules/dosomething/dosomething_campaign/fonts');
  $image_location = dosomething_helpers_application_path('/html/sites/default/files');

  // Each active campaign, call shell script to create problem share images.
  foreach($results as $result) {
    $campaign = Campaign::get($result->nid);
    $node = $campaign->getNodeData();
    $count = dosomething_reportback_get_reportback_total_plus_override($result->nid);
    $goal = dosomething_helpers_get_variable('node', $result->nid, 'goal');
    $time_left = dosomething_campaign_get_hot_time_left($node);

    $nid = escapeshellarg($result->nid);
    $action = escapeshellarg(strtoupper($campaign->reportback_info['noun'] . ' ' . $campaign->reportback_info['verb']));
    $count = escapeshellarg(number_format($count));
    $time_left = escapeshellarg(strtoupper($time_left));
    $goal = !empty($goal) ? escapeshellarg(strtoupper('of ' . number_format($goal))) : '';

    // Call shell script to create the image.
    shell_exec("/bin/bash $path/create-images.sh $font_path $image_location $nid $action $count $time_left $goal");
  }
}
