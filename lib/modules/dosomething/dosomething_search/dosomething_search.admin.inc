<?php

function dosomething_search_admin_config_form($form, &$form_state) {

  $form['dosomething_search_copy_no_results'] = array(
    '#type' => 'textarea',
    '#title' => 'No Results Found Copy',
    '#default_value' => t("@value", ['@value' => variable_get('dosomething_search_copy_no_results')]),
    '#required' => TRUE,
    );
  return system_settings_form($form);
}
