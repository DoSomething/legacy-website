<?php

/**
 * Implements hook_cron()
 */
 function dosomething_gladiator_cron() {
   $client = _dosomething_gladiator_build_http_client();

   $options = [
     'method' => 'POST',
     'headers' => $client['headers'],
   ];

   $response = drupal_http_request($client['base_url'] . '/contests', $options);
   $contests = json_decode($response->data);
 }
