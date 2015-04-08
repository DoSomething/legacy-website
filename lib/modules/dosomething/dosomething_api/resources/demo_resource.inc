<?php

function _demo_resource_definition() {
  $demo_resource = [];
  $demo_resource['reportbacks'] = [
    'operations' => [

      'retrieve' => [
        'help' => 'Retrieve a specified reportback.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/demo_resource'
        ],
        'callback' => '_demo_resource_retrieve',
        'args' => [
          [
            'name' => 'rbid',
            'optional' => FALSE,
            'source' => ['path' => 0],
            'type' => 'int',
            'description' => 'The rbid of the reportback to retrieve.'
          ],
        ],
        'access callback' => '_demo_resource_access',
      ],

      'index' => [
        'help' => 'List all reportbacks.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/demo_resource'
        ],
        'callback' => '_demo_resource_index',
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
        'access callback' => '_demo_resource_access',
      ],

    ],
  ];

  return $demo_resource;
}


function _demo_resource_index($page) {
  return [
    'data' => 'some demo data here!',
  ];
//  $reportbacks = new Reportback;
//  return $reportbacks->index($page);
}

function _demo_resource_retrieve($rbid) {

  return [
    'data' => $rbid
  ];

//  $reportbacks = new Reportback;
//  return $reportbacks->show($rbid);
}

function _demo_resource_access() {
  return TRUE;
}
