<?php

function _signup_resource_definition() {
  $signup_resource = [];
  $signup_resource['signups'] = [
    'operations' => [

      'retrieve' => [
        'help' => 'Retrieve a specified signup.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/signup_resource',
        ],
        'callback' => '_signup_resource_retrieve',
        'args' => [
          [
            'name' => 'sid',
            'description' => 'The sid of the signup record to retrieve.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => ['path' => 0],
          ],
        ],
        'access callback' => '_signup_resource_access',
        'access arguments' => ['view'],
      ],

      'index' => [
        'help' => 'List all signups.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/signup_resource',
        ],
        'callback' => '_signup_resource_index',
        // 'args' => [
        //   [
        //     'name' => 'users',
        //     'description' => 'The ids of specified users to get signups for.',
        //     'optional' => TRUE,
        //     'type' => 'string',
        //     'source' => [
        //       'param' => 'users'
        //     ],
        //     'default value' => NULL,
        //   ],
        //   [
        //     'name' => 'campaigns',
        //     'description' => 'The ids of the specified campaigns to get signups for.',
        //     'optional' => TRUE,
        //     'type' => 'string',
        //     'source' => ['param' => 'campaigns'],
        //     'default value' => NULL,
        //   ],
        // ],
        'access callback' => '_signup_resource_access',
        'access arguments' => ['index'],
      ],
    ],
  ];

  return $signup_resource;
}


/**
 * Determine whether the current user can access signup resource.
 *
 * @param string $op
 *
 * @return bool
 */
function _signup_resource_access($op) {
  if ($op === 'view') {
    return TRUE;
  }

  if ($op === 'index') {
    return TRUE;
  }

  return FALSE;
}


/**
 * Retrieve and show response for signup request.
 *
 * @param $sid
 *
 * @return array
 */
function _signup_resource_retrieve($sid) {
  return (new SignupTransformer)->show($sid);
}


/**
 * Retrieve and show index list response of signups requested.
 * @param string $users
 * @param string $campaigns
 *
 * @return mixed
 */
function _signup_resource_index(){//$parameters) {
  // $parameters = [
  //   'users' => $users,
  //   'campaigns' => $campaigns,
  // ];

  return (new SignupTransformer)->index($parameters);
}
