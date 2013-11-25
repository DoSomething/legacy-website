<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Mobile Commons Ordered Pathing'),
    'description' => t('Users are sent to Mobile Commons opt-in paths in the specified order.'),
    'handler' => array(
      'class' => 'ConductorActivityMobileCommonsOrderedPath',
    ),
  );
}
