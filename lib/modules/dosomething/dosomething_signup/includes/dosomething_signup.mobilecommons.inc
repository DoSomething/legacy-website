<?php


/**
 * Sends a Mobilecommons API request to opt-in an alpha and betas.
 *
 * @param array $values
 *   An array of form values sent from a Friends Signup Form.
 *   @see dosomething_signup_friends_form().
 *
 * @return mixed
 *   A Mobilecommons object, or FALSE if error.
 */
function dosomething_signup_get_mobilecommons_friends_vars($values) {
  // Initialize arrays to send to the Mobilecommons API.
  $args = array();
  $friends = array();
  $title = $values['title'];

  // If user is logged in already:
  if (user_is_logged_in()) {
    // Use existing function to send existing data.
    global $user;
    $args = dosomething_signup_get_mobilecommons_vars($user, $values['opt_in_path'], $title);
  }
  // Else set relevant alpha values from the given $values.
  else {
    $args['opt_in_path[]'] = $values['opt_in_path'];
    $args['person[first_name]'] = $values['alpha_name'];
    $args['person[campaign_name]'] = $title;
  }

  // Logged in user may not have a mobile #, so we check if its been set here,
  // outside of the check to see if user is logged in or not.
  if (!isset($args['person[phone]'])) {
    $args['person[phone]'] = $values['alpha_mobile'];
  }

  // Next set args for the friends.
  for ($i = 0; $i < $values['num_betas']; $i++) {
    if (!empty($values['beta_mobile_' . $i])) {
      $friends[] = $values['beta_mobile_' . $i];
    }
  }
  if (!empty($friends)) {
    $args['friends_opt_in_path'] = $values['friends_opt_in_path'];
  }
  return array('args' => $args, 'friends' => $friends);
}

/**
 * Sends a Mobilecommons API request to opt-in an alpha and betas.
 *
 * @param array $values
 *   An array of form values sent from a Friends Signup Form.
 *   @see dosomething_signup_friends_form().
 *
 * @return mixed
 *   A Mobilecommons object, or FALSE if error.
 */
function dosomething_signup_mobilecommons_opt_in_friends($values) {
  $vars = dosomething_signup_get_mobilecommons_friends_vars($values);
  if (DOSOMETHING_SIGNUP_LOG_MOBILECOMMONS) {
    watchdog('dosomething_signup_mobilecommons_opt_in_friends', json_encode($vars));
  }
  try {
    return mobilecommons_request('opt_in_with_friends', $vars);
  }
  catch (Exception $e) {
    // Log the error.
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
}

