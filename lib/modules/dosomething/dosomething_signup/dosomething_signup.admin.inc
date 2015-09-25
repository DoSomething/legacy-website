<?php

/**
 * @file
 * Admin config form settings.
 */

/**
 * Form constructor for Signup opt-in configuration.
 */
function dosomething_signup_opt_in_config_form($form, &$form_state) {

  // General Drupal variables.
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $field_prefix = "dosomething_signup_";
  $countries = dosomething_global_get_countries();
  $mailchimp_excluded_countries = ['ca', 'gb'];
  foreach ($countries as $country) {
    $country = strtolower($country);
    $form['general']['dosomething_signup'][$country] = array(
      '#type' => 'fieldset',
      '#title' => $country,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $name = $field_prefix . $country . '_mail_list_id';
    $form['general']['dosomething_signup'][$country][$name] = array(
      '#type' => 'textfield',
      '#required' => !in_array($country, $mailchimp_excluded_countries),
      '#title' => 'Mail List ID',
      '#default_value' => variable_get($name),
      '#description' => "General MailChimp List ID used in registrations and signups.",
    );

    //TEMPORARY -- Remove the IF statement to fix #5121
    if ($country == "us") {
      $name = $field_prefix . $country . '_mobile_opt_in_campaign';
      $form['general']['dosomething_signup'][$country][$name] = array(
        '#type' => 'textfield',
        '#required' => TRUE,
        '#title' => 'Mobile Opt-In path for Campaigns',
        '#default_value' => variable_get($name),
        '#description' => 'Numeric Mobile Commons opt-in path for general campaign signup.',
      );

      $name = $field_prefix . $country . '_mobile_opt_in_path_user_register';
      $form['general']['dosomething_signup'][$country][$name] = array(
        '#type' => 'textfield',
        '#required' => TRUE,
        '#title' => 'Mobile Opt-In path for User Registration',
        '#default_value' => variable_get($name),
        '#description' => 'Numeric Mobile Commons opt-in path when user registers for site.',
      );
    }
  }

  // 26 Club.
  $form['26plusclub'] = array(
    '#type' => 'fieldset',
    '#title' => t('26+ Club'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $name = 'dosomething_signup_26plusclub_enabled';
  $desc = t(
    "Makes possible to override settings for users older than 26. "
     . "Automatically excludes them from MailChimp on campaign signups "
     . "and MobileCommons on registrations."
  );
  $form['26plusclub'][$name] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable 26+ Club Overrides',
    '#default_value' => variable_get($name),
    '#description' => $desc,
  );
  $form['26plusclub']['overrides'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="' . $name . '"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form_26plusclub_overrides = &$form['26plusclub']['overrides'];

  $name = 'dosomething_signup_26plusclub_mailchimp_list_id';
  $desc = t("Override MailChimp List ID for users older than 26.");
  $form_26plusclub_overrides[$name] = array(
    '#type' => 'textfield',
    '#title' => 'MailChimp | mailchimp_list_id',
    '#default_value' => variable_get($name),
    '#description' => $desc,
  );

  $name = 'dosomething_signup_26plusclub_mailchimp_grouping_id_register';
  $desc = t("Override MailChimp Registration Grouping ID for users older than 26.");
  $form_26plusclub_overrides[$name] = array(
    '#type' => 'textfield',
    '#title' => 'MailChimp | User registration | mailchimp_grouping_id',
    '#default_value' => variable_get($name),
    '#description' => $desc,
  );

  $name = 'dosomething_signup_26plusclub_mailchimp_group_name_register';
  $desc = t("Override MailChimp Registration Interest Group Name for users older than 26.");
  $form_26plusclub_overrides[$name] = array(
    '#type' => 'textfield',
    '#title' => 'MailChimp | User registration | mailchimp_group_name',
    '#default_value' => variable_get($name),
    '#description' => $desc,
  );


  $name = 'dosomething_signup_26plusclub_mailchimp_template_name_register';
  $desc = t("Override MailChimp Registration Template Name for users older than 26.");
  $form_26plusclub_overrides[$name] = array(
    '#type' => 'textfield',
    '#title' => 'MailChimp | User registration | mailchimp_template_name',
    '#default_value' => variable_get($name),
    '#description' => $desc,
  );


  // Node helpers variables.
  $opt_in_helpers = dosomething_signup_get_opt_in_config_form_helpers_vars();
  foreach ($opt_in_helpers as $key => $vars) {
    // Output group header:
    $form[$key] = array(
      '#markup' => '<h3>' . $vars['title'] . '</h3>',
    );
    // If nodes exist for this group:
    if (!empty($vars['node_vars'])) {
      // Get the helpers_vars names for this group.
      $helpers_vars = &$vars['helpers_vars'];
      // Loop through each node:
      foreach ($vars['node_vars'] as $node_vars) {
        // Add a form element for the node's helpers variables.
        dosomething_signup_opt_in_config_form_add_elements($form, $node_vars, $helpers_vars);
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
 * Submit handler for dosomething_signup_opt_in_config_form().
 */
function dosomething_signup_opt_in_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  // Grabs all country fieldsets within dosomething_signup
  foreach ($form['general']['dosomething_signup'] as $field_name => $field) {

    // Get a list of all the countries we support
    $countries = dosomething_global_get_countries();
    foreach ($countries as $country) {
      $country = strtolower($country);

      // Verify the field name is a country and not something like #parents
      if ($field_name == $country) {

        // Go through each field within the country fieldset
        foreach ($field as $sub_field_name => $sub_field) {

          // Verify the field contains dosomething_signup
          if (strpos($sub_field_name, 'dosomething_signup') !== FALSE) {

            // Set the field in the DB
            variable_set($sub_field_name, $values[$sub_field_name]);
          }
        }
        break;
      }
    }
  }

  // 26+ Club.
  $club_enabled = !empty($values['dosomething_signup_26plusclub_enabled']);
  $config_variables = array(
    'dosomething_signup_26plusclub_mailchimp_list_id',
    'dosomething_signup_26plusclub_mailchimp_grouping_id_register',
    'dosomething_signup_26plusclub_mailchimp_group_name_register',
    'dosomething_signup_26plusclub_mailchimp_template_name_register',
  );
  foreach ($config_variables as $var_name) {
    if ($club_enabled) {
      variable_set($var_name, $values[$var_name]);
    } else {
      variable_del($var_name);
    }
  }

  // Save node helpers variables.
  $opt_in_helpers = dosomething_signup_get_opt_in_config_form_helpers_vars();
  foreach ($opt_in_helpers as $vars) {
    // If no nodes exist, go to next group.
    if (empty($vars['node_vars'])) {
      continue;
    }

    // Loop through each node:
    foreach ($vars['node_vars'] as $node_vars) {
      $nid = $node_vars['nid'];
      $node = node_load($nid);
      // Loop through the relevant helpers_vars for this node.
      foreach ($vars['helpers_vars'] as $name => $description) {
        // Get the form input value for this node helpers variable.
        $value = $values[$nid . '_' . $name];
        // Save it as a helpers variable.
        dosomething_helpers_set_variable('node', $node->nid, $name, $value);
      }
    }
  }

  drupal_set_message(t("Configuration saved."));
}

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
