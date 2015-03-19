<?php

  $plugin = array(
    'label' => t('Signups'),
    'description' => t('Export Signup entity.'),
    'resource' => 'signups',
    'class' => 'DoSomethingSignupsResource',
    'entity_type' => 'signup',
    'authentication_types' => TRUE,
    'authentication_optional' => TRUE,
  );
