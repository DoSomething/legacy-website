<?php
/**
 * @file
 * Helper functions for theming.
 */

/**
 * Returns admin tabs edited for regional admins.
 *
 * @param mixed  $tabs
 * @return mixed mixed
 */
function paraneue_dosomething_edit_regional_admin_tabs($tabs) {
  $primary_tabs = $tabs['#primary'];

  if (!$primary_tabs) {
    return $tabs;
  }

  $removeable_tabs = [
    'Devel',
    'Translate',
  ];

  foreach($primary_tabs as $index => $tab) {
    if (in_array($tab['#link']['title'], $removeable_tabs)) {
      unset($primary_tabs[$index]);
    }
  }

  // Reset array indexes
  $tabs['#primary'] = array_values($primary_tabs);

  return $tabs;
}

/**
 * Returns a gallery css class name for a given gallery cms $style
 *
 * @param string $style
 *   CSS class selected from gallery style dropdown
 *
 * @return string
 *   Gallery css class name
 */
function paraneue_dosomething_get_gallery_style($style) {
  switch ($style) {
    case '2col':
      return '-duo';
      break;
    case '3col_short':
      return '-triad -aligned';
      break;
    default:
      return '-triad';
      break;
  }
}

/**
 * Returns available social networks.
 *
 * @return array
 *   Supported social networks names indexed with designated ids
 */
function paraneue_dosomething_get_social_networks() {
  return array(
    'facebook'  => array(
      'id'    => 'facebook',
      'name'  => t('Facebook'),
    ),
    'twitter'   => array(
      'id'    => 'twitter',
      'name'  => t('Twitter'),
    ),
    'snapchat'    => array(
      'id'    => 'snapchat',
      'name'  => t('Snapchat'),
    ),
    'weheartit'    => array(
      'id'    => 'weheartit',
      'name'  => t('We Heart It'),
    ),
    'instagram' => array(
      'id'    => 'instagram',
      'name'  => t('Instagram'),
    ),
    'youtube'   => array(
      'id'    => 'youtube',
      'name'  => t('Youtube'),
    ),
  );
}

/**
 * For given $partners_data array, return themed sponsor logos.
 *
 * @param array $partners_data
 *   Array of field_partners data.
 *   @see dosomething_taxonomy_get_partners_data().
 *
 * @return string
 */
function paraneue_dosomething_get_sponsor_logos($partners_data = array()) {
  if (empty($partners_data)) {
    return '';
  }
  $sponsors = array();
  foreach ($partners_data as $delta => $partner) {
    if ($partner['is_sponsor']) {
      $sponsors[$delta]['name'] = $partner['name'];
      $sponsors[$delta]['logo_url'] = $partner['logo']['url']['default'];
    }
  }
  if (!empty($sponsors)) {
    return theme('sponsor_logos', array(
      'sponsors' => $sponsors,
    ));
  }
  return '';
}

/**
 * For given array of search results, get the variables needed for theming each result.
 *
 * @param array $results
 *   Array of search results.
 *
 * @return array
 */
