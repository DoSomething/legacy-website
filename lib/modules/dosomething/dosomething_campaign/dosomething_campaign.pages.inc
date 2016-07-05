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
  $wrapper = dosomething_helpers_node_metadata_wrapper($node);
  $clc = dosomething_helpers_get_current_language_content_code();

  // Initialize $vars to pass to the reportback_confirmation theme function.
  $scholarship_language = t('You\'ve taken the first step in being entered to win the scholarship. Next step is to complete the experience!');

  $vars = [
    'back_to_campaign_link' => NULL,
    'call_to_action' => NULL,
    'copy' => $node->field_scholarship_amount[$clc][0]['value'] ? $scholarship_language : $node->field_reportback_confirm_msg[$clc][0]['value'],
    'more_campaigns_link' => NULL,
    'page_title' => NULL,
    'recommended' => NULL,
    'redeem_form' => NULL,
  ];
  // Image size to pass to campaign block.
  $image_size = '740x480';
  // Signup source to pass to campaign block.
  $source = dosomething_campaign_get_confirmation_path($node->nid);

  // Set variables for anonymous user:
  if (!user_is_logged_in()) {
    $button_text = t(variable_get('dosomething_campaign_confirmation_page_anon_button_text'));
    $vars['call_to_action'] = t(variable_get('dosomething_campaign_confirmation_page_anon_cta_text'));
    // The button should open the login/register form.
    $vars['more_campaigns_link'] = dosomething_user_get_login_modal_link_markup($button_text, 'large');
  }
  // Else set variables for authenticated user:
  else {
    $button_text = t(variable_get('dosomething_campaign_confirmation_page_button_text'));
    // Set button to link to /campaigns.
    $vars['more_campaigns_link'] = l(t($button_text), 'campaigns', [
      'attributes' => [
        'class' => [
          'button'
        ]
      ]
    ]);
    if (module_exists('dosomething_reward')) {
      // If a reportback count reward exists:
      if ($reward = dosomething_reward_exists('reportback_count')) {
        // If Reward has not been redeemed:
        if (!$reward->redeemed) {
          // Get the Reward Redeem vars for this Reward.
          $vars = dosomething_reward_get_redeem_form_vars($reward);
          // Return the themed Reward Redeem page.
          return theme('reward_redeem_reportback_count', $vars);
        }
      }
    }
  }

  // Link back to current node.
  $campaign_link_title = t('Back to @title', ['@title' => $node->title]);
  $vars['back_to_campaign_link'] = l($campaign_link_title, 'node/' . $node->nid, ['html' => TRUE]);

  // Store current node's primary cause tid.
  $tid = $wrapper->field_primary_cause->getIdentifier();
  // Get 4 recommended campaign nids for term $tid and current user.
  $rec_nids = dosomething_campaign_get_recommended_campaign_nids($tid, NULL, 4);
  // Initalize array to store reccomended campaign vars.
  $rec_vars = [];
  // Loop through rec_nids to load relevant variables.
  foreach ($rec_nids as $nid) {
    // Make sure $nid returned isn't the current $node's $nid.
    // This could happen for a SMS Game, where the confirmation page can be
    // viewed by anonymous user, so we don't have a signup to filter out.
    if ($nid != $node->nid) {
      $rec_vars[] = dosomething_campaign_get_campaign_block_vars($nid, $image_size);
    }
  }
  // We only want to display 3 campaigns blocks - we might have 4.
  $vars['recommended'] = array_slice($rec_vars, 0, 3);

  // Page title is set already based on campaign type.
  // @see dosomething_campaign_menu().
  $vars['page_title'] = drupal_get_title();

  // Returned themed reportback confirmation page.
  return theme('reportback_confirmation', $vars);
}
