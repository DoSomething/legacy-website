<?php

/**
 * This activity controls a user's progression through a series of Mobile
 * Commons opt-in paths. The user will text a keyword which triggers an mData
 * that in the end will trigger this activity.
 */
class ConductorActivityMobileCommonsGamePaths extends ConductorActivity {

  /**
   * Defines the mapping between requests from an mData id and the opt-in paths
   * and game id associated with it.
   *
   * @code
   *   $activity->paths = array(
   *     '123456' => array( // mData id
   *       'optInPaths' => array(1111, 2222, 3333),
   *       'gameId' => DoSomethingSmsGameConstants::EXAMPLE_GAME_ID,
   *     ),
   *   );
   * @endcode
   *
   * @var array
   */
  public $paths;

  /**
   * Called when this activity gets activated and run by the containing
   * ConductorWorkflow's controller.
   */
  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Get the mData id the request came from.
    $mdataId = intval($_REQUEST['mdata_id']);

    // Find the set with the matching mdata_id.
    if (array_key_exists($mdataId, $this->paths)) {
      $path = $this->paths[$mdataId];

      // Get last opt-in path user was sent to. Function returns an array.
      $lastOptInArray = dosomething_sms_game_get_paths($mobile, $path['gameId']);

      // Select next opt-in path to send the user to.
      $lastOptIn = $lastOptInArray[0];
      $lastOptInIndex = array_search($lastOptIn, $path['optInPaths']);
      $nextOptInIndex = $lastOptInIndex + 1;

      if ($nextOptInIndex >= count($path['optInPaths']) || $lastOptInIndex === FALSE) {
        $nextOptInIndex = 0;
      }

      // Send user to selected opt-in path
      if ($nextOptInIndex >= 0 && $nextOptInIndex < count($path['optInPaths'])) {
       dosomething_sms_mobilecommons_opt_in($mobile, $path['optInPaths'][$nextOptInIndex]);

        // Save path to database
        try {
          // If no existing record, create one
          if (empty($lastOptIn)) {
            dosomething_sms_game_create_record($mobile, $path['gameId']);
          }

          // Update existing record, adding the newly selected path
          $currentOptIn = array($path['optInPaths'][$nextOptInIndex]);
          dosomething_sms_game_set_paths($mobile, $path['gameId'], $currentOptIn);
        }
        catch (Exception $e) {
          watchdog('dosomething_sms', 'ConductorActivityMobileCommonsGamePaths exception - ' . $e->getMessage());
        }
      }
    }

    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }
}
