<?php
/**
 * @file
 * Code for dosomething_campaign page callbacks.
 */

/**
 * Page callback for the user reportback confirmation page.
 *
 * @param object $node
 *   The loaded campaign node.
 *
 * @return string
 *   Rendered HTML.
 */
function dosomething_campaign_reportback_confirmation_page($node) {
  $wrapper = entity_metadata_wrapper('node', $node);

  if (!user_is_logged_in()) {
    $button_text = variable_get('dosomething_campaign_confirmation_page_anon_button_text');
    $call_to_action = variable_get('dosomething_campaign_confirmation_page_anon_cta_text');
    // The button should open the login/register form.
    $more_campaigns_link = dosomething_user_get_login_modal_link_markup($button_text, 'large');
  }
  else {
    $button_text = variable_get('dosomething_campaign_confirmation_page_button_text');
    $call_to_action = NULL;
    // Set button to link to /campaigns.
    $more_campaigns_link = l(t($button_text), 'campaigns', array(
      'attributes' => array('class' =>
        array('btn', 'large')
      ))
    );
  }

  // Link back to current node.
  $campaign_link_title = t('Back to @title', array('@title' => $node->title));
  $back_to_campaign_link = l($campaign_link_title, 'node/' . $node->nid, array('html' => TRUE));
  // Store current node's primary cause tid.
  $tid = $wrapper->field_primary_cause->getIdentifier();
  // Get 4 recommended campaign nids for term $tid and current user.
  $rec_nids = dosomething_campaign_get_recommended_campaign_nids($tid, NULL, 4);
  // Initalize array to store reccomended campaign vars.
  $rec_vars = array();
  // Loop through rec_nids to load relevant variables.
  foreach ($rec_nids as $nid) {
    // Make sure $nid returned isn't the current $node's $nid.
    // This could happen for a SMS Game, where the confirmation page can be
    // viewed by anonymous user, so we don't have a signup to filter out.
    if ($nid != $node->nid) {
      $rec_vars[] = dosomething_campaign_get_campaign_block_vars($nid);
    }
  }
  // We only want to display 3 campaigns blocks - we might have 4.
  $rec_vars = array_slice($rec_vars, 0, 3);
  
  // Page title is set already based on campaign type.
  // @see dosomething_campaign_menu().
  $page_title = drupal_get_title();

  // Returned themed reportback confirmation page.
  return theme('reportback_confirmation', array(
    'page_title' => $page_title,
    'copy' => $wrapper->field_reportback_confirm_msg->value(),
    'more_campaigns_link' => $more_campaigns_link,
    'back_to_campaign_link' => $back_to_campaign_link,
    'recommended' => $rec_vars,
    'call_to_action' => $call_to_action,
    )
  );
}

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
