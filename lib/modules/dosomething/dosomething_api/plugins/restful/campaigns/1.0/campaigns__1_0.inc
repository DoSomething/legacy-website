<?php

  $plugin = array(
    'label' => t('Campaigns'),
    'description' => t('Export the "Campaign" entity.'),
    'resource' => 'campaigns',
    'class' => 'DoSomethingCampaignsResource',
    'entity_type' => 'node',
    'bundle' => 'campaign',
    'authentication_types' => TRUE,
    'authentication_optional' => TRUE,
  );
