<?php

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
  if ($op == 'index') {
    return TRUE;
  }

  $node = node_load($args[0]);

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

  return dosomething_reportback_save($values);
}
