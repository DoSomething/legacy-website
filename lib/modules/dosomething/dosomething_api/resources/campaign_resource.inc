<?php

function _campaign_resource_defintion() {
  $campaign_resource = array();
  $campaign_resource['campaigns'] = array(
    'operations' => array(
      'index' => array(
        'help' => 'List all active campaigns.',
        'file' => array('type' => 'inc', 'module' => 'dosomething_api', 'name' => 'resources/campaign_resource'),
        'callback' => '_campaign_resource_index',
        'access callback' => '_campaign_resource_access',
        'access arguments' => array('index'),
        'args' => array(
          array(
            'name' => 'parameters',
            'optional' => TRUE,
            'type' => 'array',
            'description' => 'Parameters',
            'default value' => array(),
            'source' => array('param' => 'parameters'),
          ),
        ),
      ),
    ),
    'relationships' => array(
      'gallery' => array(
        'file' => array('type' => 'inc', 'module' => 'dosomething_api', 'name' => 'resources/campaign_resource'),
        'help'   => 'Returns Reportback Gallery. GET from campaigns/123/gallery',
        'access callback' => '_node_resource_access',
        'access arguments' => array('view'),
        'access arguments append' => TRUE,
        'callback' => '_campaign_resource_load_gallery',
        'args'     => array(
          array(
            'name' => 'nid',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'int',
            'description' => 'The nid of the node whose gallery we are getting',
          ),
          array(
            'name'         => 'count',
            'type'         => 'int',
            'description'  => t('Number of Reportback Files to load.'),
            'source'       => array('param' => 'count'),
            'optional'     => TRUE,
          ),
          array(
            'name'         => 'offset',
            'type'         => 'int',
            'description'  => t('If count is set to non-zero value, you can pass also non-zero value for start. For example to get Reportback Files from 5 to 15, pass count=10 and start=5.'),
            'source'       => array('param' => 'offset'),
            'optional'     => TRUE,
          ),
        ),
      ),
    ),
    'targeted_actions' => array(
      'signup' => array(
        'help' => 'Signup a user for a campaign. POST to campaigns/123/signup',
        'file' => array('type' => 'inc', 'module' => 'dosomething_api', 'name' => 'resources/campaign_resource'),
        'callback' => '_campaign_resource_signup',
        'access callback' => '_campaign_resource_access',
        'access arguments' => array('signup'),
        'access arguments append' => TRUE,
        'args' => array(
          array(
            'name' => 'nid',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'int',
            'description' => 'The nid of the Campaign node to signup for.',
          ),
          array(
            'name' => 'values',
            'optional' => FALSE,
            'source' => 'data',
            'description' => 'The Signup data',
            'type' => 'array',
          ),
        ),
      ),
      'reportback' => array(
        'help' => 'Post a user reportback for a campaign: campaigns/123/reportback',
        'file' => array('type' => 'inc', 'module' => 'dosomething_api', 'name' => 'resources/campaign_resource'),
        'callback' => '_campaign_resource_reportback',
        'access callback' => '_campaign_resource_access',
        'access arguments' => array('reportback'),
        'access arguments append' => TRUE,
        'args' => array(
          array(
            'name' => 'nid',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'int',
            'description' => 'The nid of the Campaign node to post a reportback.',
          ),
          array(
            'name' => 'values',
            'optional' => FALSE,
            'source' => 'data',
            'description' => 'The Reportback data',
            'type' => 'array',
          ),
        ),
      ),
    ),
  );
  return $campaign_resource;
}

/**
 * Determine whether the current user can access a node resource.
 *
 * @param string $op
 *   Possible values of view, signup, reportback.
 * @param array $args
 *   Resource arguments passed through from the original request.
 * @return bool
 *
 * @see node_access()
 */
function _campaign_resource_access($op = 'view', $args = array()) {
  if (DOSOMETHING_REPORTBACK_LOG) {
    watchdog('dosomething_api', '_campaign_resource_access args:' . json_encode($args));
  }

  if ($op == 'index') {
    return TRUE;
  }

  $node = node_load($args[0]);
  if (!$node) {
    return services_error(t('No node found for @nid', array('@nid' => $args[0])), 403);
  }

  if ($op == 'view') {
    return node_access($op, $node);
  }

  if (!user_is_logged_in()) {
    return services_error(t('Must be logged in!'), 403);
  }

  if (dosomething_campaign_is_active($node)) {
    return TRUE;
    //@todo: If op==reportback and SMS Game, return 403 error.
  }

  return services_error(t('Campaign node @nid is not active.', array('@nid' => $node->nid)), 403);
}

