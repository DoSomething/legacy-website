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
$workflow->name = 'dosomething_sms_start_campaign_transition';
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

/**
 * Report back for Comeback Clothes 2014.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'dosomething_sms_comeback_clothes_reportback';
$workflow->title = 'Comeback Clothes 2014 Report Back';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_quantity');
$activity->noMmsResponse = 165425;

$activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
$activity->name = 'ask_quantity';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_why_participated');
$activity->optInPathId = 165421;

$activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
$activity->name = 'ask_why_participated';
$activity->inputs = array('ask_quantity');
$activity->outputs = array('strip_signature');
$activity->optInPathId = 165423;

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_why_participated');
$activity->outputs = array('submit_reportback');

$activity = $workflow->newActivity('dosomething_sms_submit_reportback');
$activity->name = 'submit_reportback';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->nid = 362; // Comeback Clothes node id
$activity->mmsContext = 'ask_picture:mms';
$activity->propertyToContextMap = array(
  'quantity' => 'ask_quantity:message',
  'why_participated' => 'ask_why_participated:message',
);
$activity->optInPathId = 165405;
$activity->optOutCampaignId = 124765;
$activity->mobileCommonsCompletedCampaignId = 124797;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_reportback');

$workflows[$workflow->name] = $workflow;
