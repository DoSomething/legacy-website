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
  $user = user_load($user_profile['uid']);

  $user_account['id']                  = isset($user_profile['uid']) ? $user_profile['uid'] : NULL;
  $user_account['username']            = isset($user_profile['username']) ? $user_profile['username'] : NULL;
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


  // Collect Signed Up Campaigns data.
  $user_account['signedup'] = $variables['elements']['signedup'];
  

  // Create empty gallery item.
  $user_account['signedup_count'] = count($user_account['signedup']);
  $empty_class_modifier = NULL;
  $empty_tile = FALSE;

  switch ($user_account['signedup_count'] % 4) {
    case 1:
      $empty_class_modifier = '-trio';
      $empty_tile = TRUE;
      break;

    case 2:
      $empty_class_modifier = '-duo';
      $empty_tile = TRUE;
      break;

    case 3:
      $empty_class_modifier = '-mono';
      $empty_tile = TRUE;
      break;
  }

  $user_account['empty_class_modifier'] = $empty_class_modifier;
  $user_account['empty_tile'] = $empty_tile;
  

  // Collect Recommended Campaigns data.
  $user_account['recommended'] = $variables['elements']['recommended'];
  
  $variables['user_account'] = $user_account;

  $variables['subtitle'] = variable_get('dosomething_user_profile_subtitle', NULL);
}
