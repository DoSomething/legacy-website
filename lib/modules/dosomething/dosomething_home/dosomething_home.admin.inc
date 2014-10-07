<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Shipment specific variables.
 */
function dosomething_home_admin_config_form($form, &$form_state) {
  $form['dosomething_home_title'] = array(
    '#type' => 'textarea',
    '#title' => t('Homepage title'),
    '#rows' => 2,
    '#description' => t("Overrides the title on the homepage."),
    '#default_value' => variable_get('dosomething_home_title'),
  );
  return system_settings_form($form);
}
