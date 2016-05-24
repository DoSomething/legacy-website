<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Settings specific variables.
 */
function dosomething_settings_admin_config_form($form, &$form_state) {

  $form['copy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sitewide Copy'),
    '#description' => t("Copy displayed in various page sections, such as the footer of Taxonomy Term pages.")
  );

  $var_name = 'dosomething_settings_copy_about_ds';
  $form['copy'][$var_name] = array(
    '#type' => 'textarea',
    '#title' => t('About DoSomething'),
    '#default_value' => t(variable_get($var_name)),
  );

  $var_name = 'dosomething_settings_copy_scholarships';
  $form['copy'][$var_name] = array(
    '#type' => 'textarea',
    '#title' => t('Scholarships'),
    '#default_value' => t(variable_get($var_name)),
  );

  $var_name = 'dosomething_settings_copy_campaign_value_proposition';
  $form['copy'][$var_name] = array(
    '#type' => 'textarea',
    '#title' => t('What You Get'),
    '#default_value' => t(variable_get($var_name)),
  );
   $form['share'] = array(
    '#type' => 'fieldset',
    '#title' => t('Share settings'),
    '#collapsible' => TRUE,
    '#description' => t("Contains settings for social share")
  );
  $var_name = 'dosomething_settings_facebook_app_id';
  $form['share'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook App Id'),
    '#default_value' => variable_get($var_name),
  );

  $form['fun'] = array(
    '#type' => 'fieldset',
    '#title' => t('FUN!'),
    '#description' => t("Control fun things.")
  );

  $var_name = 'dosomething_settings_realtimefeed_update_url';
  $form['fun'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Update URL for lobby dashboard'),
    '#default_value' => variable_get($var_name),
  );

  return system_settings_form($form);
}
