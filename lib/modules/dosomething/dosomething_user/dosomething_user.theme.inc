<?php
/**
 * @file
 * Preprocess functions for the dosomething_user module.
 */

/**
 * Implements template_preprocess_user_profile().
 */
function dosomething_user_preprocess_user_profile(&$variables) {
	
	krumo($variables);

  // Array to contain all User Account information.
  $user_account = array();

  // Collect User Account data.
  $user_profile = $variables['user_profile'];

  $user_account['id']                 = $variables['user']->uid;
  $user_account['username']           = $variables['user']->name;
  $user_account['email']              = $variables['user']->mail;
  $user_account['first_name']         = !empty($user_profile['field_first_name']['#items'][0]['safe_value']) ? $user_profile['field_first_name']['#items'][0]['safe_value'] : NULL;
  $user_account['last_name']          = !empty($user_profile['field_last_name']['#items'][0]['safe_value']) ? $user_profile['field_last_name']['#items'][0]['safe_value'] : NULL;
  $user_account['birthday']           = !empty($user_profile['field_birthdate']['#items'][0]['value']) ? $user_profile['field_birthdate']['#items'][0]['value'] : NULL;
  $user_account['address']['country'] = !empty($user_profile['field_address']['#items'][0]['country']) ? $user_profile['field_address']['#items'][0]['country'] : NULL;
  $user_account['address']['state']   = !empty($user_profile['field_address']['#items'][0]['administrative_area']) ? $user_profile['field_address']['#items'][0]['administrative_area'] : NULL;
  $user_account['address']['city']    = !empty($user_profile['field_address']['#items'][0]['locality']) ? $user_profile['field_address']['#items'][0]['locality'] : NULL;
  $user_account['address']['zip']     = !empty($user_profile['field_address']['#items'][0]['postal_code']) ? $user_profile['field_address']['#items'][0]['postal_code'] : NULL;
  $user_account['address']['street']  = !empty($user_profile['field_address']['#items'][0]['thoroughfare']) ? $user_profile['field_address']['#items'][0]['thoroughfare'] : NULL;
  $user_account['address']['premise'] = !empty($user_profile['field_address']['#items'][0]['premise']) ? $user_profile['field_address']['#items'][0]['premise'] : NULL;
  $user_account['mobile']             = !empty($user_profile['field_mobile']['#items'][0]['safe_value']) ? $user_profile['field_mobile']['#items'][0]['safe_value'] : NULL;


  // Collect Signed Up Campaigns Data
  $user_account['campaigns'] = $variables['elements']['campaigns']['#markup'];
  $user_account['campaigns'] = NULL;  // Temp until Aaron's code is ready.
  

  // Collect Recommended Campaigns Data
  $user_account['recommended'] = $variables['elements']['recommended']['#markup'];
  

  $variables['user_account'] = $user_account;
}
