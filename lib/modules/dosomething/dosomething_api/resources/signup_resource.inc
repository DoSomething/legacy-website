<?php

function _signup_resource_defintion() {
  $resource = array();
  $resource['signups'] = array(
    'operations' => array(
      'create' => array(
        'help' => 'Create a signup.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/signup_resource',
        ),
        'callback' => '_signup_resource_create',
          'args' => array(
            array(
              'name' => 'source',
              'type' => 'string',
              'description' => 'The signup source.',
              'source' => 'data',
              'optional' => FALSE,
            ),
          ),
        'access callback' => 'user_is_logged_in',
      ),
      'index' => array(
        'help' => 'List of all signups.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/signup_reource',
        ),
        'callback' => '_signup_resource_index',
        'access callback' => 'user_is_logged_in',
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
  );
  return $resource;
}

/**
 * Callback for Signup create.
 *
 * @param obj $signup
 *   Array passed to the endpoint. Possible keys:
 *   - source (string).
 *   - nid (int).
 *
 *
 * @return mixed
 *   Object of the newly created sgnup if successful. String if errors.
 */
function _signup_resource_create($data) {
  global $user;
  if (!isset($data['source'])) {
    return services_error("Source is required.");
  }
  // Check if the given source has a target nid.
  $nid = dosomething_signup_get_target_nid_for_source(check_plain($data['source']));
  if (!$nid) {
    if (!isset($data['nid']) || !is_numeric($data['nid'])) {
      return services_error("Numeric nid is required.");
    }
    $nid = $data['nid'];
  }
  try {
    if ($sid = dosomething_signup_create($nid, $user->uid, $data['source'])) {
      return signup_load($sid);
    }
    return services_error("Could not create signup.");
  }
  catch (Exception $e) {
    services_error($e);
  }
}

/**
 * Callback for Signups index.
 *
 * @param array $parameters
 *   Array passed within query string. Possible keys:
 *   - source (string).
 *   - nid (int).
 *
 * @return mixed
 *   Object of the newly created user if successful. String if errors.
 */
function _signup_resource_index($parameters) {
  // Initialize output.
  $result = array();
  $alpha_sid = NULL;

  $query = db_select('dosomething_signup', 's');
  $query->fields('s', array('sid'));
  if (isset($parameters['source'])) {
    $source = check_plain($parameters['source']);
    $query->condition('source', $source);
    // Check if the source is an invite code.
    if ($nid = dosomething_signup_get_target_nid_for_source($source)) {
      // Strip out the sid.
      $source_parts = explode('/', $source);
      // Add the alpha signup.
      $result[] = signup_load((int)$source_parts[1]);
    }
  }
  if (isset($parameters['nid'])) {
    $query->condition('nid', $parameters['nid']);
  }

  // Return max of 25 records for now.
  $query->range(0, 25);
  $query_results = $query->execute()->fetchAll();
  foreach ($query_results as $record) {
    $result[] = signup_load($record->sid);
  }
  return $result;
}
