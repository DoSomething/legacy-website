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
    user_save($user, ['field_mobile' => [ LANGUAGE_NONE => [] ] ]);

    $removed++;

    // Now, update the corresponding profile in Northstar by Drupal ID.
    dosomething_northstar_update_user($user, ['mobile' => null, 'drupal_id' => $user->uid]);
  }

  print PHP_EOL;
}

print '[✔] Removed duplicate mobile field from ' . $removed . ' users.' . PHP_EOL;
