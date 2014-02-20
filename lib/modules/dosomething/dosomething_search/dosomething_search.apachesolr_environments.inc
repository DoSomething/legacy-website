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

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://192.168.1.21:8080/solr/collection1';
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
      0 => 'fact',
      1 => 'fact_page',
      2 => 'static_content',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
