<?php
/**
 * @file
 * dosomething_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'l10n_update_import_mode';
  $strongarm->value = '2';
  $export['l10n_update_import_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_file_pattern';
  $strongarm->value = '';
  $export['pathauto_file_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = '';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_clickjacking';
  $strongarm->value = array(
    'x_frame' => '3',
    'x_frame_allow_from' => 'http://optimizely.com',
    'js_css_noscript' => 0,
    'noscript_message' => 'Sorry, you need to enable JavaScript to visit this website.',
  );
  $export['seckit_clickjacking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_xss';
  $strongarm->value = array(
    'csp' => array(
      'checkbox' => 0,
      'report-only' => 0,
      'default-src' => '\'self\' *.dosomething.org',
      'script-src' => '\'self\' \'unsafe-inline\' \'unsafe-eval\' *.dosomething.org *.google-analytics.com *.optimizely.com bam.nr-data.net js-agent.newrelic.com *.youtube.com *.akamaihd.net *.googleapis.com',
      'object-src' => '\'self\' *.dosomething.org *.akamaihd.net',
      'style-src' => '\'self\' \'unsafe-inline\' *.dosomething.org *.googleapis.com',
      'img-src' => '\'self\' \'unsafe-inline\' *.dosomething.org *.google-analytics.com bam.nr-data.net *.akamaihd.net *.googleapis.com data:',
      'media-src' => '\'self\' *.dosomething.org *.gstatic.com',
      'frame-src' => '\'self\' *.dosomething.org *.youtube.com *.akamaihd.net',
      'font-src' => '\'self\' *.dosomething.org *.googleapis.com *.gstatic.com',
      'connect-src' => '\'self\' dsrealtimefeed.herokuapp.com *.optimizely.com bam.nr-data.net *.googleapis.com',
      'report-uri' => 'admin/config/system/seckit/csp-report',
      'policy-uri' => '',
    ),
    'x_xss' => array(
      'select' => '0',
    ),
    'x_content_type' => array(
      'checkbox' => 1,
    ),
  );
  $export['seckit_xss'] = $strongarm;

  return $export;
}
