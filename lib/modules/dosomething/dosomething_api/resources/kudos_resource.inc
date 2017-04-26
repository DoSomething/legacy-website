<?php

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
  if (variable_get('rogue_collection', FALSE)) {
    $data = [
      'northstar_id' => $northstar_id,
      'post_id' => $reportback_item_id,
    ];

    $client = dosomething_rogue_client();
    $response = $client->postReaction($data);

    return [
      [
        'kid' => $response['data']['post_id'],
      ]
    ];
  }

  $parameters = [
    'fid' => $reportback_item_id,
    'tids' => $term_ids,
    'northstar_id' => $northstar_id,
  ];

  return (new KudosTransformer)->create($parameters);
}


/**
 * Delete the specified kudos record.
 *
 * @param $kudos_id
 *
 * @return string
 */
function _kudos_resource_delete($kudos_id) {
  // if (variable_get('rogue_collection', FALSE)) {
  //   // @TODO: we need to get the below values
  //   $data = [
  //     'northstar_id' => $northstar_id,
  //     'post_id' => $reportback_item_id,
  //   ];

  //   $response = dosomething_rogue_client()->postReaction($data);

  //   if ($response['meta']['action'] === 'unliked') {
  //     return [
  //       [
  //         'kid' => 0,
  //       ]
  //     ];
  //   }
  // }

  return (new KudosTransformer)->delete($kudos_id);
}
