<?php
/**
 * @file
 * Database query code for Reportback Item data.
 */


/**
* Returns a SelectQuery object of Reportback Files with given $params.
*
* @param array $params
*   An associative array of conditions to filter by. Possible keys:
*   - nid: (string) A campaign node nid to filter by.
*   - rbid: (string) A reportback rbid to filter by.
*   - tid: (string) A taxonomy term tid, filters RB Files for all nodes tagged tid.
*   - fid: (string) A reportback item fid to filter by.
*   - status: (string) The RB File status.
*   - random: (boolean) If set, randomly sort the results.
*   - order: (string) If set, return results in asc/desc order.
* @return SelectQuery object
*/
function dosomething_reportback_build_reportback_items_query($params = array()) {
  $query = db_select('dosomething_reportback_file', 'rbf');
  $query->join('dosomething_reportback', 'rb', 'rbf.rbid = rb.rbid');
  $query->leftJoin('field_data_field_reportback_noun', 'fn', 'rb.nid = fn.entity_id');
  $query->leftJoin('field_data_field_reportback_verb', 'fv', 'rb.nid = fv.entity_id');
  $query->join('users', 'u', 'rb.uid = u.uid');
  $query->join('node', 'n', 'rb.nid = n.nid');
  $query->join('file_managed', 'f', 'rbf.fid = f.fid');

  $query->leftJoin('dosomething_kudos', 'k', 'k.fid = rbf.fid');

  $query->addExpression('GROUP_CONCAT(DISTINCT k.kid)', 'kids');

  if (isset($params['tid'])) {
    $query->join('field_data_field_primary_cause', 't', 't.entity_id = n.nid');
    $query->condition('t.field_primary_cause_tid', $params['tid']);
    $query->condition('t.entity_type', 'node');
  }

  if (isset($params['status'])) {
    if (is_array($params['status'])) {
      $query->condition('rbf.status', $params['status'], 'IN');
    }
    else {
      $query->condition('rbf.status', $params['status']);
    }
  }

  if (isset($params['nid'])) {
    if (is_array($params['nid'])) {
      $query->condition('rb.nid', $params['nid'], 'IN');
    }
    else {
      $query->condition('rb.nid', $params['nid']);
    }
  }
  elseif (isset($params['fid'])) {
    if (is_array($params['fid'])) {
      $query->condition('rbf.fid', $params['fid'], 'IN');
    }
    else {
      $query->condition('rbf.fid', $params['fid']);
    }
  }
  elseif (isset($params['rbid'])) {
    $query->condition('rb.rbid', $params['rbid']);
  }

  if (isset($params['exclude'])) {
    $query->condition('rbf.fid', $params['exclude'], 'NOT IN');
  }

  // Public API properties to expose:
  $rbf_fields = array('fid', 'caption', 'rbid', 'status', 'source');
  $rb_fields = array('created', 'updated', 'quantity', 'uid');

  // Staff-only properties to add:
  if (user_access('view any reportback')) {
    $rb_fields[] = 'why_participated';
    $rb_fields[] = 'flagged';
  }

  $query->fields('rbf', $rbf_fields);
  $query->fields('rb', $rb_fields);
  $query->fields('n', array('nid', 'title'));
  $query->fields('f', array('timestamp'));
  $query->addField('fn', 'field_reportback_noun_value', 'noun');
  $query->addField('fv', 'field_reportback_verb_value', 'verb');

  $query->groupBy('rbf.fid');

  if (isset($params['random'])) {
    $query->orderRandom();
  }
  elseif (isset($params['order'])) {
    $query->orderBy('rb.updated', $params['order']);
  }
  else {
    $query->orderBy('rb.updated', 'DESC');
  }

  return $query;
}


/**
* Returns Reportback Items query result to loop through.
*
* @param  array  $params
*   An associative array of conditions to filter by.
*  - fid (string)
*  - nid (string|array)
*  - status (string|array)
*  - count (int)
*  - page (int)
*  - offset (int)
*  - random (bool)
*  - load_user (bool)
* @param  bool  $tally
* @return object
*    An executed database query object to iterate through.
*/
function dosomething_reportback_get_reportback_items_query($params, $tally = FALSE) {
  if (isset($params['status']) && !$params['status']) {
      return FALSE;
  }

  $query = dosomething_reportback_build_reportback_items_query($params);
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
