<?php

$plugin = array(
  'label' => t('Reportback Gallery'),
  'resource' => 'gallery',
  'name' => 'gallery__1_0',
  'data_provider_options' => array(
    'table_name' => 'dosomething_reportback_file',
    'id_column' => 'fid',
  ),
  'description' => t('Expose Reportback Items with relevant Campaign data.'),
  'class' => 'DoSomethingGalleryResource',
);
