<?php

/**
 * @file
 * ConductorWorkflow definitions for DoSomething SMS endpoints.
 */

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


// Loop through all active SMS Workflows.
foreach (dosomething_sms_get_sms_workflows() as $wf) {

  $workflow = new ConductorWorkflow();
  $workflow->wid = 'new';
  $workflow->name = 'sms_workflow_' . $wf->id;
  $workflow->title = $wf->title;
  $workflow->api_version = '1.0';

  $activity = $workflow->newActivity('start');
  $activity->name = 'start';
  $activity->outputs = array('ask_picture');

  $activity = $workflow->newActivity('mms_prompt');
  $activity->name = 'ask_picture';
  $activity->inputs = array('start');
  $activity->outputs = array('ask_quantity');
  $activity->noMmsResponse = $wf->id_no_mms_response;

  $activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
  $activity->name = 'ask_quantity';
  $activity->inputs = array('ask_picture');
  $activity->outputs = array('ask_why_participated');
  $activity->optInPathId = $wf->id_ask_quantity;

  $activity = $workflow->newActivity('mobilecommons_opt_in_prompt');
  $activity->name = 'ask_why_participated';
  $activity->inputs = array('ask_quantity');
  $activity->outputs = array('strip_signature');
  $activity->optInPathId = $wf->id_ask_why_participated;

  $activity = $workflow->newActivity('sms_strip_signature');
  $activity->name = 'strip_signature';
  $activity->inputs = array('ask_why_participated');
  $activity->outputs = array('submit_reportback');

  $activity = $workflow->newActivity('dosomething_sms_submit_reportback');
  $activity->name = 'submit_reportback';
  $activity->inputs = array('strip_signature');
  $activity->outputs = array('end');
  $activity->nid = $wf->nid;
  $activity->mmsContext = 'ask_picture:mms';
  $activity->propertyToContextMap = array(
    'quantity' => 'ask_quantity:message',
    'why_participated' => 'ask_why_participated:message',
  );
  $activity->optInPathId = $wf->id_submit_reportback;
  $activity->optOutCampaignId = $wf->id_campaign_opt_out;
  $activity->mobileCommonsCompletedCampaignId = $wf->id_campaign_completed;

  $activity = $workflow->newActivity('end');
  $activity->name = 'end';
  $activity->inputs = array('submit_reportback');

  $workflows[$workflow->name] = $workflow;
}
