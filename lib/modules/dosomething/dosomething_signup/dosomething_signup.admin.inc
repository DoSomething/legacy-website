<?php

/**
 * @file
 * Admin config form settings.
 */

/**
 * Settings form third party opt-in ids.
 */
function dosomething_signup_optin_config($form, &$form_state) {
  $form = array();

  // Main campaign/ds general ids.
  $form['dosomething_mobilecommons_general'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Commons General Opt-In'),
    '#default_value' => variable_get('dosomething_mobilecommons_general'),
  );

  $form['dosomething_mobilecommons_campaign_general'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Commons Campaigns Opt-In'),
    '#default_value' => variable_get('dosomething_mobilecommons_campaign_general'),
  );

  // Each staff pick could have a special opt-in for third party communications.
  $staff_picks = dosomething_campaign_get_staff_picks();
  foreach ($staff_picks as $staff_pick) {
    $nid = $staff_pick['nid'];
    $title = $staff_pick['title'];
    // Create a fieldset for each campaign.
    $form[$nid] = array(
      '#type' => 'fieldset',
      '#title' => $title . ' : ' . $nid,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    // Each campagin gets a mailchimp & mobile commons id.
    $form[$nid]['dosomething_mailchimp_id_' . $nid] = array(
      '#type' => 'textfield',
      '#title' => t('MailChimp Group'),
      '#default_value' => variable_get('dosomething_mailchimp_id_' . $nid, ''),
    );
    $form[$nid]['dosomething_mobilecommons_id_' . $nid] = array(
      '#type' => 'textfield',
      '#title' => t('Mobile Commpns Opt-In'),
      '#default_value' => variable_get('dosomething_mobilecommons_id_' . $nid, ''),
    );
  }

  return system_settings_form($form);
}