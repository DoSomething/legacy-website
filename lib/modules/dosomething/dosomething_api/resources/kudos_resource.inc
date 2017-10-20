<?php

use Carbon\Carbon;

function _kudos_resource_definition() {
  $kudos_resource = [];
  $kudos_resource['kudos'] = [
    'operations' => [

      'retrieve' => [
        'help' => 'Retrieve a specified kudos record on a reportback item.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/kudos_resource',
        ],
        'callback' => '_kudos_resource_retrieve',
        'args' => [
          [
            'name' => 'id',
            'description' => 'The kid of the kudos record to retrieve.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => ['path' => 0],
          ],
        ],
        'access callback' => '_kudos_resource_access',
        'access arguments' => ['view'],
      ],

      'index' => [
        'help' => 'List all kudos.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/kudos_resource',
        ],
        'callback' => '_kudos_resource_index',
        'args' => [
          [
            'name' => 'reportbackitems',
            'description' => 'The ids of specified reportbacks to get kudos.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => [
              'param' => 'reportbackitems'
            ],
            'default value' => NULL,
          ],
          [
            'name' => 'count',
            'description' => 'The number of kudos to retrieve.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'count'],
            'default value' => 25,
          ],
        ],
        'access callback' => '_kudos_resource_access',
        'access arguments' => ['index'],
      ],

      'create' => [
        'help' => 'Create a new kudos record.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/kudos_resource',
        ],
        'callback' => '_kudos_resource_create',
        'args' => [
          [
            'name' => 'reportback_item_id',
            'description' => 'The id of reportback item to create kudos record.',
            'optional' => FALSE,
            'type' => 'string',
            'source' => [
              'data' => 'reportback_item_id',
            ],
          ],
          [
            'name' => 'term_ids',
            'description' => 'An array of kudos term IDs.',
            'optional' => FALSE,
            'type' => 'array',
            'source' => [
              'data' => 'term_ids',
            ],
          ],
          [
            'name' => 'northstar_id',
            'description' => 'The Northstar ID of the user to create this reaction for',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['data' => 'northstar_id'],
            'default_value' => NULL,
          ],
        ],
        'access callback' => '_kudos_resource_access',
        'access arguments' => ['create'],
      ],

      'delete' => [
        'help' => 'Delete a kudos record.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/kudos_resource',
        ],
        'callback' => '_kudos_resource_delete',
        'args' => [
          [
            'name' => 'kudos_id',
            'optional' => FALSE,
            'type' => 'int',
            'source' => [
              'path' => 0,
            ],
          ],
        ],
        'access callback' => '_kudos_resource_access',
        'access arguments' => ['delete'],
      ],
    ],

  ];

  return $kudos_resource;
}


/**
 * Determine whether the current user can access kudos resource.
 *
 * @param string $op
 *
 * @return bool
 */
function _kudos_resource_access($op) {
  if ($op === 'view') {
    return TRUE;
  }

  if ($op === 'index') {
    return TRUE;
  }

  if ($op === 'create' || $op === 'delete') {
    if (!user_is_anonymous()) {
      return TRUE;
    }
  }

  return FALSE;
}


/**
 * Retrieve and show response for kudos request.
 *
 * @param $id
 *
 * @return string
 */
function _kudos_resource_retrieve($id) {
  return (new KudosTransformer)->show($id);
}


/**
 * Retrieve and show index list response of kudos requested.
 * @param $reportbackitems
 *
 * @return mixed
 */
function _kudos_resource_index($reportbackitems, $count) {
  $parameters = [
    'reportbackitem_ids' => $reportbackitems,
    'count' => $count,
  ];

  return (new KudosTransformer)->index($parameters);
}

/**
 * Create a new kudos record.
 *
 * @param $reportback_item_id
 * @param $user_id
 * @param $term_ids
 */
function _kudos_resource_create($reportback_item_id, $term_ids, $northstar_id) {
  global $user;

  if (!isset($northstar_id)) {
    $northstar_id = dosomething_user_get_northstar_id($user->uid);
  }

  $data = [
    'northstar_id' => $northstar_id,
    'post_id' => $reportback_item_id,
  ];

  $response = dosomething_rogue_client()->postReaction($data);

  // If Rogue doesn't acknowledge that we liked a post, return Phoenix-style failure.
  if ($response['meta']['action'] !== 'liked') {
    return [false];
  }

  // Otherwise, return Phoenix-style success!
  return [
    [
      'kid' => $response['data']['post_id'] . '|' . $northstar_id,
      'fid' => $reportback_item_id,
      'uid' => $northstar_id,
      'tid' => $term_ids[0],
      'created' => (new Carbon($response['data']['created_at']))->timestamp,
    ]
  ];
}

/**
 * Delete the specified kudos record.
 *
 * @param $kudos_id
 *
 * @return array
 */
function _kudos_resource_delete($kudos_id) {
  global $user;

  list($post_id, $northstar_id) = explode('|', $kudos_id);

  // Make sure authenticated user is an admin or the kudo owner.
  $api_user_is_an_admin = user_access('view any reportback', $user);
  $logged_in_user_matches_given_id = dosomething_user_get_northstar_id($user->uid) === $northstar_id;
  if (!$api_user_is_an_admin && !$logged_in_user_matches_given_id) {
    return [
      'error' => [
        'message' => 'There was an error deleting the specified kudos record.',
      ],
    ];
  }

  $data = [
    'northstar_id' => $northstar_id,
    'post_id' => $post_id,
  ];

  $response = dosomething_rogue_client()->postReaction($data);

  // If Rogue doesn't acknowledge that we unliked a post, return Phoenix-style failure.
  if ($response['meta']['action'] !== 'unliked') {
    return [
      'error' => [
        'message' => 'There was an error deleting the specified kudos record.',
      ],
    ];
  }

  // Otherwise, return Phoenix-style success!
  return [
    'success' => [
      'message' => 'Kudos record successfully deleted.',
    ],
  ];
}
