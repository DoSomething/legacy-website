<?php
/**
 * @file
 * Helper functions for dosomething_campaign functionality.
 */

/**
 * Returns a scaled down version of a campaign loaded $node.
 *
 * @return object
 *   Available properties:
 *
 *   - nid: (int)
 *   - title: (string)
 *   - status (string). 'active' | 'closed'
 *   - type (string). 'campaign' | 'sms_game'
 *
 *   - call_to_action (string). Plain text.
 *   - time_and_place (string). HTML.
 *   - vips (string). HTML.
 *
 */
function dosomething_campaign_load($node) {
  if ($node->type != 'campaign') { return FALSE; }

  // Load the entity metadata wrapper for easy value getting.
  $wrapper = entity_metadata_wrapper('node', $node);

  $campaign = new stdClass();
  $campaign->nid = $node->nid;
  $campaign->title = $node->title;
  $campaign->status = dosomething_campaign_get_campaign_status($node);
  $campaign->type = dosomething_campaign_get_campaign_type($node);

  // Plain text fields.
  $plain_text = array(
    'call_to_action',
    'solution_support',
    'starter_statement_header',
  );
  foreach ($plain_text as $property) {
    $field_name = 'field_' . $property;
    $campaign->{$property} = $wrapper->{$field_name}->value();
  }

  // Filtered text fields.
  $filtered_text = array(
    'items_needed',
    'promoting_tips',
    'solution_copy',
    'starter_statement',
    'time_and_place',
    'vips',
  );
  foreach ($filtered_text as $property) {
    $field_name = 'field_' . $property;
    if ($value = $wrapper->{$field_name}->value()) {
      // Store filtered text.
      $campaign->{$property} = $value['safe_value'];
    }
  }

  // Taxonomy fields.
  $campaign->primary_cause = NULL;
  if ($primary_cause = $wrapper->field_primary_cause->value()) {
    $campaign->primary_cause['tid'] = $primary_cause->tid;
    $campaign->primary_cause['name'] = $primary_cause->name;
  }

  // Fact fields.
  $campaign->fact_problem = NULL;
  $campaign->fact_solution = NULL;
  $campaign->fact_sources = NULL;
  // Collect multiple fact fields values as fact and sources variables.
  $fact_fields = array('field_fact_problem', 'field_fact_solution');
  $fact_vars = dosomething_fact_get_mutiple_fact_field_vars($wrapper->nid->value(), $fact_fields);
  if (!empty($fact_vars)) {
    if (isset($fact_vars['facts']['field_fact_problem'])) {
      $campaign->fact_problem = $fact_vars['facts']['field_fact_problem'];
    }
    if (isset($fact_vars['facts']['field_fact_solution'])) {
      $campaign->fact_solution = $fact_vars['facts']['field_fact_solution'];
    }
    // Store all sources from fields as a sources array.
    $campaign->fact_sources  = $fact_vars['sources'];
  }

  return $campaign;
}

/**
 * Returns a loaded campaign $node's field_campaign_type value.
 *
 * @param object $node
 *   A loaded campaign node.
 *
 * @return mixed
 *   If node type == campaign, returns string value of field_campaign_type.
 *     - Defaults to 'campaign' if value is not set.
 *   Else returns FALSE.
 */
function dosomething_campaign_get_campaign_type($node) {
  // Sanity check to make sure this is a campaign.
  if ($node->type != 'campaign') { return FALSE; }

  // Return campaign by default if no value is set.
  if (!isset($node->field_campaign_type[LANGUAGE_NONE][0]['value'])) {
    return 'campaign';
  }
  return $node->field_campaign_type[LANGUAGE_NONE][0]['value'];
}

/**
 * Returns a loaded campaign $node's field_campaign_status value.
 *
 * @param object $node
 *   A loaded campaign node.
 *
 * @return mixed
 *   If node type == campaign, returns string value of field_campaign_status.
 *     - Defaults to 'active' if value is not set.
 *   Else returns FALSE.
 */
function dosomething_campaign_get_campaign_status($node) {
  // Sanity check to make sure this is a campaign.
  if ($node->type != 'campaign') { return FALSE; }

  // Return active by default if no value is set.
  if (!isset($node->field_campaign_status[LANGUAGE_NONE][0]['value'])) {
    return 'active';
  }
  return $node->field_campaign_status[LANGUAGE_NONE][0]['value'];
}

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
