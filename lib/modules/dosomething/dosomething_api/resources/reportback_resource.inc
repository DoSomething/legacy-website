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
            'default value' => 'approved',
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
        'access callback' => '_reportback_resource_access',
      ),

    ),

  );

  return $reportback_resource;
}


function _reportback_resource_access() {
  // @TODO: Temp universal access for now.
  // Permissions are still in effect for certain fields returned.
  return TRUE;
}


function _reportback_resource_index($campaigns, $status, $count, $random, $page) {
  $parameters =  array(
    'campaigns' => $campaigns,
    'status' => $status,
    'count' => $count,
    'random' => $random,
    'page' => $page,
  );

  $reportbacks = new ReportbackTransformer;
  return $reportbacks->index($parameters);
}


function _reportback_resource_retrieve($rbid) {
  $reportbacks = new ReportbackTransformer;
  return $reportbacks->show($rbid);
}