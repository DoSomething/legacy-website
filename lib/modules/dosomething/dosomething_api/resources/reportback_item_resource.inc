<?php

function _reportback_item_resource_definition() {
  $reportback_item_resource = array();
  $reportback_item_resource['reportback-items'] = array(
    'operations' => array(

      'retrieve' => array(
        'help' => 'Retrieve a specified reportback item.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_item_resource',
        ),
        'callback' => '_reportback_item_resource_retrieve',
        'args' => array(
          array(
            'name' => 'fid',
            'description' => 'The fid of the reportback item to retrieve.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => array('path' => 0),
          ),
          array(
            'name' => 'load_user',
            'description' => 'Flag to indicate whether to make call to northstar to retrieve full user data.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => array('param' => 'load_user'),
            'default value' => FALSE,
          ),
        ),
        'access callback' => '_reportback_item_resource_access',
        'access arguments' => array('view'),
      ),

      'index' => array(
        'help' => 'List all reportbacks items.',
        'file' => array(
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_item_resource'
        ),
        'callback' => '_reportback_item_resource_index',
        'args' => array(
          array(
            'name' => 'campaigns',
            'description' => 'The ids of specified campaigns to get reportback items.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'campaigns'),
            'default value' => NULL,
          ),
          array(
            'name' => 'status',
            'description' => 'Comma delimited list of reportback statuses to collect reportback items for.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'status'),
            'default value' => 'approved',
          ),
          array(
            'name' => 'count',
            'description' => 'The number of reportback items to retrieve.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'count'),
            'default value' => 25,
          ),
          array(
            'name' => 'random',
            'description' => 'Boolean to indicate whether to retrieve reportback items in random order.',
            'optional' => TRUE,
            'type' => 'int',
            'source' => array('param' => 'random'),
            'default value' => 0,
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
            'description' => 'Flag to indicate whether to make call to northstar to retrieve full user data.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => array('param' => 'load_user'),
            'default value' => FALSE,
          ),
        ),
        'access callback' => '_reportback_item_resource_access',
        'access arguments' => array('index'),
      ),

    ),

  );

  return $reportback_item_resource;
}


/**
 * Determine whether the current user can access campaign resource.
 *
 * @param string $op
 *
 * @return bool
 */
function _reportback_item_resource_access($op) {
  if ($op === 'view') {
    return TRUE;
  }

  if ($op === 'index') {
    return TRUE;
  }

  return FALSE;
}


function _reportback_item_resource_index($campaigns, $status, $count, $random, $page, $load_user) {
  $parameters = array(
    'campaigns' => $campaigns,
    'status' => $status,
    'count' => $count,
    'random' => $random,
    'page' => $page,
    'load_user' => $load_user,
  );

  $reportbackItems = new ReportbackItemTransformer;
  return $reportbackItems->index($parameters);
}


function _reportback_item_resource_retrieve($fid, $load_user) {
  $parameters = array(
    'fid' => $fid,
    'load_user' => $load_user,
  );

  $reportbackItems = new ReportbackItemTransformer;
  return $reportbackItems->show($parameters);
}
