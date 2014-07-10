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

$aliases['international.prod'] = array(
 'uri' => 'default',
 'root' => '/var/www/international.dosomething.org/current/html',
 'remote-host' => '72.32.106.161',
 'remote-user' => 'dosomething',
 'path-aliases' => array(
   '%files' => '/var/www/international.dosomething.org/shared/files',
 ),
);

$countries = array(
  'botswana',
  'canada',
  'congo',
  'ghana'
  'kenya'
  'indonesia',
  'nigeria',
  'training',
  'uk',
);

foreach ($countries as $country) {
  $aliases[$country . '.prod'] = array(
   'parent' => '@international.prod',
   'uri' => $country,
   '%dump-dir' => '/tmp',
  );
}
