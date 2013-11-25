<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Mobile Commons Random Pathing'),
    'description' => t('Users are sent to a random Mobile Commons opt-in path they have yet to be sent to.'),
    'handler' => array(
      'class' => 'ConductorActivityMobileCommonsRandomPath',
    ),
  );
}
