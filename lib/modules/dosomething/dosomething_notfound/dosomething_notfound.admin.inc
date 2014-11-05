<?php

function dosomething_notfound_admin_config_form($form, &$form_state){

  $form['dosomething_notfound_disable_results'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable relevant results'),
    );
  return system_settings_form($form);
}
