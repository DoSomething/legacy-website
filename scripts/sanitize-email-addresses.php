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

  try {
    $response = NULL;

    // Update the corresponding profile in Northstar if we have one.
    $id = dosomething_user_get_field('field_northstar_id', $user);
    if ($id) {
      $response = dosomething_northstar_client()
        ->put('v1/users/id/'.$id, dosomething_northstar_transform_user($user));
    }

    // If user didn't have ID or 404'd on Northstar, try to create them.
    if (empty($response)) {
      $response = dosomething_northstar_client()
        ->post('v1/users', dosomething_northstar_transform_user($user));

      // And save an updated ID field.
      dosomething_northstar_save_id_field($user->uid, $response);
    }

    print 'Updated Northstar profile: ' . $response['data']['id'] . PHP_EOL;
  } catch (\DoSomething\Gateway\Exceptions\ApiException $e) {
    print 'Received an exception when trying to sync ' . $user->uid . ': ' . $e->getMessage() . PHP_EOL;
  }
}

print 'done';
