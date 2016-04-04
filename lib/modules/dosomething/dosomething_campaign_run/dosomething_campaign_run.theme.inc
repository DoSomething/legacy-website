<?php
/**
 * @file 
 * Preprocess funtions for the dosomething_campaign_run module.
 */

/**
 * Implements hook_preprocess_node().
 */
function dosomething_campaign_run_preprocess_node(&$vars) {
  if ($vars['type'] != 'campaign_run' || $vars['view_mode'] != 'full') return;

  $vars['campaign_nid'] = $vars['field_campaigns'][0]['target_id'];
  
  $vars['campaign_title'] = node_load($vars['field_campaigns'][0]['target_id'])->title;
}
