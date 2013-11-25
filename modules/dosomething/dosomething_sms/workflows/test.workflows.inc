<?php

/**
 * @file
 * ConductorWorkflow definitions for test endpoints.
 */

require_once drupal_get_path('module', 'dosomething_sms') . '/sms_flow_game_constants.inc';

$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'dosomething_sms_test';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('prompt');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'prompt';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->question = 'this is a test.';

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('prompt');

$workflows[$workflow->name] = $workflow;
