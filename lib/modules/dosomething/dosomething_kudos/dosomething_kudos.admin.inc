<?php
/**
 * @file
 * Code for dosomething_kudos admin functionality.
 */

/**
 * Form constructor for Kudos admin config form.
 *
 * @see dosomething_kudos_menu()
 */
function dosomething_kudos_admin_config_form($form, &$form_state) {
  $form['dosomething_kudos_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Kudos globally for all campaigns.'),
    '#default_value' => variable_get('dosomething_kudos_enabled', FALSE),
    '#description' => t("Allows admins to enable/disable Kudos feature."),
  );

  return system_settings_form($form);
}
