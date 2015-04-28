<?php

  $plugin = array(
    'label' => t('Assets'),
    'description' => t('Export the "Image" entity.'),
    'resource' => 'assets',
    'class' => 'DoSomethingAssetsResource',
    'entity_type' => 'node',
    'bundle' => 'image',
    'authentication_types' => TRUE,
    'authentication_optional' => TRUE,
  );
