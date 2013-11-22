<?php

/**
 * Given the mdata_id that the request comes from, the activity selects
 * the opt-in path to send the user to from an ordered list. The sms_flow_game
 * table is used to determine which opt-in path the user will be sent to next.
 */
class ConductorActivityMobileCommonsOrderedPath extends ConductorActivity {

  /**
   * Nested array of ordered lists of Mobile Commons opt-in paths.
   *
   * Definition:
   * @code
   * array(
   *   array(
   *     'mdata_id' => mData ID associated with this set
   *     'game_id' => Unique identifier. Needs to be unique also compared to random pathing workflow and other SMS games
   *     'opt_in_paths' => Array of ordered paths
   *     'paths_finished_msg' => Optional. Number. Opt-in path to send user to if they've finished all tips.
   *     'should_loop' => Optional. Set to TRUE if you want the tips to loop through again after going through them all.
   *   ), ...
   * )
   * @endcode
   */
  public $sets = array();

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $mdataID = intval($_REQUEST['mdata_id']);

    // Find the set with the matching mdata_id
    $setIndex = -1;
    for ($i = 0; $i < count($this->sets); $i++) {
      if ($this->sets[$i]['mdata_id'] == $mdataID) {
        $setIndex = $i;
        break;
      }
    }

    if ($setIndex >= 0) {
      $set = $this->sets[$setIndex];
      if (count($set['opt_in_paths']) == 0) {
        watchdog('sms_flow_game', "ConductorActivityMobileCommonsOrderedPath set missing opt_in_paths for mdata_id $mdataID");
      }
      else {
        // Get last opt-in path user was sent to. Function returns an array
        $lastOptIn = dosomething_sms_game_get_paths($mobile, $set['game_id']);

        // Select next opt-in path to send user to
        $nextOptInIndex = 0;
        if (!empty($lastOptIn)) {
          // Array should always only contain one item
          if (count($lastOptIn) == 1) {
            $lastOptIn = $lastOptIn[0];
            $lastOptInIndex = array_search($lastOptIn, $set['opt_in_paths']);
            $nextOptInIndex = $lastOptInIndex + 1;

            if ($nextOptInIndex >= count($set['opt_in_paths']) && $set['should_loop'] === TRUE) {
              $nextOptInIndex = 0;
            }
          }
          else {
            watchdog('sms_flow_game', "ConductorActivityMobileCommonsOrderedPath accessing multi-item array when trying to find last opt in. $mobile / ".$set['game_id']);
            $nextOptInIndex = -1;
          }
        }

        // Send user to selected opt-in path or nothing if they've already received the last path
        if ($nextOptInIndex >= 0 && $nextOptInIndex < count($set['opt_in_paths'])) {

          // @todo Convert to use mobilecommons module
          // sms_mobile_commons_opt_in($mobile, $set['opt_in_paths'][$nextOptInIndex]);

          // Save path to database
          try {
            // If no existing record, create one
            if (empty($lastOptIn)) {
              dosomething_sms_game_create_record($mobile, $set['game_id']);
            }

            // Update existing record, adding the newly selected path
            $lastOptIn = array($set['opt_in_paths'][$nextOptInIndex]);
            dosomething_sms_game_set_paths($mobile, $set['game_id'], $lastOptIn);
          }
          catch (Exception $e) {
            watchdog('sms_flow_game', 'ConductorActivityMobileCommonsOrderedPath exception - ' . $e->getMessage());
          }
        }
        elseif (!empty($set['paths_finished_msg'])) {
          // @todo Convert to use mobilecommons module
          // sms_mobile_commons_opt_in($mobile, $set['paths_finished_msg']);
        }
      }
    }

    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }
}
