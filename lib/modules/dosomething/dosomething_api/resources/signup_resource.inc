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
  $nid = NULL;
  $source_parts = explode('/', $data['source']);
  // Check if this source is a signup.
  if (!empty($source_parts)) {
    if ($source_parts[0] == 'signup' && is_numeric($source_parts[1])) {
      // Find the node the source signup is associated with.
      $source_signup = signup_load((int) $source_parts[1]);
      $nid = $source_signup->nid;
    }
  }
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
  $index = array();

  $query = db_select('dosomething_signup', 's');
  $query->fields('s');
  if (isset($parameters['source'])) {
    $query->condition('source', $parameters['source']);
  }
  if (isset($parameters['nid'])) {
    $query->condition('nid', $parameters['nid']);
  }

  // @todo: We still need to figure out how to include the alpha.
  // This is only returning the betas that used the alpha signup as source.

  // Return max of 25 records for now.
  $query->range(0, 25);
  return $query->execute()->fetchAll();
}
