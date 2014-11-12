<?php

function dosomething_notfound_admin_config_form($form, &$form_state){
 
  $form['dosomething_notfound_disable_results'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable relevant results'),
    );
  $form['dosomething_notfound_copy_projects'] = array(
    '#type' => 'textarea',
    '#title' => 'Projects copy', 
    '#default_value' => variable_get('dosomething_notfound_copy_projects'),
    );
  $form['dosomething_notfound_copy_grants'] = array(
    '#type' => 'textarea',
    '#title' => 'Grants copy', 
    '#default_value' => variable_get('dosomething_notfound_copy_grants'),
    );
  return system_settings_form($form);
}