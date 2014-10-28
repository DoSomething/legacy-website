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

  // Array to contain all User Account information.
  $user_account = array();


  // Collect User Account data.
  $user_profile = $variables['user_profile'];
  $uid = $variables['user']->uid;
  $user = user_load($uid);
  $variables['first_name'] = dosomething_user_get_field('field_first_name', $user, 'ucwords');
  $variables['edit_link'] = 'user/' . $uid . '/edit';


  $user_account['email']               = isset($user_profile['mail']) ? $user_profile['mail'] : NULL;
  $user_account['first_name']          = dosomething_user_get_field('field_first_name', $user, 'ucwords');
  $user_account['last_name']           = dosomething_user_get_field('field_last_name', $user, 'ucwords');
  $user_account['birthday']            = dosomething_user_get_field('field_birthdate', $user, 'F j, Y');
  $user_account['mobile']              = dosomething_user_get_field('field_mobile', $user);
  $user_account['location']['country'] = isset($user_profile['field_address']['#items'][0]['country']) ? $user_profile['field_address']['#items'][0]['country'] : NULL;
  $user_account['location']['state']   = isset($user_profile['field_address']['#items'][0]['administrative_area']) ? $user_profile['field_address']['#items'][0]['administrative_area'] : NULL;
  $user_account['location']['city']    = isset($user_profile['field_address']['#items'][0]['locality']) ? $user_profile['field_address']['#items'][0]['locality'] : NULL;
  $user_account['location']['zip']     = isset($user_profile['field_address']['#items'][0]['postal_code']) ? $user_profile['field_address']['#items'][0]['postal_code'] : NULL;
  $user_account['location']['street']  = isset($user_profile['field_address']['#items'][0]['thoroughfare']) ? $user_profile['field_address']['#items'][0]['thoroughfare'] : NULL;
  $user_account['location']['premise'] = isset($user_profile['field_address']['#items'][0]['premise']) ? $user_profile['field_address']['#items'][0]['premise'] : NULL;


  // Collect Address information that user has provided.
  $address = array();

  foreach($user_account['location'] as $key => $value) {
    if (!empty($value)) {
      $address[$key] = $value;
    }
  }

  $user_account['address'] = $address;

  // Collect Campaigns Doing.
  $variables['doing'] = array();
  $doing = dosomething_campaign_get_campaigns_doing($user->uid);
  if (empty($doing)) {
    $default_header = t("There's nothing here!");
    $variables['no_signups_header'] = $default_header;
    $default_copy = t("(Yet.) Sign up for a campaign to make the world suck less. Then send pics of you in action for the chance at scholarship money and swag.");
    $variables['no_signups_copy'] = $default_copy;
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

  $variables['user_account'] = $user_account;
  $variables['title'] = t("Hey, @name!", array("@name" => $variables['first_name'])); 
  $variables['subtitle'] = variable_get('dosomething_user_profile_subtitle', NULL);
}
