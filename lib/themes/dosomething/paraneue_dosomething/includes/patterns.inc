<?php
/**
 * @file
 * Functions for themeing Neue patterns.
 */

/**
 * Function that themes an item, based on a pattern from neue, that can then go into a gallery.
 *
 * @param mixed $content
 *   An associative array of content, can contain:
 *   - $content['title']: Used as a heading (string).
 *   - $content['description']: (string).
 *   - $content['impact']: Reportback impact (string).
 *   - $content['image']: Image markup to display (string).
 *   - $content['url']: Url to link to (string).
 * @param string $type
 *   The pattern that the content should be themed by.
 * @param boolean $use_default
 *   If the template should use a default image if it can't find one.
 * @param array $classes_array
 *   Array of classes to add to the gallery item template.
 *
 * @return string
 */
function paraneue_dosomething_get_gallery_item($content, $type = 'figure', $use_default = TRUE, $classes_array = array()) {

  // If no image is provided and we want to use a default, then set the default image here.
  if ($use_default) {
    $content = (array) $content;

    if (empty($content['image'])) {
      $content['image'] = theme('image', array(
        'path' => FORGE_ASSET_PATH . '/dist/assets/images/apple-touch-icon-precomposed.png'
      ));
    }
  }

  $variables = array(
    'content' => $content,
    'classes' => implode(' ', $classes_array)
  );

  $tpl = 'paraneue_' . $type;
  return theme($tpl, $variables);
}

/**
 * Function that returns a <ul> representing a gallery.
 *
 * @param array $content
 *   An array of themed content to go into each <li>.
 * @param string $layout
 *   The type of gallery.
 * @param array $classes_array
 *   Any additional classes to add to the <ul>.
 *
 * @return string
 */
function paraneue_dosomething_get_gallery($content, $layout = 'triad', $classes_array = array(), $show_more = FALSE, $title = '') {
  if (empty($content)) {
    return '';
  }
  $items = array();
  foreach ($content as $delta => $item) {
    $items[$delta]['content'] = $item;
  }
  $classes = NULL;
  if (!empty($classes_array)) {
    $classes = implode(' ', $classes_array);
  }
  $data_roles = NULL;
  if ($show_more){
    $data_roles = "data-show-more='true'";
  }
  // Prepare variables to send to gallery theme functions.
  $variables = array(
    'items' => $items,
    'title' => $title,
    'layout' => $layout,
    'classes' => $classes,
    'roles' => $data_roles,
  );
  return theme('paraneue_gallery', $variables);
}
