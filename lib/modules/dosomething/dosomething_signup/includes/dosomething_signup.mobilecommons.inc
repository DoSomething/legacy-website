<?php

/**
 * Sends a Mobilecommons API request to opt-in user with given campaign title.
 *
 * @param object $account
 *   The user object of user to opt-in.
 * @param int $lid
 *   The opt-in path to use for opt-in.
 * @param string $title
 *   Optional The campaign title the user has signed up for.
 */
function dosomething_signup_mobilecommons_opt_in($account, $lid, $title = NULL) {
  // Make sure mobilecommons module is enabled.
  if (!module_exists('mobilecommons')) { return; }

  // If user doesn't have mobile number, exit function.
  $mobile = dosomething_user_get_mobile($account);
  if (!$mobile) { return; }

  try {
    $args = array(
      'opt_in_path' => $lid,
      'person[phone]' => $mobile,
      'person[campaign_name]' => $title,
      // Expected format is YYYY-MM-DD.
      'person[date_of_birth]' => dosomething_user_get_birthdate('Y-m-d', $account),
      'person[first_name]' => dosomething_user_get_field('field_first_name', $account),
      'person[email]' => $account->mail,
    );
    return mobilecommons_request('opt_in', $args);
  }
  catch (Exception $e) {
    // Log the error.
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
  return FALSE;
}
