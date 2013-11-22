<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Mobile Commons Timed Pathing'),
    'description' => t('Users are sent to a Mobile Commons opt-in path depending on the date and time'),
    'handler' => array(
      'class' => 'ConductorActivityMobileCommonsTimedPath',
    ),
  );
}
