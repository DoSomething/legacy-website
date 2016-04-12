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
            'description' => 'The rbid of the reportback to retrieve.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => ['path' => 0],
          ],
        ],
        'access callback' => '_reportback_resource_access',
        'access arguments' => ['view'],
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
            'name' => 'ids',
            'description' => 'Retrieve reportbacks based on specific node ids.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'ids'],
            'default value' => NULL,
          ],
          [
            'name' => 'campaigns',
            'description' => 'The ids of specified campaigns to get reportbacks.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'campaigns'],
            'default value' => NULL,
          ],
          [
            'name' => 'status',
            'description' => 'Comma delimited list of reportback statuses to collect reportbacks for.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'status'],
            'default value' => 'promoted,approved',
          ],
          [
            'name' => 'count',
            'description' => 'The number of reportbacks to retrieve.',
            'optional' => TRUE,
            'type' => 'int',
            'source' => ['param' => 'count'],
            'default value' => 25,
          ],
          [
            'name' => 'random',
            'description' => 'Boolean to indicate whether to retrieve reportbacks in random order.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => ['param' => 'random'],
            'default value' => FALSE,
          ],
          [
            'name' => 'page',
            'description' => 'The zero-based index of the page to get, defaults to 0.',
            'optional' => TRUE,
            'type' => 'int',
            'source' => ['param' => 'page'],
            'default value' => 1,
          ],
          [
            'name' => 'load_user',
            'description' => 'Boolean to indicate whether to make call to northstar to retrieve full user data.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => ['param' => 'load_user'],
            'default value' => FALSE,
          ],
          [
            'name' => 'flagged',
            'description' => 'Boolean to indicate whether to also retrieve flagged reportbacks.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => ['param' => 'flagged'],
            'default value' => FALSE,
          ],
          [
            'name' => 'runs',
            'description' => 'The ids of the specified campaign runs to get reportbacks for.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'runs'],
            'default value' => NULL,
          ],
        ],
        'access callback' => '_reportback_resource_access',
        'access arguments' => ['index'],
      ],

    ],

  ];

  return $reportback_resource;
}


/**
 * Determine whether the current user can access reportback resource.
 *
 * @param string $op
 *
 * @return bool
 */
function _reportback_resource_access($op) {
  if ($op === 'view') {
    return TRUE;
  }

  if ($op === 'index') {
    return TRUE;
  }

  return FALSE;
}

/**
 * Retrieve and show index list response of reportbacks requested.
 *
 * @param  string  $ids
 * @param  string  $campaigns
 * @param  string  $status
 * @param  int     $count
 * @param  bool    $random
 * @param  int     $page
 * @param  bool    $load_user
 * @param  bool    $flagged
 * @return array
 */
function _reportback_resource_index($ids, $campaigns, $status, $count, $random, $page, $load_user, $flagged, $runs) {
  $parameters =  [
    'ids' => $ids,
    'campaigns' => $campaigns,
    'status' => $status,
    'count' => $count,
    'random' => $random,
    'page' => $page,
    'load_user' => $load_user,
    'flagged' => $flagged,
    'runs' => $runs,
  ];

  return (new ReportbackTransformer)->index($parameters);
}


function _reportback_resource_retrieve($rbid) {
  return (new ReportbackTransformer)->show($rbid);
}
