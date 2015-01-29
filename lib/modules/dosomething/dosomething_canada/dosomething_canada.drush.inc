<?php

/**
 *  Implements hook_drush_command
 */
function dosomething_canada_drush_command() {
  $items = array(
    'post-missing-tig-users' => array(
      'description' => 'Posts missing TIG users to the remote user API.',
      'arguments' => array(
        'filename' => t('A JSON file with users list to process.'),
      ),
      'required-arguments' => TRUE,
    ),
  );
  return $items;
}

/**
 * Callback for post-missing-tig-users command.
 *
 * Posts missing TIG users to the remote user API.
 */
function drush_dosomething_canada_post_missing_tig_users($filename) {
  $input = file_get_contents($filename);
  if (!$input) {
    drush_log(t('Can’t open file: !name', array('!name' => $filename)), 'error');
    return FALSE;
  }

  $users = json_decode($input);
  if (!is_array($users) || empty($users)) {
    drush_log(
      t('Wrong JSON user list provided in: !name.', array('!name' => $filename)),
      'error'
    );
    return FALSE;

  }

  // Prepare connection.
  $sso = dosomething_canada_get_sso();
  $user_factory = new DosomethingCanadaSsoUserFactory();

  foreach ($users as $email) {
    $account = dosomething_user_get_user_by_email($email);
    if (!$account) {
      drush_log(t('User not found: !email', array('!email' => $email)), 'error');
      continue;
    }

    $remote_account = $user_factory->fromLocalUser($account, user_password());

    if ($sso->signup($remote_account)) {
      // Success.
      drush_log(t('Created: !email', array('!email' => $email)), 'ok');
      continue;
    }

    // Parse errors.
    drush_log(
      t('Error creating remote user !email: ', array('!email' => $email)),
      'error'
    );
    if ($error_messages = $sso->getErrorMessages()) {
      foreach ($error_messages as $field_name => $field_errors) {
        foreach ($field_errors as $error) {
          $human_name = ucwords(preg_replace('/[^\da-z]/i', ' ', $field_name));
          $error_text = $human_name . ': ' . $error;
          drush_log($error_text, 'error');
        }
      }
      print PHP_EOL;
    }
  }

}
