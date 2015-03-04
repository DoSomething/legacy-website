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
          'name' => 'resources/member_resource',
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
        'access arguments' => array('create'),
      ),
      'index' => array(
        'help' => 'List of all users.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/member_reource',
        ),
        'callback' => '_member_resource_index',
        'access callback' => '_member_resource_access',
        'access arguments' => array('index'),
        'args' => array(
          array(
            'name' => 'parameters',
            'optional' => FALSE,
            'type' => 'array',
            'description' => 'Parameters',
            'default value' => array(),
            'source' => array('param' => 'parameters'),
          ),
        ),
      ),
    ),
    'actions' => array(
      'get_member_count' => array(
        'help' => 'Returns current member count.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/member_resource',
        ),
        'callback' => '_member_resource_get_member_count',
        'access callback' => '_member_resource_access',
        'access arguments' => array('get_member_count'),
      ),
    ),
    'targeted_actions' => array(
      'password_reset_url' => array(
        'help' => 'Gets the user password reset URL.',
        'file' => array(
          'type' => 'inc', 
          'module' => 'dosomething_api', 
          'name' => 'resources/member_resource',
        ),
        'args' => array(
          array(
            'name' => 'uid',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'int',
            'description' => 'The uid of the user whose password reset url we are getting',
          ),
        ),        
        'callback' => '_member_resource_reset',
        'access callback' => '_member_resource_access',
        'access arguments' => array('password_reset_url'),
      ), 
    ),   
  );
  return $member_resource;
}

/**
 * Access callback for User resources.
 */
function _member_resource_access($op) {
  if ($op == 'create' || $op == 'get_member_count' || $op == 'password_reset_url') {
    return TRUE;
  }
  global $user;
  // For now, only admins can access any other User resources.
  return in_array('administrator', $user->roles);
}

/**
 * Callback for User create.
 *
 * @param obj $account
 *   Array passed to the endpoint. Possible keys:
 *   - email (string). Required.
 *   - password (string).
 *   - birthdate (datestring).
 *   - first_name (string).
 *   - last_name (string).
 *   - mobile (string).
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

/**
 * Callback for Users index.
 *
 * @param array $parameters
 *   Array passed within query string. Possible keys:
 *   - email (string)..
 *   - mobile (string).
 *
 * @return mixed
 *   Object of the newly created user if successful. String if errors.
 */
function _member_resource_index($parameters) {
  // Initialize output.
  $index = array();

  $query = db_select('users', 'u');
  // We only need uid for now, as we're just checking for user existence.
  $query->fields('u', array('uid'));
  if (isset($parameters['email'])) {
    $query->condition('mail', $parameters['email']);
  }
  if (isset($parameters['mobile'])) {
    $query->join('field_data_field_mobile', 'm', 'u.uid = m.entity_id');
    $query->condition('field_mobile_value', $parameters['mobile']);
  }
  // Return max of ten records.
  $query->range(0, 10);
  return $query->execute()->fetchAll();
}

/**
 * Callback for user password reset URL
 *
 * @param array $parameters
 *   Array passed within query string.
 *   - email (string)..
 *
 * @return string
 *   String of the password reset URL or errors.
 */
function _member_resource_reset($uid) {
  $account = user_load($uid);
  $reset_url = user_pass_reset_url($account);
  return $reset_url;
}
