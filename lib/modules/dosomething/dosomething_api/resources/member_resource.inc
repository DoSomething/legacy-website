<?php

function _member_resource_definition() {
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
    'relationships' => array(
      'activity' => array(
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/member_resource',
        ),
        'help'   => 'Returns Current User Activity. GET from users/current/activity, users/23423/activity',
        'access callback' => '_member_resource_access',
        'access arguments' => array('activity'),
        'access arguments append' => TRUE,
        'callback' => '_member_resource_get_activity',
        'args'     => array(
          array(
            'name' => 'uid',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'string',
            'description' => 'The uid of the user whose activity to retrieve. Use current for logged in user.',
          ),
          array(
            'name' => 'nid',
            'type' => 'int',
            'description' => t('Node nid to filter by.'),
            'source' => array('param' => 'nid'),
            'optional' => TRUE,
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
  if ($op == 'create' || $op == 'get_member_count') {
    return TRUE;
  }
  global $user;
  // For now, only admins can access any other User resources.
  return in_array('administrator', $user->roles);
}

/**
 * Callback for User create.
 *
 * @param $request
 *   Array passed to the endpoint. Possible keys:
 *   - email (string). Required.
 *   - password (string).
 *   - birthdate (date string).
 *   - first_name (string).
 *   - last_name (string).
 *   - mobile (string).
 *   - user_registration_source (string).
 *
 * @return mixed
 *   Object of the newly created user if successful. String if errors.
 */
function _member_resource_create($request) {
  $query = drupal_get_query_parameters();
  
  if (!isset($request['email'])) {
    return services_error("Email is required.");
  }
  
  // Check if email is formatted correctly and not already in use.
  $email = $request['email'];
  if ($user = user_load_by_mail($email)) {
    return services_error(t('Email @email is registered to User uid @uid.', ['@email' => $email, '@uid' => $user->uid]), 403);
  }
  if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    return services_error(t('Email @email is not a valid email address.', ['@email' => $email]), 422);
  }
  
  // Check if account exists for phone.
  $mobile = $request['mobile'];
  if ($mobile && $user = dosomething_user_get_user_by_mobile($mobile)) {
    return services_error(t('Mobile @mobile is registered to User uid @uid.', ['@mobile' => $mobile, '@uid' => $user->uid]), 403);
  }
  if ($mobile && !dosomething_user_valid_mobile($mobile)) {
    return services_error(t('Mobile @mobile is not a valid phone number.', ['@mobile' => $mobile]), 422);
  }
  
  // Initialize array to pass to user_save().
  $edit = [
    'mail' => $email,
    'name' => user_password(), // Overridden below.
    'status' => 1,
    'created' => REQUEST_TIME,
  ];

  // Map request input to Drupal fields, or use default values.
  $fields = [
    'birthdate' => $request['birthdate'],
    'first_name' => $request['first_name'],
    'country' => !empty($request['country']) ? $request['country'] : 'US',
    'last_name' => !empty($request['last_name']) ? $request['last_name'] : NULL,
    'mobile' => !empty($request['mobile']) ? dosomething_user_clean_mobile_number($request['mobile']) : NULL,
    'user_registration_source' => !empty($request['user_registration_source']) ? $request['user_registration_source'] : NULL,
  ];

  dosomething_user_set_fields($edit, $fields);

  // Set given password, or generate a random one if blank.
  $edit['pass'] = !empty($request['password']) ? $request['password'] : user_password();

  // Infer the user's language from their country code field.
  $edit['language'] = dosomething_global_convert_country_to_language($fields['country']);

  try {
    $user = user_save('', $edit);
    
    // Ensure user has UID set for name, since insert hooks don't fire on API.
    // @see: dosomething_user_user_insert
    user_save($user, ['name' => $user->uid]);
    
    // Forward users to Northstar, unless `?forward=false` is explicitly set.
    $should_forward = isset($query['forward']) ? filter_var($query['forward'], FILTER_VALIDATE_BOOLEAN, FILTER_NULL_ON_FAILURE) : true;
    if ($should_forward && module_exists('dosomething_northstar')) {
      $payload = dosomething_northstar_transform_user($user);
      $payload['password'] = $edit['pass'];
      
      dosomething_northstar_register_user($user, $payload);
    }

    // Don't return the hashed password in the response!
    unset($user->pass);
    
    return $user;
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
 * Returns User Activity for given $uid and optional $nid.
 *
 * @param mixed $uid
 *   Numeric User uid or the string "current" for logged in user.
 * @param int $nid
 *   Optional node nid to query activity for.
 *
 * @return mixed
 *   If $nid specified, an object, else an array.
 */
function _member_resource_get_activity($uid, $nid = NULL) {
  if ($uid === 'current') {
    global $user;
    $uid = $user->uid;
  }
  elseif (is_numeric($uid)) {
    $uid = (int) $uid;
  }
  else {
    return services_error(t('Invalid uid value @uid.', array('@uid' => $uid)), 403);
  }

  // If nid is specified, we just want one Activity result for the nid.
  if ($nid) {
    return _member_resource_get_activity_result($uid, $nid);
  }

  $result = array();
  $nids = dosomething_signup_get_signup_nids_by_uid($uid);
  foreach ($nids as $nid) {
    $result[] = _member_resource_get_activity_result($uid, $nid);
  }
  return $result;
}

/**
 * Returns User Activity object for given $uid and $nid.
 */
function _member_resource_get_activity_result($uid, $nid) {
  $result = new StdClass();
  if ($sid = dosomething_signup_exists($nid, NULL, $uid)) {
    $signup = signup_load($sid);
    $result->sid = $signup->sid;
    $result->nid = $signup->nid;
    $result->signed_up = $signup->timestamp;
    $result->source = $signup->source;
    $result->rbid = NULL;
    if ($rbid = dosomething_reportback_exists($result->nid, NULL, $uid)) {
      $reportback = reportback_load($rbid);
      $result = (object) array_merge((array) $result, (array) $reportback);
      // Remove unneeded properties.
      unset($result->uid);
    }
  }
  return $result;
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
