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
