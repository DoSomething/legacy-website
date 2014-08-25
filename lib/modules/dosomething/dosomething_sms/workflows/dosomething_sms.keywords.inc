<?php

/**
 * @file
 * Array of endpoints ("keywords") and the name of the workflows they are each
 * associated with.
 */
$keywords['start-campaign-transition'] = 'dosomething_sms_start_campaign_transition';
$keywords['sms-game-paths'] = 'dosomething_sms_game_paths';
$keywords['imaboss-reportback'] = 'dosomething_sms_imaboss_reportback';

// Loop through all active SMS Workflows.
foreach (dosomething_sms_get_sms_workflows() as $wf) {
  $keywords[$wf->endpoint] = 'sms_workflow_' . $wf->id;
}
