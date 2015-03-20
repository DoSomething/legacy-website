<?php

  $plugin = array(
    'label' => t('Reportback Items'),
    'description' => t('Export Reportback Item entity.'),
    'resource' => 'reportback_items',
    'class' => 'DoSomethingReportbackItemsResource',
    'entity_type' => 'reportback_file',
    'authentication_types' => TRUE,
    'authentication_optional' => TRUE,
  );
