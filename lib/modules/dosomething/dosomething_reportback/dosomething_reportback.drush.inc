<?php

/**
 * Implements hook_drush_cache_clear().
 */
function dosomething_reportback_drush_cache_clear(&$types) {
  $types['dosomething reportback'] = 'dosomething_reportback_cache_clear_all';
}
