<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Mobile Commons Opt-In'),
    'description' => t('Opt the user into a specified Mobile Commons opt-in path.'),
    'handler' => array(
      'class' => 'ConductorActivityMobileCommonsOptIn',
    ),
  );
}
