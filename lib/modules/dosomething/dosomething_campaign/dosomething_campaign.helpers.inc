<?php
/**
 * @file
 * Helper functions for dosomething_campaign functionality.
 */

/**
 * Returns a scaled down version of a campaign loaded $node.
 *
 * @param obj $node
 *   A loaded Node object.
 * @param bool $public
 *   If TRUE, do not return non-content attributes, e.g. variables.
 *
 * @return obj
 *   Available properties:
 *
 *   - nid: (int)
 *   - title: (string)
 *   - status (string). 'active' | 'closed'
 *   - type (string). 'campaign' | 'sms_game'
 *
 *   - call_to_action (string). Plain text.
 *   - fact_problem (array)
 *       - fact (string) HTML.
 *   - fact_solution (array)
 *       - fact (string) HTML.
 *   - fact_sources (array)
 *        Contains composite sources of fact_problem and fact_solution.
 *   - faq (array). Multidimensional - each element is an array which contains:
 *       - header (string) Plain text.
 *       - copy (string) HTML.
 *   - high_season_end (string). Date string.
 *   - high_season_start (string). Date string.
 *   - image_cover (array). The field_image_campaign_cover value.
 *     - nid (int)
 *     - is_dark_image (bool)
 *     - src (string)
 *   - image_header (array). Usually the image_cover, but can be overridden.
 *     - nid (int)
 *     - is_dark_image (bool)
 *     - src (string)
 *   - is_staff_pick (bool)
 *   - items_needed (string). HTML.
 *   - low_season_end (string). Date string.
 *   - low_season_start (string). Date string.
 *   - primary_cause (array)
 *       - tid (int)
 *       - name (string)
 *   - promoting_tips (string). HTML.
 *   - solution_copy (string). HTML.
 *   - solution_support (string). Plain text.
 *   - step_pre (array). Multidimensional - each element is an array which contains:
 *       - header (string) Plain text.
 *       - copy (string) HTML.
 *   - step_post (array). Multidimensional - each element is an array which contains:
 *       - header (string) Plain text.
 *       - copy (string) HTML.
 *   - starter_statement (string). HTML.
 *   - starter_statement_header (string). Plain text.
 *   - time_and_place (string). HTML.
 *   - variables (array). Used to control various presentation settings.
 *   - vips (string). HTML.
 *
 */
function dosomething_campaign_load($node, $public = FALSE) {
  if ($node->type != 'campaign') { return FALSE; }

  // Set the image src ratio and styles.
  $image_src_ratio = 'square';
  $image_src_style = '300x300';

  // Load the entity metadata wrapper for easy value getting.
  $wrapper = entity_metadata_wrapper('node', $node);

  $campaign = new stdClass();
  $campaign->nid = $node->nid;
  $campaign->title = $node->title;
  $campaign->status = dosomething_campaign_get_campaign_status($node);
  $campaign->type = dosomething_campaign_get_campaign_type($node);

  // Plain text fields.
  $fields_plain_text = array(
    'call_to_action',
    'solution_support',
    'starter_statement_header',
  );
  foreach ($fields_plain_text as $property) {
    $field_name = 'field_' . $property;
    $campaign->{$property} = $wrapper->{$field_name}->value();
  }

  // Filtered text fields.
  $fields_filtered_text = array(
    'items_needed',
    'promoting_tips',
    'solution_copy',
    'starter_statement',
    'time_and_place',
    'vips',
  );
  foreach ($fields_filtered_text as $property) {
    $field_name = 'field_' . $property;
    if ($value = $wrapper->{$field_name}->value()) {
      // Store filtered text.
      $campaign->{$property} = $value['safe_value'];
    }
    else {
      $campaign->{$property} = NULL;
    }
  }

  // Taxonomy fields.
  $campaign->is_staff_pick = $wrapper->field_staff_pick->value();
  $campaign->primary_cause = NULL;
  if ($primary_cause = $wrapper->field_primary_cause->value()) {
    $campaign->primary_cause['tid'] = $primary_cause->tid;
    $campaign->primary_cause['name'] = $primary_cause->name;
  }

  // Date fields.
  $campaign->high_season_start = NULL;
  $campaign->high_season_end = NULL;
  $campaign->low_season_start = NULL;
  $campaign->low_season_end = NULL;
  $fields_date = array(
    'high_season',
    'low_season',
  );
  foreach ($fields_date as $property) {
    $field_name = 'field_' . $property;
    if ($value = $wrapper->{$field_name}->value()) {
      $start_property = $property . '_start';
      $campaign->{$start_property} = $value['value'];
      $end_property = $property . '_end';
      $campaign->{$end_property} = $value['value2'];
    }
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

  // Compound text field collections.
  $compound_fc_fields = array('faq', 'step_pre', 'step_post');
  foreach ($compound_fc_fields as $property) {
    $field_name = 'field_' . $property;
    $campaign->{$property} = dosomething_helpers_get_field_collection_values($wrapper, $field_name);
  }

  // Store any dosomething_helpers variables.
  $campaign->variables = dosomething_helpers_get_variables($campaign->nid);

  // Set image_cover property.
  $campaign->image_cover = NULL;
  if ($image_cover = $wrapper->field_image_campaign_cover->value()) {
    $campaign->image_cover['nid'] = (int) $image_cover->nid;
    // Initalize as FALSE.
    $campaign->image_cover['is_dark_image'] = FALSE;
    // If is_dark_image field value exists:
    if (isset($image_cover->field_dark_image[LANGUAGE_NONE][0]['value'])) {
      $campaign->image_cover['is_dark_image'] = (bool) $image_cover->field_dark_image[LANGUAGE_NONE][0]['value'];
    }
    // Set the src property.
    $campaign->image_cover['src'] = dosomething_image_get_themed_image_url($campaign->image_cover['nid'], $image_src_ratio, $image_src_style);
  }

  // Set image_header property.
  // If there is an override for the campaign header image.
  if (isset($campaign->variables['alt_image_campaign_cover_nid'])) {
    // Set the nid to the overridden value.
    $campaign->image_header['nid'] = (int) $campaign->variables['alt_image_campaign_cover_nid'];
    // Initalize as FALSE.
    $campaign->image_header['is_dark_image'] = FALSE;
    // Load the alt image node.
    $alt_image = node_load($campaign->image_header['nid']);
    if (isset($alt_image->field_dark_image[LANGUAGE_NONE][0]['value'])) {
      $campaign->image_header['is_dark_image'] = (bool) $alt_image->field_dark_image[LANGUAGE_NONE][0]['value'];
    }
    // Set the src property.
    $campaign->image_header['src'] = dosomething_image_get_themed_image_url($campaign->image_header['nid'], $image_src_ratio, $image_src_style);
  }
  // Else if no override:
  else {
    // Same as the image_cover.
    $campaign->image_header = $campaign->image_cover;
  }

  // If this is accessed via API:
  if ($public) {
    // Unset properties which shouldn't be public.
    unset($campaign->variables);
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
 * For given node entity wrapper, return its field_variables as an array.
 */
function dosomething_campaign_get_field_variables($wrapper) {
  if (!isset($wrapper->field_variables)) { return array(); }

  $vars = array();
  foreach ($wrapper->field_variables->value() as $variable) {
    $name = $variable->field_variable_name[LANGUAGE_NONE][0]['value'];
    $value = $variable->field_variable_value[LANGUAGE_NONE][0]['value'];
    $vars[$name] = $value;
  }
  return $vars;
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
