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
  public $optInPathId;

  public function run() {
    $state = $this->getState();

    if ($state->getContext($this->name . ':message') === FALSE && !empty($this->optInPathId)) {
      // Opt user into a Mobile Commons path.
      $mobile = $state->getContext('sms_number');
      dosomething_sms_mobilecommons_opt_in($mobile, $this->optInPathId);

      // Bypass conductor_sms error thrown when no text response is given.
      $state->setContext('ignore_no_response_error', TRUE);

      // Wait for user response before going to next activity in workflow.
      $state->markSuspended();
      return;
    }

    parent::run();
  }

}
