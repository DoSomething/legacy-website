<?php

/**
 * Implements theme_preprocess_page().
 */
function paraneue_dosomething_preprocess_page(&$vars) {
  $vars['logo'] = $vars['base_path'] . NEUE_PATH . '/assets/images/ds-logo.png';


  // Navigation Output Setup
  $navigation_vars = array(
    'base_path' => $vars['base_path'],
    'front_page' => $vars['front_page'],
    'logged_in' => $vars['logged_in'],
    'search_box' => $vars['search_box'],
  );

  $vars['navigation'] = theme('navigation', $navigation_vars);


  // Footer Output Setup
  $vars['footer'] = theme('footer');
}

/**
 * Implements theme_preprocess_node().
 */
function paraneue_dosomething_preprocess_node(&$variables) {
  if($variables['node']->type == "home") {
    $homepage_nids = array(362, 843, 955, 832, 15, 31, 55, 850, 18);
    $thumbnails = array();

    foreach($homepage_nids as $key => &$nid) {
      $node = node_load($nid);

      $thumbnail = array();
      $thumbnail[nid] = $nid;
      $thumbnail[staff_pick] = $node->field_staff_pick[LANGUAGE_NONE][0][value];
      if($key == 0) { $thumbnail[modifier_classes] = "big"; }
      $thumbnail[title] = $node->title;
      $thumbnail[cta] = $node->field_call_to_action[LANGUAGE_NONE][0][safe_value];

      $image_nid = $node->field_image_campaign_cover[LANGUAGE_NONE][0][target_id];
      $thumbnail[image] = dosomething_image_get_themed_image_url($image_nid, 'square', '300x300');

      $thumbnail[link] = l('<span>' . $title . '</span>', 'node/' . $nid, array(
        'attributes' => array(
          'class' => array('full-link')
        ),
        'html' => TRUE
      ));

      $thumbnails[$nid] = theme('thumbnail', $thumbnail);
    }

    $variables['thumbnails'] = $thumbnails;
  }
}

/**
 * Implements theme_preprocess_user_profile().
 */
function paraneue_dosomething_preprocess_user_profile(&$variables) {
  // krumo($variables);
  // May delete this function if processing output content in the module.
}
