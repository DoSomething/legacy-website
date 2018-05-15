<?php

$countries = [
  'indonesia',
];

$sites = [];
foreach ($countries as $country) {
  $sites["8888.dev.{$country}.dosomething.org"] = $country;
}
