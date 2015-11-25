<?php

/*
 * Script to import user data from old world into new world.
 * tables needed from old world
 *  - profile
 *  - field_data_field_user_first_name
 *  - field_data_field_user_birthday
 *
 * to run:
 * drush --script-path=../scripts/ php-script import-all-the-things.php
 *
 */

$profile_id = '_profile_old_world';
$birthday_data = '_birthday_old_world';
$first_name = '_first_name_old_world';
$users = 'users';
$last_saved = variable_get('last_user_saved', '');
// Let's only try to get people who don't already have a mobile value.
$users_no_data = db_query("SELECT u.uid, ob.field_user_birthday_value, ofn.field_user_first_name_value
                    FROM {$users} u
                    LEFT JOIN field_data_field_first_name fn ON fn.entity_id = u.uid
                    LEFT JOIN field_data_field_birthdate b on b.entity_id = u.uid
                    INNER JOIN {$profile_id} p on p.uid = u.uid
                    LEFT JOIN {$birthday_data} ob on ob.entity_id = p.pid
                    LEFT JOIN {$first_name} ofn on ofn.entity_id = p.pid
                    WHERE u.uid > $last_saved
                    AND (fn.field_first_name_value is NULL
                    OR b.field_birthdate_value is NULL)");

foreach ($users_no_data as $user_row) {
  $edit = [];
  if ($user_row->field_user_birthday_value) {
    // Save the uid of the last saved.
    variable_set('last_user_saved', $user_row->uid);
    $edit['field_birthdate'] = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $user_row->field_user_birthday_value,
        ],
      ],
    ];
  }

  if ($user_row->field_user_first_name_value) {
    $edit['field_first_name'] = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $user_row->field_user_first_name_value,
        ],
      ],
    ];
  }
  if (!empty($edit)) {
    $account = user_load($user_row->uid);
    // Save account with extra data.
    user_save($account, $edit);

    // Calculate the age if we have the birthday.
    if (in_array('field_birthdate', $edit)) {
      dosomething_user_is_under_thirteen($account);
    }
  }
}
