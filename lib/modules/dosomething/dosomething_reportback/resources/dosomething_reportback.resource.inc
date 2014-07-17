<?php
/**
 * @file
 * Code for DoSomething Reportback Services resources.
 *
 * @see dosomething_reportback_services_resources()
 */

/**
 * Access callback for Reportback resources.
 */
function _dosomething_reportback_resource_access() {
  global $user;
  // For now, only admins can access any reportback resources.
  return in_array('administrator', $user->roles);
}

/**
 * Callback for Reportback resource retrieve.
 */
function _dosomething_reportback_resource_retrieve($rbid) {
  if ($reportback = reportback_load($rbid)) {
    return get_object_vars($reportback);
  }
  else {
    return FALSE;
  }
}

/**
 * Callback for Reportback resource save.
 */
function _dosomething_reportback_resource_save($uid, $nid, $quantity, $why_participated, $file_url) {
  // Create a file from the $file_url.
  $file = dosomething_reportback_save_file_from_url($nid, $uid, $file_url);
  if (!$file) {
    return FALSE;
  }
  // @todo: Move this logic into dosomething_reportback_save().
  $rbid = dosomething_reportback_exists($nid, $uid);
  if (!$rbid) {
    $rbid = 0;
  }
  // Prepare values for save.
  $values = array(
    'rbid' => $rbid,
    'uid' => $uid,
    'nid' => $nid,
    'quantity' => $quantity,
    'why_participated' => $why_participated,
    'fid' => $file->fid,
  );
  return dosomething_reportback_save($values);
}