function paraneue_dosomething_get_search_vars($results) {
  if (empty($results)) {
    return '';
  }
  // Preprocess each result and store the information we need.
  foreach ($results as $delta => $value) {
    switch ($value['bundle']) {
      case 'campaign_group':
      case 'campaign':
        $result_node = node_load($value['node']->entity_id);
        // Get the image field from the campaign node.
        // Make it available as a variable, if it exists. Otherwise, leave it empty.
        if (isset($result_node->field_image_campaign_cover)) {
          $image = $result_node->field_image_campaign_cover;
          $clc = dosomething_helpers_get_current_language_content_code();
          if ($image[$clc]) {
            $value['display_image'] = dosomething_image_get_themed_image($image[$clc][0]['target_id'], 'square', '300x300');
          }
          //If the current language doesn't have an image, use the node's default langauge image.
          else {
            $default_language = $result_node->language;
            $value['display_image'] = dosomething_image_get_themed_image($image[$default_language][0]['target_id'], 'square', '300x300');
          }
        }
        else {
          $value['display_image'] = '';
        }
        $value['subtitle'] = $value['fields']['sm_field_call_to_action'][0];
        $item = array(
          'title' => $value['title'],
          'url' => $value['link'],
          'image' => $value['display_image'],
          'description' => $value['subtitle'],
        );
        $result_variables[$delta] = $item;
        break;
      case 'static_content':
      case 'fact_page':
        if (!empty($value['fields']['sm_field_subtitle'][0])) {
          $value['subtitle'] = $value['fields']['sm_field_subtitle'][0];
        }
        else {
          $value['subtitle'] = $value['fields']['sm_field_intro_title'][0];
        }
        $item = array(
          'title' => $value['title'],
          'url' => $value['link'],
          'description' => $value['subtitle'],
        );
        $result_variables[$delta] = $item;
      break;
      default:
        $item = array(
          'title' => $value['title'],
          'url' => $value['link'],
          'description' => $value['subtitle'],
        );
        $result_variables[$delta] = $item;
        break;
    }
  }
  return $result_variables;
}

/**
 * For given array of search results, theme a duo gallery with them.
 *
 * @param array $results
 *   Array of search results.
 *
 * @return string
 */
function paraneue_dosomething_get_search_gallery($results) {
  if (empty($results)) {
    return '';
  }
  // Get the variables we need to theme each result.
  $results_variables = paraneue_dosomething_get_search_vars($results);
  // Theme each result with the media pattern.
  if ($results_variables) {
    foreach ($results_variables as $delta => $value) {
      $result_items[$delta] = paraneue_dosomething_get_gallery_item($value, 'figure', TRUE, array('-left', '-medium'));
    }
  }
  // Theme the set of results as duo gallery.
  return paraneue_dosomething_get_gallery($result_items, 'duo');
}

/**
 * Returns a Paraneue Gallery content array for a given Node $nid.
 *
 * @param int $nid
 *   The Node $nid to render as Gallery Item content.
 * @param string $source
 *   The source query string to append to the link.
 */
function paraneue_dosomething_get_node_gallery_item($nid, $source = NULL) {
  $classes_array = [];

  $node = node_load($nid);
  $url_options = [];
  if ($source) {
    $url_options['query']['source'] = $source;
  }
  $link = url(drupal_get_path_alias('node/' . $nid), $url_options);

  $title = $node->title;
  if ($node->status == 0) {
    $title = t('Stay Tuned');
    $classes_array[] = '-unpublished';
  }

  $image = NULL;
  $clc = dosomething_helpers_get_current_language_content_code();
  // If the node has a Cover Image:
  if (!empty($node->field_image_campaign_cover)) {
    // Presets for the node's Cover Image display.
    $ratio = 'square';
    $default = '400x400';
    $large = '768x768';
    // Get the Cover Image node nid.
    $nid_image = $node->field_image_campaign_cover[$clc][0]['target_id'];
    // Get its high-res URL.
    $large_url = dosomething_image_get_themed_image_url($nid_image, $ratio, $large);
    // Set attributes to pass to the themed image.
    $attributes = array(
      'data-src-large' => $large_url,
    );
    $image = dosomething_image_get_themed_image($nid_image, $ratio, $default, $node->title, $attributes);
  }

  $content = array(
    'link' => $link,
    'title' => $title,
    'tagline' => $node->field_call_to_action[$clc][0]['value'],
    'status' => $node->status,
    'image' => $image,
    'is_staff_pick' => $node->field_staff_pick[$clc][0]['value'],
  );
  return array(
    'content' => $content,
    'classes_array' => $classes_array,
  );
}

/**
 * Returns a themed mosaic gallery with campaign tiles for given $nids.
 */
