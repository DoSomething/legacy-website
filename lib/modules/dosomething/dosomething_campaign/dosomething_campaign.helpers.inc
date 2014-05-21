<?php
/**
 * @file
 * Helper functions for dosomething_campaign functionality.
 */

/**
 * Returns variables for campaigns with field_campaign_type.
 *
 * @return array
 *  Array of nids and titles of all published/unpublished staff picks.
 */
function dosomething_campaign_get_sms_games() {
 $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('type', 'campaign');
  $query->innerJoin('field_data_field_campaign_type', 'ct', 'ct.entity_id = n.nid');
  $query->condition('field_campaign_type_value' , 'sms_game');
  $results = $query->execute();

  foreach($results as $key => $result) {
    $sms_games[$key]['nid'] = $result->nid;
    $sms_games[$key]['title'] = $result->title;
  }
  if ($sms_games) {
    return $sms_games;
  }
  // If no SMS Games, return null.
  return NULL;
}
