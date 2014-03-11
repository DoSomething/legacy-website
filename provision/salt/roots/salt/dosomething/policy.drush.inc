<?php

function drush_policy_sql_sync_validate($source = NULL, $destination = NULL) {
  if ($destination == '@ds.staging') {
    return drush_set_error('POLICY_DENY', dt('You cannot overwrite the staging db from here'));
  }
}

function drush_policy_core_rsync_validate($source, $destination, $additional_options = array()) {
  if ($destination == '@ds.staging') {
    return drush_set_error('POLICY_DENY', dt('You cannot overwrite the staging files from here'));
  }
}
