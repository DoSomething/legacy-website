<?php
/**
 * @file
 * Database query code for Signup data.
 */


/**
 * Returns a object of Signups with given $params.
 *
 * @param  array  $params
 *   An associative array of conditions to filter by. Possible keys:
 *  - sid (string|array)
 *  - user (string)
 *  - campaigns (string|array)
 *  - count (int)
 * @return object
 *   An executed database query object to iterate through.
 */
function dosomething_signup_get_signups_query($params, $tally = FALSE) {
  $query = dosomething_signup_build_signups_query($params);
  $offset = dosomething_helpers_isset($params, 'offset', 0);

  if ($tally) {
    $count = 'all';
  }
  else {
    $count = dosomething_helpers_isset($params, 'count', 25);
  }

  if ($count && $count !== 'all') {
    $query->range($offset, $count);
  }

  $result = $query->execute();

  if ($tally) {
    return $result->rowCount();
  }
  else {
    return $result->fetchAll();
  }
}

/**
 * Returns a SelectQuery object of Signups with given $params.
 *
 * @param array $params
 *   An associative array of conditions to filter by. Possible keys:
 *   - uid: (string) User id(s) to filter by.
 *   - campaigns: (string) Campaign nid(s) to filter by.
 *   - competition: (boolean) Only return competition signups & order by reportback quantity. 
 *   - runs: (string) Campaign run nid(s) to filter by. 
 * @return SelectQuery object
 */
function dosomething_signup_build_signups_query($params = []) {
  $query = db_select('dosomething_signup', 's');
  $query->leftJoin('dosomething_reportback', 'rb', 's.uid = rb.uid and s.nid = rb.nid and s.run_nid = rb.run_nid');
  $query->leftJoin('field_data_field_northstar_id', 'ns', 'ns.entity_id = s.uid');
  $query->fields('s', ['sid', 'uid', 'nid', 'run_nid', 'timestamp']);
  $query->fields('rb', ['rbid']);
  $query->fields('ns', ['field_northstar_id_value']);
  $query->orderBy('sid', 'DESC');

  if (isset($params['sid'])) {
    if (is_array($params['sid'])) {
      $query->condition('s.sid', $params['sid'], 'IN');
    } else {
      $query->condition('s.sid', $params['sid'], '=');
    }
  }

  if (isset($params['user'])) {
    if (is_array($params['user'])) {
      $query->condition('s.uid', $params['user'], 'IN');
    } else {
      $query->condition('s.uid', $params['user'], '=');
    }
  }

  if (isset($params['competition'])) {
    $query->condition('s.competition', 1, '=');
    $query->orderBy('rb.quantity', 'DESC');
  }

  if (isset($params['campaigns'])) {
    if (is_array($params['campaigns'])) {
      $query->condition('s.nid', $params['campaigns'], 'IN');
    } else {
      $query->condition('s.nid', $params['campaigns'], '=');
    }
  }

  if (isset($params['runs'])) {
    if (is_string($params['runs'])) {
      $params['runs'] = explode(' ', $params['runs']);
    }

    $campaign_runs = [];
    
    foreach ($params['runs'] as $campaign_run) {
      if (is_numeric($campaign_run)) {
        array_push($campaign_runs, $campaign_run);
      } 
    }
    
    $query->condition('s.run_nid', $campaign_runs, 'IN');
  }

  return $query;
}
