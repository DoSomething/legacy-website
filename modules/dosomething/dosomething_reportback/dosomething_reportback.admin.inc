<?php
/**
 * @file
 * Admin pages for dosomething_reportback.module.
 */

/**
 * Form constructor for the reportback entity form.
 *
 * @ingroup forms
 */
function reportback_form($form, &$form_state, $reportback, $op = 'edit') {
  $form['nid'] = array(
    '#title' => t('Nid'),
    '#type' => 'textfield',
    '#default_value' => isset($reportback->nid) ? $reportback->nid : '',
    '#required' => TRUE,
  );
  field_attach_form('reportback', $reportback, $form, $form_state);
  // Form actions:
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($reportback->rbid) ? t('Update reportback') : t('Save reportback'),
    ),
  );
  return $form;
}

/**
 * Form submission handler for reportback_form().
 *
 * @see reportback_form()
 */
function reportback_form_submit($form, &$form_state) {
  $reportback = entity_ui_form_submit_build_entity($form, $form_state);
  $reportback->save();
  $form_state['redirect'] = 'admin/reportback';
}
