<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Out of Flow Responder'),
    'description' => t('Intended to be hooked up to the end of a conversation flow as a Mobile Commons mData. Parses incoming user messages to give custom responses.'),
    'handler' => array(
      'class' => 'ConductorActivityOutOfFlowResponder',
    ),
  );
}
