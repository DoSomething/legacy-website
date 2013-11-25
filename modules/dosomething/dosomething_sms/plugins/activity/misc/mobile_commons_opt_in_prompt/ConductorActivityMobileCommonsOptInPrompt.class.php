<?php

/**
 * Extends ConductorActivitySMSPrompt. Opts the user into a Mobile Commons
 * opt-in path and suspends the workflow until a response is received.
 */
class ConductorActivityMobileCommonsOptInPrompt extends ConductorActivitySMSPrompt {

  /**
   * The Mobile Commons opt-in path to join the user into.
   *
   * @var int
   */
  public $opt_in_path_id;

  public function run() {
    $state = $this->getState();

    if ($state->getContext($this->name . ':message') === FALSE && !empty($this->opt_in_path_id)) {
      $mobile = $state->getContext('sms_number');
      dosomething_sms_mobile_commons_opt_in($mobile, $this->opt_in_path_id);

      $state->setContext('ignore_no_response_error', TRUE);
      $state->markSuspended();
      return;
    }

    parent::run();
  }

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers() {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }

}
