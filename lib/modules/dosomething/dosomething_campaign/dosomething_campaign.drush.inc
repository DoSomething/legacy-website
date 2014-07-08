<?php

/**
 * Implementation of hook_drush_command().
 */
function dosomething_campaign_drush_command() {
  $items = array();
  // Name of the drush command.
  $items['create-campaign'] = array(
    'description' => 'Creates a campaign node',
    'callback' => 'dosomething_campaign_drush_create_campaign',
  );
  return $items;
}

/**
 * Callback for create-campaign command.
 */
function dosomething_campaign_drush_create_campaign() {
  return "Hey there";
}
