<?php
/**
 * @file
 * Admin pages for dosomething_campaign.module.
 */

/**
 * Form constructor for the Campaign entity form.
 *
 * @ingroup forms
 */
function campaign_form($form, &$form_state, $campaign, $op = 'edit') {
  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->title) ? $campaign->title : '',
    '#description' => t('Campaign title.'),
    '#required' => TRUE,
    '#weight' => -50,
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($campaign->id) ? t('Update Campaign') : t('Save Campaign'),
    ),
  );
  return $form;
}

/**
 * Form submission handler for campaign_form().
 *
 * @see campaign_form()
 */
function campaign_form_submit($form, &$form_state) {
  $campaign = entity_ui_form_submit_build_entity($form, $form_state);
  $campaign->save();
  $form_state['redirect'] = 'admin/campaign';
}
