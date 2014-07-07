<?php

/**
 * @file
 * Admin config form settings.
 */

/**
 * Page callback for the Signup Opt In configuration page.
 */
function dosomething_signup_opt_in_config_page() {
  $output = '';
  // This is the form we'll replace.
  $variables_form = drupal_get_form('dosomething_signup_optin_config_form');
  $output .= drupal_render($variables_form);
  // This is the new form writes to the signup_variable table.
  $config_form = drupal_get_form('dosomething_signup_admin_config_form');
  $output .= drupal_render($config_form);
  return $output;
}

/**
 * Form constructor for Signup opt-in configuration.
 */
function dosomething_signup_admin_config_form($form, &$form_state) {
  $form['staff_picks'] = array(
    '#markup' => '<h3>Staff Picks</h3>',
  );
  // Each staff pick could have a special opt-in for third party communications.
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
        '#required' => TRUE,
        '#default_value' => dosomething_helpers_get_variable($nid, 'mobilecommons_opt_in_path'),
      );
      $form[$nid][$nid . '_beta'] = array(
        '#type' => 'textfield',
        '#title' => t('Mobile Commons Beta Opt-In Path'),
        '#required' => TRUE,
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
 * Submit handler for dosomething_signup_admin_config_form().
 */
function dosomething_signup_admin_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];
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
 * Settings form third party opt-in ids.
 */
function dosomething_signup_optin_config_form($form, &$form_state) {
  $form = array();

  // Main campaign/ds general ids.
  $form['dosomething_mobilecommons_general'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Commons General Opt-In'),
    '#default_value' => variable_get('dosomething_mobilecommons_general'),
  );

  $form['dosomething_mobilecommons_campaign_general'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Commons Campaigns Opt-In'),
    '#default_value' => variable_get('dosomething_mobilecommons_campaign_general'),
  );
  return system_settings_form($form);
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
    'mailchimp_grouping_id' => t('The numeric Grouping ID for the Group Name'),
    'mailchimp_group_name' => t('The alphanumeric Interest Group Name'),
    'mobilecommons_opt_in_path' => t('The numeric Mobilecommons opt-in path'),
  );
}