function paraneue_dosomething_get_campaign_gallery($nids, $source = NULL, $show_more = FALSE) {
  $items = [];

  foreach ($nids as $delta => $nid) {
    $item = paraneue_dosomething_get_node_gallery_item($nid, $source);
    $items[] = paraneue_dosomething_get_gallery_item($item['content'], 'tile', TRUE);
  }

  $gallery_classes = array('-mosaic');
  // If 5 items or more, the tiles should appear with a featured tile.
  if (count($items) > 4) {
    $gallery_classes = array('-featured -mosaic');
  }
  return paraneue_dosomething_get_gallery($items, 'quartet', $gallery_classes, $show_more);
}

/**
 * Returns a themed gallery of recommended campaigns.
 */
function paraneue_dosomething_get_recommended_campaign_gallery($tid = NULL, $uid = NULL, $limit = 3) {
  // Get recommended campaigns
  $rec_nids = dosomething_campaign_get_recommended_campaign_nids($tid, $uid, $limit);
  $rec_vars = array();
  foreach ($rec_nids as $nid) {
    $rec_vars[] = dosomething_campaign_get_campaign_block_vars($nid);
  }
  // Theme the gallery.
  if (isset($rec_vars)) {
    $gallery_items = array();
    foreach ($rec_vars as $delta => $value) {
      $image = dosomething_image_get_themed_image($value['nid_image'], 'landscape', '400x400');
      $item = array(
        'title' => $value['link'],
        'image' => $image,
        'description' => $value['call_to_action'],
        'url' => base_path() . $value['path_alias'],
      );
      array_push($gallery_items, paraneue_dosomething_get_gallery_item($item, 'figure'));
    }
    return paraneue_dosomething_get_gallery($gallery_items, 'triad');
  }
}

/**
 * Return a specified number of themed Reportbacks by status type.
 *
 * @deprecated Remove if no conflicts.
 */
function paraneue_dosomething_get_themed_reportbacks_by_status($campaign_id, $status, $count, $random = NULL) {
  $reportback_items = array();

  $params = array();
  $params['nid'] = $campaign_id;
  $params['status'] = $status;
  $params['count'] = $count;
  $params['random'] = $random;

  $reportback_results = dosomething_reportback_get_reportback_items_query($params);

  $admin_access = user_access('view any reportback');

  foreach ($reportback_results as $reportback) {
    // @Todo: DRY. Potentially grab this data from the API endpoint to truly DRY?
    if ($admin_access) {
      $reportback->admin_link = '/admin/reportback/' . $reportback->rbid;
    }
    $reportback->image = dosomething_image_get_themed_image_url_by_fid($reportback->fid, '400x400');
    $reportback_items[] = paraneue_dosomething_get_gallery_item((array) $reportback, 'photo');
  }

  return $reportback_items;
}

/**
 * Theme a single Reportback Item for the gallery.
 *
 * @param  object  $data
 * @return null|string
 */
function paraneue_dosomething_get_themed_reportback_item($data) {
  if (!$data) {
    return NULL;
  }

  if ($data->id && !$data->disable_reactions) {
    $data->reaction_totals = [
      'heart' => dosomething_kudos_get_total_for_file_by_term_name($data->id, 'heart'),
    ];

    $data->existing_kids = dosomething_kudos_get_kudos_for_user_by_file($data->id);
  }

  if ($data instanceof ReportbackItem && user_access('view any reportback')) {
    $data->admin_link = '/admin/reportback/' . $data->reportback['id'];
  }

  return paraneue_dosomething_get_gallery_item($data, 'photo', FALSE);
}

/**
 * Returns specified number of themed Placeholder Reportbacks.
 *
 * @param  integer  $count
 * @return array
 */
