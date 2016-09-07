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
            'name' => 'campaign_run',
            'description' => 'The id of the specified campaign run.',
            'type' => 'string',
            'optional' => TRUE,
            'source' => [
              'param' => 'campaign_run',
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
 * @return array|ServicesException
 */
function _magick_resource_index($action, $campaign, $campaign_run, $user, $key, $source) {
  if ($action === 'signup') {
    return magick_signup(compact('campaign', 'campaign_run', 'user', 'key', 'source'));
  }

  return services_error('This endpoint is specifically for calling custom actions (spells). Please refer to the documentation.', 401);
}

/**
 * Complete the automatic campaign signup for a user via
 * the SignupTransformer class.
 *
 * @param  array $parameters
 * @return array|Exception
 */
function magick_signup($parameters) {
  if (! $parameters['key']) {
    return services_error('The request is missing the \'key\' token parameter.', 401);
  }

  if (! $parameters['user']) {
    return services_error('The request is missing the \'user\' parameter.', 401);
  }

  if (! $parameters['campaign']) {
    return services_error('The request is missing the \'campaign\' parameter.', 401);
  }

  // @TODO: forcing requirement for including the campaign_run, but can likely remove this
  // with a bit of code to figure it out. We've done it in the dosomething_signup_create()
  // but didn't inlcude it for now in the SignupTransformer->create() method.
  if (! $parameters['campaign_run']) {
    return services_error('The request is missing the \'campaign_run\' parameter.', 401);
  }

  return (new SignupTransformer)->create($parameters);
}
