<?php

/**
 * Preprocesses variables for user profiles.
 *
 * Themes the doing, reportback galleries.
 */
function paraneue_dosomething_preprocess_user_profile(&$vars) {
  global $base_url;
  global $user;
  $language = $user->language;

  if ($doing = $vars['doing']) {
    foreach ($doing as $delta => $value) {
      $image = dosomething_image_get_themed_image($value['nid_image'], 'landscape', '400x400');
      $item = array(
        'title' => htmlspecialchars_decode($value['link'], ENT_QUOTES),
        'image' => $image,
        'description' => $value['call_to_action'],
        'url' => dosomething_global_node_url($value['nid'], $language, 'prove'),
        'button_text' => t("Prove It"),
      );
      $doing_items[$delta] = paraneue_dosomething_get_gallery_item($item, 'figure');
    }
    $vars['doing_gallery'] = paraneue_dosomething_get_gallery($doing_items, 'triad', array(), TRUE);
  }
  // Get an array of reportbacks.
  $reportbacks = $vars['reportbacks'];
  if (!empty($reportbacks)) {
    // Theme each reportback and create an array.
    foreach ($reportbacks as $delta => $rbid) {
      $reportback = reportback_load((int) $rbid);
      $impact = $reportback->quantity . ' ' . $reportback->noun . ' ' . $reportback->verb;
      if (user_access('view any reportback')) {
        // Link to the full reportback entity view.
        $impact = l($impact, 'admin/reportback/' . $rbid);
      }
      else {
        $impact = l($impact, 'reportback/' . $rbid);
      }
      $img = dosomething_image_get_themed_image_by_fid($reportback->fids[0], '300x300');
      // Media gallery template expects a full URL.
      $url = dosomething_global_url('node/' . $reportback->nid);
      $content = array(
        'url' => $url,
        'title' => htmlspecialchars_decode($reportback->node_title, ENT_QUOTES),
        'image' => $img,
        'description' => $impact,
      );

      $reportback_items[$delta] = paraneue_dosomething_get_gallery_item($content, 'figure', TRUE, ['-left', '-medium', '-tinted']);
    }
  }
  // Theme a gallery of reportbacks, and give the user profile template access to it.
  $vars['reportback_gallery'] = paraneue_dosomething_get_gallery($reportback_items, 'duo', [], TRUE);
}

