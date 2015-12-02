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
      'country_name' => 'Mexico',
    ),
    'pt-br' => array(
      'display_name' => 'Portuguese, Brazil',
      'default_roles' => array(
        0 => 'brazil admin',
      ),
      'country' => 'BR',
      'country_name' => 'Brazil',
    ),
    'en' => array(
      'display_name' => 'English',
      'default_roles' => array(),
      'country' => 'US',
      'country_name' => 'United States',
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
      'country_name' => 'United Kingdom',
    ),
    'en-ca' => array(
      'display_name' => 'English, Canada',
      'default_roles' => array(
        0 => 'canada admin',
      ),
      'country' => 'CA',
      'country_name' => 'Canada',
    ),
    'fr-ca' => array(
      'display_name' => 'French, Canada',
      'default_roles' => array(
        0 => 'canada admin',
      ),
      'country' => 'CA',
      'country_name' => 'Canada',
    ),
  );
  $export['dosomething_global_language_map'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_entity_types';
  $strongarm->value = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
    'field_collection_item' => 0,
    'file' => 0,
    'user' => 0,
  );
  $export['entity_translation_entity_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_default';
  $strongarm->value = (object) array(
    'language' => 'en-global',
    'name' => 'English, Global',
    'native' => 'English, Global',
    'direction' => '0',
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => '',
    'weight' => 0,
    'javascript' => '',
  );
  $export['language_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language';
  $strongarm->value = array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'locale-user' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_user',
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
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
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
  $strongarm->name = 'language_negotiation_language_url';
  $strongarm->value = array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'locale-url-fallback' => array(
      'callbacks' => array(
        'language' => 'locale_language_url_fallback',
      ),
      'file' => 'includes/locale.inc',
    ),
  );
  $export['language_negotiation_language_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_field_language_fallback';
  $strongarm->value = 0;
  $export['locale_field_language_fallback'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_language_providers_weight_language';
  $strongarm->value = array(
    'locale-user' => '-9',
    'locale-url' => '-10',
    'locale-session' => '-8',
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
    'locale-user' => '-9',
    'locale-session' => '-8',
    'locale-browser' => '-7',
    'locale-interface' => '-6',
    'language-default' => '-5',
  );
  $export['locale_language_providers_weight_language_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_campaign_en-global_pattern';
  $strongarm->value = '';
  $export['pathauto_node_campaign_en-global_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_campaign_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_campaign_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_campaign_es-mx_pattern';
  $strongarm->value = 'voluntario/[node:title]';
  $export['pathauto_node_campaign_es-mx_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_campaign_pt-br_pattern';
  $strongarm->value = 'voluntario/[node:title]';
  $export['pathauto_node_campaign_pt-br_pattern'] = $strongarm;

  return $export;
}
