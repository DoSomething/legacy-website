<?php
/**
 * @file
 * Code for dosomething_sms admin functionality.
 */

/**
 * Page callback for SMS Workflow admin page.
 */
function dosomething_sms_workflow_overview_page() {
  $admin_path = DOSOMETHING_SMS_WORKFLOW_ADMIN_PATH;

  $help = "A SMS Workflow enables Reportbacks via MobileCommons for a Campaign.";
  $output = '<p>' . t($help) . '</p>';

  $add_link = l(t('Add SMS Workflow'), $admin_path . '/add');
  $output .= '<ul class="action-links"><li>' . $add_link. '</li></ul>';

  $rows = array();
  $header = array(
    t('ID'),
    t('Endpoint'),
    t('Node'),
    t('Status'),
    t('MMS Response'),
    t('Ask Quantity'),
    t('Ask Why Participated'),
    t('Submit Reportback'),
    t('Campaign Opt-out'),
    t('Campaign Completed'),
    t('Op'),
  );
  // Loop through all sms_workflows, regardless of status:
  foreach (dosomething_sms_get_sms_workflows(FALSE) as $workflow) {
    $nid = $workflow->nid;
    $rows[] = array(
      $workflow->id,
      $workflow->endpoint,
      l($nid, 'node/' . $nid . '/reportbacks'),
      $workflow->status ? t('Enabled') : t('Disabled'),
      $workflow->id_no_mms_response,
      $workflow->id_ask_quantity,
      $workflow->id_ask_why_participated,
      $workflow->id_submit_reportback,
      $workflow->id_campaign_opt_out,
      $workflow->id_campaign_completed,
      l(t('Edit'), $admin_path . '/' . $workflow->id . '/edit'),
    );
  }
  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
  $config_form = drupal_get_form('dosomething_sms_workflow_config_form');
  $output .= render($config_form);
  return $output;
}

/**
 * Form constructor for SMS Workflow form.
 */
function dosomething_sms_workflow_form($form, &$form_state, $workflow = NULL) {
  if ($workflow) {
    $form['id'] =  array(
      '#type' => 'hidden',
      '#value' => $workflow->id,
    );
  }
  $desc = "The unique path for this workflow, appended to the https://www.dosomething.org/dosomething_sms URL that we use for mDatas.<p>e.g. If the endpoint is set to <em><strong>comebackclothes-reportback</strong></em>, the URL for its associated mData needs to be set to <em>https://dosomething.org/dosomething_sms/comebackclothes-reportback</em>.</p>Only use alpha-numeric characters and dashes (no spaces).";
  $form['endpoint'] =  array(
    '#type' => 'textfield',
    '#title' => t('Endpoint'),
    '#description' => t($desc),
    '#required' => TRUE,
    '#default_value' => isset($workflow->endpoint) ? $workflow->endpoint : NULL,
  );
  $form['nid'] =  array(
    '#type' => 'entity_autocomplete',
    '#title' => t('Campaign'),
    '#description' => t('Select the campaign this workflow is for.'),
    '#bundles' => array('campaign'),
    '#required' => TRUE,
    '#default_value' => isset($workflow->nid) ? $workflow->nid : NULL,
  );
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => "Uncheck if this endpoint should no longer be accessed.",
    // Default to 1 for new workflows.
    '#default_value' => isset($workflow->status) ? $workflow->status : 1,
  );
  $desc = t("This title is used internally to describe this workflow. e.g. <em>Comeback Clothes 2014.</em>");
  $form['title'] =  array(
    '#type' => 'textfield',
    '#title' => t('Human readable title'),
    '#required' => TRUE,
    '#description' => t($desc),
    '#default_value' => isset($workflow->title) ? $workflow->title : NULL,
  );
  $ids = array(
    'id_no_mms_response',
    'id_ask_quantity',
    'id_ask_why_participated',
    'id_submit_reportback',
    'id_campaign_opt_out',
    'id_campaign_completed',
  );
  foreach ($ids as $id) {
    $form[$id] =  array(
      '#type' => 'textfield',
      '#title' => $id,
      '#required' => TRUE,
      '#default_value' => isset($workflow->{$id}) ? $workflow->{$id} : NULL,
      '#element_validate' => array('element_validate_integer_positive'), 
    );
  }
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Validation callback for dosomething_reportback_form().
 */
function dosomething_sms_workflow_form_validate($form, &$form_state) {
  $endpoint = $form_state['values']['endpoint'];
  if (preg_match('/[^a-z_\-0-9]/i', $endpoint)) {
    form_set_error('endpoint', t("Alpha-numeric and dashes only."));
  }
}

/**
 * Submit callback for dosomething_reportback_form().
 */
function dosomething_sms_workflow_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  if (!isset($values['id'])) {
    $entity = entity_create('sms_workflow', $values);
  }
  else {
    $entity = sms_workflow_load($values['id']);
    foreach ($values as $key => $value) {
      $entity->{$key} = $value;
    }
  }
  $entity->save();
  $form_state['redirect'] = DOSOMETHING_SMS_WORKFLOW_ADMIN_PATH;
  drupal_set_message("SMS Workflow saved.");
}

/**
 * Form constructor for SMS Workflow config form.
 */
function dosomething_sms_workflow_config_form($form, &$form_state) {
  $form['dev'] = array(
    '#type' => 'fieldset',
    '#title' => t('Development'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('These settings should always be disabled in production.'),
  );
  $form['dev']['dosomething_sms_workflow_log'] =  array(
    '#type' => 'checkbox',
    '#title' => t('Enable logging'),
    '#description' => t("Logs requests to any SMS Workflow endpoint."),
    '#default_value' => variable_get('dosomething_sms_workflow_log'),
  );
  $form['dev']['dosomething_sms_workflow_access_bypass'] =  array(
    '#type' => 'checkbox',
    '#title' => t('Bypass IP checks'),
    '#description' => t("Disables check for incoming MobileCommons IP."),
    '#default_value' => variable_get('dosomething_sms_workflow_access_bypass'),
  );
  return system_settings_form($form);
}
