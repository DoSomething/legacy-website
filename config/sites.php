<?php

$countries = array(
  'indonesia',
);

$sites = array();
foreach ($countries as $country) {
  $sites["8888.dev.{$country}.dosomething.org"] = $country;
}
