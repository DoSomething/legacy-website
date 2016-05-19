<?php
/**
 * Script to remove users with
 *
 * to run:
 * drush --script-path=../scripts/ php-script remove-duplicate-emails.php
 */

$users = db_query('SELECT uid FROM users 
  WHERE mail IN (SELECT mail FROM users GROUP BY mail HAVING COUNT(mail) > 1)
  AND uid NOT IN (SELECT MIN(uid) FROM users GROUP BY mail HAVING COUNT(mail) > 1)');

foreach ($users as $user) {
  $user = user_load($user->uid);

  if($user->access == 0) {
    print 'Deleting ' . $user->uid . ' (' . $user->mail . ')' . PHP_EOL;

    $northstar_id = $user->field_northstar_id[LANGUAGE_NONE][0]['value'];

    if ($northstar_id !== 'NONE') {
      print 'User ' . $user->uid . ' has a Northstar profile: ' . $northstar_id;
    }

    user_delete($user->uid);
  } else {
    print 'Ignoring duplicate ' . $user->uid . ' (' . $user->mail . ')' . PHP_EOL;
  }
}
