<?php

  $plugin = array(
    'label' => t('Reportbacks'),
    'description' => t('Export Reportback entity.'),
    'resource' => 'reportbacks',
    'class' => 'DoSomethingReportbacksResource',
    'entity_type' => 'reportback',
    'authentication_types' => TRUE,
    'authentication_optional' => TRUE,
  );
