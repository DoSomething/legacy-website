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
