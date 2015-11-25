<?php

$countries = [
  'botswana',
  'canada',
  'congo',
  'ghana',
  'kenya',
  'indonesia',
  'nigeria',
  'training',
  'uk',
];

$sites = [];
foreach ($countries as $country) {
  $sites["8888.dev.{$country}.dosomething.org"] = $country;
}