/**
 * Callback for Campaigns index.
 */
function _campaign_resource_index($parameters) {
  // Initialize output.
  $index = array();

  // Get the results of the explore_campaigns view.
  $view = views_get_view('explore_campaigns');
  $view->execute();

  $filter_staff_pick = FALSE;
  if (isset($parameters['is_staff_pick']) && $parameters['is_staff_pick']) {
    $filter_staff_pick = TRUE;
  }

  foreach ($view->result as $result) {
    $campaign = new StdClass();
    $campaign->title = $result->label;
    $campaign->nid = $result->entity_id;
    $campaign->is_staff_pick = $result->bm_field_staff_pick[0];
    // If not filtering by staff pick:
    if (!$filter_staff_pick) {
      // Add this campaign to the result.
      $index[] = $campaign;
    }
    // Else check if it's a staff pick:
    if ($campaign->is_staff_pick) {
      $index[] = $campaign;
    }
  }

  return $index;
}

/**
 * Callback for Campaigns Signup targeted action.
 *
 * @param int $nid
 *   The Node nid to post the signup to.
 * @param array $values
 *   The signup data to post. Expected keys:
 *   - uid: The user uid (int).  Optional, uses global $user if not set.
 *   - source (string).
 */
function _campaign_resource_signup($nid, $values) {
  global $user;
  if (!isset($values['uid'])) {
    $values['uid'] = $user->uid;
  }
  if (!isset($values['source'])) {
    $values['source'] = NULL;
  }
  if (DOSOMETHING_SIGNUP_LOG_SIGNUPS) {
    watchdog('dosomething_api', '_campaign_resource_signup values:' . json_encode($values));
  }
  // @todo: Pass parameter into signup_create whether or not to send SMS.
  // Since SMS campaign signups would hit this endpoint, would not want 
  // to send an additional "You've signed up text".
  return dosomething_signup_create($nid, $values['uid'], $values['source']);
}

/**
 * Callback for Campaigns Reportback targeted action.
 *
 * @param int $nid
 *   The Node nid to post the reportback to.
 * @param array $values
 *   The reportback data to post. Expected keys:
 *   - uid: The user uid (int).  Optional, uses global $user if not set.
 *   - file_url: The URL of the reportback file.
 *   - quantity (int).
 *   - why_participated (string).
 *   - num_participants (int).
 */
function _campaign_resource_reportback($nid, $values) {
  // @todo: Return error if signup doesn't exist.
  $values['nid'] = $nid;
  if (!isset($values['uid'])) {
    global $user;
    $values['uid'] = $user->uid;
  }
  $uid = $values['uid'];

  // Create a file from the $file_url.
  $file = dosomething_reportback_save_file_from_url($nid, $uid, $values['file_url']);
  if (!$file) {
    return FALSE;
  }
  $values['fid'] = $file->fid;

  // @todo: Move this logic into dosomething_reportback_save().
  $rbid = dosomething_reportback_exists($nid, $uid);
  if (!$rbid) {
    $rbid = 0;
  }
  $values['rbid'] = $rbid;
  if (DOSOMETHING_REPORTBACK_LOG) {
    watchdog('dosomething_api', '_campaign_resource_reportback:' . json_encode($values));
  }
  return dosomething_reportback_save($values);
}

/**
 * Returns the Reportback Gallery of a specified node.
 *
 * @param $nid
 *   Unique identifier for the node.
 * @param $count
 *   Number of Reporback Files to return.
 * @param $start
 *   Which RB File to start with. If present, $start and $count are used together
 *   to create a LIMIT clause to select RB Files. This could be used to do paging.
 *
 * @return
 *   An array of Reportback File objects.
 */
function _campaign_resource_load_gallery($nid, $count = 25, $start = 0) {
  // Load Services module to use its index_query functions.
  module_load_include('inc', 'services', 'services.module');
  $int_properties = array('rbid', 'fid', 'fid_processed');
  $params = array(
    'nid' => $nid,
    'status' => 'approved',
    'count' => $count,
    'start' => $start,
  );
  $results = dosomething_reportback_get_reportback_files_query(0, $params);
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
