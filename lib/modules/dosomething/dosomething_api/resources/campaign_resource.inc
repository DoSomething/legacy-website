<?php

/**
 * Access callback for Campaign resources.
 */
function _campaign_resource_access() {
  watchdog('dosomething_api', "what the fuck");
  return TRUE;
}

function _campaign_resource_index() {
  $view = views_get_view('explore_campaigns');
  $view->execute();
  $index = array();
  foreach ($view->result as $result) {
    $campaign = new StdClass();
    $campaign->title = $result->label;
    $campaign->nid = $result->entity_id;
    $campaign->is_staff_pick = $result->bm_field_staff_pick[0];
    $index[] = $campaign;
  }
  return $index;
}

