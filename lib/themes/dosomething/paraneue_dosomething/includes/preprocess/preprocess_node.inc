<?php

/**
 * Implements theme_preprocess_node().
 */
function paraneue_dosomething_preprocess_node(&$vars) {
  $regional_url_data = paraneue_dosomething_get_regional_url_data($vars['node']);
  $campaign = node_load($vars['node']->nid);
  $languages = $campaign->translations->data;

  if ($regional_url_data) {
    foreach ($regional_url_data as $language => $url) {
      if ($languages[$language]['status'] == 1) {
        drupal_add_html_head_link(['rel' => 'alternate', 'hreflang' => $language, 'href' => $url]);
      }
    }
  }

  switch($vars['node']->type) {

    case "campaign":
      paraneue_dosomething_preprocess_node_campaign($vars);
      paraneue_dosomething_add_info_bar($vars);
      break;

    case "campaign_group":
      paraneue_dosomething_preprocess_node_campaign_group($vars);
      paraneue_dosomething_preprocess_field_partners($vars);
      paraneue_dosomething_add_info_bar($vars);
      break;

    case "fact_page":
      // Return facts as two arrays.
      // Allow CTAs to be properly embedded in between.
      $vars['first_fact_group'] = array_slice($vars['facts'], 0, 5);
      $vars['second_fact_group'] = array_slice($vars['facts'], 5);
      paraneue_dosomething_preprocess_field_partners($vars);
      break;

    case "home":
      // Set these here to remove db calls from tpl files:
      $vars['show_campaign_finder'] = theme_get_setting('show_campaign_finder');
      $vars['show_sponsors'] = theme_get_setting('show_sponsors');
      break;

    case "static_content":
      // Preprocess field_gallery.
      paraneue_dosomething_preprocess_node_field_gallery($vars);
      break;

    case "notfound":
      paraneue_dosomething_preprocess_node_notfound($vars);
      break;
  }
}

/**
 * Preprocesses an info_bar based on given $vars.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_add_info_bar(&$vars) {
  $info_bar_vars = array();

  if (isset($vars['formatted_partners'])) {
    $info_bar_vars['formatted_partners'] = $vars['formatted_partners'];
  }

  if (module_exists('dosomething_global')) {
    $country_code = dosomething_global_get_current_prefix();

    $country_contact_emails = [
      'br' => 'ajuda@dosomething.org',
      'mx' => 'ayuda@dosomething.org',
    ];

    // For the countries in $country_contact_emails, use a contact email address instead of zendesk form.
    if ($country_code && array_key_exists($country_code, $country_contact_emails)) {
      $info_bar_vars['contact_us_email'] = '<a href="mailto:' . $country_contact_emails[$country_code] .'">'. $country_contact_emails[$country_code] . '</a>';
      // All other countries get the zendesk form.
    }
    else {

      // If being called from a taxonomy page, this won't be set.
      if (isset($vars['nid'])) {
        // If the campaign is closed, link to the help center
        // If the campaign is open, link to the FAQs if there are any
        $node = node_load($vars['nid']);
        if (dosomething_campaign_is_closed($node)) {
          $info_bar_vars['help_center'] = true;
          $info_bar_vars['faqs'] = NULL;
        }
        else {
          $info_bar_vars['faqs'] = !empty($vars['field_faq']);
          $info_bar_vars['help_center'] = NULL;
        }
      }

      $zendesk_form_header = t(variable_get('dosomething_zendesk_form_header'));

      $info_bar_vars['zendesk_form_header'] = $zendesk_form_header;

      if (isset($vars['zendesk_form'])) {
        $info_bar_vars['zendesk_form'] = $vars['zendesk_form'];
      }
    }
  }

  $vars['info_bar'] = theme('info_bar', $info_bar_vars);
}

/**
 * Preprocesses a campaign node's $vars.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_campaign(&$vars) {
  // List of partials to add as $vars.
  $partials = array(
    'campaign_creator',
    'campaign_headings',
    'sponsor_logos',
    'promotions',
  );
  // Initialize to NULL.
  foreach ($partials as $partial) {
    $vars[$partial] = NULL;
  }

  // Check for campaign class:
  // @see dosomething_campaign_preprocess_node().
  if (isset($vars['campaign'])) {

    $campaign = $vars['campaign'];

    // Add $campaign_scholarship variable.
    paraneue_dosomething_preprocess_node_campaign_scholarship($vars);

    // Construct the proper end date text
    if (!empty($vars['field_high_season'])) {
      $end_date = new DateTime($vars['field_high_season'][0]['value2']);
      $vars['campaign_end_date'] = $end_date->format('F j');
    }

    // Set campaign headings.
    $vars['campaign_headings'] = theme('campaign_headings', $vars);

    // If creator property has been set:
    if ($creator = $campaign->creator) {
      // Pass $campaign->creator array to the campaign_creator theme function.

      $file = file_load($creator['picture']['fid']);
      $creator['picture']['src_square'] = image_style_url('300x300', $file->uri);
      $vars['campaign_creator'] = theme('campaign_creator', $creator);
    }

    // Check for partner embed
    $partner_embed_enabled = dosomething_helpers_get_variable('node', $campaign->nid, 'partner_embed_enable');
    if ($partner_embed_enabled) {
      global $user;
      $markup = dosomething_helpers_get_variable('node', $campaign->nid, 'partner_embed_markup');
      $markup = str_replace('${northstarId}', dosomething_user_get_northstar_id($user->uid), $markup);
      $vars['partner_embed_markup'] = $markup;
    }

    // Check for sponsors.
    $vars['sponsor_logos'] = paraneue_dosomething_get_sponsor_logos($campaign->partners);

    // Output sponsors and creator in promotions module.
    if ($vars['sponsor_logos'] || $vars['campaign_creator']) {
      $classes = NULL;

      if ($vars['sponsor_logos'] && $vars['campaign_creator']) {
        $classes = ' -dual';
        $vars['promotions'] = $vars['sponsor_logos'] . $vars['campaign_creator'];
      }
      elseif ($vars['sponsor_logos']) {
        $vars['promotions'] = $vars['sponsor_logos'];
      }
      elseif ($vars['campaign_creator']) {
        $vars['promotions'] = $vars['campaign_creator'];
      }

      $vars['promotions'] = '<div class="promotions' . $classes . '">' . $vars['promotions'] . '</div>';

    }
  }

  // Add class to header if promotions will be included in display.
  if ($vars['promotions']) {
    $vars['classes_array'][] = 'has-promotions';
  }

  // If the campaign requires a signup modal to display:
  if (isset($vars['node']->required_signup_data_form)) {
    // Add JS to open the signup data form modal.
    $id = 'modal-signup-data-form';
    $closeButton = 'false';
    $skipForm = '#dosomething-signup-user-skip-signup-data-form';

    // Add skip button if setting is enabled
    if (isset($vars['node']->skippable_signup_data_form)) {
      $closeButton = 'skip';
    }

    $js = 'jQuery(document).ready(function() { DSModal.open( jQuery("#' . $id . '"), {animated: false, closeButton: "' . $closeButton . '", skipForm: "' . $skipForm . '"}); });';
    drupal_add_js($js, 'inline');
  }

  // If this is not the pitch page:
  if (!isset($vars['is_pitch_page'])) {
    $vars['reportbacks_gallery'] = paraneue_dosomething_preprocess_reportback_gallery($vars);
  }

  if (isset($vars['is_pitch_page'])) {
    $vars['show_persistent_signup'] = theme_get_setting('show_persistent_signup');
  }
}

/**
 * Expands $reportbacks_gallery array with themed Reportback items and data for given node preprocess $vars.
 */
