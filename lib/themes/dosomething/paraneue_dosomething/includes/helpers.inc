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
function paraneue_dosomething_get_gallery_item_order_class($index) {
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

/**
 * Returns a an array split into chunks of new arrays
 *
 * @param array $array
 *   An array to be chunked
 *
 * @param int $size
 *   Specifies size of each chunk
 *
 * @return array
 *   Array of array chunks
 */
function paraneue_dosomething_chunk_array($array, $size) {
  return array_chunk($array, $size);
}
