<?php

/**
 * Sends a Mobilecommons API request to opt-in user with given campaign title.
 *
 * @param object $account
 *   The user object of user to opt-in.
 * @param string $title
 *   The campaign title the user has signed up for.
 */
function dosomething_signup_mobilecommons_opt_in($account, $lid, $title) {
  // Make sure mobilecommons module is enabled.
  if (!module_exists('mobilecommons')) { return; }

  // If user doesn't have mobile number, exit function.
  $mobile = dosomething_user_get_mobile($account);
  if (!$mobile) { return; }

  try {
    // @todo: Move $config / new MobileCommons($config) code
    // into a new function in the contrib mobilecommons.module.
    $library = libraries_load('mobilecommons-php');
    if (empty($library['loaded'])) {
      return FALSE;
    }
    $config = array(
      'username' => variable_get('mobilecommons_api_auth_email'),
      'password' => variable_get('mobilecommons_api_auth_password'),
    );
    $MobileCommons = new MobileCommons($config);
    // Next get prepare the opt-in request.
    $args = array(
      // All campaigns use this opt-in path for now.
      'opt_in_path' => $lid,
      'person[phone]' => $mobile,
      'person[campaign_name]' => $title,
      // Expected format is YYYY-MM-DD.
      'person[date_of_birth]' => dosomething_user_get_birthdate('Y-m-d', $account),
      'person[first_name]' => dosomething_user_get_field('field_first_name', $account),
      'person[email]' -> $account->mail,
    );
    return $MobileCommons->opt_in($args);
  }
  catch (Exception $e) {
    // Log the error.
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
  return FALSE;
}