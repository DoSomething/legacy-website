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
    ],
  ];
}

/**
 * Temporrary function to change user reg source of specific user subset.
 *
 * See https://github.com/DoSomething/devops/issues/176.
 */
function drush_dosomething_global_ds_user_niche_reg_source_fix() {
  $ids = [2, 3, 4, 5, 6, 7, 8, 9, 10, 1700784, 7777777777];

  $users = user_load_multiple($ids);
  $count_total = count($users);
  $count_current = 0;
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
