<?php
/**
 * @file
 * Database query code for Reportback data.
 */


/**
 * Returns a SelectQuery object of Reportbacks with given $params.
 *
 * @param array $params
 *   An associative array of conditions to filter by. Possible keys:
 *   - nid: (string) A campaign node nid to filter by.
 *   - rbid: (string) A reportback rbid to filter by.
 *   - random: (boolean) If set, randomly sort the results.
 * @return SelectQuery object
 */
function dosomething_reportback_build_reportbacks_query($params = array()) {
  global $language;

  $query = db_select('dosomething_reportback', 'rb');
  $query->join('dosomething_reportback_file', 'rbf', 'rb.rbid = rbf.rbid');
  $query->leftJoin('field_data_field_reportback_noun', 'fn', 'rb.nid = fn.entity_id');
  $query->leftJoin('field_data_field_reportback_verb', 'fv', 'rb.nid = fv.entity_id');
  $query->join('node', 'n', 'rb.nid = n.nid');

  $query->addExpression('GROUP_CONCAT(DISTINCT rbf.fid)', 'items');

  print_r($query);
  die();

  if (isset($params['rbid'])) {
    if (is_array($params['rbid'])) {
      $query->condition('rb.rbid', $params['rbid'], 'IN');
    }
    else {
      $query->condition('rb.rbid', $params['rbid']);
    }
  }

  if (isset($params['nid'])) {
    $query->condition('fn.language', $language->language);
    $query->condition('fv.language', $language->language);
    if (is_array($params['nid'])) {
      $query->condition('rb.nid', $params['nid'], 'IN');
    }
    else {
      $query->condition('rb.nid', $params['nid']);
    }
  }

  if (isset($params['status'])) {
    if (is_array($params['status'])) {
      $query->condition('rbf.status', $params['status'], 'IN');
    }
    else {
      $query->condition('rbf.status', $params['status']);
    }
  }

  if (!isset($params['flagged'])) {
    $query->condition('rb.flagged', 0);
  }
  else {
    if (!$params['flagged']) {
      $query->condition('rb.flagged', 0);
    }
  }

  // Public API properties to expose:
  $rb_fields = array('rbid', 'created', 'updated', 'quantity', 'uid');

  // Staff-only properties to add:
  if (user_access('view any reportback')) {
    $rb_fields[] = 'why_participated';
    $rb_fields[] = 'flagged';
  }

  $query->fields('rb', $rb_fields);
  $query->fields('n', ['nid', 'title']);
  $query->addField('fn', 'field_reportback_noun_value', 'noun');
  $query->addField('fv', 'field_reportback_verb_value', 'verb');

  $query->groupBy('rb.rbid');

  // @TODO: After campaign gallery changes, update this condition to: isset($params['random']) && $params['random']
  if (isset($params['random'])) {
    $query->orderRandom();
  }
  else {
    $query->orderBy('rb.updated', 'DESC');
  }

  return $query;
}


/**
 * Returns Reportbacks query result to loop through.
 *
 * @param  array  $params
 *   An associative array of conditions to filter by.
 *  - rbid (string)
 *  - nid (string|array)
 *  - status (string|array)
 *  - count (int)
 *  - offset (int)
 *  - random (bool)
 *  - load_user (bool)
 *  - flagged (bool)
 * @return object
 *   An executed database query object to iterate through.
 */
function dosomething_reportback_get_reportbacks_query($params) {
  $params = dosomething_reportback_filter_flagged_reportbacks($params);

  $query = dosomething_reportback_build_reportbacks_query($params);
  $offset = dosomething_helpers_isset($params, 'offset', 0);
  $count = dosomething_helpers_isset($params, 'count', 25);

  if ($count && $count !== 'all') {
    $query->range($offset, $count);
  }

  $result = $query->execute()->fetchAll();

  return $result;
}


/**
 * Filter out requested flagged Reportbacks based on user permissions.
 *
 * @param  array  $params
 * @return mixed
 */
function dosomething_reportback_filter_flagged_reportbacks($params) {
  if (user_access('view any reportback')) {
    return $params;
  }

  // Unset False boolean values that affect the query builder.
  if (isset($params['flagged'])) {
    unset($params['flagged']);
  }

  return $params;
}

