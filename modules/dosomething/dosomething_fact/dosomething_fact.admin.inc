<?php
/**
 * @file
 * Admin pages for dosomething_fact.module.
 */

/**
 * Form constructor for the Fact entity form.
 *
 * @ingroup forms
 */
function fact_form($form, &$form_state, $fact, $op = 'edit') {
  // Basic info:
  $form['fact'] = array(
    '#title' => t('Fact'),
    '#type' => 'textarea',
    '#default_value' => isset($fact->fact) ? $fact->fact : '',
    '#required' => TRUE,
  );
  $form['source'] = array(
    '#title' => t('Source'),
    '#type' => 'textfield',
    '#default_value' => isset($fact->source) ? $fact->source : '',
    '#required' => TRUE,
  );
  $form['url_source'] = array(
    '#title' => t('Source URL'),
    '#type' => 'textfield',
    '#default_value' => isset($fact->url_source) ? $fact->url_source : '',
  );
  $form['status'] = array(
    '#title' => t('Active'),
    '#type' => 'checkbox',
    '#default_value' => isset($fact->status) ? $fact->status : 0,
  );
  // Form actions:
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($fact->id) ? t('Update Fact') : t('Save Fact'),
    ),
  );
  return $form;
}

/**
 * Form submission handler for fact_form().
 *
 * @see fact_form()
 */
function fact_form_submit($form, &$form_state) {
  $fact = entity_ui_form_submit_build_entity($form, $form_state);
  $fact->save();
  $form_state['redirect'] = 'admin/fact';
}
