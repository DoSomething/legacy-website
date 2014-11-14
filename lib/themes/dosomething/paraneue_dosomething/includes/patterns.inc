<?php
/**
 * @file
 * Functions for themeing Neue patterns.
 */

/**
 * Function that themes an item, based on a pattern from neue, that can then go into a gallery.
 *
 * @param array $content
 *   An associative array of content, can contain:
 *   - $content['title']: Used as a heading (string).
 *   - $content['description']: (string).
 *   - $content['impact']: Reportback impact (string).
 *   - $content['image']: Image markup to display (string).
 *   - $content['url']: Url to link to (string).
 *
 * @param string $type
 *   The pattern that the content should be themed by.
 *
 * @param boolean $use_default
 *   If the template should use a default image if it can't find one.
 *
 * @return string
 */
function paraneue_get_gallery_item($content, $type, $use_default) {
  // If no image is provided and we want to use a default, then set the default image here.
  if (empty($content['image']) && $use_default) {
    $content['image'] = "<img src='/" . path_to_theme() . "/bower_components/neue/dist/assets/images/apple-touch-icon-precomposed.png' />";
  }

  $variables = array(
    'content' => $content,
  );

  switch ($type) {
    case 'media':
      return theme('paraneue_media', $variables);
    default:
      return theme('paraneue_figure', $variables);
  }
}

/**
 * Function that returns a <ul> representing a gallery.
 *
 * @param array $content
 *   An array of themed content to go into each <li>.
 * @param string $layout
 *   The type of gallery.
 * @param string $classes
 *   Any additional classes to append to the <ul> classes.
 *
 * @return string
 */
function paraneue_get_gallery($content, $layout = 'triad', $classes = NULL) {
  if (empty($content)) {
    return '';
  }
  $items = array();
  foreach ($content as $delta => $item) {
    $items[$delta]['content'] = $item;
    $class = paraneue_dosomething_get_gallery_item_order_class($delta, $layout);
    $items[$delta]['class'] = $class;
  }

  // Prepare variables to send to gallery theme functions.
  $variables = array(
    'items' => $items,
    'layout' => $layout,
    'classes' => $classes,
  );
  return theme('paraneue_gallery', $variables);
}
