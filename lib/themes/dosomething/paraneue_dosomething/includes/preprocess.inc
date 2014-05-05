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
  if ($variables['node']->type == "campaign") {
    // If the campaign requires a signup modal to display:
    if (isset($variables['node']->required_signup_data_form)) {
      // Add JS to open the signup data form modal.
      $id = 'modal-signup-data-form';
      $js = 'require(["neue/modal"], function(Modal) { Modal.open( $("#[' . $id . ']"), false); });';
      drupal_add_js($js, 'inline');
    }
  }
  elseif ($variables['node']->type == "home") {
    $homepage_nids = array(362, 832, 8, 843, 15, 31, 345, 17, 850);
    $thumbnails = array();

    foreach($homepage_nids as $key => $nid) {
      $node = node_load($nid);

      $thumbnail = array();
      $thumbnail['nid'] = $nid;
      $thumbnail['staff_pick'] = $node->field_staff_pick[LANGUAGE_NONE][0]['value'];
      $thumbnail['title'] = $node->title;
      $thumbnail['cta'] = $node->field_call_to_action[LANGUAGE_NONE][0]['safe_value'];

      $image_nid = $node->field_image_campaign_cover[LANGUAGE_NONE][0]['target_id'];
      if($key == 0) {
        $thumbnail['modifier_classes'] = "big";
        $thumbnail['image'] = dosomething_image_get_themed_image_url($image_nid, 'square', '720x720');
      } else {
        $thumbnail['image'] = dosomething_image_get_themed_image_url($image_nid, 'square', '400x400');
      }

      $thumbnail['link'] = l('<span>' . $title . '</span>', 'node/' . $nid, array(
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
