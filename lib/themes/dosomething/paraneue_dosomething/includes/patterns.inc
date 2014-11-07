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
 * @param array $items
 *   An array of themed items to go into each <li>. 
 *
 * @param $type - The type of gallery. 
 *
 * @return string
 */
function paraneue_get_gallery($items, $type = 'triad', $classes = NULL) {
  // Prepare variables to send to gallery theme functions.
  $variables = array(
    'items' => $items,
    'classes' => $classes,
  );

  switch ($type) {
    case 'duo':
      return theme('paraneue_gallery_duo', $variables);
    case 'triad':
      return theme('paraneue_gallery_triad', $variables);
  }
}
