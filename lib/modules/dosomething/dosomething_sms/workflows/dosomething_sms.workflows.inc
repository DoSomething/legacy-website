<?php

/**
 * @file
 * ConductorWorkflow definitions for DoSomething SMS endpoints.
 */

/**
 * Gateway from transactional Mobile Commons campaign to starting the actual
 * campaign SMS experience.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_start_campaign_transition';
$workflow->title = 'Start Campaign Transition';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('start_campaign');

$activity = $workflow->newActivity('start_campaign');
$activity->name = 'start_campaign';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->routes = array(
  '10851' => array(                // mData id with the campaign start keyword.
    'out_campaign_id' => '124251', // Starting campaign id to opt-out of.
    'opt_in_path_id' => '164793',  // In-progress campaign opt-in path id to opt-in to.
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('start_campaign');

$workflows[$workflow->name] = $workflow;
