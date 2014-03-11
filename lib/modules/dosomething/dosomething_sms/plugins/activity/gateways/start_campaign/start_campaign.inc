<?php

$plugin = array(
  'title' => t('Start Campaign Gateway'),
  'description' => t('Transitions user from transactional Mobile Commons campaign to the actual campaign.'),
  'handler' => array(
    'class' => 'ConductorActivityStartCampaignGateway',
  ),
);
