<?php

/**
 * @file
 * Rogue admin functionality.
 */

/**
 * System settings form for Rogue configuration.
 */
function dosomething_rogue_config_form($form, &$form_state) {
  $form = array();

  $form['rogue'] = [
    '#type' => 'fieldset',
    '#title' => t('Rogue Settings.')
  ];

  $form['rogue']['dosomething_rogue_url'] = [
    '#type' => 'textfield',
    '#title' => t('Rogue URL'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_rogue_url', 'http://rogue.app/'),
  ];

  $form['rogue']['dosomething_rogue_api_version'] = [
    '#type' => 'textfield',
    '#title' => t('Rogue API version number'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_rogue_api_version', 'v1'),
  ];

  $form['rogue']['dosomething_rogue_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('Rogue API Key'),
    '#required' => FALSE,
    '#default_value' => variable_get('dosomething_rogue_api_key', ''),
  ];

  return system_settings_form($form);
}

/**
 * Adds helper flag to turn on rogue collection on the custom settings page on campaign nodes.
 */
function dosomething_rogue_campaign_config_form($form, &$form_state, $node) {
  // Load the node's helpers variables.
  $vars = dosomething_helpers_get_variables('node', $node->nid);

  $form['nid'] = [
    '#type' => 'hidden',
    '#value' => $node->nid,
  ];

  $form['rogue'] = [
    '#type' => 'fieldset',
    '#title' => t("Rogue"),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];

  $form['rogue']['rogue_collection'] = [
    '#type' => 'checkbox',
    '#title' => t('Send reportbacks to rogue'),
    '#description' => t('If set, when a user submits a reportback it will be sent to our reportback service.'),
    '#default_value' => $vars['rogue_collection'],
    '#size' => 20,
  ];

  $form['rogue']['actions'] = [
    '#type' => 'actions',
    'submit' => [
      '#type' => 'submit',
      '#value' => 'Save',
    ],
  ];
  return $form;
}

/**
 * Submit callback for dosomething_rogue_campaign_config_form().
 */
function dosomething_rogue_campaign_config_form_submit(&$form, &$form_state) {
  $var_names = ['rogue_collection'];

  foreach($var_names as $var_name) {
    $values = $form_state['values'];
    dosomething_helpers_set_variable('node', $values['nid'], $var_name, $values[$var_name]);
  }

  drupal_set_message("Updated.");
}