function paraneue_dosomething_preprocess_reportback_gallery(&$vars, $count = 6) {
  $gallery = [
    'admin_access' => user_access('view any reportback') ? 'true' : 'false',
    'desired_count' => $count,
    'campaign_id' => $vars['nid'],
    'items' => [],
    'item_ids' => [],
  ];

  $filters = [
    'nid' => $gallery['campaign_id'],
    'status' => ['promoted'],
    'count' => $gallery['desired_count'],
    'random' => TRUE,
  ];

  // If the Rogue feature flag is on, grab reportbacks from Rogue.
  if (variable_get('rogue_collection', FALSE)) {
    // Hit the GET /reportbacks endpoint in Rogue with campaign_id filter.
    $promotedReportbackItemsResponse = dosomething_rogue_get_reportback_items([
      'filter' => [
        'campaign_id' => $gallery['campaign_id'],
        'status' => 'accepted',
      ],
      'as_user' => dosomething_user_get_field('field_northstar_id'),
      'limit' => 6
    ]);

    $promotedReportbackItems = $promotedReportbackItemsResponse['data'];

    foreach ($promotedReportbackItems as $key => $promotedReportbackItem) {
      if ($promotedReportbackItem['media']['uri'] === 'default') {
        unset($promotedReportbackItems[$key]);
      }
    }

    $gallery['initial_promoted_count'] = count($promotedReportbackItems);

    // Since Rogue only sends back approved reportbacks, we can just set total_approved to total_promoted.
    $gallery['total_promoted'] = $promotedReportbackItemsResponse['meta']['pagination']['total'];

    // # Approved Reportbacks:
    $gallery['total_approved'] = $gallery['total_promoted'];
  }
  else {
    // # Promoted Reportbacks:
    try {
      $promotedReportbackItems = (new ReportbackItem)->find($filters);
    }
    catch (Exception $error) {
      $promotedReportbackItems = [];
    }
    $gallery['initial_promoted_count'] = count($promotedReportbackItems);

    $gallery['total_promoted'] = dosomething_reportback_get_reportback_items_total_by_filters(['nid' => $gallery['campaign_id'], 'status' => 'promoted']);

    // # Approved Reportbacks:
    $gallery['total_approved'] = dosomething_reportback_get_reportback_items_total_by_filters(['nid' => $gallery['campaign_id'], 'status' => 'approved']);
  }

  // # Build the full initial gallery:

  // Collect Reportbacks to fulfill desired amount.
  if ($gallery['initial_promoted_count'] < $gallery['desired_count']) {
    $reportbackItems = paraneue_dosomething_build_reportbacks_gallery_collection($gallery, $promotedReportbackItems, TRUE);
  }
  // There are enough Promoted Reportbacks to fulfill desired amount.
  else {
    $reportbackItems = $promotedReportbackItems;
  }

  foreach ($reportbackItems as $item) {
    if (variable_get('rogue_collection', FALSE)) {
      $item = (object) $item;
      $gallery['item_ids'][] = $item->id;
      $gallery['items'][] = paraneue_dosomething_get_themed_reportback_item($item, TRUE);
    }
    else {
      if ($item instanceof ReportbackItem) {
        $gallery['item_ids'][] = $item->id;
      }

      $gallery['items'][] = paraneue_dosomething_get_themed_reportback_item($item);
    }
  }

  // Get total of Promoted & Approved RB Items prefetched.
  $gallery['prefetched'] = count($gallery['item_ids']);

  if (variable_get('rogue_collection', FALSE)) {
    $gallery['total_sum'] = $gallery['total_approved'];
  }
  else {
    // Get total of Promoted & Approved RB Items for Campaign.
    $gallery['total_sum'] = $gallery['total_promoted'] + $gallery['total_approved'];
  }

  // Get total remaining after subtracting the RB Items already retrieved.
  $gallery['remaining'] = $gallery['total_sum'] - $gallery['prefetched'];

  global $user;

  drupal_add_js(
    [
      'dsKudosReactions' => [
        'approved' => Kudos::getApprovedReactions(),
        'enabled' => !dosomething_kudos_disable_reactions($vars['nid']),
        'terms' => [
          // @TODO: Ideally this would call a function that retrieves all
          // kudos reaction terms and sets up the associative array, but
          // for the time being we are only using a single term, "heart",
          // so let's keep it simple ;)
          'heart' => dosomething_kudos_get_term_id_by_name('heart'),
        ],
        'user' => isset($user->uid) ? $user->uid : null,
      ]
    ],
    'setting'
  );

  return $gallery;
}

