<?php

/*
 * Script to import mobile data from old world into new world.
 *
 * to run:
 * drush --script-path=../scripts/ php-script import-mobile-data.php
 *
 */

$profile_id = '_profile_old_world';
$mobile_data = '_mobile_old_world';
$users = 'users';

// Let's only try to get people who don't already have a mobile value.
$users_no_mobile = db_query("SELECT * FROM {$users} u
                    LEFT JOIN field_data_field_mobile m ON m.entity_id = u.uid
                    WHERE m.field_mobile_value is NULL;");
$edit = array();
foreach ($users_no_mobile as $user_row) {
  $account = user_load($user_row->uid);

  $mobile_result = db_query("SELECT  m.field_user_mobile_value
                             FROM {$mobile_data} m
                             INNER JOIN {$profile_id} p on m.entity_id = p.pid
                             WHERE p.uid = $user_row->uid")->fetchField();
  if ($mobile_result) {
    $edit['field_mobile'] = array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $mobile_result,
        ),
      ),
    );
    // Save account with extra data.
    user_save($account, $edit);
  }

}