function paraneue_dosomething_get_placeholder_reportbacks($count = 6) {
  $placeholders = [];
  $placeholder_urls = dosomething_campaign_get_default_gallery_image_urls();
  $placeholder_captions = [
    t('DoSomething? Just did.'),
    t('Doing good never looked so good.'),
    t('Don’t let the smile fool you. I crushed it.'),
    t('Making the world suck less, one photo at a time.'),
    t('Pics or it didn’t happen? Oh, it happened.'),
    t('I get action. Social action.'),
  ];

  // If no placeholders added to site, let's fallback to locally stored ones.
  if (!$placeholder_urls) {
    $placeholder_urls = [];
    for ($i = 1; $i <= $count; $i++) {
      $placeholder_urls[] = PARANEUE_PATH . '/dist/images/gallery-placeholder-' . $i . '.jpg';
    }
  }

  for ($i = 0; $i < $count; $i++) {
    $placeholder = (object) [];
    $placeholder->id = NULL;
    $placeholder->caption = $placeholder_captions[$i];
    $placeholder->media['uri'] = $placeholder_urls[$i];
    $placeholder->media['type'] = 'image';

    $placeholders[] = $placeholder;
  }

  return $placeholders;
}

/**
 * Get regional url data for specified node if it has translated content available.
 *
 * @param object $node  Specified Node object for which to add regional urls.
 * @return array|null
 */
function paraneue_dosomething_get_regional_url_data($node) {
  global $language_url;
  global $base_url;

  $available_translations = dosomething_helpers_isset($node->translations->data);

  if (!$available_translations) {
    return NULL;
  }

  $supported_languages = language_list();
  foreach ($supported_languages as $language) {
    $language->country = dosomething_global_convert_language_to_country($language->language);
  }

  $regional_url_data = [];

  foreach ($available_translations as $language_key => $translation) {
    // Skip creating regional url for global english.
    if ($language_key === 'en-global') {
      continue;
    }

    if (array_key_exists($language_key, $supported_languages) && $language_key !== $language_url->language) {
      $country = strtolower($supported_languages[$language_key]->country);
      $regional_url_data[$language_key] = $base_url . '/' . $country . '/' . drupal_get_path_alias('node/' . $node->nid, $language_key);
    }
  }

  return $regional_url_data;
}

/**
 * Return an assimilated collection of Reportbacks based on Promoted & Approved Reportback counts.
 *
 * @param  array  $gallery
 * @param  array  $reportbacks
 * @param  bool   $use_placeholders
 * @return bool
 */
function paraneue_dosomething_build_reportbacks_gallery_collection ($gallery, $reportbacks, $use_placeholders = FALSE) {
  $fill_count = $gallery['desired_count'] - $gallery['initial_promoted_count'];

  $filters = [
    'nid' => $gallery['campaign_id'],
    'status' => ['approved'],
    'random' => TRUE,
  ];

  // Absolutely no Approved Reportbacks to fulfill the fill count needed.
  if ($gallery['total_approved'] === 0) {
    if ($use_placeholders) {
      $placeholders = paraneue_dosomething_get_placeholder_reportbacks($fill_count);
      $reportbacks = array_merge($reportbacks, $placeholders);
    }
    else {
      return $reportbacks;
    }
  }

  // Some but not enough Approved Reportbacks to fulfill the fill count needed.
  elseif ($gallery['total_approved'] < $fill_count) {
    $filters['count'] = $gallery['total_approved'];

    try {
      $approvedReportbacks = (new ReportbackItem)->find($filters);
    }
    catch (Exception $error) {
      $approvedReportbacks = [];
    }

    $placeholders = paraneue_dosomething_get_placeholder_reportbacks($fill_count - $gallery['total_approved']);
    $reportbacks = array_merge($reportbacks, $approvedReportbacks, $placeholders);
  }

  // There are enough Approved Reportbacks to fulfill the fill count needed.
  else {
    $filters['count'] = $fill_count;

    try {
      $approvedReportbacks = (new ReportbackItem)->find($filters);
    }
    catch (Exception $error) {
      $approvedReportbacks = [];
    }

    $reportbacks = array_merge($reportbacks, $approvedReportbacks);
  }

  return $reportbacks;
}
