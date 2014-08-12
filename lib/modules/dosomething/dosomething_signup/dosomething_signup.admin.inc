<?php

/**
 * @file
 * Admin config form settings.
 */

/**
 * Form constructor for Signup opt-in configuration.
 */
function dosomething_signup_optin_config_form($form, &$form_state) {

  // General Drupal variables.
  $name = 'dosomething_mobilecommons_opt_in_path_user_register';
  $desc = t("Numeric Mobilecommons opt-in path when user registers for site.");
  $form[$name] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Mobilecommons Opt-In Path: User registration'),
    '#default_value' => variable_get($name),
    '#size' => 10,
    '#description' => $desc,
  );
  $name = 'dosomething_mobilecommons_opt_in_path_general_campaign_signup';
  $desc = t("Numeric Mobilecommons opt-in path for general campaign signup.");
  $form[$name] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Mobilecommons Opt-In Path: General campaign signup'),
    '#default_value' => variable_get($name),
    '#size' => 10,
    '#description' => $desc,
  );

  // Node helpers variables.
  foreach (dosomething_signup_get_optin_config_form_helpers_vars() as $key => $vars) {
    // Output section header:
    $form[$key] =array(
      '#markup' => '<h3>' . $vars['title'] . '</h3>',
    );
    // If nodes exist for this section:
    if (!empty($vars['node_vars'])) {
      // Loop through each node:
      foreach ($vars['node_vars'] as $node_vars) {
        $type = $vars['form_element_type'];
        // Add a form element for the node's helpers variables.
        dosomething_signup_optin_config_form_add_elements($form, $node_vars, $type);
      }
    }
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Submit handler for dosomething_signup_optin_config_form().
 */
function dosomething_signup_optin_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  // Save general Drupal variables.
  $config_variables = array(
    'dosomething_mobilecommons_opt_in_path_user_register',
    'dosomething_mobilecommons_opt_in_path_general_campaign_signup',
  );
  foreach ($config_variables as $var_name) {
    variable_set($var_name, $values[$var_name]);
  }

  // Save node helpers variables.
  foreach (dosomething_signup_get_optin_config_form_helpers_vars() as $vars) {
    // If no nodes exist, go to next group.
    if (empty($vars['node_vars'])) continue;

    // Loop through each node:
    foreach ($vars['node_vars'] as $node_vars) {
      $nid = $node_vars['nid'];
      $node = node_load($nid);
      // Loop through the relevant helpers_vars for this node.
      foreach ($vars['helpers_vars'] as $name => $description) {
        // Get the form input value for this node helpers variable.
        $value = $values[$nid . '_' . $name];
        // Save it as a helpers variable.
        dosomething_helpers_set_variable($node, $name, $value);
      }
    }
  }

  drupal_set_message(t("Configuration saved."));
}

/**
 * Adds form elements to store third party values for given set of $vars.
 */
function dosomething_signup_optin_config_form_add_elements(&$form, $vars, $type = NULL) {
  $nid = $vars['nid'];

  // Get the helper variables to create form elements based on the $type.
  $variables = dosomething_signup_get_admin_config_campaign_variables();
  if ($type == 'sms_game') {
    $variables = dosomething_signup_get_admin_config_sms_game_variables();
  }
 
  // Create a fieldset for each campaign.
  $form[$nid] = array(
    '#type' => 'fieldset',
    '#title' => $vars['title'] . ' | NID ' . $nid,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Loop through each variable it can contain:
  foreach ($variables as $name => $description) {
    // Create a form element for it.
    $form[$nid][$nid . '_' . $name] = array(
      '#type' => 'textfield',
      '#title' => $name,
      '#default_value' => dosomething_helpers_get_variable($nid, $name),
      '#description' => $description,
    );
  }
}

/**
 * Returns list of helper variables that a standard Campaign can implement.
 *
 * @return array
 *   Associative array keyed by variable name.
 */
function dosomething_signup_get_admin_config_campaign_variables() {
  return array(
    'mailchimp_grouping_id' => t('The numeric Grouping ID for the Group Name.'),
    'mailchimp_group_name' => t('The alphanumeric Interest Group Name.'),
    'mobilecommons_opt_in_path' => t('The numeric Mobilecommons opt-in path.'),
  );
}

/**
 * Returns list of helper variables that a SMS Game Campaign can implement.
 *
 * @return array
 *   Associative array keyed by variable name.
 */
function dosomething_signup_get_admin_config_sms_game_variables() {
  return array(
    'mobilecommons_opt_in_path' => t('Single-player: Mobile Commons Alpha Opt-In Path'),
    'mobilecommons_friends_opt_in_path' => t('Single-player: Mobile Commons Beta Opt-In Path'),
    'sms_game_mp_story_id' => t('Multi-player: Story Id'),
    'sms_game_mp_story_type' => t('Multi-player: Story Type'),
  );
}

/**
 * Returns list of variables to construct the Op-tin Config form.
 *
 * @return array
 */
function dosomething_signup_get_optin_config_form_helpers_vars() {
  $vars = array();
  $vars['staff_pick'] = array(
    'title' => t("Staff Picks"),
    'node_vars' => dosomething_campaign_get_staff_picks(),
    'helpers_vars' => dosomething_signup_get_admin_config_campaign_variables(),
    'form_element_type' => NULL,
  );
  $vars['campaign_group'] = array(
    'title' => t("Grouped Campaigns"),
    'node_vars' => dosomething_helpers_get_node_vars('campaign_group'),
    'helpers_vars' => dosomething_signup_get_admin_config_campaign_variables(),
    'form_element_type' => NULL,
  );
  $vars['sms_game'] = array(
    'title' => t("SMS Games"),
    'node_vars' => dosomething_campaign_get_sms_games(),
    'helpers_vars' => dosomething_signup_get_admin_config_sms_game_variables(),
    'form_element_type' => 'sms_game',
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
    '#description' => t("URL to post a multi-player SMS Game request, e.g. <em>http://ds-heroku/sms-multiplayer-game/create</em>"),
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

