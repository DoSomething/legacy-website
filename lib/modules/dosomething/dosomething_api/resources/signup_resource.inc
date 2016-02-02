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
        'args' => [
          [
            'name' => 'user',
            'description' => 'The id of the specified user to get signups for.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'user'],
            'default value' => NULL,
          ],
          [
            'name' => 'campaigns',
            'description' => 'The ids of the specified campaigns to get signups for.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'campaigns'],
            'default value' => NULL,
          ],
        ],
        'access callback' => '_signup_resource_access',
        'access arguments' => ['index'],
      ],
    ],
  ];

  return $signup_resource;
}

function _signup_resource_access() {
  // Temp universal access for now.
  return TRUE;
}

/**
 * Retrieve and show index list response of signups requested.
 * @param string $user
 * @param string $campaigns
 * @return array
 */
function _signup_resource_index($user, $campaigns) {
  $parameters = [
    'user' => $user,
    'campaigns' => $campaigns,
  ];
  print_r($parameters);
  die();

  return (new SignupTransformer)->index($parameters);
}

/**
 * Retrieve and show response for signup request.
 *
 * @param string $sid Signup id.
 *
 * @return array
 */
function _signup_resource_retrieve($sid) {
  return (new SignupTransformer)->show($sid);
}
