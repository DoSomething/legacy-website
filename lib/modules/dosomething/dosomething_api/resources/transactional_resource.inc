<?php

function _transactional_resource_definition() {
  return [
    'transactionals' => [
      'operations' => [
        'create' => [
          'help' => 'Create a transactional message.',
          'file' => [
            'type' => 'inc',
            'module' => 'dosomething_api',
            'name' => 'resources/transactional_resource',
          ],
          'callback' => '_transactional_resource_create',
          'args' => [
            [
              'name' => 'id',
              'type' => 'string',
              'description' => 'The user\'s Northstar ID.',
              'source' => 'data',
              'optional' => FALSE,
            ],
            [
              'name' => 'template',
              'type' => 'string',
              'description' => 'The type of transactional to send.',
              'source' => 'data',
              'optional' => FALSE,
            ],
          ],
          'access callback' => '_transactional_resource_access',
          'access arguments' => ['create'],
        ],
      ],
    ]
  ];
}

/**
 * Access callback for User resources.
 */
function _transactional_resource_access() {
  global $user;

  return in_array('administrator', $user->roles);
}

/**
 * Callback for triggering a transactional.
 *
 * @param array $request
 *   Array passed to the endpoint. Possible keys:
 *   - $id (string). The user's Northstar ID
 *   - $template (string). The type of transactional to send.
 *
 * @return mixed
 */
function _transactional_resource_create($request) {
  global $user;

  $account = user_load(dosomething_user_convert_to_legacy_id($request['id']));

  if (! $account) {
    return services_error('Could not load Drupal account for the given ID.');
  }

  $templates = ['register'];
  if (! in_array($request['template'], $templates)) {
    return services_error('Template must be one of: ' . implode(',', $templates) . '.');
  }

  $user = $account;

  return ['success' => true];
}
