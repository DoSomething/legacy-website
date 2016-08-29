<?php
/**
 * Script to set a placeholder email for users with blank mail field.
 *
 * to run:
 * drush --script-path=../scripts/ php-script fix-empty-mail.php
 */

$troublemakers = db_query('SELECT uid FROM users LEFT JOIN field_data_field_mobile ON uid = entity_id WHERE mail = \'\' AND uid != 0');
$fixed = 0;

foreach ($troublemakers as $user) {
  $user = user_load($user->uid);

  // Set the new email for the deactivated user.
  $mobile = dosomething_user_get_field('field_mobile', $user);
  $fresh_and_clean_digits = dosomething_user_clean_mobile_number(preg_replace('[^0-9]', '', $mobile));
  if (! $fresh_and_clean_digits) {
    print 'Could not fix ' . $user->uid . ' (' . $mobile . ', ' . $user->mail . ')' . PHP_EOL;
    continue;
  }

  $new_email = $fresh_and_clean_digits . '@mobile.import';
  print 'Updated user ' . $user->uid . '(' . $user->mail . ' --> ' . $new_email . ')' . PHP_EOL;
  $user = user_save($user, ['mail' => $new_email]);

  $fixed++;
}

print '[✔] Fixed mobile placeholder email for ' . $fixed . ' users.' . PHP_EOL;
