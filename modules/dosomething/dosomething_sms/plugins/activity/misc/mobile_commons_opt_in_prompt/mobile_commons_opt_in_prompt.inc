<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Mobile Commons Opt-In Prompt'),
    'description' => t('Opt the user into a specified Mobile Commons opt-in path, and suspend the workflow until a response is received.'),
    'handler' => array(
      'class' => 'ConductorActivityMobileCommonsOptInPrompt',
    ),
  );
}
