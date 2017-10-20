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
        'url' => '/' . $value['path_alias'] . '#prove',
        'button_text' => t("Prove It"),
      );
      $doing_items[$delta] = paraneue_dosomething_get_gallery_item($item, 'figure');
    }
    $vars['doing_gallery'] = paraneue_dosomething_get_gallery($doing_items, 'triad', array(), TRUE);
  }

  $reportback_items = $vars['reportbacks'];

  // Theme a gallery of reportbacks, and give the user profile template access to it.
  $vars['reportback_gallery'] = paraneue_dosomething_get_gallery($reportback_items, 'duo', [], TRUE);
}
