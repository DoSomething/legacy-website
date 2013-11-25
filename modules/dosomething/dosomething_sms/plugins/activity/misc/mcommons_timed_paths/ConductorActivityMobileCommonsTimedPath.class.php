<?php

/**
 * Given the mdata_id that the request comes from, this activity will select
 * the Mobile Commons opt-in path to send the user to next based on time.
 */
class ConductorActivityMobileCommonsTimedPath extends ConductorActivity {

  /**
   * Contains the info for sets of opt-in paths and the earliest possible time
   * they can be sent to. Sets are grouped by their unique mdata_id from Mobile Commons.
   *
   * Defintion:
   * $sets = array(
   *   array(
   *     'mdata_id'         // Number. ID provided by the mData setup in Mobile Commons.
   *     'timezone'         // String. Timezone to process times in. ex: 'America/New_York'
   *     'paths' => array(
   *       array(
   *         'time'         // String. Earliest time when users will be sent to this opt-in path.
   *                        //  Format: Y-m-d H:i:s ex: '2013-07-16 10:00:00'
   *         'opt_in_path'  // Number. Opt-in path to send user to.
   *       ),
   *       ...
   *     )
   *   ), ...
   */
  public $sets = array();

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $mdataId = intval($_REQUEST['mdata_id']);

    // Find the set with the matching mdata_id
    $setIndex = -1;
    for ($i = 0; $i < count($this->sets); $i++) {
      if ($this->sets[$i]['mdata_id'] == $mdataId) {
        $setIndex = $i;
        break;
      }
    }

    if ($setIndex >= 0) {
      $set = $this->sets[$setIndex];
      $optInPath = 0;

      $dateOverride = check_plain($_REQUEST['date_override']);
      if (!empty($dateOverride)) {
        // For testing, use the override time provided in the params.
        // Expected dateOverride format: Y-m-d H:i:s
        $dateObj = new DateTime($dateOverride, new DateTimeZone($set['timezone']));
        $currTime = $dateObj->getTimestamp();
      }
      else {
        // Otherwise, get current time for timezone specified. eg: America/New_York
        $dateObj = new DateTime(NULL, new DateTimeZone($set['timezone']));
        $currTime = $dateObj->getTimestamp();
      }

      // Assumption is that arrays are ordered from earliest time to latest.
      // So traverse the list in descending order, searching for the first
      // instance of a time that's before the current time.
      $paths = $set['paths'];
      for ($i = count($paths) - 1; $i >= 0; $i--) {
        $pathTimeStr = $set['paths'][$i]['time'];
        $pathTimeObj = new DateTime($pathTimeStr, new DateTimeZone($set['timezone']));
        $pathTime = $pathTimeObj->getTimestamp();

        if ($currTime >= $pathTime) {
          $optInPath = $set['paths'][$i]['opt_in_path'];
          break;
        }
      }

      if ($optInPath > 0) {
        dosomething_sms_mobile_commons_opt_in($mobile, $optInPath);
      }
    }

    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }
}
