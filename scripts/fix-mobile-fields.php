<?php
/**
 * Script to fix users with `xxxx@mobile` emails, but nothing set in their mobile field.
 *
 * to run:
 * drush --script-path=../scripts/ php-script fix-mobile-fields.php
 */

$records = db_query('SELECT u.uid FROM users u
  LEFT JOIN field_data_field_mobile m ON u.uid = m.entity_id
  WHERE mail LIKE \'%@mobile\'
  AND (m.field_mobile_value IS NULL OR m.field_mobile_value = \'\')');

foreach ($records as $record) {
  $user = user_load($record->uid);

  $mobile = dosomething_user_clean_mobile_number(str_replace('@mobile', '', $user->mail));

  // If we couldn't clean the mobile number, print an error and skip this record.
  if(! $mobile) {
    print 'Could not fix mobile field for ' . $user->uid . ' (' . $user->mail . ')' . PHP_EOL;
    continue;
  }

  $edit = [];
  dosomething_user_set_fields($edit, [
    'mobile' => $mobile
  ]);

  // Make sure we're not making a duplicate of an existing mobile field.
  if($existing = dosomething_user_get_user_by_mobile($mobile)) {
    print 'Could not overwrite existing mobile field for ' . $existing->uid . ' with ' . $user->uid . ' (' . $user->mail . ')' . PHP_EOL;
    continue;
  }

  user_save($user, $edit);

  print 'Fixed mobile field for ' . $user->uid . ' (' . $user->mail . ' --> ' . $mobile . ')' . PHP_EOL;
}
