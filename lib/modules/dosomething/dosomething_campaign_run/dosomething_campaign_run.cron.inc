<?php


/**
 * @file
 * Provides cron job/drush command for dosomething_campaign_run.module.
 */

/**
 * Implements hook_cron().
 */
function dosomething_campaign_run_cron() {
  // Get all campaign runs and the start and end date for each translation of the run date field.
  $results = db_query("SELECT campaign_run.entity_id as campaign_run_nid,
                              run_date.field_run_date_value as start_date,
                              run_date.field_run_date_value2 as end_date,
                              run_date.language,
                              campaigns.field_campaigns_target_id as campaign_nid
                       FROM entity_translation as campaign_run
                       INNER JOIN field_data_field_run_date as run_date
                          ON campaign_run.entity_id = run_date.entity_id
                          AND campaign_run.language = run_date.language
                       INNER JOIN field_data_field_campaigns as campaigns
                          ON campaign_run.entity_id = campaigns.entity_id
                          AND campaigns.language = run_date.language;");

  // Update the campaign status of the campaign node.
  foreach ($results as $result) {
    $start = new DateTime($result->start_date);
    $end = new DateTime($result->end_date);
    $status = dosomething_helpers_get_campaign_status($start, $end);
    $campaign = entity_metadata_wrapper('node', $result->campaign_nid);
    $campaign->language($result->language)->field_campaign_status = $status;
    $campaign->save();
  }
}
