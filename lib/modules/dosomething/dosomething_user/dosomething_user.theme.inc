<?php
/**
 * @file
 * Preprocess functions for the dosomething_user module.
 */

/**
 * Returns markup for link to open the login/register modal with given $label.
 *
 * @param string $label
 *   The text to display on the button.
 * @param string $class
 *   A class to apply to the button.
 */
function dosomething_user_get_login_modal_link_markup($label, $class = 'medium') {
  return '<a id="link--campaign-signup-login" href="#" data-modal-href="#modal--login" class="btn ' . $class . '">' . $label . '</a>';
}

/**
 * Implements template_preprocess_user_profile().
 */
function dosomething_user_preprocess_user_profile(&$variables) {

  // Collect User Account data.
  $uid = $variables['user']->uid;
  $user = user_load($uid);
  $variables['first_name'] = dosomething_user_get_field('field_first_name', $user, 'ucwords');
  $variables['last_name'] = dosomething_user_get_field('field_last_name', $user, 'ucwords');
  $variables['edit_link'] = 'user/' . $uid . '/edit';
  $variables['email'] = $user->mail;
  $variables['mobile'] = dosomething_user_get_field('field_mobile', $user);

  // Collect Campaigns Doing.
  $variables['doing'] = array();
  $doing = dosomething_campaign_get_campaigns_doing($user->uid);
  // If user isn't doing anything:
  if (empty($doing)) {
    // Set No Signups Header.
    $variables['no_signups_header'] = variable_get('dosomething_user_profile_no_signups_header');
    if (empty($variables['no_signups_header'])) {
      $variables['no_signups_header'] = t("There's nothing here!");
    }
    // Set No Signups Copy.
    $variables['no_signups_copy'] = variable_get('dosomething_user_profile_no_signups_copy');
    if (empty($variables['no_signups_copy'])) {
      $variables['no_signups_copy'] = t("(Yet.) Sign up for a campaign to make the world suck less. Then send pics of you in action for the chance at scholarship money and swag.");
    }
  }
  else {
    $image_size = '400x400';
    foreach ($doing as $doing_nid) {
      $campaign_vars = dosomething_campaign_get_campaign_block_vars($doing_nid, $image_size);
      $variables['doing'][] = array(
        '#markup' => theme('campaign_block', $campaign_vars),
      );
    }
  }

  $variables['title'] = t("Hey, @name!", array("@name" => $variables['first_name'])); 
  $variables['subtitle'] = variable_get('dosomething_user_profile_subtitle', NULL);
}
