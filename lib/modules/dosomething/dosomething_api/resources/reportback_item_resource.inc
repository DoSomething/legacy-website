<?php

function _reportback_item_resource_definition() {
  $reportback_item_resource = [];
  $reportback_item_resource['reportback-items'] = [
    'operations' => [

      'retrieve' => [
        'help' => 'Retrieve a specified reportback item.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_item_resource',
        ],
        'callback' => '_reportback_item_resource_retrieve',
        'args' => [
          [
            'name' => 'fid',
            'description' => 'The fid of the reportback item to retrieve.',
            'optional' => FALSE,
            'type' => 'int',
            'source' => array('path' => 0),
          ],
        ],
        'access callback' => '_reportback_item_resource_access',
        'access arguments' => array('view'),
      ],

      'index' => [
        'help' => 'List all reportbacks items.',
        'file' => [
          'type' => 'inc',
          'module' => 'dosomething_api',
          'name' => 'resources/reportback_item_resource'
        ],
        'callback' => '_reportback_item_resource_index',
        'args' => [
          [
            'name' => 'campaigns',
            'description' => 'The ids of specified campaigns to get reportback items.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'campaigns'),
            'default value' => NULL,
          ],
          [
            'name' => 'exclude',
            'description' => 'Exclude reportbacks from results based on specific ids.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'exclude'],
            'default value' => NULL,
          ],
          [
            'name' => 'status',
            'description' => 'Comma delimited list of reportback statuses to collect reportback items for.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'status'),
            'default value' => 'promoted,approved',
          ],
          [
            'name' => 'count',
            'description' => 'The number of reportback items to retrieve.',
            'optional' => TRUE,
            'type' => 'string',
            'source' => array('param' => 'count'),
            'default value' => 25,
          ],
          [
            'name' => 'random',
            'description' => 'Boolean to indicate whether to retrieve reportback items in random order.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => array('param' => 'random'),
            'default value' => FALSE,
          ],
          [
            'name' => 'page',
            'description' => 'The zero-based index of the page to get, defaults to 0.',
            'optional' => TRUE,
            'type' => 'int',
            'source' => array('param' => 'page'),
            'default value' => 1,
          ],
          [
            'name' => 'load_user',
            'description' => 'Flag to indicate whether to make call to northstar to retrieve full user data.',
            'optional' => TRUE,
            'type' => 'boolean',
            'source' => array('param' => 'load_user'),
            'default value' => FALSE,
          ],
          [
            'name' => 'as_user',
            'description' => 'Override the current global user',
            'optional' => TRUE,
            'type' => 'string',
            'source' => ['param' => 'as_user'],
            'default_value' => NULL,
          ],
        ],
        'access callback' => '_reportback_item_resource_access',
        'access arguments' => array('index'),
      ],

    ],

  ];

  return $reportback_item_resource;
}


/**
 * Determine whether the current user can access campaign resource.
 *
 * @param string $op
 *
 * @return bool
 */
function _reportback_item_resource_access($op) {
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
 * @param  string  $campaigns
 * @param  string  $exclude
 * @param  string  $status
 * @param  int     $count
 * @param  bool    $random
 * @param  int     $page
 * @param  bool    $load_user
 * @param  string  $as_user
 * @return array
 */
function _reportback_item_resource_index($campaigns, $exclude, $status, $count, $random, $page, $load_user, $as_user) {
  $parameters = [
    'campaigns' => $campaigns,
    'exclude' => $exclude,
    'status' => $status,
    'count' => $count,
    'random' => $random,
    'page' => $page,
    'load_user' => $load_user,
    'as_user' => $as_user,
  ];

  // If Rogue is enabled, fetch reportback items from there.
  if (variable_get('rogue_collection', FALSE)) {
    $response = dosomething_rogue_client()->getAllReportbacks([
      'filter' => [
        'campaign_id' => $campaigns,
        'exclude' => $exclude,
      ],
      'as_user' => dosomething_user_get_field('field_northstar_id'),
      'limit' => 12,
      'page' => $page,
    ]);

    return $response;
  }

  $reportbackItems = new ReportbackItemTransformer;
  return $reportbackItems->index($parameters);
}


function _reportback_item_resource_retrieve($fid) {
  $reportbackItems = new ReportbackItemTransformer;
  return $reportbackItems->show($fid);
}
