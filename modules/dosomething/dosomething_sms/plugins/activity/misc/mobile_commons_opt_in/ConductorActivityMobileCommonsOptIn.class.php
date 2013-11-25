<?php

/**
 * Opt-in the mobile user into a given Mobile Commons opt-in path.
 */
class ConductorActivityMobileCommonsOptIn extends ConductorActivity {

  /**
   * The Mobile Commons opt-in path to join the user into.
   *
   * @var int
   */
  public $opt_in_path_id;

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    dosomething_sms_mobile_commons_opt_in($mobile, $this->opt_in_path_id);

    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }

}
