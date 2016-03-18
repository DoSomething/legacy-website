<?php

/**
 * Implements hook_cron()
 */
 function dosomething_gladiator_cron() {
   $client = _dosomething_gladiator_build_http_client();

   $options = [
     'method' => 'GET',
     'headers' => $client['headers'],
   ];

   $response = drupal_http_request($client['base_url'] . '/contests', $options);

   if ($response->code != 200 ) {
     return;
   }

   $contests = json_decode($response->data)->data;

   foreach ($contests as $contest) {
     $nid = $contest->campaign->id;
     // For some reason using the boolean value doesnt work in the fields array, have to convert to int.
     $signups_open = $contest->waiting_room->open ? 1 : 0;

     db_update('dosomething_signup_data_form')
       ->fields([
         'required' => $signups_open,
         'competition_signup' => $signups_open,
       ])
       ->condition('nid', $nid)
       ->execute();
   }
 }
