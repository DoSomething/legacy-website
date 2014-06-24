<?php

  /**
   * Helper functions for theming.
   */


	/**
	 * Returns class name (either 'first', 'second', 'third') for a given $key.
	 */
	function helpers_get_gallery_item_order_class($key) {
	  // Assuming $key starts with 0;
	  $key++;
	  switch ($key%3) {
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