<?php

/**
 * @file
 * ConductorWorkflow definitions for DoSomething SMS endpoints.
 */

require_once drupal_get_path('module', 'dosomething_sms') . '/dosomething_sms_game_constants.inc';

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
  '10043' => array(                // mData id with the campaign start keyword.
    'out_campaign_id' => '124817', // Starting campaign id to opt-out of.
    'opt_in_path_id' => '165505',  // In-progress campaign opt-in path id to opt-in to.
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('start_campaign');

$workflows[$workflow->name] = $workflow;

/**
 * SMS game/tips routing of Mobile Commons opt-in paths.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'dosomething_sms_game_paths';
$workflow->title = 'SMS Game Paths';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('game_paths');

$activity = $workflow->newActivity('dosomething_sms_game_mobilecommons_paths');
$activity->name = 'game_paths';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->paths = array(
  '10753' => array(
    'optInPaths' => array(165443, 165445, 165447),
    'gameId' => DoSomethingSmsGameConstants::COMEBACKCLOTHES_KNOW,
  ),
  '10763' => array(
    'optInPaths' => array(165449, 165451, 165453, 165455, 165457),
    'gameId' => DoSomethingSmsGameConstants::COMEBACKCLOTHES_PLAN,
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('game_paths');

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
$activity->outputs = array('ask_dropoff');
$activity->optInPathId = 165421;

$activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
$activity->name = 'ask_dropoff';
$activity->inputs = array('ask_quantity');
$activity->outputs = array('ask_why_participated');
$activity->optInPathId = 166261;

$activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
$activity->name = 'ask_why_participated';
$activity->inputs = array('ask_dropoff');
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
  'dropoff_hm' => array(
    'conversion_type' => 'yesno',
    'context' => 'ask_dropoff:message',
  ),
);
$activity->optInPathId = 165405;
$activity->optOutCampaignId = 124765;
$activity->mobileCommonsCompletedCampaignId = 124797;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_reportback');

$workflows[$workflow->name] = $workflow;

/**
 * Report back for Thumb Wars 2014.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'dosomething_sms_thumbwars_reportback';
$workflow->title = 'Thumb Wars 2014 Report Back';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_quantity');
$activity->noMmsResponse = 167301;

$activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
$activity->name = 'ask_quantity';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_why_participated');
$activity->optInPathId = 167303;

$activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
$activity->name = 'ask_why_participated';
$activity->inputs = array('ask_quantity');
$activity->outputs = array('strip_signature');
$activity->optInPathId = 167305;

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_why_participated');
$activity->outputs = array('submit_reportback');

$activity = $workflow->newActivity('dosomething_sms_submit_reportback');
$activity->name = 'submit_reportback';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->nid = 1508; // Thumb Wars node id
$activity->mmsContext = 'ask_picture:mms';
$activity->propertyToContextMap = array(
  'quantity' => 'ask_quantity:message',
  'why_participated' => 'ask_why_participated:message',
);
$activity->optInPathId = 167295;
$activity->optOutCampaignId = 126069;
$activity->mobileCommonsCompletedCampaignId = 126071;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_reportback');

$workflows[$workflow->name] = $workflow;

/**
 * Report back for Fifth Harmony #ImABoss 2014.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'dosomething_sms_imaboss_reportback';
$workflow->title = 'Fifth Harmony #ImABoss 2014 Report Back';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_quantity');
$activity->noMmsResponse = 168597;

$activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
$activity->name = 'ask_quantity';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_why_participated');
$activity->optInPathId = 168599;

$activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
$activity->name = 'ask_why_participated';
$activity->inputs = array('ask_quantity');
$activity->outputs = array('strip_signature');
$activity->optInPathId = 168601;

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_why_participated');
$activity->outputs = array('submit_reportback');

$activity = $workflow->newActivity('dosomething_sms_submit_reportback');
$activity->name = 'submit_reportback';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->nid = 2401; // #ImABoss node id
$activity->mmsContext = 'ask_picture:mms';
$activity->propertyToContextMap = array(
  'quantity' => 'ask_quantity:message',
  'why_participated' => 'ask_why_participated:message',
);
$activity->optInPathId = 168589;
$activity->optOutCampaignId = 126961;
$activity->mobileCommonsCompletedCampaignId = 126963;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_reportback');

$workflows[$workflow->name] = $workflow;
