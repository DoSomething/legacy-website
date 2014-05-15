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

/**
 * Page callback for active scholarships.
 *
 * @see dosomething_campaign_menu().
 */
function dosomething_campaign_scholarships_page() {
  // Fake featurey flag so this is safe to deploy without a theme.
  if (variable_get('dosomething_campaign_scholarship_page_is_active', '')) {
    // Grab published campaigns with cash prizes.
    $scholarships = dosomething_campaign_get_scholarships();
    if (isset($scholarships)) {
      // Get a link, CTA, image, etc for each campaign.
      foreach($scholarships as $key => $scholarship) {
        $rows[$key]['data'] = dosomething_campaign_get_campaign_block_vars($scholarship['nid']);
        unset($rows[$key]['data']['src']);
        $rows[$key]['data']['amount'] = '$' . $scholarship['amount'];
        $rows[$key]['data']['deadline'] = $scholarship['deadline'];
      }

      $vars['header'] = array('nid', 'title', 'cta', 'image', 'amount', 'deadline');
      $vars['rows'] = $rows;

      // For now, just send back a table view of the campaigns.
      return theme('table', $vars);
    }
    return t('No active scholarships right now, check back!');
  }
  return drupal_not_found();
}
