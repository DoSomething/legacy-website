<?php

/**
 * Extends ConductorActivitySMSPrompt. Asks user a question and expects an MMS
 * image in return.
 */
class ConductorActivityMMSPrompt extends ConductorActivitySMSPrompt {

  /**
   * If no mms image is found, opt user into this Mobile Commons path.
   *
   * @var int
   */
  public $noMmsResponse;

  public function run() {
    $state = $this->getState();

    // Process user's response, expecting any mms to be in $_REQUEST['mms_image_url'].
    // If none is set, jump to the end of the workflow.
    $mms_image_url = $_REQUEST['mms_image_url'];
    if (!empty($mms_image_url)) {
      $state->setContext($this->name . ':mms', $mms_image_url);
    }
    elseif (!empty($this->noMmsResponse)) {
      // Send user a response for no MMS being sent.
      $mobile = $state->getContext('sms_number');
      dosomething_sms_mobilecommons_opt_in($mobile, $this->noMmsResponse);

      // Bypass conductor_sms error thrown when no text response is given.
      $state->setContext('ignore_no_response_error', TRUE);

      // Send user to the end of the workflow.
      self::useOutput('end');
    }

    $state->markCompleted();
  }

  /**
   * Removes all outputs from this activity except for the one specified in the param
   *
   * @param string $activityName
   *   Name of activity in outputs array to keep
   */
  private function useOutput($activityName) {
    foreach($this->outputs as $key => $val) {
      if ($val != $activityName) {
        unset($this->outputs[$key]);
      }
    }
  }

}
