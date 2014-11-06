<?php

/**
 * @file
 * Zendesk admin settings.
 */

function dosomething_zendesk_admin_page() {
  $config_form = drupal_get_form('dosomething_zendesk_config_form');
  $output = render($config_form);
  // If authenticated:
  if ($client = dosomething_zendesk_get_client()) {
    $output .= '<hr>';
    // Include the groups settings form.
    $groups_form = drupal_get_form('dosomething_zendesk_groups_config_form');
    $output .= render($groups_form);
  }
  return $output;
}

/**
 * System settings form for auth settings.
 */
function dosomething_zendesk_config_form($form, &$form_state)  {
  $form['authentication'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
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
  $form['copy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form copy'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['copy']['dosomething_zendesk_form_header'] = array(
    '#type' => 'textarea',
    '#title' => t('Form Header'),
    '#description' => t("Copy displayed in the form header."),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_zendesk_form_header'),
  );
  $form['copy']['dosomething_zendesk_form_body_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Textarea Label'),
    '#description' => t("Label displayed above the textarea."),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_zendesk_form_body_label'),
  );
  $form['log'] = array(
    '#type' => 'fieldset',
    '#title' => t('Logging'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['log']['dosomething_zendesk_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Zendesk.'),
    '#default_value' => variable_get('dosomething_zendesk_log', FALSE),
    '#description' => t("Logs Zendesk activity. This should be disabled on production."),
  );
  return system_settings_form($form);
}

/**
 * Form constructor for entering Zendesk group_ids.
 */
function dosomething_zendesk_groups_config_form() {
  $form['groups'] = array(
    '#title' => t('Available Zendesk Groups'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $groups = dosomething_zendesk_get_zendesk_groups();
  if (empty($groups)) {
    return array('help' => array(
      '#markup' => t("Not authenticated."),
    ));
  }
  // List available groups and group id's from Zendesk API.
  foreach (dosomething_zendesk_get_zendesk_groups() as $group_id => $group_name) {
    $form['groups'][$group_id] = array(
      '#markup' => '<p>' . $group_name . ': ' . $group_id . '</p>',
    );
  }

  // Affiliate sites can route all ZD tickets to just one ZD group.
  $form['sitewide'] = array(
    '#title' => t('Sitewide'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['sitewide']['dosomething_zendesk_group_id'] = array(
    '#type' => 'textfield',
    '#title' => t("Sitewide Zendesk Group ID"),
    '#size' => 10,
    '#default_value' => variable_get('dosomething_zendesk_group_id'),
    '#description' => t("If set, all Zendesk tickets will be sent to this Group.")
  );

  // Store Zendesk group id's for each term in the Cause vocabulary.
  $form['cause'] = array(
    '#title' => t('Terms: Cause'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Load the cause vocbulary.
  $vocab = taxonomy_vocabulary_machine_name_load('cause');
  // Load all terms in the cause vocabulary.
  $terms = taxonomy_get_tree($vocab->vid);
  // Foreach cause: term
  foreach ($terms as $term) {
    $var = dosomething_zendesk_get_group_varname('tid', $term->tid);
    $form['cause'][$var] = array(
      '#type' => 'textfield',
      '#title' => t($term->name),
      '#size' => 10,
      '#default_value' => variable_get($var),
    );
  }

  // Store Zendesk group id's for each campaign_group node.
  $form['campaign_group'] = array(
    '#title' => t('Nodes: Grouped Campaigns'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  if (module_exists('dosomething_helpers')) {
    // Load nid and titles of all campaign_group nodes.
    if ($campaign_groups = dosomething_helpers_get_node_vars('campaign_group')) {
      // For each campaign_group:
      foreach ($campaign_groups as $campaign_group) {
        $var = dosomething_zendesk_get_group_varname('nid', $campaign_group['nid']);
        $form['campaign_group'][$var] = array(
          '#type' => 'textfield',
          '#title' => t($campaign_group['title']),
          '#default_value' => variable_get($var),
        );
      }
    }
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
    // If the value is set, and not in the group ids:
    if (!empty($value) && !in_array($value, $group_ids)) {
      // Set error.
      form_set_error($key, 'Group_id ' . $value . ' does not exist.');
    }
  }
}
