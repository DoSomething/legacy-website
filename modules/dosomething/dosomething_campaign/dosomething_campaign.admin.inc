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
  // Prefix for form description variables:
  $desc_prefix = 'dosomething_campaign_form_desc_';

  // Basic info:
  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->title) ? $campaign->title : '',
    '#description' => variable_get($desc_prefix . 'title', ''),
    '#required' => TRUE,
  );
  $form['cta_text'] = array(
    '#title' => t('Call to action'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->cta_text) ? $campaign->cta_text : '',
    '#description' => variable_get($desc_prefix . 'cta_text', ''),
    '#required' => TRUE,
  );

  // Timing:
  $form['timing'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Timing'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => variable_get($desc_prefix . 'timing', ''),
  );
  $form['timing']['season_high_start'] = array(
    '#title' => t('High Season - Start Date'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->season_high_start) ? $campaign->season_high_start : '',
    '#attributes' =>array('placeholder' => t('MM/DD')),
    '#description' => variable_get($desc_prefix . 'season_high_start', ''),
  );
  $form['timing']['season_high_end'] = array(
    '#title' => t('High Season - End Date'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->season_high_end) ? $campaign->season_high_end : '',
    '#attributes' =>array('placeholder' => t('MM/DD')),
    '#description' => variable_get($desc_prefix . 'season_high_end', ''),
  );
  $form['timing']['is_season_high_end_displayed'] = array(
    '#title' => t('Show End Date on Pitch & Action Page'),
    '#type' => 'checkbox',
    '#default_value' => isset($campaign->is_season_high_end_displayed) ? $campaign->is_season_high_end_displayed : 0,
  );
  $form['timing']['season_low_start'] = array(
    '#title' => t('Low Season - Start Date'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->season_low_start) ? $campaign->season_low_start : '',
    '#attributes' =>array('placeholder' => t('MM/DD')),
    '#description' => variable_get($desc_prefix . 'season_low_start', ''),
  );
  $form['timing']['season_low_end'] = array(
    '#title' => t('Low Season - End Date'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->season_low_end) ? $campaign->season_low_end : '',
    '#attributes' =>array('placeholder' => t('MM/DD')),
    '#description' => variable_get($desc_prefix . 'season_low_end', ''),
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
