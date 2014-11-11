<?php

/**
 * @file
 * Provides an option to override address country with affiliate country.
 */

$plugin = array(
  'title' => t('Dosomething Affiliate Country'),
  'format callback' => 'dosomething_user_format_address_country',
  'type' => 'address',
  'weight' => -200,
);

function dosomething_user_format_address_country(&$format, &$address, $context = array()) {
  $address['country'] = dosomething_settings_get_affiliate_country_code();
}
