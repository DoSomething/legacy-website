<?php

function _term_resource_defintion() {
  $resource = array();
  $resource['terms'] = array(
    'operations' => array(
      'index' => array(
        'help' => 'List relevant taxonomy terms.',
        'file' => array('type' => 'inc', 'module' => 'dosomething_api', 'name' => 'resources/term_resource'),
        'callback' => '_term_resource_index',
        'access arguments' => array('access content'),
        'args' => array(
          array(
            'name' => 'parameters',
            'optional' => TRUE,
            'type' => 'array',
            'description' => 'Parameters',
            'default value' => array(),
            'source' => array('param' => 'parameters'),
          ),
        ),
      ),
    ),
    'relationships' => array(
      'inbox' => array(
        'file' => array('type' => 'inc', 'module' => 'dosomething_api', 'name' => 'resources/term_resource'),
        'help'   => 'Returns Reportback Inbox for a term. GET from terms/123/inbox',
        'access arguments' => array('view any reportback'),
        'callback' => '_term_resource_load_inbox',
        'args'     => array(
          array(
            'name' => 'tid',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'int',
            'description' => 'The tid of the term whose gallery we are getting',
          ),
          array(
            'name' => 'count',
            'type' => 'int',
            'description' => t('Number of Reportback Files to load.'),
            'source' => array('param' => 'count'),
            'optional' => TRUE,
          ),
          array(
            'name' => 'offset',
            'type' => 'int',
            'description' => t('If count is set to non-zero value, you can pass also non-zero value for start. For example to get Reportback Files from 5 to 15, pass count=10 and start=5.'),
            'source' => array('param' => 'offset'),
            'optional' => TRUE,
          ),
        ),
      ),
    ),
  );
  return $resource;
}

/**
 * Callback for Terms index.
 *
 * For now, only return Cause terms (only needed vocabulary for this endpoint).
 */
function _term_resource_index($parameters) {
  $terms = array();
  $int_properties = array('tid', 'vid');
  $cause = taxonomy_vocabulary_machine_name_load('cause');
  if ($cause) {
    $terms = taxonomy_get_tree($cause->vid);
  }
  $display_totals = user_access('view any reportback');
  foreach ($terms as &$term) {
    // Convert string output to integers where appropriate.
    foreach ($int_properties as $property) {
      $term->{$property} = (int) $term->{$property};
    }
    $params = array(
      'tid' => $term->tid,
      'status' => 'pending',
    );
    if ($display_totals) {
      $term->inbox = dosomething_reportback_get_reportback_files_query_count($params);
    }

  }
  unset($term);
  return $terms;
}


/**
 * Returns the Reportback Inbox of a specified term.
 *
 * @param int $tid
 *   Unique identifier for the taxonomy term.
 * @param int $count
 *   Number of Reporback Files to return.
 * @param int $start
 *   Which RB File to start with. If present, $start and $count are used together
 *   to create a LIMIT clause to select RB Files. This could be used to do paging.
 *
 * @return
 *   An array of Reportback File objects.
 */
function _term_resource_load_inbox($tid, $count = 25, $start = 0) {
  $params = array(
    'tid' => $tid,
    'status' => 'pending',
  );
  return dosomething_api_get_reportback_files($params, $count, $start);
}
