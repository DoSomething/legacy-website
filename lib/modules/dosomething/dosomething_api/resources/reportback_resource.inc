<?php

function _reportback_resource_defintion() {
  $resources = array();
  $resources['reportback_files'] = array(
    'targeted_actions' => array(
      'review' => array(
        'help' => 'Review a reportback file. POST to reportback_files/123/review',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_resource',
        ),
        'callback' => '_reportback_resource_review',
        'access arguments' => array('view any reportback'),
        'args' => array(
          array(
            'name' => 'fid',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'int',
            'description' => 'The fid of the Reportback File to review.',
          ),
          array(
            'name' => 'values',
            'optional' => FALSE,
            'source' => 'data',
            'description' => 'Array including Reviewer status and source',
            'type' => 'array',
          ),
        ),
      ),
    ),
  );
  return $resources;
}

/**
 * Callback for Reportback Files review targeted action.
 *
 * @param int $fid
 *   The Reportback File fid to post the review to.
 * @param array $values
 *   The review data to post. Expected keys:
 *   - status: (string).
 *   - source (string). e.g. 'ios', 'android'.
 */
function _reportback_resource_review($fid, $values) {
  $rbf = reportback_file_load($fid);
  if (!$rbf) {
    return NULL;
  }
  $rbf->review($values);
  return $rbf;
}
