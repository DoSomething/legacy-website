<?php


/**
 * @file
 * Provides cron job/drush command for dosomething_campaign_run.module.
 */

/**
 * Implements hook_cron().
 */
function dosomething_campaign_run_cron() {
  $results = db_query("SELECT campaign.entity_id as campaign_nid, campaign.language, current_run.field_current_run_target_id as current_run, current_run.language as current_run_language
                      FROM entity_translation as campaign
                      INNER JOIN node ON node.nid = campaign.entity_id
                      LEFT JOIN field_data_field_current_run as current_run
                        ON campaign.entity_id = current_run.entity_id
                        AND campaign.language = current_run.language
                      WHERE node.type = 'campaign'
                      AND campaign.entity_type = 'node';");
  // Update the campaign status of the campaign node.
  foreach ($results as $result) {
    // Load the current run.
    $run = node_load($result->current_run);
    // Get the start and end dates.
    $start = new DateTime($run->field_run_date[$result->language][0]['value']);
    // The generated runs don't have end dates set, but when runs are created manually,
    // if an end date isn't speficied the start and end dates will be the same.
    // So we emulate this here.
    $end = (!$run->field_run_date[$result->language][0]['value2']) ? $start : new DateTime($run->field_run_date[$result->language][0]['value2']);
    $status = dosomething_helpers_get_campaign_status($start, $end);
    $campaign = entity_metadata_wrapper('node', $result->campaign_nid);
    $campaign->language($result->language)->field_campaign_status = $status;
    $campaign->save();
  }
}
