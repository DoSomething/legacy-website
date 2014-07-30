<?php
/**
 * @file
 * Code for dosomething_sms admin functionality.
 */

function dosomething_sms_workflow_overview_page() {
  $admin_path = DOSOMETHING_SMS_WORKFLOW_ADMIN_PATH;
  $add_link = l(t('Add SMS Workflow'), $admin_path . '/add');
  $output = '<ul class="action-links"><li>' . $add_link. '</li></ul>';
  $rows = array();
  $header = array(
    t('ID'),
    t('Endpoint'),
    t('Node'),
    t('Status'),
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
      l(t('Edit'), $admin_path . '/' . $workflow->id . '/edit'),
    );
  }
  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
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
  $form['endpoint'] =  array(
    '#type' => 'textfield',
    '#title' => t('Endpoint'),
    '#description' => "The unique path that this workflow is be accessed from.",
    '#required' => TRUE,
    '#default_value' => $workflow->endpoint,
  );
  $form['title'] =  array(
    '#type' => 'textfield',
    '#title' => t('Human readable title'),
    '#required' => TRUE,
    '#default_value' => $workflow->title,
  );
  $form['nid'] =  array(
    '#type' => 'textfield',
    '#title' => t('Node nid'),
    '#required' => TRUE,
    '#default_value' => $workflow->nid,
  );
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => "Uncheck if this endpoint should no longer be accessed.",
    // Default to 1 for new workflows.
    '#default_value' => isset($workflow->status) ? $workflow->status : 1,
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
      '#default_value' => $workflow->{$id},
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
  // Redirect to confirmation.
  $form_state['redirect'] = DOSOMETHING_SMS_WORKFLOW_ADMIN_PATH;
  drupal_set_message("SMS Workflow saved.");
}
