<?php
/*
 * Script to correct languages on users.
 *
 * If we have the address for a user, and it's the US, set the lang to english.
 * Or if the user comes from niche, or a mobile app, set the lang to english as well.
 *
 * drush --script-path=../scripts php-script correct-language-for-users.php
 *
 */

$global_peeps = db_query("SELECT u.uid, s.field_user_registration_source_value as source, a.field_address_country as country
                          FROM users u
                          LEFT JOIN field_data_field_user_registration_source s on s.entity_id = u.uid
                          LEFT JOIN field_data_field_address a on a.entity_id = u.uid
                          WHERE u.language = 'en-global' or u.language = '';");

$possible_sources = ['niche', 'Nice', 'niche-import-service', 'letsdothis_ios', 'mobileapp_android'];

foreach($global_peeps as $peep) {
  if ($peep->country == 'US' || in_array($peep->source, $possible_sources)) {
    $user = user_load($peep->uid);
    $user->language = 'en';
    print 'Saving user ' . $user->uid . "\n";
    user_save($user);
  }
}
print 'done';
