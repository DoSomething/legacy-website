<?php
/**
 * @file
 * Database query code for Campaign data.
 */


/**
* Get status whether this campaign has a competition or not.
*
* @return bool
*/
public function dosomething_campaign_is_competition($id) {
	$query = db_select('node', 'n');
	$query->leftJoin('dosomething_signup_data_form', 'sdf', 'n.nid = sdf.nid');
	$query->fields('sdf', ['competition_signup']);
	$query->condition('n.nid', $id);

	$result = $query->execute()->fetchAll();
	$result = $result[0]->competition_signup;

	return $result;
}