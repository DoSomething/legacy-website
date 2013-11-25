<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Mobile Commons Opt-Out'),
    'description' => t('Opt the user out of the specified Mobile Commons campaign(s) messages.'),
    'handler' => array(
      'class' => 'ConductorActivityMobileCommonsOptOut',
    ),
  );
}
