<?php

function dosomething_notfound_admin_config_form($form, &$form_state) {

  $form['dosomething_notfound_disable_results'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable relevant results'),
    '#default_value' => variable_get('dosomething_notfound_disable_results'),
    );
  $form['dosomething_notfound_copy_projects'] = array(
    '#type' => 'textarea',
    '#title' => 'Projects copy',
    '#default_value' => variable_get('dosomething_notfound_copy_projects'),
    '#required' => TRUE,
    );
  $form['dosomething_notfound_copy_grants'] = array(
    '#type' => 'textarea',
    '#title' => 'Grants copy',
    '#default_value' => variable_get('dosomething_notfound_copy_grants'),
    '#required' => TRUE,
    );
  $form['dosomething_notfound_copy_search_results'] = array(
    '#type' => 'textarea',
    '#title' => 'Search Copy',
    '#default_value' => variable_get('dosomething_notfound_copy_search_results'),
    '#required' => TRUE,
    );
  $form['dosomething_notfound_search_filter'] = array(
    '#type' => 'textarea',
    '#title' => 'Search filter words',
    '#description' => 'Comma separated list of all words to exclude from the search string (e.g. blog, actnow)',
    '#default_value' => variable_get('dosomething_notfound_search_filter'),
    );
  return system_settings_form($form);
}
