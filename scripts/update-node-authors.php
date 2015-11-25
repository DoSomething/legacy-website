<?php
/*
 * Script to update node authors from the random uids from stage to acutal uids.
 *
 * To get the authors array, ran this query on stage and then query for matching uids on prod.
 * SELECT DISTINCT u.uid, u.mail FROM users u INNER JOIN node  n on n.uid = u.uid NNER JOIN node_revision nr on nr.uid = u.uid;
 *
 * drush --script-path=../scripts/ php-script update-node-authors.php
 *
 */

// stage uid, beta uid, email for reference.
$authors = array(
  1  => 1,        /*'admin@example.com',             */
  2  => 615996,   /*'ddeluca@dosomething.org',       */
  3  => 632265,   /*'rmohammed@dosomething.org',     */
  4  => 868854,   /*'spipergoldberg@dosomething.org',*/
  5  => 1176550,  /*'aschachter@dosomething.org',    */
  6  => 623863,   /*'fsheikh@dosomething.org',       */
  7  => 1261053,  /*'hgridley@dosomething.org',      */
  8  => 329195,   /*'mfantini@dosomething.org',      */
  9  => 1193105,  /*'nmody@dosomething.org',         */
  11 => 1192054,  /*'aruderman@dosomething.org',     */
  12 => 1324854,   /*'mholford@dosomething.org',     */
  14 => 1157702,  /*'jlorch@dosomething.org',        */
  15 => 879789,    /*'bkassoy@dosomething.org',      */
  18 => 1258186,  /*'dfurnes@dosomething.org',       */
  19 => 547446,   /*'bclark@dosomething.org',        */
  22 => 329195,   /*'mfantini@dosomething.org',      */
);

// Need to update the revisions first, otherwise it zeros out uids
$revision_results = db_query('SELECT nid, vid, uid from node_revision');
foreach($revision_results as $result) {
  $old_uid = $result->uid;
  $new_uid = $authors[$old_uid];
  if ($new_uid)  {
    echo 'Updating node revision: ' . $result->nid . ' : ' . $result->vid . ' from ' . $old_uid . ' to ' . $new_uid . "\n";
    db_update('node_revision')
      ->fields(array(
        'uid' => $new_uid,
      ))
      ->condition('uid', $old_uid)
      ->condition('nid', $result->nid)
      ->execute();

  }
}

// Then, grab all nodes
$results = db_query('SELECT nid, uid from node');
foreach($results as $result) {
  // For each node, grab the old and new uid.
  $old_uid = $result->uid;
  $new_uid = $authors[$old_uid];
  // If in the authors array...
  if ($new_uid) {
    $node = node_load($result->nid);
    echo 'Updating node: ' . $node->nid . ' from ' . $old_uid . ' to ' . $new_uid . "\n";
    $node->uid = $new_uid;
    // Update the node author.
    node_save($node);
  }
}

echo 'Finished';
