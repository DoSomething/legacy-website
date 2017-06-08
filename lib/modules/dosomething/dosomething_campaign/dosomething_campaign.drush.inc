<?php

/**
 * Implementation of hook_drush_command().
 */
function dosomething_campaign_drush_command() {
  $items = [];

  // Name of the drush command.
  $items['campaign-create'] = [
    'description' => 'Creates a campaign node from given JSON file.',
    'arguments' => array(
      'filename' => 'Name of the JSON file to read.',
    ),
    'required-arguments' => TRUE,
    'callback' => 'dosomething_campaign_drush_campaign_create',
    'examples' => array(
      'drush campaign-create ../tests/campaign/campaign.json' => 'Creates a campaign node from contents of campaign.json.',
    ),
  ];

  // Name of the drush command.
  $items['affiliate-opt-ins-age-backfill'] = [
    'description' => 'Backfills the affiliate optins collected user data with their age.',
    'callback' => 'dosomething_campaign_drush_affiliate_opt_ins_age_backfill',
    'arguments' => [
      'campaign_id' => 'The ID for the specified campaign.',
      'campaign_run_id' => 'The ID for the specified campaign run.',
    ],
    'examples' => [
      'drush affiliate-optins-age-backfill' => 'Backfills age data for opted-in users on specified campaign.',
    ],
  ];

  return $items;
}

/**
 * Callback for campaign-create command.
 */
function dosomething_campaign_drush_campaign_create($filename) {
  if ($string = file_get_contents($filename)) {
    $node = dosomething_campaign_create_node_from_json($string);
    $message = "Created node nid " . $node->nid . ".";
    return $message;
  }
  else {
    return "Invalid filename.";
  }
}

/**
 * Callback for affiliate-optins-age-backfill command.
 */
function dosomething_campaign_drush_affiliate_opt_ins_age_backfill() {
  $results = db_select('dosomething_campaign_affiliate_opt_ins', 'optins')
      ->fields('optins', ['northstar_id', 'age'])
      ->execute()
      ->fetchAll();

  if ($results) {
    foreach($results as $result) {
      if (is_null($result->age)) {
        $northstar_user = dosomething_northstar_get_user($result->northstar_id);
        $northstar_user_age = dosomething_user_get_age($northstar_user->birthdate)->y;

        db_update('dosomething_campaign_affiliate_opt_ins')
          ->fields(['age' => $northstar_user_age])
          ->condition('northstar_id', $northstar_user->id, '=')
          ->execute();
      }
    }

    drupal_set_message(dt('Completed executing affiliate optins age backfill.'), 'success');
  } else {
    drupal_set_message(dt('No affiliate optin data found.'), 'error');
  }
}


