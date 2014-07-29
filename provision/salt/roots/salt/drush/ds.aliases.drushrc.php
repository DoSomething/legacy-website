<?php

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
  foreach (array('prod', 'qa') as $environment) {
    $aliases["{$country . $environment}"] = array(
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
}
