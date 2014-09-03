<?php
/**
 * @file
 * Code for DoSomething User Services resources.
 *
 * @see dosomething_user_services_resources()
 */

/**
 * Access callback for User resources.
 */
function _dosomething_user_resource_access() {
  // Return TRUE for development.
  return TRUE;
  global $user;
  // For now, only admins can access any reportback resources.
  return in_array('administrator', $user->roles);
}

/**
 * Callback for Reportback resource create.
 *
 * @param obj $account
 *   Array passed to the endpoint. Possible keys:
 *   - email (string). Required.
 *   - password (string).
 *   - birthdate (datestring).
 *   - first_name (string).
 *   - last_name (string).
 *   - user_registration_source (string).
 *
 * @return mixed
 *   Object of the newly created user if successful. String if errors.
 */
function _dosomething_user_resource_create($account) {
  if (!isset($account['email'])) {
    return services_error("Email is required.");
  }
  $email = $account['email'];
  // Check if account exists for email.
  if ($user = user_load_by_mail($email)) {
    return services_error(t('Email @email is registered to User uid @uid.', array('@email' => $email, '@uid' => $user->uid)), 403);
  }
  // Initialize array to pass to user_save().
  $edit = array();
  $edit['mail'] = $email;
  $edit['name'] = $email;
  $edit['status'] = 1;
  $edit['created'] = REQUEST_TIME;
  if (isset($account['password'])) {
    $edit['pass'] = $account['password'];
  }
  // List of available properties to save:
  $properties = array(
    'birthdate',
    'first_name',
    'last_name',
    'user_registration_source',
  );
  // Loop through each property:
  foreach ($properties as $property) {
    if (isset($account[$property])) {
      // Get its relevant field name.
      $field_name = 'field_' . $property;
      // Set the expected field value arrays.
      $edit[$field_name] = array(
        LANGUAGE_NONE => array(
          0 => array(
            'value' => $account[$property],
          ),
        ),
      );
    }
  }
  try {
    $account = user_save('', $edit);
    return $account;
  }
  catch (Exception $e) {
    services_error($e);
  }
}
