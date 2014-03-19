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

// Let's only try to get people who don't already have a mobile value.
$users_no_data = db_query("SELECT uid FROM {$users} u
                    LEFT JOIN field_data_field_first_name fn ON fn.entity_id = u.uid
                    LEFT JOIN field_data_field_birthdate b on b.entity_id = u.uid
                    WHERE fn.field_first_name_value is NULL
                    OR b.field_birthdate_value is NULL;");
$edit = array();
foreach ($users_no_data as $user_row) {
  $account = user_load($user_row->uid);

  $birthday_result = db_query("SELECT  b.field_user_birthday_value
                               FROM {$birthday_data} b
                               INNER JOIN {$profile_id} p on b.entity_id = p.pid
                               WHERE p.uid = $user_row->uid")->fetchField();

  if ($birthday_result) {
    $edit['field_birthdate'] = array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $birthday_result,
        ),
      ),
    );
  }

  $first_name_result = db_query("SELECT fn.field_user_first_name_value
                                 FROM {$first_name} fn
                                 INNER JOIN {$profile_id} p on fn.entity_id = p.pid
                                 WHERE p.uid = $user_row->uid")->fetchField();


  if ($first_name_result) {
    $edit['field_first_name'] = array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $first_name_result,
        ),
      ),
    );
  }
  if (!empty($edit)) {
    // Save account with extra data.
      user_save($account, $edit);

      // Calculate the age if we have the birthday.
      if (in_array('field_birthdate', $edit)) {
        dosomething_user_is_under_thirteen($account);
      }
    }
  }
