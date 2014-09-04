<?php

$aliases["default"] = array (
  'root' => '/var/www/vagrant/html',
  'uri' => true,
  'path-aliases' =>
  array (
    '%drush' => '/opt/drush',
    '%site' => 'sites/1/',
  ),
  '%dump-dir' => '/tmp',
  'databases' =>
  array (
    'default' =>
    array (
      'default' =>
      array (
        'database' => 'dosomething',
        'username' => 'root',
        'password' => '',
        'host' => 'localhost',
        'port' => '',
        'driver' => 'mysql',
        'prefix' => '',
      ),
    ),
  ),
  '#file' => '/home/vagrant/.drush/ds.aliases.drushrc.php',
  '#name' => 'default',
);

$aliases['staging'] = array(
 'uri' => 'staging.beta.dosomething.org',
 'root' => '/var/www/beta.dosomething.org/current/html',
 'remote-host' => 'staging.beta.dosomething.org',
 'remote-user' => 'dosomething',
 'path-aliases' => array(
   '%files' => '/var/www/beta.dosomething.org/shared/files',
 ),
);

$countries = array(
  'botswana',
  'canada',
  'congo',
  'ghana',
  'kenya',
  'indonesia',
  'nigeria',
  'training',
  'uk',
);

foreach ($countries as $country) {
  foreach (array('prod', 'staging') as $environment) {
    $aliases["{$country}.{$environment}"] = array(
     'root' => '/var/www/international.dosomething.org/current/html',
     'remote-host' => 'international.' . $environment,
     'remote-user' => 'dosomething',
     'uri' => $country,
     '%dump-dir' => '/tmp',
      'path-aliases' => array(
       '%files' =>  "/var/www/international.dosomething.org/current/html/sites/{$country}/files",
     ),
    );
  }
  $aliases["{$country}.dev"] = array (
    'root' => '/var/www/vagrant/html',
    'uri' => "http://dev.{$country}.dosomething.org",
    'path-aliases' =>
      array (
        '%files' => "/var/www/vagrant/html/sites/{$country}/files",
      ),
    '%dump-dir' => '/tmp',
    'databases' =>
      array (
        'default' =>
        array (
          'default' =>
          array (
            'database' => "dosomething_{$country}",
            'username' => 'root',
            'password' => '',
            'host' => 'localhost',
            'port' => '',
            'driver' => 'mysql',
            'prefix' => '',
          ),
        ),
      ),
  );
}
