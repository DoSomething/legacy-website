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
          // @todo: We'll want this for SMS campaigns where uid doesn't exist?
          // array(
          //   'name' => 'uid',
          //   'optional' => TRUE,
          //   'source' => array('data' => 'uid'),
          //   'description' => 'The User uid to signup',
          //   'type' => 'int',
          // ),
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
 */
function _campaign_resource_signup($nid) {
  // @todo: Pass parameter into signup_create whether or not to send SMS.
  // Since SMS campaign signups would hit this endpoint, would not want 
  // to send an additional "You've signed up text".
  return dosomething_signup_create($nid);
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
