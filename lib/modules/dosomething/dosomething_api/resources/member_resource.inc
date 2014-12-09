<?php

function _member_resource_defintion() {
  $member_resource = array();
  $member_resource['users'] = array(
    'operations' => array(
      'create' => array(
        'help' => 'Create a user.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/member.resource',
        ),
        'callback' => '_member_resource_create',
          'args' => array(
            array(
              'name' => 'account',
              'type' => 'array',
              'description' => 'The user object',
              'source' => 'data',
              'optional' => FALSE,
            ),
          ),
        'access callback' => '_member_resource_access',
      ),
    ),
    'actions' => array(
      'get_member_count' => array(
        'help' => 'Returns current member count.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/member.resource',
        ),
        'callback' => '_member_resource_get_member_count',
        'access callback' => '_member_resource_access',
      ),
    ),
  );
  return $member_resource;
}

/**
 * Access callback for User resources.
 */
function _member_resource_access() {
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
function _member_resource_create($account) {
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
    'mobile',
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

/**
 * Callback for the get_member_count resource.
 *
 * @return array
 *   Associative array of the member count, in different formats.
 */
function _member_resource_get_member_count() {
  return array(
    'formatted' => dosomething_user_get_member_count(),
    'readable' => dosomething_user_get_member_count($readable = TRUE),
  );
}
