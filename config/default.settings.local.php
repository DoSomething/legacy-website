<?php
/**
 * @file
 * Drupal instance-specific configuration file. This is included at the end of
 * the distributed settings.php, so use this to set everything related to
 * your local instance.
 *
 * Example settings below. See the original settings.php for full
 * documentation.
 *
 * TO USE: Copy to html/sites/default/settings.local.php and edit. Your local
 * copy will be ignored by Git.
 */

// Database settings.
$databases = array(
  'default' =>
    array(
      'default' =>
        array(
          'database' => 'dosomething',
          'username' => 'root',
          'password' => '',
          'host'     => 'localhost',
          'port'     => '',
          'driver'   => 'mysql',
          'prefix'   => '',
        ),
    ),
);

// Salt for one-time login links and cancel links, form tokens, etc.
$drupal_hash_salt = '3i_SZ1VTl_8FBxXeZhTEvf6LkeVNypM0EV90tNuHs5k';

// Base URL
$base_url = getenv('DS_BASE_URL') ?: 'http://dev.dosomething.org:8888';  // NO trailing slash!

// Secure Pages integration.
$conf['https'] = TRUE;

// Add Varnish as the page cache handler.
$conf['varnish_version'] = '3';
$conf['cache_backends'] = array('profiles/dosomething/modules/contrib/varnish/varnish.cache.inc');
$conf['cache_class_cache_page'] = 'VarnishCache';

// This is managed from salt://varnishd/secret
$conf['varnish_control_key'] = '00c9203c65874ca5b4c359e19f00bf56';

// Drupal 7 does not cache pages when we invoke hooks during bootstrap.
// This needs to be disabled.
$conf['page_cache_invoke_hooks'] = FALSE;

// These settings point to the solr instance on staging.
$conf['apachesolr_host'] = getenv('DS_APACHESOLR_HOST') ?: 'solr';
$conf['apachesolr_port'] = getenv('DS_APACHESOLR_PORT') ?: '8080';

$conf_path = explode('/', conf_path());
$solr_path = $conf_path[1] == 'default' ? 'collection1' : $conf_path[1];
$conf['apachesolr_path'] = "solr/{$solr_path}";

// This is different from the apachesolr host because it's on the client side
$conf['dosomething_search_finder_url'] = (getenv('DS_FINDER_URL') ?: 'http://solr.dev.dosomething.org') . ":{$conf['apachesolr_port']}/solr/";

$conf['dosomething_search_finder_collection'] = $solr_path;

#$conf['apachesolr_read_only'] = 1;
