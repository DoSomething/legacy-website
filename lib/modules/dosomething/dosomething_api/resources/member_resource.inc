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
        'help' => 'Returns Current User Activity. GET from users/current/activity, users/23423/activity',
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
      'update' => [
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/member_resource',
        ],
        'help' => 'Update the users profile',
        'args' => [
          [
            'name' => 'id',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'string',
            'description' => 'The Northstar ID of the user we\'re updating.',
          ],
          [
            'name' => 'account',
            'type' => 'array',
            'description' => 'The user object',
            'source' => 'data',
            'optional' => FALSE,
          ],
        ],
        'callback' => '_member_resource_update',
        'access callback' => '_member_update_access',
        'access arguments append' => TRUE,
      ],
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
      'magic_login_url' => array(
        'help' => 'Create a magic login link for a user.',
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
            'description' => 'The UID of the user who we\'re making a magic login link for.',
          ),
        ),
        'callback' => '_member_resource_magic_login_url',
        'access callback' => '_member_resource_access',
        'access arguments' => array('magic_login_url'),
      ),
    ),
  );
  return $member_resource;
}

/**
 * Access callback for User resources.
 */
function _member_resource_access($op) {
  if ($op == 'get_member_count') {
    return TRUE;
  }
  global $user;
  // For now, only admins can access any other User resources.
  return in_array('administrator', $user->roles);
}

/**
 * Access calback for the user update resource.
 *
 * Only allow users to edit their own profile for now.
 */
function _member_update_access($id) {
  global $user;

  $request_user = dosomething_user_get_user_by_northstar_id($id);
  return $user->uid === $request_user->uid;
}

/**
 * Callback for User create.
 *
 * @param $request
 *   Array passed to the endpoint. Possible keys:
 *   - _id (string). Required.
 *
 * @return mixed
 *   Object of the newly created user if successful. String if errors.
 */
function _member_resource_create($request) {
  if (!isset($request['_id'])) {
    return services_error("New Drupal accounts must be registered via Northstar.");
  }

  // Check if email is formatted correctly and not already in use.
  // Initialize array to pass to user_save().
  $edit = [
    'mail' => $request['_id'] . '@dosomething.org',
    'name' => user_password(),
    'status' => 1,
    'created' => REQUEST_TIME,
  ];

  // Map request input to Drupal fields, or use default values.
  $fields = [
    'northstar_id' => $request['_id'],
  ];

  dosomething_user_set_fields($edit, $fields);

  try {
    $user = user_save('', $edit);

    // Ensure user has UID for name & an authmap record. We need to do this because insert hooks
    // don't fire on API. (See `dosomething_user_user_insert` & `dosomething_northstar_create_user`.)
    user_save($user, ['name' => $user->uid]);
    user_set_authmaps($user, ['authname_openid_connect_northstar' => $request['_id']]);

    // Don't return the hashed password in the response!
    unset($user->pass);

    return $user;
  }
  catch (Exception $e) {
    services_error($e);
  }
}

/**
 * Callback for User create.
 *
 * @param $request Array passed to the endpoint.
 *   Possible keys:
 *   - addr_street1
 *   - addr_street2
 *   - addr_city
 *   - addr_state
 * @return mixed Object of the newly created user if successful. String if errors.
 */
function _member_resource_update($id, $request) {
  $keys = ['addr_street1', 'addr_street2', 'addr_city', 'addr_state', 'addr_zip'];
  $fields = [];
  $account = $request['account'];

  if ($account) {
    foreach ($keys as $key) {
      $value = $account[$key];

      if (isset($value)) {
        $fields[$key] = $value;
      }
    }
  }

  dosomething_northstar_clear_user_cache($id);
  $response = dosomething_northstar_client()->asUser()->post('v1/profile', $fields);

  return $response;
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
    $northstar_user = dosomething_user_get_user_by_northstar_id($uid);
    if (!$northstar_user) {
      return services_error(t('Invalid uid value @uid.', array('@uid' => $uid)), 403);
    }

    $uid = $northstar_user->uid;
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
  $reset_url = user_pass_reset_url($account) . '/login';
  return $reset_url;
}

/**
 * Callback for the `/users/{nid}/magic_login_url` endpoint. This creates
 * a one-time login link for the given user.
 * @see dosomething_user_magic_session
 *
 * @return array
 */
function _member_resource_magic_login_url($uid) {
  $account = user_load($uid);
  $timestamp = REQUEST_TIME;

  if (! $account) {
    return services_error('That user does not exist', 404);
  }
 $prefix = dosomething_global_get_prefix_for_language($account->language);

  // Create a one-time login URL using the same methods as built-in Drupal password reset.
  $magic_url = url($prefix . '/user/magic/' . $uid . '/' . $timestamp . '/' . user_pass_rehash($account->pass, $timestamp, $account->login, $account->uid), ['absolute' => TRUE]);

  return [
    'url' => $magic_url,
    'expires' => date('c', $timestamp),
  ];
}
