<?php
/*
 * Script to import users from old world into new world.
 *
 * to run:
 * import user data from old world site into temporary tables
 * will need legacy 'users', 'profile', and 'field_data_field_user_mobile' and 'field_data_field_user_birthday'.
 * once temp tables are in place
 * drush --script-path=../scripts/ php-script import-users.php
 *
 */
$user_table = 'users';
$old_users = '_users_old_world';
$profile_id = '_profile_old_world';
$mobile_data = '_mobile_old_world';
$birthday_data = '_birthday_old_world';

$last_saved = variable_get('last_user_saved', '');
if ($last_saved) {
  $result = db_query("SELECT * FROM {$old_users} where uid > $last_saved");
}
// This is just a fail safe, since we should set the last_saved variable.
else {
  $result = db_query("SELECT * FROM {$old_users}");
}

foreach ($result as $user_row) {
  // Only migrate users with active status.
 if ($user_row->status == 1) {
     $user = [];
     // Will be overridden by uid.
     $user['name'] = user_password(8);
     $user['uid'] = $user_row->uid;
     $user['pass'] = $user_row->pass;
     $user['mail'] = $user_row->mail;
     $user['created'] = $user_row->created;
     $user['access'] = $user_row->access;
     // Set the init value as the old world uid.
     $user['init'] = $user_row->init;
     $user['status'] = $user_row->status;
     $account = user_save('', $user);
  }
  $edit = [];
  // Some users only have mobile as login method.
  $mobile_result = db_query("SELECT  m.field_user_mobile_value
                             FROM {$mobile_data} m
                             INNER JOIN {$profile_id} p on m.entity_id = p.pid
                             WHERE p.uid = $user_row->uid")->fetchField();
  if ($mobile_result) {
    $edit['field_mobile'] = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $mobile_result,
        ],
      ],
    ];
  }

  $birthday_result = db_query("SELECT  b.field_user_birthday_value
                               FROM {$birthday_data} b
                               INNER JOIN {$profile_id} p on b.entity_id = p.pid
                               WHERE p.uid = $user_row->uid")->fetchField();

  if ($birthday_result) {
    $edit['field_birthdate'] = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $birthday_result,
        ],
      ],
    ];
  }

  // Save account with extra data.
  $account = user_save($account, $edit);
  variable_set('last_user_saved', $account->uid);

  // Are any of these people under 13?
  dosomething_user_is_under_thirteen($account);

}
