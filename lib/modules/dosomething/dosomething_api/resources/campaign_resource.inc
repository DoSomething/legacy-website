<?php

/**
 * Access callback for Campaign resources.
 */
function _campaign_resource_access() {
  return TRUE;
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
 * Callback for Campaigns signup targeted action.
 */
function _campaign_resource_signup($nid) {
  // @todo: Pass parameter into signup_create whether or not to send SMS.
  // Since SMS campaign signups would hit this endpoint, would not want 
  // to send an additional "You've signed up text".
  return dosomething_signup_create($nid);
}
