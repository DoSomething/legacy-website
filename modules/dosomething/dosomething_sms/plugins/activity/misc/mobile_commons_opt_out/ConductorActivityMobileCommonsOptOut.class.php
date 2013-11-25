<?php

/**
 * Opt-out the mobile user from a given campaign id(s)
 */
class ConductorActivityMobileCommonsOptOut extends ConductorActivity {

  /**
   * Array of campaign id(s) to opt the user out of.
   *
   * @var array
   */
  public $opt_out_ids = array();

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    dosomething_sms_mobile_commons_opt_out($mobile, $this->opt_out_ids);

    $state->markCompleted();
  }

}
