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
        ),
        'access callback' => '_reportback_item_resource_access',
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
        ),
        'access callback' => '_reportback_item_resource_access',
      ),

    ),

  );

  return $reportback_item_resource;
}


function _reportback_item_resource_access() {
  // @TODO: Temp universal access for now.
  // Permissions are still in effect for certain fields returned.
  return TRUE;
}


function _reportback_item_resource_index($campaigns, $status, $count, $random, $page) {
  $parameters = array(
    'campaigns' => $campaigns,
    'status' => $status,
    'count' => $count,
    'random' => $random,
    'page' => $page,
  );

  $reportbackItems = new ReportbackItemTransformer;
  return $reportbackItems->index($parameters);
}


function _reportback_item_resource_retrieve($fid) {
  $reportbackItems = new ReportbackItemTransformer;
  return $reportbackItems->show($fid);
}
