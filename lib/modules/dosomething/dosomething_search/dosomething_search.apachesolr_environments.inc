<?php
/**
 * @file
 * dosomething_search.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function dosomething_search_apachesolr_environments() {
  $export = array();

  $host = variable_get('apachesolr_host', '192.168.1.169');
  $port = variable_get('apachesolr_port', '8080');
  $path = variable_get('apachesolr_path', 'solr/collection1');

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'Solr Server';
  $environment->url = "http://{$host}:{$port}/{$path}";
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_direct_commit' => 0,
    'apachesolr_index_updated' => 1392910246,
    'apachesolr_last_optimize' => 1392910246,
    'apachesolr_read_only' => '0',
    'apachesolr_soft_commit' => 0,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'fact_page',
      1 => 'static_content',
      2 => 'campaign',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
