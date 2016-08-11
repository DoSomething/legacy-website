<?php
/*
 * Sanitize mobile numbers on user accounts from ages ago.
 *
 *
 *
 * drush --script-path=../scripts php-script sanitize-mobile-numbers.php
 *
 */

$wild_typers = db_query("SELECT entity_id as uid, field_mobile_value as mobile
                        FROM field_data_field_mobile
                        WHERE field_mobile_value NOT REGEXP '^[0-9]+$';");


foreach($wild_typers as $wilder) {
  if ($wilder->mobile) {
    $fresh_and_clean_digits = dosomething_user_clean_mobile_number($wilder->mobile);
    if ($fresh_and_clean_digits) {
      $user = user_load($wilder->uid);
      $edit = ['field_mobile' => [ LANGUAGE_NONE => [ 0 => [ 'value' => $fresh_and_clean_digits ] ] ] ];
      user_save($user, $edit);
      print "Updated user " . $wilder->uid . "\n";
    }
    else {
      print "something terrible with " . $wilder->uid . "\n";
    }
  }
}

print "done";
