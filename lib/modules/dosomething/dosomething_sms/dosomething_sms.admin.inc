<?php
/**
 * @file
 * Code for dosomething_sms admin functionality.
 */

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
  $entity->save();
  // Redirect to confirmation.
  $form_state['redirect'] = 'admin/config/dosomething/dosomething_sms';
  drupal_set_message("SMS Workflow saved.");
}
