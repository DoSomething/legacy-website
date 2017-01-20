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

  return services_error('This endpoint is specifically for calling custom actions (spells). Please refer to the documentation.', 400);
}

/**
 * Complete the automatic campaign signup for a user via
 * the SignupTransformer class.
 *
 * @param  array $parameters
 * @return array|Exception
 */
function magick_signup($parameters) {
  foreach (['key', 'user', 'campaign', 'campaign_run'] as $name) {
    if (! $parameters[$name]) {
      return services_error('The request is missing the \'' . $name . '\' token parameter.', 422);
    }
  }

  $response = (new SignupTransformer)->create($parameters);

  $data = magick_get_data($parameters['user'], $parameters['campaign']);

  $campaign_uri = $data['language_prefix'] . '/node/' . $parameters['campaign'];

  if (array_key_exists('error', $response)) {
    return magick_redirect($campaign_uri);
  }

  $query = [
    'magicks' => TRUE,
    'user_id' => $parameters['user'],
    'campaign_id' => $parameters['campaign'],
  ];

  return magick_redirect($campaign_uri, $query);
}

/**
 * Redirect to a specified page.
 *
 * @param  string $path
 * @param  array  $query
 * @param  string $fragment
 * @return void
 */
function magick_redirect($path, array $query = [], $fragment = '') {
  $url_options = [
    'query' => $query,
    'fragment' => $fragment,
  ];

  drupal_goto($path, $url_options);
}

/**
 * Get a bunch of useful ingredients we need to conjure
 * magick spells.
 *
 * @param  string $user_id
 * @param  string $campaign_id
 * @return array
 */
function magick_get_data($user_id, $campaign_id) {
  $user = user_load($user_id);
  $campaign = node_load($campaign_id);

  $language_code = dosomething_global_get_language($user, $campaign, TRUE);
  $language_prefix = dosomething_global_get_prefix_for_language($language_code);

  return [
    'user' => $user,
    'campaign' => $campaign,
    'language_code' => $language_code,
    'language_prefix' => $language_prefix,
  ];
}
