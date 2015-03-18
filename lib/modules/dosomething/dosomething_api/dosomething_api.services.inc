<?php
/**
 * @file
 * dosomething_api.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function dosomething_api_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'drupalapi';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/v1';
  $endpoint->authentication = array(
    'services' => 'services',
  );
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
      'application/x-www-form-urlencoded' => TRUE,
      'application/xml' => TRUE,
      'application/vnd.php.serialized' => FALSE,
      'application/x-yaml' => FALSE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'user' => array(
      'alias' => 'auth',
      'actions' => array(
        'login' => array(
          'enabled' => '1',
        ),
        'logout' => array(
          'enabled' => '1',
        ),
        'token' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'campaigns' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'relationships' => array(
        'gallery' => array(
          'enabled' => '1',
        ),
      ),
      'targeted_actions' => array(
        'signup' => array(
          'enabled' => '1',
        ),
        'reportback' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'node' => array(
      'alias' => 'content',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'reportback_files' => array(
      'targeted_actions' => array(
        'review' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'signups' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'system' => array(
      'actions' => array(
        'connect' => array(
          'enabled' => '1',
        ),
        'set_variable' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'terms' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'relationships' => array(
        'inbox' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'users' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'get_member_count' => array(
          'enabled' => '1',
        ),
      ),
      'relationships' => array(
        'activity' => array(
          'enabled' => '1',
        ),
      ),
      'targeted_actions' => array(
        'password_reset_url' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['drupalapi'] = $endpoint;

  return $export;
}
