<?php
/**
 * @file
 * dosomething_global.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_global_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dosomething_global_language_map';
  $strongarm->value = array(
    'es-mx' => array(
      'display_name' => 'Spanish, Mexico',
      'default_roles' => array('mexico admin'),
      'country' => 'MX',
    ),
    'pt-br' => array(
      'display_name' => 'Portuguese, Brazil',
      'default_roles' => array('brazil admin'),
      'country' => 'BR',
    ),
    'en' => array(
      'display_name' => 'English',
      'default_roles' => array(),
      'country' => 'US'
    ),
    'en-global' => array(
      'display_name' => 'English, Global',
      'default_roles' => array(),
    ),
  );
  $export['dosomething_global_language_map'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language';
  $strongarm->value = array(
    'locale-session' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_session',
        'switcher' => 'locale_language_switcher_session',
        'url_rewrite' => 'locale_language_url_rewrite_session',
      ),
      'file' => 'includes/locale.inc',
    ),
    'language-default' => array(
      'callbacks' => array(
        'language' => 'language_from_default',
      ),
    ),
  );
  $export['language_negotiation_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language_content';
  $strongarm->value = array(
    'locale-session' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_session',
        'switcher' => 'locale_language_switcher_session',
        'url_rewrite' => 'locale_language_url_rewrite_session',
      ),
      'file' => 'includes/locale.inc',
    ),
    'locale-interface' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_interface',
      ),
      'file' => 'includes/locale.inc',
    ),
    'language-default' => array(
      'callbacks' => array(
        'language' => 'language_from_default',
      ),
    ),
  );
  $export['language_negotiation_language_content'] = $strongarm;

  return $export;
}
