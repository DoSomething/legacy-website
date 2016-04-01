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

  $campaign_nid = dosomething_campaign_run_get_parent_nid($vars['node']->nid);
  $vars['campaign_nid'] = $campaign_nid;
  
  $vars['campaign_title'] = node_load($campaign_nid)->title;
}

/**
 * Preprocesses variables for campaign run page.
 *
 * @param array $vars
 *  Node variables, passed from the preprocess_node.
 * @param object $wrapper
 *  The corresponding entity wrapper for the node in $vars. 
 */
function dosomething_campaign_run_preprocess_page(&$vars, &$wrapper) {  

  // Use the pitch page template to the theme. 
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'];
}
