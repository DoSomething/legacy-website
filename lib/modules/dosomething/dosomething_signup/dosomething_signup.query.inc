<?php
/**
 * @file
 * Database query code for Signup data.
 */


/**
 * Returns Signup query result to loop through.
 *
 * @param  array  $params
 *   An associative array of conditions to filter by.
 *  - user (string)
 *  - campaigns (string|array)
 * @return object
 *   An executed database query object to iterate through.
 */
function dosomething_signup_get_signups_query($params) {
  $query = dosomething_signup_build_signups_query($params);

  $result = $query->execute();//->fetchAll();

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
function dosomething_signup_build_signups_query($params = []) {
  global $language;

  $query = db_query("SELECT * FROM dosomething_signup s;");

  if (isset($params['user'])) {
    $query->condition('s.uid', $params['user']);
  }

  if (isset($params['campaigns'])) {
    if (is_array($params['campaigns'])) {
      $query->condition('s.nid', $params['campaigns'], 'IN');
    }
    else {
      $query->condition('s.nid', $params['campaigns']);
    }
  }

  return $query;
}
