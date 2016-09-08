<?php

/**
 * Constructs a new Drupal user for the given account details to represent a Facebook user.
 * @param  array $account_details  All of the properties to instantiate
 * @return $user
 */
function dosomething_user_make_facebook_user($account_details) {
  $edit = [
    'mail' => $account_details['email'],
    'name' => $account_details['email'],
    'pass' => user_password(),
    'status' => 1,
    'created' => REQUEST_TIME,
  ];

  dosomething_user_set_fields($edit, $account_details);

  $user = user_save(null, $edit);
  user_save($user, ['name' => $user->uid]);

  return $user;
}

/**
 * Registers a new user with Northstar (or upserts with existing) & returns a Drupal account
 * @param  array $account_details Account details for the user to register
 * @return $user
 */
function dosomething_user_register_facebook_user($account_details) {
  $user = null;

  // Checks if there is an existing account for the given email
  if (isset($account_details['email'])) {
    $email = $account_details['email'];
    $northstar_account = dosomething_northstar_get_user_by_custom_index('email', $email);
  }

  if ($northstar_account === null) {
    $user = dosomething_user_make_facebook_user($account_details);
  }
  else {
    $user = user_load($northstar_account->data->drupal_id);
  }

  $user->facebook_id = $account_details['facebook_id'];
  dosomething_northstar_create_user($user);

  return $user;
}

/**
 * Verify the given access token & Facebook ID are correct with Northstar
 * @param  string $facebook_id  Facebook ID
 * @param  String $access_token Access token to validate
 * @return bool
 */
function dosomething_user_verify_facebook_user($facebook_id, $access_token) {
  // TODO
  return true;
}

/**
 * Creates a Drupal session for a given Facebook user
 * @param  $user User to create session for
 */
function dosomething_user_create_facebook_session($user) {
  $form_state['uid'] = $user->uid;
  user_login_submit([], $form_state);
  user_login_finalize($form_state);
}

/**
 * Handles POST request for /user/social/facebook
 * Which can register or login a Facebook user
 */
function dosomething_user_facebook_login() {
  global $user;

  if (!isset($_POST['facebook_id']) || !isset($_POST['access_token']) || !isset($_POST['email'])) {
    return services_error("Email, Facebook ID & access token is required.");
  }

  $facebook_id = $_POST['facebook_id'];
  $access_token = $_POST['access_token'];
  $verify_token = TRUE;
  $token_verified = FALSE;

  $account_details = [
    'email' => data_get($_POST, 'email'),
    'first_name' => data_get($_POST, 'first_name'),
    'last_name' => data_get($_POST, 'last_name'),
    'facebook_id' => $facebook_id,
    'user_registration_source' => 'facebook_auth',
  ];

  $northstar_account = dosomething_northstar_get_user_by_custom_index('facebook_id', $facebook_id);

  if ($northstar_account != null) {
    // If the user is already registered with us, start to load them into Drupal
    $user = user_load($northstar_account->data->drupal_id);
  }
  else {
    $user = dosomething_user_register_facebook_user($account_details);
    // No need to run a verify on the initial signup.
    $verify_token = FALSE;
    $token_verified = TRUE;
  }

  // We now have Northstar verify the given oAuth token is actually for this person
  if ($verify_token) {
    $token_verified = dosomething_user_verify_facebook_user($facebook_id, $access_token);
  }

  // If they passed the login verification, create a session
  if ($token_verified) {
    dosomething_user_create_facebook_session($user);
  }

  // Always return them to the previous page
  drupal_goto($_SERVER['HTTP_REFERER']);
}
