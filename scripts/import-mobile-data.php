<?php

/*
 * Script to import mobile data from old world into new world.
 *
 * to run:
 * drush --script-path=../scripts/ php-script import-mobile-data.php
 *
 */

$start = time();
print "Start: {$start} \n";

$profile_id = '_profile_old_world';
$mobile_data = '_mobile_old_world';
$users = 'users';

// Only select users who don't have mobile in the new world and have mobile in the old world.
$users_no_mobile = db_query("SELECT u.uid, mbw.field_user_mobile_value
                    FROM {$users} u
                    LEFT JOIN field_data_field_mobile m ON m.entity_id = u.uid
                    INNER JOIN {$profile_id} p on p.uid = u.uid
                    LEFT JOIN {$mobile_data} mbw ON mbw.entity_id = p.pid
                    WHERE m.field_mobile_value is NULL
                    AND mbw.field_user_mobile_value != '';");

$edit = [];
foreach ($users_no_mobile as $user_row) {
  // If there is a mobile value.
  if ($user_row->field_user_mobile_value) {
    $edit['field_mobile'] = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $user_row->field_user_mobile_value,
        ],
      ],
    ];
    // Load the user before the save.
    $account = user_load($user_row->uid);
    // Save account with extra data.
    user_save($account, $edit);
  }

}
$running_time = (time() - $start) / 60;
print "Running time: {$running_time}";
