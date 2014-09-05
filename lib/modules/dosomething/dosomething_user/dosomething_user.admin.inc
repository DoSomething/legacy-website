<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Shipment specific variables.
 */
function dosomething_user_admin_config_form($form, &$form_state) {
  $var_name = 'dosomething_user_node_terms_service';
  $form[$var_name] = array(
    '#type' => 'entity_autocomplete',
    '#title' => t('Terms of Service'),
    '#entity_type' => 'node',
    '#bundles' => array('static_content'),
    '#description' => t("Select the node which provides site Terms of Service."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );
  $var_name = 'dosomething_user_node_privacy_policy';
  $form[$var_name] = array(
    '#type' => 'entity_autocomplete',
    '#title' => t('Privacy Policy'),
    '#entity_type' => 'node',
    '#bundles' => array('static_content'),
    '#description' => t("Select the node which provides site Privacy Policy."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  // Login form settings.
  $form['login'] = array(
    '#type' => 'fieldset',
    '#title' => t('Login'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $var_name = 'dosomething_user_login_form_copy';
  $form['login'][$var_name] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Login Form copy'),
    '#description' => t("Copy displayed below the Login Form header. Optional."),
    '#default_value' => variable_get($var_name),
  );
  $var_name = 'dosomething_user_login_form_display_password_link';
  $form['login'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Display "Forgot Password" link'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("If unchecked, the link will not be displayed. Helpful for single sign-on implementations that do not yet support password reset."),
  );

  // Development settings.
  $form['devel'] = array(
    '#type' => 'fieldset',
    '#title' => t('Development'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $var_name = 'dosomething_user_enable_clean_slate';
  $form['devel'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Clean Slate Form.'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("Allows staff user access to delete all activity for their account. This should be disabled on production."),
  );
  return system_settings_form($form);
}

/**
 * Form constructor for a Clean Slate form.
 *
 * Deletes all of the logged in user's campaign activity.
 *
 * @ingroup forms
 */
function dosomething_user_clean_slate_form($form, &$form_state) {
  if (variable_get('dosomething_user_enable_clean_slate', FALSE) == FALSE) {
    $form['disabled'] = array(
      '#markup' => t("Clean Slate has been disabled."),
    );
    return $form;
  }
  $help = "As staff, you may delete all of your Campaign Signups, Reportbacks, Rewards, and Shipments.<h1>WARNING THIS CANNOT BE UNDONE</h1><h1>ARE YOU REALLY SURE ABOUT THIS</h1><h2>YOU ARE BRINGING THIS UPON YOURSELF</h2>";
  $form['help'] = array(
    '#markup' => $help,
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t("Clean Slate Me"),
    ),
  );
  return $form;
}

/**
 * Submit callback for dosomething_user_clean_slate_form().
 */
function dosomething_user_clean_slate_form_submit($form, &$form_state) {
  global $user;
  $msg = t("Clean Slate form submitted for User %uid", array(
    '%uid' => $user->uid,
  ));
  watchdog('dosomething_user_clean_slate', $msg);
  // Go git em.
  dosomething_user_clean_slate($user->uid);
}
