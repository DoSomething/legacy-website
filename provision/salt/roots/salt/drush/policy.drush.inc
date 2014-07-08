<?php

function drush_policy_sql_sync_validate($source = NULL, $destination = NULL) {
  dosomething_check_target($destination, 'db');
}

function drush_policy_core_rsync_validate($source, $destination, $additional_options = array()) {
  dosomething_check_target($destination, 'files');
}

function dosomething_check_target($destination, $asset) {
  if (stristr($destination, '.prod')|| stristr($destination, '.staging')) {
    return drush_set_error('POLICY_DENY', dt('You cannot overwrite the !destination !asset from here', array('!destination' => $destination, '!asset' => $asset)));
  }
}
