<?php
/**
 * @file
 * dosomething_northstar.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_northstar_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openid_connect_clients_enabled';
  $strongarm->value = array(
    'northstar' => 'northstar',
  );
  $export['openid_connect_clients_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openid_connect_userinfo_mapping_claims';
  $strongarm->value = array(
    0 => 'birthdate',
    1 => 'given_name',
    2 => 'phone_number',
    3 => 'address',
    4 => 'family_name',
    5 => 'zoneinfo',
  );
  $export['openid_connect_userinfo_mapping_claims'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openid_connect_userinfo_mapping_property_field_address';
  $strongarm->value = 'address';
  $export['openid_connect_userinfo_mapping_property_field_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openid_connect_userinfo_mapping_property_field_birthdate';
  $strongarm->value = 'birthdate';
  $export['openid_connect_userinfo_mapping_property_field_birthdate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openid_connect_userinfo_mapping_property_field_first_name';
  $strongarm->value = 'given_name';
  $export['openid_connect_userinfo_mapping_property_field_first_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openid_connect_userinfo_mapping_property_field_last_name';
  $strongarm->value = 'family_name';
  $export['openid_connect_userinfo_mapping_property_field_last_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openid_connect_userinfo_mapping_property_field_mobile';
  $strongarm->value = 'phone_number';
  $export['openid_connect_userinfo_mapping_property_field_mobile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openid_connect_userinfo_mapping_property_timezone';
  $strongarm->value = 'zoneinfo';
  $export['openid_connect_userinfo_mapping_property_timezone'] = $strongarm;

  return $export;
}
