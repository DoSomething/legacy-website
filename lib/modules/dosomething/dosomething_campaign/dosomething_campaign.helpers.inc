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
 * @param bool $cache
 *   If TRUE, store $campaign in the cache
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
 *   - creator (array)
 *     - uid (int)
 *     - first_name (string). Plain text
 *     - last_initial (string). Plain text.
 *     - city (string). Plain text.
 *     - state (string). Plain text.
 *     - copy (string). Markdown.
 *     - picture (array)
 *       - fid (int)
 *       - src (string)
 *   - downloads (array).
 *     - url (string).
 *     - description (string).
 *   - end_date (string). Timestamp.
 *     @todo: Investigate making format consistent with season date strings.
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
 *     - url (array)
 *       - square (array)
 *         - raw (string). URL to the raw file uploaded.
 *   - is_staff_pick (bool)
 *   - items_needed (string). HTML.
 *   - latest_news_copy (string). Plain text.
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
 *   - stats (array)
 *     - signups (int)
 *   - time_and_place (string). HTML.
 *   - variables (array). Used to control various presentation settings.
 *   - vips (string). HTML.
 *
 */
function dosomething_campaign_load($node, $public = FALSE, $cache = TRUE) {
  if ($node->type != 'campaign') { return FALSE; }

  // Get the appropriate lang
  $current_lang = dosomething_global_convert_country_to_language(dosomething_global_get_current_prefix());

  if (($cached_node = cache_get('ds_campaign_' . $node->nid .'_'. $current_lang, 'cache_dosomething_campaign')) && $cache) {
    $campaign = $cached_node->data;

    // If this is accessed via API:
    if ($public) {
      // Add stats property.
      dosomething_campaign_load_stats($campaign);
      // Unset properties which shouldn't be public.
      unset($campaign->variables);
    }
    return $campaign;
  }
  else {
    // Set the image src ratio and styles.
    $image_src_ratio = 'square';
    $image_src_style = '300x300';

    // Load the entity metadata wrapper for easy value getting.
    $wrapper = dosomething_helpers_node_metadata_wrapper($node);

    $campaign = new stdClass();
    $campaign->nid = $node->nid;
    $campaign->title = $node->title;
    $campaign->status = dosomething_campaign_is_closed($node) ? 'closed' : 'active';
    $campaign->type = dosomething_campaign_get_campaign_type($node);
    $campaign->scholarship = NULL;
    if (array_key_exists($current_lang, $node->field_scholarship_amount)) {
      $campaign->scholarship = (int) $node->field_scholarship_amount[$current_lang][0]['value'];
    }

    $campaign->partners = NULL;
    // Set partners.
    if (!empty($node->field_partners)) {
      $campaign->partners = dosomething_taxonomy_get_partners_data($node->field_partners[LANGUAGE_NONE]);
    }

    // Plain text properties.
    $plain_text = dosomething_campaign_get_property_names_plain_text();

    foreach ($plain_text as $property) {
      $field_name = 'field_' . $property;
      if (isset($wrapper->{$field_name})) {
        $campaign->{$property} = $wrapper->{$field_name}->value();
      }
    }

    // Filtered text properties.
    $filtered_text = dosomething_campaign_get_property_names_filtered_text();
    foreach ($filtered_text as $property) {
      $field_name = 'field_' . $property;

      if ($value = $wrapper->{$field_name}->value()) {
        // Store filtered text.
        if (isset($value['safe_value'])) {
          $campaign->{$property} = $value['safe_value'];
        }
        else {
          $campaign->{$property} = $value;
        }
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
    $campaign->issue = NULL;
    if ($issue = $wrapper->field_issue->value()) {
      $campaign->issue['tid'] = $issue->tid;
      $campaign->issue['name'] = $issue->name;
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
    // Load end_date property.
    dosomething_campaign_load_end_date($campaign, $wrapper);

    // Fact fields.
    $campaign->fact_problem = NULL;
    $campaign->fact_solution = NULL;
    $campaign->fact_sources = NULL;
    // Collect multiple fact fields values as fact and sources variables.
    $fact_fields = array('field_fact_problem', 'field_fact_solution');

    // @TODO: Consider removing old function.
    // For global translation work we had issues dealing with the entity_metadata_wrapper method and
    // EntityDrupalWrapper retrieving appropriate content based on url language prefix, so this function
    // is disabled for now in favor of the dosomething_fact_get_facts_data() function instead.
    // $fact_vars = dosomething_fact_get_mutiple_fact_field_vars($wrapper->nid->value(), $fact_fields);
    $fact_vars = dosomething_fact_get_facts_data($node, $fact_fields);

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

    $campaign->downloads = NULL;
    if (!empty($node->field_downloads)) {
      foreach ($node->field_downloads[$current_lang] as $file) {
        $campaign->downloads[] = array(
          'url' => file_create_url($file['uri']),
          'description' => $file['description'],
        );
      }
    }

    // Store any dosomething_helpers variables.
    $campaign->variables = dosomething_helpers_get_variables('node', $campaign->nid);

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
      // @todo: Deprecate when Message Broker uses url array instead.
      $campaign->image_cover['src'] = dosomething_image_get_themed_image_url($campaign->image_cover['nid'], $image_src_ratio, $image_src_style);
      // Set the url array.
      dosomething_campaign_load_image_url($campaign->image_cover['url'], $image_cover);
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

    // Load Creator property.
    dosomething_campaign_load_creator($campaign, $wrapper);

    cache_set('ds_campaign_' . $campaign->nid .'_'. $current_lang, $campaign, 'cache_dosomething_campaign', REQUEST_TIME + 60*60*24);

    // If this is accessed via API:
    if ($public) {
      // Add stats property.
      dosomething_campaign_load_stats($campaign);
      // Unset properties which shouldn't be public.
      unset($campaign->variables);
    }
  }

  return $campaign;
}

/**
 * Adds creator property to given $campaign with given node entity $wrapper.
 */
function dosomething_campaign_load_creator(&$campaign, $wrapper) {
  $campaign->creator = NULL;
  if (isset($wrapper->field_created_by)) {
    // If a Created By field value exists:
    if ($account = $wrapper->field_created_by->value()) {
      // Initialize Creator array.
      $campaign->creator = array(
        'uid' => $account->uid,
        'first_name' => dosomething_user_get_field('field_first_name', $account),
        'last_initial' => NULL,
        'city' => NULL,
        'state' => NULL,
        'picture' => NULL,
        'copy' => NULL,
      );
      if ($last_name = dosomething_user_get_field('field_last_name', $account)) {
        $campaign->creator['last_initial'] = $last_name[0];
      }
      if ($address = dosomething_user_get_field('field_address', $account)) {
        $campaign->creator['city'] = $address['locality'];
        $campaign->creator['state'] = $address['administrative_area'];
      }
      if ($file = $account->picture) {
        $campaign->creator['picture'] = array(
          'fid' => $file->fid,
          'src' => file_create_url($file->uri),
        );
      }
      if ($copy =$wrapper->field_created_copy->value()) {
        $campaign->creator['copy'] = $copy['safe_value'];
      }
    }
  }
}

/**
 * Adds end_date property to given $campaign with given node entity $wrapper.
 */
function dosomething_campaign_load_end_date(&$campaign, $wrapper) {
  $campaign->end_date = NULL;
  // Determines whether or not to display end date.
  $display_date = $wrapper->field_display_end_date->value();
  // Check if there is a value in the High Season date field.
  if ($display_date == 1 && $wrapper->field_high_season->value()) {
    $campaign->end_date = $wrapper->field_high_season->value2->value();
  }
}

function dosomething_campaign_load_image_url(&$campaign_property, $image_node) {
  $fields = array(
    'landscape',
    'square',
    'portrait',
    'thumbnail',
  );
  foreach ($fields as $name) {
    $campaign_property[$name] = NULL;
    $field_name = 'field_image_' . $name;
    if (isset($image_node->{$field_name}[LANGUAGE_NONE][0])) {
      $file = $image_node->{$field_name}[LANGUAGE_NONE][0];
      $campaign_property[$name] = array(
        'raw' => file_create_url($file['uri']),
      );
    }
  }
}

/**
 * Adds stats property to given $campaign.
 */
function dosomething_campaign_load_stats(&$campaign) {
  $campaign->stats = array(
    'signups' => dosomething_signup_get_signup_total_by_nid($campaign->nid),
  );
}

/**
 * Create a new record to store the user's messaging opt-in preference.
 *
 * @param  object $user
 * @param  string $campaign_id
 * @return void
 */
function dosomething_campaign_create_affiliate_messaging_opt_in($user, $campaign_id) {
  $campaign_run = dosomething_helpers_get_current_campaign_run_for_user($campaign_id, $user);
  $northstar_user = dosomething_northstar_get_user($user->uid, 'drupal_id');

  db_insert('dosomething_campaign_affiliate_opt_ins')
    ->fields([
      'campaign_id' => $campaign_id,
      'campaign_run_id' => $campaign_run->nid,
      'northstar_id' => $northstar_user->id,
      'first_name' => $northstar_user->first_name,
      'email' => $northstar_user->email,
      'mobile' => $northstar_user->mobile,
      'age' => dosomething_user_get_age($northstar_user->birthdate)->y,
    ])->execute();

  drupal_set_message('And thanks for signing up for messaging from our affiliate!');
}

/**
 * Creates and returns a campaign node from given JSON string.
 */
function dosomething_campaign_create_node_from_json($string) {
  $data = json_decode($string);
  $node = new stdClass();

  // We'll use this as a flag to find test nodes.
  $node->created = '-1';

  $node->type = $data->type;
  $node->title = $data->title;

  // Set all plain text properties:
  $plain_text = dosomething_campaign_get_property_names_plain_text();
  foreach ($plain_text as $text_field) {
    if (isset($data->{$text_field})) {
      $field_name = 'field_' . $text_field;
      $node->{$field_name}[LANGUAGE_NONE][0]['value'] = $data->{$text_field};
    }
  }
  // Set all filtered text properties:
  $filtered_text = dosomething_campaign_get_property_names_filtered_text();
  foreach ($filtered_text as $text_field) {
    if (isset($data->{$text_field})) {
      $field_name = 'field_' . $text_field;
      $node->{$field_name}[LANGUAGE_NONE][0]['value'] = $data->{$text_field};
      $node->{$field_name}[LANGUAGE_NONE][0]['format'] = 'markdown';
    }
  }

  // Set all fact properties:
  $fact = dosomething_campaign_get_property_names_fact();
  foreach($fact as $fact_field) {
    if (isset($data->{$fact_field})) {
      $field_name = 'field_' . $fact_field;
      $fact_node = dosomething_fact_create_node_from_json(json_encode($data->{$fact_field}));
      $node->{$field_name}[LANGUAGE_NONE][0]['target_id'] = $fact_node->nid;
    }
  }

  // Set all fact array properties:
  $fact_array = dosomething_campaign_get_property_names_fact_array();
  foreach($fact_array as $fact_field) {
    if (isset($data->{$fact_field})) {
      $field_name = 'field_' . $fact_field;
      foreach($data->{$fact_field} as $data_fact) {
        $fact_node = dosomething_fact_create_node_from_json(json_encode($data_fact));
        $node->{$field_name}[LANGUAGE_NONE][]['target_id'] = $fact_node->nid;
      }
    }
  }

  // Set issue
  if (isset($data->issue)) {
    $term = dosomething_taxonomy_create_term($data->issue, "cause");
    $node->field_issue[LANGUAGE_NONE][0]['tid'] = $term->tid;
  }

  // Set all image properties:
  $image = dosomething_campaign_get_property_names_image();
  foreach($image as $image_field) {
    if (isset($data->{$image_field})) {
      $field_name = 'field_' . $image_field;
      $image_node = dosomething_image_create_node_from_json(json_encode($data->{$image_field}));
      $node->{$field_name}[LANGUAGE_NONE][0]['target_id'] = $image_node->nid;
    }
  }

  // Set all field collection properties:
  $field_collection = dosomething_campaign_get_property_names_field_collection();
  foreach ($field_collection as $field_collection_field) {
    if (isset($data->{$field_collection_field})) {
      foreach ($data->{$field_collection_field} as $key => $item) {
        $field_name = 'field_' . $field_collection_field;
        $field_collection_entity = dosomething_campaign_create_field_collection_from_json(json_encode($item), $field_name, $node);
        $node->{$field_name}[LANGUAGE_NONE][$key]['target_id'] = $field_collection_entity->nid;
      }
    }
  }

  node_save($node);
  return $node;
}

/**
 * Returns array of campaign property names which contain plain text.
 */
function dosomething_campaign_get_property_names_plain_text() {
  return array(
    'call_to_action',
    'latest_news_copy',
    'starter_statement_header',
    'pre_step_header',
    'post_step_header',
    'reportback_noun',
    'reportback_verb',
    'location_finder_url',
    'secondary_call_to_action',
    'value_proposition',
  );
}

/**
 * Returns array of campaign property names which contain filtered text.
 */
function dosomething_campaign_get_property_names_filtered_text() {
  return [
    'items_needed',
    'promoting_tips',
    'solution_copy',
    'solution_support',
    'starter_statement',
    'items_needed',
    'time_and_place',
    'vips',
    'location_finder_copy',
    'pre_step_copy',
    'photo_step',
    'post_step_copy',
    'reportback_copy',
    'helpful_tips',
    'reportback_confirm_msg',
  ];
}

/**
 * Returns array of campaign property names which contain a fact node.
 */
function dosomething_campaign_get_property_names_fact() {
  return array(
    'fact_problem',
    'fact_solution',
  );
}

/**
 * Returns array of campaign property names which contain an array of fact nodes.
 */
function dosomething_campaign_get_property_names_fact_array() {
  return array(
    'facts',
  );
}

/**
 * Returns array of campaign property names which contain an image node.
 */
function dosomething_campaign_get_property_names_image() {
  return array(
    'image_campaign_cover',
    'image_psa_replacement',
    'image_step_gallery'
  );
}

/**
 * Returns array of campaign property names which contain field collections.
 */
function dosomething_campaign_get_property_names_field_collection() {
  return array(
    'faq',
    'step_pre',
    'step_post',
  );
}

/**
 * Create a field collection with the given fields from JSON string.
 */
function dosomething_campaign_create_field_collection_from_json($string, $field_collection_name, $node) {
  $data = json_decode($string);

  $field_collection_item = entity_create('field_collection_item', array('field_name' => $field_collection_name));
  $field_collection_item->setHostEntity('node', $node);

  foreach ($data as $data_field => $data_field_value) {
    $collection_field_name =  "field_compound_text_" . $data_field;
    $field_collection_item->{$collection_field_name}[LANGUAGE_NONE][0]['value'] = $data_field_value;
    if ($data_field == "copy") {
      $field_collection_item->{$collection_field_name}[LANGUAGE_NONE][0]['format'] = 'markdown';
    }
  }

  $field_collection_item->save();
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

  foreach ($results as $key => $result) {
    $sms_games[$key]['nid'] = $result->nid;
    $sms_games[$key]['title'] = $result->title;
  }
  if ($sms_games) {
    return $sms_games;
  }
  // If no SMS Games, return null.
  return NULL;
}

/**
 * Returns the amount of the scholarship tied to a campaign.
 *
 * @return int
 *  Amount of the scholarship.
 */
function dosomething_campaign_get_scholarship($nid) {
  $wrapper = dosomething_helpers_node_metadata_wrapper($nid);
  return $wrapper->field_scholarship_amount->value();
}


/**
 * Get all the campaign runs associated with a node translation.
 *
 * @param $nid The nid of the node to grab runs for
 * @param $language The language of the translation to grab runs for.
 */
function dosomething_campaign_get_runs($nid, $language) {
  $campaign_runs = db_query("SELECT entity_id
                             FROM field_data_field_campaigns
                             WHERE field_campaigns_target_id = :nid
                             AND language = :language
                             AND bundle = 'campaign_run';", array(
                              ':nid' => $nid,
                              ':language' => $language
                             ))->fetchAll();

  return $campaign_runs;
}

/**
 * Get all the affiliate configurations data for a campaign.
 *
 * @param  string|array $campaign_info Either a node ID or an array of campaign variables.
 * @return array|null
 */
function dosomething_campaign_get_affiliate_data($campaign_info) {
  if (!$campaign_info) {
    return NULL;
  }

  // Is provided info an array of campaign variables?
  if (is_array($campaign_info)) {
    $variables = $campaign_info;
  }

  // Is provided info a string node ID?
  if (is_string($campaign_info)) {
    $variables = dosomething_helpers_get_variables('node', $campaign_info);
  }

  $data = [
    'messaging_opt_in' => [
      'enabled' => (bool) $variables['affiliate_opt_in_toggle'],
    ],
  ];

  if ($data['messaging_opt_in']['enabled']) {
    $data['messaging_opt_in']['label'] = $variables['affiliate_opt_in_toggle_label'];
    $data['messaging_opt_in']['info_label'] = $variables['affiliate_opt_in_toggle_information_label'];
    $data['messaging_opt_in']['info_message'] = $variables['affiliate_opt_in_toggle_information_message'];
  }

  return $data;
}
