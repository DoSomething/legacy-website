<?php
/**
 * @file
 * dosomething_settings.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function dosomething_settings_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'drupalapi';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/v1';
  $endpoint->authentication = array();
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'xml' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'yaml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/xml' => TRUE,
      'application/vnd.php.serialized' => FALSE,
      'application/x-www-form-urlencoded' => FALSE,
      'application/x-yaml' => FALSE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'node' => array(
      'alias' => 'content',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['drupalapi'] = $endpoint;

  return $export;
}
