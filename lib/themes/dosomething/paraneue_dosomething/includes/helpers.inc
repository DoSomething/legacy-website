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
      'glyph' => '&#xe600;'
    ),
    'twitter'   => array(
      'id'    => 'twitter',
      'name'  => t('Twitter'),
      'glyph' => '&#xe603;'
    ),
    'tumblr'    => array(
      'id'    => 'tumblr',
      'name'  => t('Tumblr'),
      'glyph' => '&#xe602;'
    ),
    'instagram' => array(
      'id'    => 'instagram',
      'name'  => t('Instagram'),
      'glyph' => '&#xe604;'
    ),
    'youtube'   => array(
      'id'    => 'youtube',
      'name'  => t('Youtube'),
      'glyph' => '&#xe601;'
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
      case 'campaign':
        $result_node = node_load($value['node']->entity_id);
        // Get the image field from the campaign node.
        $image = $result_node->field_image_campaign_cover;
        // Make it available as a variable, if it exists. Otherwise, leave it empty.
        if (!empty($image)) {
          $value['display_image'] = dosomething_image_get_themed_image($image['und'][0]['target_id'], 'square', '300x300');
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
      break;
      default:
        break;
    }
    $result_variables[$delta] = $item;
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
      $result_items[$delta] = paraneue_get_gallery_item($value, 'media', TRUE);
    }
  }
  // Theme the set of results as duo gallery.
  return paraneue_get_gallery($result_items, 'duo');
}
