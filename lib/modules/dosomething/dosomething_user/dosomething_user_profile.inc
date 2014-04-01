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
}
