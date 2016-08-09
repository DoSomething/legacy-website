<?php
/**
 * Script to unset duplicate mobile numbers (keeping only the most recently logged in).
 *
 * to run:
 * drush --script-path=../scripts/ php-script unset-duplicate-mobiles.php
 */

$dupes = array_keys(db_query('SELECT field_mobile_value FROM field_data_field_mobile WHERE field_mobile_value != \'\'
  GROUP BY field_mobile_value HAVING COUNT(field_mobile_value) > 1')->fetchAllKeyed());
$removed = 0;

// Watch out, because we're gonna make a database table. Yee-haw!
db_query('
  CREATE TABLE IF NOT EXISTS `dosomething_northstar_delete_queue` (
    `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
    `uid` int(11) unsigned NOT NULL,
    `northstar_id` varchar(32) DEFAULT NULL,
    PRIMARY KEY (`id`));
');

foreach ($dupes as $mobile) {
  // Load all users with that duped mobile field, with the most recently accessed first.
  $users = db_query('SELECT u.uid FROM users u 
    LEFT JOIN field_data_field_mobile m on u.uid = m.entity_id
    WHERE m.field_mobile_value = :mobile ORDER BY u.access DESC', [':mobile' => $mobile]);

  foreach ($users as $index => $user) {
    $user = user_load($user->uid);

    // Since the most recently accessed account with that mobile number is first, skip it.
    if ($index == 0) {
      print 'Keeping ' . $user->uid . ' for ' . $mobile . '.' . PHP_EOL;
      continue;
    }

    // Remove the mobile field for that user.
    print ' - Removing mobile from ' . $user->uid . ' (' . $mobile . ')' . PHP_EOL;
    $entity = entity_load_single('user', $user->uid);
    $entity->field_mobile[LANGUAGE_NONE] = [];
    entity_save('user', $entity);

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

print '[✔] Removed duplicate mobile field from ' . $removed . ' users.' . PHP_EOL;
