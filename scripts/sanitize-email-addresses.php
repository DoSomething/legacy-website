<?php
/*
 * Sanitize email addresses on user accounts from ages ago.
 *
 * drush --script-path=../scripts php-script sanitize-email-addresses.php
 */

// Any invalid email addresses weren't synced to Northstar, so we can start there.
$wild_typers = db_query('SELECT uid, mail FROM users WHERE uid NOT IN (SELECT uid FROM authmap);');

foreach($wild_typers as $wilder) {
  $user = user_load($wilder->uid);

  if ($user->uid == 0) {
    continue;
  }

  if (! filter_var($user->mail, FILTER_VALIDATE_EMAIL)) {
    print 'Removing invalid email for ' . $user->uid . ' (' . $user->mail . ')' . PHP_EOL;

    user_save($user, ['mail' => 'bad-email-' . $user->uid . '@dosomething.invalid']);
  }

  // Now, update the corresponding profile in Northstar & save ID to authmap table.
  $response = dosomething_northstar_update_user($user);
  dosomething_northstar_save_id_field($user->uid, $response);

  // If user 404'd on Northstar, try to create them.
  if (is_null($response)) {
    dosomething_northstar_create_user($user, $password);
  }
}

print 'done';
