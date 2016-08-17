<?php
/**
 * @file
 * Drush commands for dosomething_global.module.
 */

/**
 *  Implements hook_drush_command
 */
function dosomething_user_drush_command() {
  return [
    'ds-user-niche-reg-source-fix' => [
      'description' => 'Corrects user registration source to niche based on csv.',
      'arguments' => array(
        'filename' => 'Name of the CSV file to read.',
      ),
      'required-arguments' => TRUE,
    ],
  ];
}

/**
 * Temporrary function to change user reg source of specific user subset.
 *
 * See https://github.com/DoSomething/devops/issues/176.
 */
function drush_dosomething_global_ds_user_niche_reg_source_fix($filename) {
  // Only local files.
  $filename = 'file://' . $filename;
  if (($handle = fopen($filename, "r")) === FALSE) {
    drush_log(
      'Can\'t  open file: ' . $filename . '.',
      'status'
    );
    return;
  }
  drush_log('Parsing ' . $filename, 'status');

  // Prepare a list of ids.
  $row = 0;
  $ids = [];
  while(($data = fgetcsv($handle)) !== FALSE) {
    $row++;
    // Skip header.
    if ($row === 1) {
      continue;
    }
    if (empty($data[2])) {
      continue;
    }
    array_push($ids, $data[2]);
  }

  // Processing users.
  $users = user_load_multiple($ids);
  $count_total = count($users);
  $count_current = 0;
  drush_log(
    'Processing ' . $count_current . ' records.', 'status'
  );

  foreach ($users as $user) {
    $count_current++;
    $metauser = entity_metadata_wrapper('user', $user);
    $source = $metauser->field_user_registration_source->value();
    if (!empty($source)) {
      drush_log(
        'Skipping "' . $user->mail . '" as it has source "' . $source . '".',
        'status'
      );
      continue;
    }
    drush_log(
      'Processing user for ' . $count_current .
      ' of ' . $count_total . ' users: ' . $user->mail . ', id ' . $user->uid . '.',
      'status'
    );

    $metauser->field_user_registration_source->set('niche');
    $metauser->save();
  }
}
