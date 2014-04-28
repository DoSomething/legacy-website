<?php


/**
 * Implements hook_user_view().
 */
function dosomething_user_user_view($account, $view_mode, $langcode) {
  $image_size = '310x310';


  // Output user signup campaigns.
  $signup_nids = dosomething_signup_get_signup_nids_by_uid($account->uid);
  $signups = array();

  foreach ($signup_nids as $delta => $nid) {
    $vars = dosomething_campaign_get_campaign_block_vars($nid, $image_size);
    $signups['signup_' . $delta] = array(
      '#markup' => theme('campaign_block', array('vars' => $vars)),
    );
  }

  $account->content['campaigns_signedup'] = $signups;


  // Output recommended campaigns.
  $rec_nids = dosomething_campaign_get_recommended_campaign_nids('', $account->uid);
  $recommended = array();

  foreach ($rec_nids as $delta => $nid) {
    $vars = dosomething_campaign_get_campaign_block_vars($nid, $image_size);
    $recommended['recommended_' . $delta] = array(
      '#markup' => theme('campaign_block', array('vars' => $vars)),
    );
  }

  $account->content['campaigns_recommended'] = $recommended;


  // Output update link.
  $account->content['updated'] = array(
    '#type' => 'user_profile_item',
    '#markup' => l('Update', 'user/' . $account->uid . '/edit'),
    '#weight' => 300,
  );
}
