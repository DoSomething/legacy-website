<?php

function dosomething_user_make_facebook_user($account_details) {
  $edit = [
    'mail' => $account_details['email'],
    'name' => $account_details['email'],
    'pass' => user_password(),
    'status' => 1,
    'created' => REQUEST_TIME,
  ];

  $account_details['user_registration_source'] = 'facebook_auth';
  dosomething_user_set_fields($edit, $account_details);

  $user = user_save(null, $edit);
  user_save($user, ['name' => $user->uid]);
  $account_details['drupal_id'] = $user->uid;

  return $user;
}

function dosomething_user_facebook_login() {
  global $user;

  if (!isset($_POST['facebook_id']) || !isset($_POST['access_token']) || !isset($_POST['email'])) {
    return services_error("Email, Facebook ID & access token is required.");
  }

  $facebook_id = $_POST['facebook_id'];
  $access_token = $_POST['access_token'];
  $verify_token = TRUE;
  $logged_in = FALSE;

  $account_details = [
    'email' => data_get($_POST, 'email'),
    'first_name' => data_get($_POST, 'first_name'),
    'last_name' => data_get($_POST, 'last_name'),
    'facebook_id' => $facebook_id,
  ];

  if (dosomething_northstar_get_user_by_term('facebook_id', $facebook_id)) {
    // If the user is already registered with us, start to load them into Drupal
    $user = user_load(json_decode($response->data)->data->drupal_id);
  }
  else {
    // Otherwise check if we need to make a new account or upsert with an existing.
    $create_new_account = TRUE;
    $client = _dosomething_northstar_build_http_client();

    if (isset($account_details['email'])) {
      $email = $account_details['email'];
      $create_new_account = !dosomething_northstar_get_user_by_term('email', $email);
    }

    if ($create_new_account) {
      // Create the Drupal user.
      // Unfortunately there doesn't seem to be anyway around this because of how Drupal is architected.
      $user = dosomething_user_make_facebook_user($account_details);

      // Create Northstar user w/ Facebook ID
      $response = drupal_http_request($client['base_url'] . '/users', [
        'headers' => $client['headers'],
        'method' => 'POST',
        'data' => json_encode($account_details),
      ]);

      // No need to run a verify on the initial signup.
      $verify_token = FALSE;
      $logged_in = TRUE;
    }
    else {
      // Update existing Northstar user to link Facebook ID
      $response = drupal_http_request($client['base_url'] . '/users/email/' . $email, [
        'headers' => $client['headers'],
        'method' => 'PUT',
        'data' => json_encode(['facebook_id' => $facebook_id]),
      ]);
      $user = user_load(json_decode($response->body)->data->drupal_id);
    }
  }

  // We now have Northstar verify the given oAuth token is actually for this person
  if ($verify_token) {
    // TODO: implement verify response, if they verify...
    $logged_in = TRUE;
  }

  // If they passed the login verification, create a session
  if ($logged_in) {
    $form_state['uid'] = $user->uid;
    user_login_submit([], $form_state);
    user_login_finalize($form_state);
  }

  // Always return them to the previous page
  drupal_goto($_SERVER['HTTP_REFERER']);
}
