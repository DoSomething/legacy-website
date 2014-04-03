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

  $rec_nids = dosomething_campaign_get_recommended_campaign_nids('', $account->uid);
  foreach ($rec_nids as $nid) {
    $rec_vars[] = dosomething_campaign_get_recommended_campaign_vars($nid);
  }

  $account->content['recomended'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Recomended'),
    '#markup' => $rec_vars, //@TODO: theme this.
  );
}



