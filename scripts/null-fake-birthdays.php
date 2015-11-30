<?php
/*
 * Script to null out birthdays that are set to 1969-12-31 00:00:00.
 *
 * drush --script-path=../scripts php-script null-fake-birthdays.php
 *
 */

echo "Updating filler birthdays \n";

db_update('field_data_field_birthdate')
  ->fields([
    'field_birthdate_value' => NULL
  ])
  ->condition('field_birthdate_value', '1969-12-31 00:00:00')
  ->execute();

echo "Finished \n";
