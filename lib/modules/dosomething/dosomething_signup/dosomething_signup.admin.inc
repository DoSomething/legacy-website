<?php

/**
 * @file
 * Admin config form settings.
 */

/**
 * Returns multi-dimensional array of relevant Signup helpers variable names.
 *
 * @return array
 *   Returns multi-dimensional array, indexed by the Campaign type.
 */
function dosomething_signup_get_signup_helpers_var_names() {
  return array(
    'campaign' => array(
      'mailchimp_grouping_id' => t('The numeric Grouping ID for the Group Name.'),
      'mailchimp_group_name' => t('The alphanumeric Interest Group Name.'),
      'mobilecommons_opt_in_path' => t('The numeric Mobilecommons opt-in path.'),
    ),
    'sms_game' => array(
      'mobilecommons_opt_in_path' => t('Single-player: Mobile Commons Alpha Opt-In Path'),
      'mobilecommons_friends_opt_in_path' => t('Single-player: Mobile Commons Beta Opt-In Path'),
      'sms_game_mp_story_id' => t('Multi-player: Story Id'),
      'sms_game_mp_story_type' => t('Multi-player: Story Type'),
    ),
  );
}

/**
 * System settings form for DoSomething Signup specific variables.
 */
function dosomething_signup_admin_config_form($form, &$form_state) {
  $form['sms_game'] = array(
    '#type' => 'fieldset',
    '#title' => t('SMS Game'),
  );
  $var_name = 'dosomething_signup_sms_game_multiplayer_endpoint';
  $form['sms_game'][$var_name] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('SMS Multi-player Game Endpoint'),
    '#description' => t("URL to post a multi-player SMS Game request, e.g. <em>http://ds-heroku.biz/sms-multiplayer-game/create</em>"),
    '#default_value' => variable_get($var_name),
  );
  $form['log'] = array(
    '#type' => 'fieldset',
    '#title' => t('Logging'),
  );
  $form['log']['dosomething_signup_log_signups'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Signups.'),
    '#default_value' => variable_get('dosomething_signup_log_signups', FALSE),
    '#description' => t("Logs Signup entity activity. This should be disabled on production."),
  );
  $form['log']['dosomething_signup_log_mobilecommons'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Mobile Commons requests.'),
    '#default_value' => variable_get('dosomething_signup_log_mobilecommons', FALSE),
    '#description' => t("This should be disabled on production."),
  );
  return system_settings_form($form);
}
