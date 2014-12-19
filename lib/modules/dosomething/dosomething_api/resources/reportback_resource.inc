<?php

function _reportback_resource_defintion() {
  $resources = array();
  $resources['reportback_files'] = array(
    'operations' => array(
      'index' => array(
        'help' => 'List all reportback files',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_resource',
        ),
        'callback' => '_reportback_file_resource_index',
        'args' => array(
          array(
            'name' => 'page',
            'optional' => TRUE,
            'type' => 'int',
            'description' => 'The zero-based index of the page to get, defaults to 0.',
            'default value' => 0,
            'source' => array('param' => 'page'),
          ),
          array(
            'name' => 'parameters',
            'optional' => TRUE,
            'type' => 'array',
            'description' => 'Parameters array',
            'default value' => array(),
            'source' => array('param' => 'parameters'),
          ),
          array(
            'name' => 'pagesize',
            'optional' => TRUE,
            'type' => 'int',
            'description' => 'Number of records to get per page.',
            'default value' => variable_get('services_node_index_page_size', 20),
            'source' => array('param' => 'pagesize'),
          ),
        ),
        'access arguments' => array('access content'),
      ),
    ),
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
 * Return an array of optionally paged reportback files based on a set of criteria.
 *
 * @param $page
 *   Page number of results to return (in pages of $pagesize, or 20).
 * @param $parameters
 *   An array containing fields and values used to build a sql WHERE clause
 *   indicating items to retrieve.
 * @param $page_size
 *   Integer number of items to be returned.
 *
 * @return
 *   An array of Reportback File objects.
 */
function _reportback_file_resource_index($page, $parameters, $page_size) {
  // Load Services module to use its index_query functions.
  module_load_include('inc', 'services', 'services.module');

  $int_properties = array('rbid', 'fid', 'fid_processed', 'nid', 'quantity');
  $results = dosomething_reportback_get_reportback_files_query($page, $parameters, $page_size);
  $result = services_resource_build_index_list($results, 'reportback_files', 'fid');

  foreach ($result as &$record) {
    // Convert string output to integers were appropriate.
    foreach ($int_properties as $property) {
      $record->{$property} = (int) $record->{$property};
    }
    // We'll eventually want to use the fid_processed here.
    // And also probably won't need to apply an image style, since it
    // will already be cropped.
    $record->src = dosomething_image_get_themed_image_url_by_fid($record->fid, '300x300');
  }
  // @see http://php.net/manual/en/control-structures.foreach.php:
  // Reference of a $value and the last array element remain even after
  // the foreach loop. It is recommended to destroy it by unset().
  unset($record);
  return $result;
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
