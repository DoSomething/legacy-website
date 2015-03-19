<?php

  $plugin = array(
    'label' => t('Terms'),
    'description' => t('Export Taxonomy term entity.'),
    'resource' => 'terms',
    'class' => 'DoSomethingTermsResource',
    'entity_type' => 'taxonomy_term',
//    'bundle' => 'campaign',
    'authentication_types' => TRUE,
    'authentication_optional' => TRUE,
  );
