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
 *
 * @param $type - The pattern that the content should be themed by. 
 */
function paraneue_get_gallery_item($content, $type) {
  $variables = array(
    'content' => $content,
  );

  switch ($type) {
    case 'media':
      return theme('paraneue_media', $variables);
      break;
    default:
      break;
  }
}

/**
 * Function that returns a <ul> representing a gallery.  
 *
 * @param array $items
 *   An array of themed items to go into each <li>. 
 *
 * @param $type - The type of gallery. 
 */
function paraneue_get_gallery($items, $type) {
  $variables = array(
    'items' => $items,
  );

  switch ($type) {
    case 'duo':
      return theme('paraneue_gallery_duo', $variables);
      break;
    default:
      break;
  }
}
