<?php

/**
 * @file
 * Admin config form settings.
 */

/**
 * Adds form elements to store third party values for given set of $node_vars.
 *
 * @param array $form
 *   The Form API form to add the elements to.
 * @param array $node_vars
 *   The relevant node variables for these form elements. Expected values:
 *   - nid: The node nid (int).
 *   - title: The node title (string).
 * @param array $helpers_vars
 *   The helpers variable names to get/set for this node.
 */
function dosomething_signup_opt_in_config_form_add_elements(&$form, $node_vars, $helpers_vars) {
  $nid = $node_vars['nid'];
  $title = !empty($node_vars['title']) ? $node_vars['title'] : t("Undefined");
  // Create a fieldset for each campaign.
  $form[$nid] = array(
    '#type' => 'fieldset',
    '#title' => $title . ' | NID ' . $nid,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Loop through each helpers variable name for this node:
  foreach ($helpers_vars as $name => $description) {
    // Create a form element for setting the node helpers variable.
    $form[$nid][$nid . '_' . $name] = array(
      '#type' => 'textfield',
      '#title' => $name,
      '#default_value' => dosomething_helpers_get_variable('node', $nid, $name),
      '#description' => $description,
    );
  }
}

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
 * Returns list of variables to construct the Op-tin Config form.
 *
 * @return array
 */
function dosomething_signup_get_opt_in_config_form_helpers_vars() {
  $vars = array();
  $helpers_var_names = dosomething_signup_get_signup_helpers_var_names();
  $vars['staff_pick'] = array(
    'title' => t("Staff Picks"),
    'node_vars' => dosomething_campaign_get_staff_picks(),
    'helpers_vars' => $helpers_var_names['campaign'],
  );
  $vars['campaign_group'] = array(
    'title' => t("Campaign Collections"),
    'node_vars' => dosomething_helpers_get_node_vars('campaign_group'),
    // A Campaign Group uses the same helpers variables as a standard Campaign.
    'helpers_vars' => $helpers_var_names['campaign'],
  );
  $vars['sms_game'] = array(
    'title' => t("SMS Games"),
    'node_vars' => dosomething_campaign_get_sms_games(),
    'helpers_vars' => $helpers_var_names['sms_game'],
  );
  return $vars;
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
