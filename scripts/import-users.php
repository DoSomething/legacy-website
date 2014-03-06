<?php
/*
 * Script to import users from old world into new world.
 *
 * to run:
 * import user data from old world site into temporary table
 * drush --script-path=../scripts/ php-script import-users.php
 *
 */

$user_table = '_users_old_world';

//@TODO: don't limit this.
$result = db_query('SELECT * FROM {' . $user_table . '} LIMIT 5');

foreach ($result as $row) {
  // Only migrate users with active status.
  if ($row->status == 1) {
    $user = array();
    $user['name'] = user_password(8);
    $user['pass'] = $row->pass;
    $user['mail'] = $row->mail;
    $user['created'] = $row->created;
    $user['access'] = $row->access;
    $account = user_save('', $user);

    // Keep uids.
    $old_uid = $row->uid;
    $new_uid = $account->uid;
  }
}

//@TODO: remove temp table after it's done.
//@TODO: need a temp way to keep old uid to map all old fields to new uid