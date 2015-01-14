<?php
/**
 * @file
 * Helper functions for theming.
 */

/**
 * Returns a css class name (either 'first', 'second', 'third') for a given $index.
 *
 * @param int $index
 *   An index of an array being iterated.
 *
 * @return string
 *   CSS class name
 */
function paraneue_dosomething_get_gallery_item_order_class($index, $layout = 'triad') {
  if ($layout == 'duo') {
    if ($index % 2) {
      return '-second';
    }
    return '-first';
  }
  elseif ($layout == 'triad') {
    $index++;
    switch ($index % 3) {
      case 0:
        return '-third';
        break;
      case 1:
        return '-first';
        break;
      case 2:
        return '-second';
        break;
      default:
        return;
    }
  }
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
    'tumblr'    => array(
      'id'    => 'tumblr',
      'name'  => t('Tumblr'),
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
        $image = $result_node->field_image_campaign_cover;
        // Make it available as a variable, if it exists. Otherwise, leave it empty.
        if (!empty($image)) {
          $value['display_image'] = dosomething_image_get_themed_image($image['und'][0]['target_id'], 'square', '100x100');
        }
        else {
          $value['display_image'] = '';
        }
        $value['subtitle'] = $value['fields']['sm_field_call_to_action'][0];
        $item = array(
          'title' => $value['title'],
          'link' => $value['link'],
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
          'link' => $value['link'],
          'description' => $value['subtitle'],
        );
        $result_variables[$delta] = $item;
      break;
      default:
        $item = array(
          'title' => $value['title'],
          'link' => $value['link'],
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
      $result_items[$delta] = paraneue_dosomething_get_gallery_item($value, 'media', TRUE);
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
  $classes_array = array();

  $node = node_load($nid);
  $link = drupal_get_path_alias('node/' . $nid);
  if ($source) {
    $link .= '?source=' . $source;
  }

  $title = $node->title;
  if ($node->status == 0) {
    $title = t('Stay Tuned');
    $classes_array[] = '-unpublished';
  }

  $image = NULL;
  // If the node has a Cover Image:
  if (!empty($node->field_image_campaign_cover)) {
    // Presets for the node's Cover Image display.
    $ratio = 'square';
    $default = '400x400';
    $large = '768x768';
    // Get the Cover Image node nid.
    $nid_image = $node->field_image_campaign_cover[LANGUAGE_NONE][0]['target_id'];
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
    'tagline' => $node->field_call_to_action[LANGUAGE_NONE][0]['value'],
    'status' => $node->status,
    'image' => $image,
    'is_staff_pick' => $node->field_staff_pick[LANGUAGE_NONE][0]['value'],
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
  $items = array();
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
 * Returns a themed gallery of recommended campagins.
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
      $image = dosomething_image_get_themed_image($value['nid_image'], 'landscape', '300x300');
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
