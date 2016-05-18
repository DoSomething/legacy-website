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
 * @param $account
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
    return services_error(t('Email @email is registered to User uid @uid.', ['@email' => $email, '@uid' => $user->uid]), 403);
  }
  // Check if account exists for phone.
  $mobile = $account['mobile'];
  if ($mobile && $user = dosomething_user_get_user_by_mobile($mobile)) {
    return services_error(t('Mobile @mobile is registered to User uid @uid.', ['@mobile' => $mobile, '@uid' => $user->uid]), 403);
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
  $fields = array(
    'birthdate' => $account['birthdate'],
    'first_name' => $account['first_name'],
    'country' => !empty($account['country']) ? $account['country'] : 'US',
    'last_name' => !empty($account['last_name']) ? $account['last_name'] : NULL,
    'mobile' => !empty($account['mobile']) ? dosomething_user_clean_mobile_number($account['mobile']) : NULL,
    'user_registration_source' => !empty($account['user_registration_source']) ? $account['user_registration_source'] : NULL,
  );

  dosomething_user_set_fields($edit, $fields);

  // Set user's language if provided, or infer from country code
  if(! empty($account['language'])) {
    $languages = array_keys(variable_get('dosomething_global_language_map', ''));

    // Only allow whitelisted languages.
    if(! in_array($account['language'], $languages)) {
      return services_error(t('The language @language is not supported.', ['@language' => $account['language']]), 422);
    }

    $edit['language'] = $account['language'];
  } else {
    $edit['language'] = dosomething_global_convert_country_to_language($fields['country']);
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
