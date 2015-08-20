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
    'prefix' => 'es-mx',
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
    'prefix' => 'pt-br',
    'weight' => 0,
  );
  return $languages;
}
