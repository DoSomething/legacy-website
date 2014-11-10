<?php
/**
 * @file
 * Functions for themeing Neue patterns.
 */

/**
 * Function that themes an item, based on a pattern from neue, that can then go into a gallery. 
 *
 * @param array $content
 *   array that can contain: 
 *     - title
 *     - description
 *     - impact
 *     - image
 *     - url
 * @param string $classes
 *   Any additional class(es) added into the <ul>.
 *
 * @param $type - The pattern that the content should be themed by. 
 */
function paraneue_get_gallery_item($content, $type) {
  $variables = array(
    'content' => $content,
    'classes' => $classes,
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
 * @param sting $layout
 *   The type of gallery.
 * @param sting $classes
 *   Any additional classes to append to the <ul> classes.
 *
 * @return string
 */
function paraneue_get_gallery($content, $layout = 'triad', $classes = NULL) {
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
