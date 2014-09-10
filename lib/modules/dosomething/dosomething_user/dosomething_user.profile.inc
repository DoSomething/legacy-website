<?php


/**
 * Implements hook_user_view().
 */
function dosomething_user_user_view($account, $view_mode, $langcode) {
  $image_size = '400x400';

  $account->content['uid'] = $account->uid;
  $account->content['name'] = $account->name;
  $account->content['mail'] = $account->mail;

  // Output user signup campaigns.
  $signup_nids = dosomething_signup_get_signup_nids_by_uid($account->uid);
  $signups = array();

  foreach ($signup_nids as $delta => $nid) {
    // Do not add the campaign if it is closed & user didn't reportback.
    if (dosomething_campaign_is_closed(node_load($nid)) && !dosomething_reportback_exists($nid, $account->uid)) {
      break;
    }
    $vars = dosomething_campaign_get_campaign_block_vars($nid, $image_size);
    $signups['signup_' . $delta] = array(
      '#markup' => theme('campaign_block', $vars),
    );

  }

  $account->content['signedup'] = $signups;


  // Output recommended campaigns.
  $rec_nids = dosomething_campaign_get_recommended_campaign_nids('', $account->uid);
  $recommended = array();

  foreach ($rec_nids as $delta => $nid) {
    $vars = dosomething_campaign_get_campaign_block_vars($nid, $image_size);
    $recommended['recommended_' . $delta] = array(
      '#markup' => theme('campaign_block', $vars),
    );
  }

  $account->content['recommended'] = $recommended;


  // Update link information.
  $edit_path = 'user/' . $account->uid . '/edit';

  $account->content['update_link_path'] = $edit_path;

  // Output update link.
  $account->content['update_link'] = array(
    '#markup' => l('Update', $edit_path),
    '#weight' => 300,
  );

}
