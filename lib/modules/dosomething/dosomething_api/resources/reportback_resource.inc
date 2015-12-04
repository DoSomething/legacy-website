<?php

function _reportback_resource_definition() {
  $reportback_resource = array();
  $reportback_resource['reportbacks'] = array(
    'operations' => array(

      'retrieve' => array(
        'help' => 'Retrieve a specified reportback.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_resource'
        ),
        'callback' => '_reportback_resource_retrieve',
        'args' => array(
          array(
            'name' => 'rbid',
            'description' => 'The rbid of the reportback to retrieve.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => array('path' => 0),
          ),
        ),
        'access callback' => '_reportback_resource_access',
        'access arguments' => array('view'),
      ),

      'index' => array(
        'help' => 'List all reportbacks.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_resource'
        ),
        'callback' => '_reportback_resource_index',
        'args' => array(
          array(
            'name' => 'campaigns',
            'description' => 'The ids of specified campaigns to get reportbacks.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'campaigns'),
            'default value' => NULL,
          ),
          array(
            'name' => 'status',
            'description' => 'Comma delimited list of reportback statuses to collect reportbacks for.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'status'),
            'default value' => 'promoted,approved',
          ),
          array(
            'name' => 'count',
            'description' => 'The number of reportbacks to retrieve.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'count'),
            'default value' => 25,
          ),
          array(
            'name' => 'random',
            'description' => 'Boolean to indicate whether to retrieve reportbacks in random order.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => array('param' => 'random'),
            'default value' => FALSE,
          ),
          array(
            'name' => 'page',
            'description' => 'The zero-based index of the page to get, defaults to 0.',
            'optional' => TRUE,
            'type' => 'int',
            'source' => array('param' => 'page'),
            'default value' => 1,
          ),
          array(
            'name' => 'load_user',
            'description' => 'Boolean to indicate whether to make call to northstar to retrieve full user data.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => array('param' => 'load_user'),
            'default value' => FALSE,
          ),
          array(
            'name' => 'flagged',
            'description' => 'Boolean to indicate whether to also retrieve flagged reportbacks.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => array('param' => 'flagged'),
            'default value' => FALSE,
          ),
        ),
        'access callback' => '_reportback_resource_access',
        'access arguments' => array('index'),
      ),

    ),

  );

  return $reportback_resource;
}


/**
 * Determine whether the current user can access reportback resource.
 *
 * @param string $op
 *
 * @return bool
 */
function _reportback_resource_access($op) {
  if ($op === 'view') {
    return TRUE;
  }

  if ($op === 'index') {
    return TRUE;
  }

  return FALSE;
}


function _reportback_resource_index($campaigns, $status, $count, $random, $page, $load_user, $flagged) {
  $parameters =  array(
    'campaigns' => $campaigns,
    'status' => $status,
    'count' => $count,
    'random' => $random,
    'page' => $page,
    'load_user' => $load_user,
    'flagged' => $flagged,
  );

  $reportbacks = new ReportbackTransformer;
  return $reportbacks->index($parameters);
}


function _reportback_resource_retrieve($rbid) {
  $reportbacks = new ReportbackTransformer;
  return $reportbacks->show($rbid);
}
