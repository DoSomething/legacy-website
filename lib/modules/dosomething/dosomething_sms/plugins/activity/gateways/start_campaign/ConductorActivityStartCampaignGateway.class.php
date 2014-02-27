<?php

/**
 * Through an mData trigger, users are opted out of a Mobile Commons transactional
 * campaign and opted in to a path in the campaign actual.
 */
class ConductorActivityStartCampaignGateway extends ConductorActivity {

  /**
   * Map of incoming requests from an mData ID and the campaign id to opt-out of
   * along with the path id to opt-in to.
   *
   * @var array
   */
  public $routes = array();

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $mdataID = intval($_REQUEST['mdata_id']);

    // Find the routing info for replies through this mdata id
    if (array_key_exists($mdataID, $this->routes)) {
      $route = $this->routes[$mdataID];

      // Opt the user out of the transactional campaign
      dosomething_sms_mobile_commons_opt_out($mobile, $route['out_campaign_id']);

      // Opt the user into a path in the actual campaign
      dosomething_sms_mobile_commons_opt_in($mobile, $route['opt_in_path_id']);
    }

    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }
}
