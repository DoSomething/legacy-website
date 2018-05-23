<?php
/**
 * @file
 * Preprocess functions for the dosomething_user module.
 */

/**
 * Returns markup for link to sign up for a campaign.
 *
 * @param string $label - The text to display on the button.
 * @param string $nid - The campaign node ID
 * @param string $title - The campaign title
 * @return string
 */
function dosomething_user_get_sign_up_link_markup($label, $nid, $title) {
  return l(t($label), 'user/authorize', [
    'query' => ['action' => 'signup', 'node' => $nid, 'title' => $title],
    'attributes' => [
      'id' => 'link--openid-connect-campaign-signup-login',
      'class' => ['button'],
      'data-track-category' => 'Link',
      'data-track-action' => 'Click',
      'data-track-label' => 'Signup (Unauthenticated)',
    ]]);
}

/**
 * Returns markup for a link to login.
 *
 * @param string $label
 * @param array $class
 * @return string
 */
function dosomething_user_get_login_link($label, array $class = []) {
  return l(t($label), 'user/authorize', [
    'attributes' => [
      'id' => 'link--openid-connect-login',
      'data-track-category' => 'Link',
      'data-track-action' => 'Click',
      'data-track-label' => 'Login',
      'class' => $class,
    ]
  ]);
}

/**
 * Returns markup for a link to register.
 *
 * @param string $label
 * @param array $class
 * @return string
 */
function dosomething_user_get_register_link($label, array $class = []) {
  return l(t($label), 'user/authorize', [
    'query' => ['mode' => 'register'],
    'attributes' => [
      'id' => 'link--openid-connect-register',
      'data-track-category' => 'Link',
      'data-track-action' => 'Click',
      'data-track-label' => 'Register',
      'class' => $class,
    ]
  ]);
}

/**
 * Implements template_preprocess_user_profile().
 */
function dosomething_user_preprocess_user_profile(&$variables) {
  // Collect User Account data.
  $uid = $variables['elements']['#account']->uid;

  $nsUser = dosomething_northstar_get_user(
    dosomething_user_get_northstar_id($uid)
  );

  $variables['first_name'] = $nsUser->first_name;
  $variables['last_name'] = $nsUser->last_name;
  // The edit link will redirect to profile.dosomething.org for non-admins.
  $variables['edit_link'] = 'user/' . $uid . '/edit';
  $variables['email'] = $nsUser->email;
  $variables['mobile'] = $nsUser->mobile;

  // Collect Campaigns Doing.
  $variables['doing'] = array();
  $doing = dosomething_campaign_get_campaigns_doing($user->uid);
  // If user isn't doing anything:
  if (empty($doing)) {
    // Set No Signups Header.
    $variables['no_signups_header'] = t(variable_get('dosomething_user_profile_no_signups_header'));
    if (empty($variables['no_signups_header'])) {
      $variables['no_signups_header'] = t("There's nothing here!");
    }
    // Set No Signups Copy.
    $variables['no_signups_copy'] = t(variable_get('dosomething_user_profile_no_signups_copy'));
    if (empty($variables['no_signups_copy'])) {
      $variables['no_signups_copy'] = t("(Yet.) Sign up for a campaign to make the world suck less. Then send pics of you in action for the chance at scholarship money and swag.");
    }
  }
  else {
    foreach ($doing as $nid) {
      $variables['doing'][] = dosomething_campaign_get_campaign_block_vars($nid);
    }
  }

  // Collect User Reportbacks.
  $variables['reportbacks'] = dosomething_reportback_get_reportbacks($uid);

  $variables['title'] = t("Hey, @name!", array("@name" => $variables['first_name']));
  $variables['subtitle'] = t(variable_get('dosomething_user_profile_subtitle', NULL));
}
