<?php

  $plugin = array(
    'label' => t('Files'),
    'description' => t('Export the "File" entity.'),
    'resource' => 'files',
    'class' => 'DoSomethingFilesResource',
    'entity_type' => 'file',
    // Could do neat things with video, images, and different file bundles.
    // 'bundle' => '',
    'authentication_types' => TRUE,
    'authentication_optional' => TRUE,
  );