/**
 * Preprocesses a Campaign Group node.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_campaign_group(&$vars) {
  // Source to append to Campaign Gallery links.
  $source = 'node/' . $vars['nid'];
  $vars['campaign_gallery'] = paraneue_dosomething_get_campaign_gallery($vars['campaigns'], $source);
}

/**
 * Sets a $campaign_scholarship variable based on $vars.
 *
 * @see paraneue_dosomething_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_campaign_scholarship(&$vars) {
  // Initialize to NULL to avoid isset checks in the tpl.
  $vars['campaign_scholarship'] = NULL;
  $vars['prove_scholarship'] = NULL;

  // If a campaign class exists and it has a scholarship:
  if ($vars['campaign'] && $vars['campaign']->scholarship) {
    $campaign = $vars['campaign'];
    $amount = $campaign->scholarship;

    // SMS Game classes:
    if ($campaign->type == 'sms_game') {
      $classes = array('-right');
    }
    // Pitch page classes:
    elseif (isset($campaign->is_pitch_page)) {
      // Values for pitch page:
      $classes = array('-above', '-white',  '-dynamic-right');
    }
    // Else action page classes:
    else {
      // Default classes.
      $classes = array('-above',  '-white');
      // Prove it section classes.
      $prove_classes = array('-below', '-white');
      $vars['prove_scholarship'] = theme('campaign_scholarship', array(
        'amount' => $amount,
        'classes' => $prove_classes,
      ));
    }
    // Default $campaign_scholarship for campaign templates.
    $vars['campaign_scholarship'] = theme('campaign_scholarship', array(
      'amount' => $amount,
      'classes' => $classes,
    ));
  }
}

/**
 * Preprocesses the $vars['galleries'] if exists.
 *
 * @see dosomething_static_content_preprocess_galleries().
 *
 * @param array $vars
 *   Vars passed from a hook_preprocess_node().
 */
function paraneue_dosomething_preprocess_node_field_gallery(&$vars) {

  if (!isset($vars['galleries'])) return;

  // Loop through each gallery:
  foreach ($vars['galleries'] as $delta => &$gallery) {
    // Get the class to apply based on gallery style.
    $gallery_class = paraneue_dosomething_get_gallery_style($gallery['style']);
    // Sets $vars['galleries'][$delta]['class'] to $gallery_class.
    $gallery['class'] = $gallery_class;
  }

}

/**
 * Themes the recommended campaigns for the notfound page
 */
function paraneue_dosomething_preprocess_node_notfound(&$vars) {
  if (isset($vars['raw_search_results']) && count($vars['raw_search_results']) != 0) {
    // Theme the set of results as duo gallery.
    $vars['search_results'] = paraneue_dosomething_get_search_gallery($vars['raw_search_results']);
  }
  else {
    $vars['campaign_results'] = paraneue_dosomething_get_recommended_campaign_gallery(NULL, NULL, 3);
  }
}
