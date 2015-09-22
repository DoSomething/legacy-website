<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Fact Page specific variables.
 */
function dosomething_fact_page_admin_config_form($form, &$form_state) {

  $form['dosomething_fact_page_copy_intro'] = array(
    '#type' => 'textarea',
    '#title' => t('Intro copy'),
    '#required' => TRUE,
    '#default_value' => t(variable_get('dosomething_fact_page_copy_intro')),
    '#description' => t("Displayed as intro for each Fact Page."),
  );

  return system_settings_form($form);
}
