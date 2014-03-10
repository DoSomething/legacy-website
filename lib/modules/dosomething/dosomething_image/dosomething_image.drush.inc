<?php

/**
 * Implements hook_drush_cache_clear().
 */
function dosomething_image_drush_cache_clear(&$types) {
  $types['dosomething image'] = 'dosomething_image_cache_clear_all';
}