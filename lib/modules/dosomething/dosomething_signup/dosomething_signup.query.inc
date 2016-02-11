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
 *  - user (string)
 *  - campaigns (string|array)
 * @return object
 *   An executed database query object to iterate through.
 */
function dosomething_signup_get_signups_query($params = []) {
  $query = dosomething_signup_build_signups_query($params);
  $offset = dosomething_helpers_isset($params, 'offset', 0);
  $count = dosomething_helpers_isset($params, 'count', 25);

  if ($count && $count !== 'all') {
    $query->range($offset, $count);
  }

  $result = $query->execute()->fetchAll();

  return $result;
}

/**
 * Returns a SelectQuery object of Signups with given $params.
 *
 * @param array $params
 *   An associative array of conditions to filter by. Possible keys:
 *   - uid: (string) A user uid to filter by.
 *   - campaigns: (string) Campaign nid(s) to filter by.
 * @return SelectQuery object
 */
function dosomething_signup_build_signups_query($params) {
  // $offset = dosomething_helpers_isset($params, 'offset', 0);
  // $count = dosomething_helpers_isset($params, 'count', 25);
  $query = db_select('dosomething_signup', 's');
  $query->join('dosomething_reportback', 'rb', 's.nid = rb.nid AND s.run_nid = rb.run_nid');
  $query->fields('s', array('sid'));
  $query->fields('rb', array('rbid'));
  $query->condition('s.uid', 'rb.uid');
  // $query = db_query_range("SELECT s.sid, rb.rbid
  //                     FROM dosomething_signup s 
  //                     INNER JOIN dosomething_reportback rb on s.nid = rb.nid and rb.run_nid = s.run_nid
  //                     WHERE s.uid = rb.uid;", 
  //                     $offset, $count);

  // if (isset($params['user'])) {
  //   $query->condition('s.uid', $params['user']);
  // }

  // if (isset($params['campaigns'])) {
  //   if (is_array($params['campaigns'])) {
  //     $query->condition('nid', $params['campaigns'], 'IN');
  //   } else {
  //     $query->condition('nid', $params['campaigns']);
  //   }
  // }

  return $query;
}

