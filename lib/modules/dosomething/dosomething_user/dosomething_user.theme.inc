<?php
/**
 * @file
 * Preprocess functions for the dosomething_user module.
 */

/**
 * Returns markup for link to sign up for a campaign.
 *
 * @param string $label
 *   The text to display on the button.
 * @return string
 */
function dosomething_user_get_sign_up_link_markup($label, $nid) {
  // If the OpenID Connect feature flag is enabled, link to login page rather than showing classic modal.
  if (module_exists('dosomething_northstar') && variable_get('dosomething_user_openid_oauth_login_enabled')) {
    return l(t($label), 'user/authorize', [
      'query' => ['action' => 'signup', 'node' => $nid],
      'attributes' => [
        'class' => ['button'],
        'data-track-category' => 'Link',
        'data-track-action' => 'Click',
        'data-track-label' => 'Signup (Unauthenticated)',
        'id' => 'link--campaign-signup-login'
      ]]);
  }

  return l(t($label), '#', [
     'attributes' => [
       'id' => 'link--campaign-signup-login',
       'data-modal-href' => 'modal--login',
       'data-track-category' => 'Link',
       'data-track-action' => 'Click',
       'data-track-label' => 'Signup (Unauthenticated)',
       'class' => ['button'],
     ]
  ]);
}

/**
 * Returns markup for a link to login.
 *
 * @param string $label
 * @param array $class
 * @return string
 */
function dosomething_user_get_login_link($label, array $class = []) {
  if (module_exists('dosomething_northstar') && variable_get('dosomething_user_openid_oauth_login_enabled')) {
    return l(t($label), 'user/authorize', ['attributes' => ['class' => $class]]);
  }

  return l(t($label), 'user/login', ['attributes' => ['data-modal-href' => '#modal--login', 'class' => $class, 'id' => 'link--login']]);
}

/**
 * Returns markup for a link to register.
 *
 * @param string $label
 * @param array $class
 * @return string
 */
function dosomething_user_get_register_link($label, array $class = []) {
  if (module_exists('dosomething_northstar') && variable_get('dosomething_user_openid_oauth_login_enabled')) {
    // @TODO: We need to implement this `?register` query string in authorize route here, and on Northstar.
    return l(t($label), 'user/authorize?register', ['attributes' => ['class' => $class]]);
  }

  return l(t($label), 'user/register', ['attributes' => ['data-modal-href' => '#modal--register', 'class' => $class]]);
}

/**
 * Implements template_preprocess_user_profile().
 */
function dosomething_user_preprocess_user_profile(&$variables) {
  // Collect User Account data.
  $uid = $variables['elements']['#account']->uid;
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
