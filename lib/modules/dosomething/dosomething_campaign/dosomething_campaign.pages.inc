<?php
/**
 * @file
 * Code for dosomething_campaign page callbacks.
 */

/**
 * Page callback for campaigns/hunt/submit.
 *
 * @see dosomething_campaign_menu().
 */
function dosomething_campaign_submit_idea_page() {
  return theme('submit_campaign_idea');
}
