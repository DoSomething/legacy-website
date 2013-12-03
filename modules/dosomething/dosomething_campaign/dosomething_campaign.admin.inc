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
  $desc_prefix = DOSOMETHING_CAMPAIGN_FORM_DESC_PREFIX;

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
  $form['url_internal_confirm_doc'] = array(
    '#title' => t('Internal Confirmation Doc URL'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->url_internal_confirm_doc) ? $campaign->url_internal_confirm_doc : '',
    '#description' => variable_get($desc_prefix . 'url_internal_confirm_doc', ''),
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

  // Know It:
  $form['know'] = array(
    '#type' => 'fieldset',
    '#title' => t('Know It'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => variable_get($desc_prefix . 'know', ''),
  );
  $form['know']['stat_problem'] = array(
    '#title' => t('Statement on the Problem'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->stat_problem) ? $campaign->stat_problem : '',
    '#description' => variable_get($desc_prefix . 'stat_problem', ''),
  );
  $form['know']['stat_problem_source'] = array(
    '#title' => t('Source for Problem Statement'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->stat_problem_source) ? $campaign->stat_problem_source : '',
    '#description' => variable_get($desc_prefix . 'stat_problem_source', ''),
  );
  $form['know']['stat_solution'] = array(
    '#title' => t('Statement on the Solution'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->stat_solution) ? $campaign->stat_solution : '',
    '#description' => variable_get($desc_prefix . 'stat_solution', ''),
  );
  $form['know']['stat_solution_source'] = array(
    '#title' => t('Source for Solution Statement'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->stat_solution_source) ? $campaign->stat_solution_source : '',
    '#description' => variable_get($desc_prefix . 'stat_solution_source', ''),
  );
  $form['know']['url_psa'] = array(
    '#title' => t('PSA'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->url_psa) ? $campaign->url_psa : '',
    '#description' => variable_get($desc_prefix . 'url_psa', ''),
  );

  // Prep It:
  $form['prep'] = array(
    '#type' => 'fieldset',
    '#title' => t('Prep It'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => variable_get($desc_prefix . 'prep', ''),
  );
  $form['prep']['prep_intro'] = array(
    '#title' => t('Campaign Specific Starter Statement'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->prep_intro) ? $campaign->prep_intro : '',
    '#description' => variable_get($desc_prefix . 'prep_intro', ''),
  );
  $form['prep']['time_and_place'] = array(
    '#title' => t('Time and Place'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->time_and_place) ? $campaign->time_and_place : '',
    '#description' => variable_get($desc_prefix . 'time_and_place', ''),
  );
  $form['prep']['people_involved'] = array(
    '#title' => t('VIPs'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->people_involved) ? $campaign->people_involved : '',
    '#description' => variable_get($desc_prefix . 'people_involved', ''),
  );
  $form['prep']['items_needed'] = array(
    '#title' => t('Items Needed'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->items_needed) ? $campaign->items_needed : '',
    '#description' => variable_get($desc_prefix . 'items_needed', ''),
  );
  $form['prep']['promoting_tips'] = array(
    '#title' => t('Promoting Tips'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->promoting_tips) ? $campaign->promoting_tips : '',
    '#description' => variable_get($desc_prefix . 'promoting_tips', ''),
  );
  $form['prep']['locationfinder_id'] = array(
    '#title' => t('I need a location finder'),
    '#type' => 'checkbox',
    '#default_value' => isset($campaign->locationfinder_id) ? $campaign->locationfinder_id : 0,
  );

  // Do It:
  $form['do'] = array(
    '#type' => 'fieldset',
    '#title' => t('Do It'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => variable_get($desc_prefix . 'do', ''),
  );
  $form['do']['step_photo'] = array(
    '#title' => t('Take a Photo Step'),
    '#type' => 'textfield',
    '#default_value' => isset($campaign->step_photo) ? $campaign->step_photo : '',
    '#description' => variable_get($desc_prefix . 'step_photo', ''),
  );

  //@todo: Figure out how to split out these fields.
  field_attach_form('campaign', $campaign, $form, $form_state);

  // Form actions:
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

/**
 * Form constructor for the admin settings for Campaign entity form.
 *
 * @ingroup forms
 */
function dosomething_campaign_admin_settings_form($form, &$form_state) {
  // List all the campaign_form form element names for which we are storing help text for:
  $elements = array(
    'cta_text',
    'do',
    'items_needed',
    'know',
    'people_involved',
    'prep',
    'prep_intro',
    'promoting_tips',
    'season_high_start',
    'season_high_end',
    'season_low_start',
    'season_low_end',
    'stat_problem',
    'stat_problem_source',
    'stat_solution',
    'stat_solution_source',
    'step_photo',
    'timing',
    'time_and_place',
    'title',
    'url_internal_confirm_doc',
    'url_psa',
  );
  // For each element:
  foreach ($elements as $field_name) {
    // Output a textarea to set its coresponding Form Description variable.
    $form[DOSOMETHING_CAMPAIGN_FORM_DESC_PREFIX . $field_name] = array(
      '#title' => $field_name,
      '#type' => 'textarea',
      '#default_value' => variable_get(DOSOMETHING_CAMPAIGN_FORM_DESC_PREFIX . $field_name, ''),
    );
  }
  return system_settings_form($form);
}
