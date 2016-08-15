<?php
/**
 * Script to remove users with duplicate email accounts.
 *
 * to run:
 * drush --script-path=../scripts/ php-script remove-duplicate-emails.php
 */

$dupes = array_keys(db_query('SELECT mail FROM users GROUP BY mail HAVING COUNT(mail) > 1')->fetchAllKeyed());
$removed = 0;


// Watch out, because we're gonna make a database table. Yee-haw!
db_query('
  CREATE TABLE IF NOT EXISTS `dosomething_northstar_delete_queue` (
    `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
    `uid` int(11) unsigned NOT NULL,
    `northstar_id` varchar(32) DEFAULT NULL,
    PRIMARY KEY (`id`));
');

foreach ($dupes as $mail) {
  // Load all users with that duped email address, with the most recently accessed first.
  $users = db_query('SELECT uid FROM users WHERE mail = :mail AND uid != 0 ORDER BY access DESC', [':mail' => $mail]);
  $canonical_uid = 0;

  foreach ($users as $index => $user) {
    $user = user_load($user->uid);

    if ($index == 0) {
      print 'Keeping ' . $user->uid . ' for ' . $user->mail . '.' . PHP_EOL;
      $canonical_uid = $user->uid;
      continue;
    }

    // Set the new email for the deactivated user.
    $new_email = 'duplicate-' . $canonical_uid . '-' . $index . '@dosomething.invalid';
    print ' - Removing ' . $user->uid . ' (' . $user->mail . ' --> ' . $new_email . ')' . PHP_EOL;
    user_save($user, ['mail' => $new_email, 'status' => 0]);
    $removed++;

    // Finally, make a note if that user has a Northstar profile, so we can clean that up.
    $northstar_id = $user->field_northstar_id[LANGUAGE_NONE][0]['value'];
    if ($northstar_id !== 'NONE') {
      db_insert('dosomething_northstar_delete_queue')->fields(['uid' => $user->uid, 'northstar_id' => $northstar_id])->execute();
      print '   ** User ' . $user->uid . ' has a Northstar profile: ' . $northstar_id . PHP_EOL;
    }
  }

  print PHP_EOL;
}

print '[✔] Renamed & deactivated ' . $removed . ' users.' . PHP_EOL;
