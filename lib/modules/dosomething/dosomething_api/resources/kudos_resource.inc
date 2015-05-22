<?php

function _kudos_resource_definition() {
  $kudos_resource = array();
  $kudos_resource['kudos'] = array(
    'operations' => array(

      'retrieve' => array(
        'help' => 'Retrieve a specified kudos record on a reportback item.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/kudos_resource',
        ),
        'callback' => '_kudos_resource_retrieve',
        'args' => array(
          array(
            'name' => 'kid',
            'description' => 'The kid of the kudos record to retrieve.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => array('path' => 0),
          ),
        ),
        'access callback' => '_kudos_resource_access',
        'access arguments' => array('view'),
      ),

      'index' => array(
        'help' => 'List all kudos.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/kudos_resource',
        ),
        'callback' => '_kudos_resource_index',
        'args' => array(
          array(
            'name' => 'reportbackitems',
            'description' => 'The ids of specified reportbacks to get kudos.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array(
              'param' => 'reportbackitems'
            ),
            'default value' => NULL,
          ),
        ),
        'access callback' => '_kudos_resource_access',
        'access arguments' => array('index'),
      ),

      'create' => array(
        'help' => 'Create a new kudos record.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/kudos_resource',
        ),
        'callback' => '_kudos_resource_create',
        'args' => array(
          array(
            'name' => 'reportback_item_id',
            'description' => 'The id of reportback item to create kudos record.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => array(
              'data' => 'reportback_item_id',
            ),
          ),
          array(
            'name' => 'user_id',
            'description' => 'The ID of the user executing a kudos.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => array(
              'data' => 'user_id',
            ),
          ),
          array(
            'name' => 'term_ids',
            'description' => 'An array of kudos term IDs.',
            'optional' => FALSE,
            'type' => 'array',
            'source' => array(
              'data' => 'term_ids',
            ),
          ),
        ),
        'access callback' => '_kudos_resource_access',
        'access arguments' => array('create'),
      ),

      'delete' => array(
        'help' => 'Delete a kudos record.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/kudos_resource',
        ),
        'callback' => '_kudos_resource_delete',
        'args' => array(
          array(
            'name' => 'kudos_id',
            'optional' => FALSE,
            'type' => 'int',
            'source' => array(
              'path' => 0,
            )
          ),
        ),
        'access callback' => '_kudos_resource_access',
        'access arguments' => array('delete'),
      ),
    ),

  );

  return $kudos_resource;
}


/**
 * Determine whether the current user can access kudos resource.
 *
 * @param string $op
 *
 * @return bool
 */
function _kudos_resource_access($op) {
  if ($op === 'view') {
    return TRUE;
  }

  if ($op === 'index') {
    return TRUE;
  }

  // @TODO add create & delete and check access with user_access().

  return FALSE;
}


function _kudos_resource_index($reportbackitems) {
  $parameters = array(
    'fid' => $reportbackitems,
  );

  $kudos = new Kudos;
  return $kudos->index($parameters);
}


function _kudos_resource_retrieve($kid) {
  return 'retrieving specific request';
}


function _kudos_resource_create($reportback_item_id, $user_id, $term_ids) {
  $parameters = array(
    'fid' => $reportback_item_id,
    'uid' => $user_id,
    'tids' => $term_ids,
  );

  // Returns ID of newly added kudos record in database table.
  return dosomething_kudos_create($parameters);
}


function _kudos_resource_delete($kudos_id) {
  // Returns number of rows affected.
  return dosomething_kudos_delete($kudos_id);
}
