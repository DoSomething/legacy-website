<?php

/**
 * Drupal VM drush aliases.
 *
 * @see example.aliases.drushrc.php.
 */

$aliases['local'] = array(
  'uri' => 'dev.dosomething.org',
  'root' => '/var/www/dev.dosomething.org/html',
);

$aliases['staging'] = array(
  'uri' => 'staging.dosomething.org',
  'root' => '/var/www/staging.beta.dosomething.org/current/html',
  'remote-host' => 'staging.beta.dosomething.org',
  'remote-user' => 'dosomething',
);