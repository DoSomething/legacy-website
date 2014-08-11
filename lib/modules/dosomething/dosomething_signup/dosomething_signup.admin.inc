<?php

/**
 * @file
 * Admin config form settings.
 */

/**
 * Form constructor for Signup opt-in configuration.
 */
function dosomething_signup_optin_config_form($form, &$form_state) {
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
  $form['staff_picks'] = array(
    '#markup' => '<h3>Staff Picks</h3>',
  );
  $staff_picks = dosomething_campaign_get_staff_picks();
  if ($staff_picks) {
    foreach ($staff_picks as $vars) {
      dosomething_signup_optin_config_form_add_elements($form, $vars);
    }
  }
  $form['campaign_groups'] = array(
    '#markup' => '<h3>Grouped Campaigns</h3>',
  );
  if ($campaign_groups = dosomething_helpers_get_node_vars('campaign_group')) {
    foreach ($campaign_groups as $vars) {
      dosomething_signup_optin_config_form_add_elements($form, $vars);
    }
  }
  $form['header'] = array(
    '#markup' => '<h3>SMS Games</h3>',
  );
  $sms_games = dosomething_campaign_get_sms_games();
  if ($sms_games) {
    foreach ($sms_games as $vars) {
      $nid = $vars['nid'];
      // Create a fieldset for each SMS Game.
      $form[$nid] = array(
        '#type' => 'fieldset',
        '#title' => $vars['title'] . ' | NID ' . $nid,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form[$nid][$nid . '_alpha'] = array(
        '#type' => 'textfield',
        '#title' => t('Mobile Commons Alpha Opt-In Path'),
        '#default_value' => dosomething_helpers_get_variable($nid, 'mobilecommons_opt_in_path'),
      );
      $form[$nid][$nid . '_beta'] = array(
        '#type' => 'textfield',
        '#title' => t('Mobile Commons Beta Opt-In Path'),
        '#default_value' => dosomething_helpers_get_variable($nid, 'mobilecommons_friends_opt_in_path'),
      );
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

  $config_variables = array(
    'dosomething_mobilecommons_opt_in_path_user_register',
    'dosomething_mobilecommons_opt_in_path_general_campaign_signup',
  );
  foreach ($config_variables as $var_name) {
    variable_set($var_name, $values[$var_name]);
  }

  // Store list of variables that each Campaign can implement.
  $variables = dosomething_signup_get_admin_config_campaign_variables();

  // Save staff pick helpers variables.
  $staff_picks = dosomething_campaign_get_staff_picks();
  if ($staff_picks) {
    foreach ($staff_picks as $vars) {
      $nid = $vars['nid'];
      $node = node_load($nid);
      foreach ($variables as $name => $description) {
        $value = $values[$nid . '_' . $name];
        dosomething_helpers_set_variable($node, $name, $value);
      }
    }
  }

  // Save Campaign Group helpers variables.
  if ($campaign_groups = dosomething_helpers_get_node_vars('campaign_group')) {
    foreach ($campaign_groups as $vars) {
      $nid = $vars['nid'];
      $node = node_load($nid);
      foreach ($variables as $name => $description) {
        $value = $values[$nid . '_' . $name];
        dosomething_helpers_set_variable($node, $name, $value);
      }
    }
  }

  // Save SMS Games helpers variables.
  $sms_games = dosomething_campaign_get_sms_games();
  if ($sms_games) {
    foreach ($sms_games as $vars) {
      $nid = $vars['nid'];
      $node = node_load($nid);
      $alpha_name = 'mobilecommons_opt_in_path';
      $alpha_value = $values[$nid . '_alpha'];
      $beta_name = 'mobilecommons_friends_opt_in_path';
      $beta_value = $values[$nid . '_beta'];
      dosomething_helpers_set_variable($node, $alpha_name, $alpha_value);
      dosomething_helpers_set_variable($node, $beta_name, $beta_value);
    }
  }
  drupal_set_message(t("Configuration saved."));
}

/**
 * Adds form elements to store third party values for given set of $vars.
 */
function dosomething_signup_optin_config_form_add_elements(&$form, $vars) {
  $nid = $vars['nid'];
  $title = $vars['title'];
  $variables = dosomething_signup_get_admin_config_campaign_variables();

  // Create a fieldset for each campaign.
  $form[$nid] = array(
    '#type' => 'fieldset',
    '#title' => $title . ' | NID ' . $nid,
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

