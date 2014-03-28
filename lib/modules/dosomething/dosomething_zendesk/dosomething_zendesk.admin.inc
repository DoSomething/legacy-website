<?php

/**
 * @file
 * Zendesk admin settings.
 */

function dosomething_zendesk_admin_page() {
  $auth = render(drupal_get_form('dosomething_zendesk_config_form'));
  $output = $auth;
  // If authenticated:
  if ($client = dosomething_zendesk_get_client()) {
    $output .= '<hr>';
    // Include the groups settings form.
    $output .= render(drupal_get_form('dosomething_zendesk_groups_config_form'));
  }
  return $output;
}

/**
 * System settings form for auth settings.
 */
function dosomething_zendesk_config_form($form, &$form_state)  {
  $form['authentication'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication')
  );
  $form['authentication']['dosomething_zendesk_subdomain'] = array(
    '#type' => 'textfield',
    '#title' => t('Subdomain'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_zendesk_subdomain', ''),
  );
  $form['authentication']['dosomething_zendesk_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_zendesk_username', ''),
  );
  $form['authentication']['dosomething_zendesk_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Token'),
    '#required' => TRUE,
    '#description' => t('Do not share this token publicly.'),
    '#default_value' => variable_get('dosomething_zendesk_token', ''),
  );
  return system_settings_form($form);
}

/**
 * Form constructor for entering Zendesk group_ids.
 */
function dosomething_zendesk_groups_config_form() {
  $form['groups'] = array(
    '#title' => t('Available Groups'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // List available groups and group id's from Zendesk API.
  foreach (dosomething_zendesk_get_zendesk_groups() as $group_id => $group_name) {
    $form['groups'][$group_id] = array(
      '#markup' => '<p>' . $group_name . ': ' . $group_id . '</p>',
    );
  }
  $form['cause'] = array(
    '#title' => t('Cause'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );
  // Load the cause vocbulary.
  $vocab = taxonomy_vocabulary_machine_name_load('cause');
  // Load all terms in the cause vocabulary.
  $terms = taxonomy_get_tree($vocab->vid);
  // Foreach cause: term
  foreach ($terms as $term) {
    $var = dosomething_zendesk_get_group_varname($term->tid);
    $form['cause'][$var] = array(
      '#type' => 'textfield',
      '#title' => t($term->name),
      '#required' => TRUE,
      '#size' => 10,
      '#default_value' => variable_get($var),
    );
  }
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => 'Submit',
    ),
  );
  return system_settings_form($form);
}

/**
 * Submit callback for dosomething_zendesk_groups_config_form().
 */
function dosomething_zendesk_groups_config_form_validate($form, &$form_state) {
  // Exclude unnecessary elements.
  form_state_values_clean($form_state);
  // Get all available group ids from Zendesk API.
  $group_ids = array_keys(dosomething_zendesk_get_zendesk_groups());
  // Foreach value:
  foreach ($form_state['values'] as $key => $value) {
    // If the value is not in the group ids:
    if (!in_array($value, $group_ids)) {
      // Set error.
      form_set_error($key, 'Group_id ' . $value . ' does not exist.');
    }
  }
}
