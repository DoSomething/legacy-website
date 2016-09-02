<?php

function _magick_resource_definition() {
  $magick_resource = [];
  $magick_resource['magicks'] = [
    'operations' => [

      // @Index
      'index' => [
        'help' => 'List all the magick.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/magick_resource',
        ],
        'callback' => '_magick_resource_index',
        'args' => [
          [
            'name' => 'action',
            'description' => 'The action method to access.',
            'type' => 'string',
            'optional' => FALSE,
            'source' => [
              'param' => 'action',
            ],
          ],
          [
            'name' => 'campaign',
            'description' => 'The id of the specified campaign.',
            'type' => 'string',
            'optional' => TRUE,
            'source' => [
              'param' => 'campaign',
            ],
            'default value' => NULL,
          ],
          [
            'name' => 'user',
            'description' => 'The id of the specified user.',
            'type' => 'string',
            'optional' => TRUE,
            'source' => [
              'param' => 'user',
            ],
            'default value' => NULL,
          ],
          [
            'name' => 'key',
            'description' => 'Custom key to allow automatic campaign signup.',
            'type' => 'string',
            'optional' => TRUE,
            'source' => [
              'param' => 'key',
            ],
            'default value' => NULL,
          ],
          [
            'name' => 'source',
            'description' => 'Source for the request.',
            'type' => 'string',
            'optional' => TRUE,
            'source' => [
              'param' => 'source',
            ],
            'default value' => NULL,
          ],
        ],
        'access callback' => '_magick_resource_access',
        'access arguments' => ['index'],
      ],

    ],

  ];

  return $magick_resource;
}

/**
 * Determine whether the method is accessable.
 *
 * @return bool
 */
function _magick_resource_access($method) {
  // Temp universal access for now.
  return TRUE;
}

/**
 * Mediate the request and pass along to specfied action if
 * available.
 *
 * @param  string $action
 * @param  string $campaign
 * @param  string $user
 * @return Response??
 */
function _magick_resource_index($action, $campaign, $user, $key, $source) {
  if ($action === 'signup') {
    return magick_signup(compact('campaign', 'user', 'key', 'source'));
  }

  return services_error('This endpoint is specifically for calling custom actions.', 401);
}

/**
 * Complete the automatic campaign signup for a user via
 * the SignupTransformer class.
 *
 * @param  array $parameters
 * @return Response??
 */
function magick_signup($parameters) {
  if (! $parameters['key']) {
    return services_error('The request is missing the \'key\' token parameter.', 401);
  }

  if (! $parameters['user']) {
    return services_error('The request is missing the \'user\' parameter.', 401);
  }

  return (new SignupTransformer)->create($parameters);
}
