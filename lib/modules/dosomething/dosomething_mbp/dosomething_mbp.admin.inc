<?php

/**
 * @file
 * Module settings UI.
 */

/**
 * Configuration form
 */
function dosomething_mbp_config_form($form, &$form_state) {

  $form['dosomething_mbp_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Message Broker Producer requests.'),
    '#default_value' => variable_get('dosomething_mbp_log', FALSE),
    '#description' => t("This should be disabled on production."),
  );

  $form['dosomething_mbp_templates'] = array(
    '#type' => 'fieldset',
    '#title' => t('Transactional Templates')
  );
  
  $user_registration_template = variable_get('dosomething_mbp_user_registration_template', '');
  $form['dosomething_mbp_templates']['dosomething_mbp_template_selection'] = array(
    '#type' => 'select',
    '#title' => t('User Registration'),
    '#options' => _get_mb_templates('message-broker'),
    '#default_value' => $user_registration_template,
    '#description' => 'The Mandrill template to use for User Registration.',
    '#required' => TRUE,
    '#weight' => 60,
  );
  
  
  return system_settings_form($form);
}

/**
 * Gather existing Mandrill templates and format results to be used in Drupal
 * seleciton form element.
 *
 * @parm array $form
 *   Array of form elements.
 * @returns array &$form_state
 *   Array of the state of the form elements.
 */
function _get_mb_templates($target_label) {
  
  // https://mandrillapp.com/api/docs/templates.JSON.html#method=list
  // https://mandrillapp.com/api/1.0/templates/list.json
  // "label": "example-label"
  
  return $templates;
}
