<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Shipment specific variables.
 */
function dosomething_user_admin_config_form($form, &$form_state) {

  // Terms of Service node.
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

  // Privacy Policy node.
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

  // Member Count.
  $var_name = 'dosomething_user_member_count';
  $form[$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Member Count'),
    '#description' => t("Number of members, which is displayed around the site. Don't change this unless you know what you're doing."),
    '#default_value' => variable_get($var_name),
  );

  // Display Postal Code field.
  $var_name = 'dosomething_user_validate_address';
  $form[$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Validate Address Field'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("If set, the user's field_address values will be validated against a geolocator API."),
  );

  // Login form settings.
  $form['login'] = array(
    '#type' => 'fieldset',
    '#title' => t('Login'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Login form copy.
  $var_name = 'dosomething_user_login_form_copy';
  $form['login'][$var_name] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Login Form copy'),
    '#description' => t("Copy displayed below the Login Form header. Optional."),
    '#default_value' => t("@value", ['@value' => variable_get($var_name)]),
  );

  // Display Forgot Password.
  $var_name = 'dosomething_user_login_form_display_password_link';
  $form['login'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Display "Forgot Password" link'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("If unchecked, the link will not be displayed. Helpful for single sign-on implementations that do not yet support password reset."),
  );

  // Login form copy.
  $var_name = 'dosomething_user_reset_password_copy';
  $form['login'][$var_name] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Forgot Password copy'),
    '#description' => t('Password reset neutral copy displayed both on fail and success.'),
    '#default_value' => t(variable_get($var_name)),
  );

  // Registration form settings.
  $form['reg'] = array(
    '#type' => 'fieldset',
    '#title' => t('Registration'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Display Last Name field.
  $var_name = 'dosomething_user_register_form_display_last_name';
  $form['reg'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect Last Name'),
    '#default_value' => variable_get($var_name, FALSE),
  );

  // Display Opt-in Email field.
  $var_name = 'dosomething_user_register_form_display_opt_in_email';
  $form['reg'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect Opt-in Email'),
    '#default_value' => variable_get($var_name, FALSE),
  );

  // Display Opt-in SMS field.
  $var_name = 'dosomething_user_register_form_display_opt_in_sms';
  $form['reg'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect Opt-In SMS'),
    '#default_value' => variable_get($var_name, FALSE),
  );

  // Display Postal Code field.
  $var_name = 'dosomething_user_register_form_display_postal_code';
  $form['reg'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect Postal Code'),
    '#default_value' => variable_get($var_name, FALSE),
  );

  // Profile settings.
  $form['social'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social Auth'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Profile subtitle.
  $var_name = 'dosomething_user_facebook_auth_enabled';
  $form['social'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Facebook auth'),
    '#default_value' => variable_get($var_name, FALSE),
  );

  // Profile settings.
  $form['profile'] = array(
    '#type' => 'fieldset',
    '#title' => t('Profile'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Profile subtitle.
  $var_name = 'dosomething_user_profile_subtitle';
  $form['profile'][$var_name] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Subtitle'),
    '#required' => TRUE,
    '#description' => t("Displayed below the Profile main page title."),
    '#default_value' => t(variable_get($var_name)),
  );

  // No Signups header.
  $var_name = 'dosomething_user_profile_no_signups_header';
  $form['profile'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('No Signups Header'),
    '#default_value' => t("@value", ['@value' => variable_get($var_name)]),
  );

  // No Signups copy.
  $var_name = 'dosomething_user_profile_no_signups_copy';
  $form['profile'][$var_name] = array(
    '#type' => 'textarea',
    '#title' => t('No Signups Copy'),
    '#default_value' => t("@value", ['@value' => variable_get($var_name)]),
  );

  // School settings.
  $form['school'] = array(
    '#type' => 'fieldset',
    '#title' => t('School'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // School API endpoint.
  $var_name = 'dosomething_user_school_api_endpoint';
  $form['school'][$var_name] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('School API Endpoint'),
    '#description' => t("URL to request school data, e.g. <em>http://lofischools.herokuapp.com/search</em>."),
    '#default_value' => variable_get($var_name),
  );

  // School Finder Help text.
  $var_name = 'dosomething_user_school_finder_help_text';
  $form['school'][$var_name] = array(
    '#type' => 'textarea',
    '#title' => t('School Finder Help Text'),
    '#description' => t("Text displayed if User needs help finding school.  Markdown supported."),
    '#default_value' => t("@value", ['@value' => variable_get($var_name)]),
  );

  // Development settings.
  $form['devel'] = array(
    '#type' => 'fieldset',
    '#title' => t('Development'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Enable Clean Slate form.
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
  watchdog('dosomething_user', $msg);
  // Go git em.
  dosomething_user_delete_all_data($user->uid);
}
