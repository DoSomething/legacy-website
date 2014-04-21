<?php


/**
 * Implements hook_user_view().
 */
function dosomething_user_user_view($account, $view_mode, $langcode) {
  // Output user signups.
  $account->content['campaigns'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Campaigns'),
    '#markup' => views_embed_view('user_signups', 'block', $account->uid),
  );
  // Output recommended campaigns.
  $rec_nids = dosomething_campaign_get_recommended_campaign_nids('', $account->uid);
  foreach ($rec_nids as $delta => $nid) {
    $vars = dosomething_campaign_get_campaign_block_vars($nid);
    $account->content['recommended_' . $delta] = array(
      '#markup' => theme('campaign_block', array('vars' => $vars)),
    );
  }

  $account->content['updated'] = array(
    '#type' => 'user_profile_item',
    '#markup' => l('Update', 'user/' . $account->uid . '/edit'),
  );
}



