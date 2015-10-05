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
      'default_roles' => array(
        0 => 'mexico admin',
      ),
      'country' => 'MX',
    ),
    'pt-br' => array(
      'display_name' => 'Portuguese, Brazil',
      'default_roles' => array(
        0 => 'brazil admin',
      ),
      'country' => 'BR',
    ),
    'en' => array(
      'display_name' => 'English',
      'default_roles' => array(),
      'country' => 'US',
    ),
    'en-global' => array(
      'display_name' => 'English, Global',
      'default_roles' => array(),
    ),
    'en-gb' => array(
      'display_name' => 'English, UK',
      'default_roles' => array(
        0 => 'UK admin',
      ),
      'country' => 'GB',
    ),
    'en-ca' => array(
      'display_name' => 'English, Canada',
      'default_roles' => array(
        0 => 'canada admin',
      ),
      'country' => 'CA',
    ),
    'fr-ca' => array(
      'display_name' => 'French, Canada',
      'default_roles' => array(
        0 => 'canada admin',
      ),
      'country' => 'CA',
    ),
  );
  $export['dosomething_global_language_map'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language';
  $strongarm->value = array(
    'locale-user' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_user',
      ),
      'file' => 'includes/locale.inc',
    ),
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
    'locale-user' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_user',
      ),
      'file' => 'includes/locale.inc',
    ),
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

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_language_providers_weight_language';
  $strongarm->value = array(
    'locale-url' => '-9',
    'locale-session' => '-8',
    'locale-user' => '-10',
    'locale-browser' => '-7',
    'language-default' => '-6',
  );
  $export['locale_language_providers_weight_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_language_providers_weight_language_content';
  $strongarm->value = array(
    'locale-url' => '-10',
    'locale-session' => '-8',
    'locale-user' => '-9',
    'locale-browser' => '-7',
    'locale-interface' => '-6',
    'language-default' => '-5',
  );
  $export['locale_language_providers_weight_language_content'] = $strongarm;

  return $export;
}
