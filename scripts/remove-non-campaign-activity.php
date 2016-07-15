<?php
/*
 * Script to remove activity on non-campaign nodes.
 *
 * To run you need to pass which table you would like to update. signup|reportback
 * drush --script-path=../scripts/ php-script remove-non-campaign-activity.php signup|reportback
 *
 */

$arg = drush_get_arguments();
$table = 'dosomething_' . $arg[2];

if (db_table_exists($table)) {
  if ($table == 'dosomething_signup') {
    $id = 'sid';
  }
  else {
    $id = 'rbid';
  }
  $types = ['campaign_group', 'home', 'fact', 'fact_page', 'image'];
  $query = db_select($table, 't');
  $query->join('node', 'n', 't.nid = n.nid');
  $query->fields('t', ['nid'])
  ->fields('t', [$id])
  ->addField('t', $id, 'id');
  $results = $query->condition('n.type', $types, 'IN')
  ->execute();

  foreach($results as $result) {
    try {
      db_delete($table)
      ->condition($id, $result->id)
      ->execute();
      $count++;
      echo 'removed : ' . $result->id . "\n";
    }
    catch(Exception $e) {
      echo 'bad things: ' . $e;
    }
  }
  echo 'done ';
}
else {
  echo 'Are you outta your mind? ' . $arg[2] . ' is not a valid table' . "\n";
}
