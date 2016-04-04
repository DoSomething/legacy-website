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

// Use local Solr instance.
putenv('DS_FINDER_URL=http://127.0.0.1:8983');
$conf['apachesolr_environments']['solr']['url'] = 'http://127.0.0.1:8983/solr/collection1';
