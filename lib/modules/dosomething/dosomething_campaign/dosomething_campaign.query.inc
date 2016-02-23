<?php
/**
* Get status whether this campaign has a competition or not.
*
* @return bool
*/
protected function getCompetition($id) {
	$query = db_select('node', 'n');
	$query->leftJoin('dosomething_signup_data_form', 'sdf', 'n.nid = sdf.nid');
	$query->fields('sdf', ['competition_signup']);
	$query->condition('n.nid', $id);

	$result = $query->execute()->fetchAll();
	$result = $result[0]->competition_signup;

	if ($result == '1') {
	  $result = TRUE;
	}
	elseif ($result == '0') {
	  $result = FALSE;
	}

	return $result;
}