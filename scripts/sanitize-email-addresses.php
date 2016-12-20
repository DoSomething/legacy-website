<?php
/*
 * Sanitize email addresses on user accounts from ages ago.
 *
 * drush --script-path=../scripts php-script sanitize-email-addresses.php
 */

// Any invalid email addresses weren't synced to Northstar, so we can start there.
$wild_typers = db_query('SELECT uid, mail FROM users WHERE uid NOT IN (SELECT uid FROM authmap);');

foreach($wild_typers as $wilder) {
  if ($wilder->uid == 0) {
    continue;
  }

  if (! (filter_var($wilder->mail, FILTER_VALIDATE_EMAIL))) {
    print 'Removing invalid email for ' . $wilder->uid . ' (' . $wilder->mail . ')' . PHP_EOL;

    $user = user_load($wilder->uid);
    user_save($user, ['mail' => 'bad-email-' . $user->uid . '@dosomething.invalid']);
  }

  // Now, update (or create) the corresponding profile in Northstar by Drupal ID.
  dosomething_northstar_create_user($user);
}

print 'done';
