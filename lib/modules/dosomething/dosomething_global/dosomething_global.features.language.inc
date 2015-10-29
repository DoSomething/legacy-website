<?php
/**
 * @file
 * dosomething_global.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function dosomething_global_locale_default_languages() {
  $languages = array();

  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'us',
    'weight' => 0,
  );
  // Exported language: en-global.
  $languages['en-global'] = array(
    'language' => 'en-global',
    'name' => 'English, Global',
    'native' => 'English, Global',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => '',
    'weight' => 0,
  );
  // Exported language: es-mx.
  $languages['es-mx'] = array(
    'language' => 'es-mx',
    'name' => 'Spanish, Mexico',
    'native' => 'Español Mexicano',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'mx',
    'weight' => 0,
  );
  // Exported language: pt-br.
  $languages['pt-br'] = array(
    'language' => 'pt-br',
    'name' => 'Portuguese, Brazil',
    'native' => 'Português Brasileiro',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'br',
    'weight' => 0,
  );
  return $languages;
}
