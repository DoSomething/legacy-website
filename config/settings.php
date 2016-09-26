<?php

/**
 * Require Composer's class loader.
 */
require_once __DIR__ . '/../lib/autoload.php';

/**
 * Lets do something about globals
 */
define('DS_PROFILE_PATH', 'profiles/dosomething');
define('DS_MODULES_PATH', DS_PROFILE_PATH . '/modules');
define('DS_THEMES_PATH', DS_PROFILE_PATH . 'themes');
define('DS_LIBRARIES_PATH', DS_PROFILE_PATH . '/libraries');

/**
 * Database settings:
 */
$databases['default']['default'] = [
  'database' => getenv('DS_DB_MASTER_NAME') ?: 'dosomething',
  'username' => getenv('DS_DB_MASTER_USER') ?: 'root',
  'password' => getenv('DS_DB_MASTER_PASS') ?: '',
  'host' => getenv('DS_DB_MASTER_HOST') ?: 'localhost',
  'port' => getenv('DS_DB_MASTER_PORT') ?: '3306',
  'driver' => getenv('DS_DB_MASTER_DRIVER') ?: 'mysql',
  'prefix' => getenv('DS_DB_MASTER_PREFIX') ?: '',
];

/**
 * Hosts & urls
 */
$hostname = $_SERVER['HTTP_HOST'] ?: 'dev.dosomething.org';

$protocol = (!empty($_SERVER['HTTPS']) && $_SERVER['HTTPS'] !== 'off' || $_SERVER['SERVER_PORT'] == 443) ? 'https://' : 'http://';

$insecure_port = getenv('DS_INSECURE_PORT') ?: 8888;
$secure_port = getenv('DS_SECURE_PORT') ?: 8889;

// $hostname may already have port included. Check it before you wreck it!
if (!preg_match('/.+:[0-9]+$/', $hostname) && !empty($insecure_port)
    && ($insecure_port != 80)) {

  $base_url = $protocol . $hostname . ':' . $insecure_port;
}
else {
  $base_url = $protocol . $hostname;
}

$conf['https'] = TRUE;

/**
 * Caching
 */
// Add Varnish as the page cache handler.
$conf['varnish_version'] = '3';
$conf['cache_backends'] = ['profiles/dosomething/modules/contrib/varnish/varnish.cache.inc'];
$conf['cache_class_cache_page'] = 'VarnishCache';

// This is managed from salt://varnishd/secret
$conf['varnish_control_key'] = '00c9203c65874ca5b4c359e19f00bf56';

// Drupal 7 does not cache pages when we invoke hooks during bootstrap.
// This needs to be disabled.
$conf['page_cache_invoke_hooks'] = FALSE;

// Setup Redis cache backend using Predis PHP library.
$conf['redis_client_interface'] = 'Predis';

// Register Predis classes autoload.
// @see Redis_Client_Predis::setPredisAutoload().
define('PREDIS_BASE_PATH', DRUPAL_ROOT . '/' . DS_LIBRARIES_PATH . '/predis/lib/');
require_once DS_MODULES_PATH . '/contrib/redis/redis.autoload.inc';
$conf['cache_backends'][] = DS_MODULES_PATH . '/contrib/redis/redis.autoload.inc';

// Redis client settings.
$conf['redis_client_host'] = getenv('DS_REDIS_HOST') ?: '127.0.0.1';
$conf['redis_client_port'] = getenv('DS_REDIS_PORT') ?: '6379';

// Enforce a common cache key.
$conf['cache_prefix'] = 'ds';

// Cache everything in Redis, except the form cache.
$conf['cache_default_class'] = 'Redis_Cache';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

$conf['lock_inc'] = DS_MODULES_PATH . '/contrib/redis/redis.lock.inc';

/**
 * Salt hash:
 */
$drupal_hash_salt = '3i_SZ1VTl_8FBxXeZhTEvf6LkeVNypM0EV90tNuHs5k';

/**
 * PHP Configuration overrides:
 */
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);

/**
 * Fast 404 pages:
 */
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

/**
 * Load environment aware settings override files
 */
$environment = getenv('DS_ENVIRONMENT') ?: 'local';

// Include local settings file if it exists.
if (is_readable('sites/default/settings.' . $environment . '.php')) {
  include_once('sites/default/settings.' . $environment . '.php');
}

$conf['optimizely_id'] = '747623297';

$conf['dosomething_is_affiliate'] = FALSE;

// The 'solr' hostname must be defined in /etc/hosts.
$conf['apachesolr_host'] = getenv('DS_APACHESOLR_HOST') ?: 'solr';
$conf['apachesolr_port'] = getenv('DS_APACHESOLR_PORT') ?: '8080';

$conf_path = explode('/', conf_path());
$solr_path = $conf_path[1] == 'default' ? 'collection1' : $conf_path[1];
$conf['apachesolr_path'] = "solr/{$solr_path}";

// This is different from the apachesolr host because it's on the client side
$conf['dosomething_search_finder_url'] = (getenv('DS_FINDER_URL') ?: '//search.dosomething.org') . '/solr/';

$conf['dosomething_search_finder_collection'] = $solr_path;

/**
 * Setup the global application services access.
 */
require_once __DIR__ . '/../lib/app.php';
