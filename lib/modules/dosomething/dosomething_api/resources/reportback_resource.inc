<?php

function _reportback_resource_definition() {
  $reportback_resource = [];
  $reportback_resource['reportbacks'] = [
    'operations' => [

      'retrieve' => [
        'help' => 'Retrieve a specified reportback.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_resource'
        ],
        'callback' => '_reportback_resource_retrieve',
        'args' => [
          [
            'name' => 'rbid',
            'optional' => FALSE,
            'source' => ['path' => 0],
            'type' => 'int',
            'description' => 'The rbid of the reportback to retrieve.'
          ],
        ],
        'access callback' => '_reportback_resource_access',
      ],

      'index' => [
        'help' => 'List all reportbacks.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_resource'
        ],
        'callback' => '_reportback_resource_index',
        'args' => [
          [
            'name' => 'page',
            'optional' => TRUE,
            'type' => 'int',
            'description' => 'The zero-based index of the page to get, defaults to 0.',
            'default value' => 0,
            'source' => ['param' => 'page'],
          ],
        ],
        'access callback' => '_reportback_resource_access',
      ],

    ],
  ];

  return $reportback_resource;
}


function _reportback_resource_index($page) {
  $reportbacks = new Reportback;

  return $reportbacks->index($page);
}

function _reportback_resource_retrieve($rbid) {

  return [
    'data' => $rbid
  ];

//  $reportbacks = new Reportback;
//
//  return $reportbacks->show($rbid);
}

function _reportback_resource_access() {
  return TRUE;
}
