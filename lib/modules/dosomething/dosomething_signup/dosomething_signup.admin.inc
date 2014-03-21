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
  if ($staff_picks) {
    foreach ($staff_picks as $staff_pick) {
      $nid = $staff_pick['nid'];
      $title = $staff_pick['title'];
      $prefix = 'dosomething_signup_nid_' . $nid;
      $mailchimp_grouping_id = $prefix . '_mailchimp_grouping_id';
      $mailchimp_group_name = $prefix . '_mailchimp_group_name';
      $mobilecommons_id = $prefix . '_mobilecommons_id';

      // Create a fieldset for each campaign.
      $form[$nid] = array(
        '#type' => 'fieldset',
        '#title' => $title . ' : NID ' . $nid,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );

      // Each campaign gets a mailchimp grouping_id/group_name & mobilecommons id.
      $form[$nid][$mailchimp_grouping_id] = array(
        '#type' => 'textfield',
        '#title' => t('MailChimp Grouping ID'),
        '#default_value' => variable_get($mailchimp_grouping_id),
        '#description' => t('The numeric Grouping ID that the Group Name belongs to.'),
      );
      $form[$nid][$mailchimp_group_name] = array(
        '#type' => 'textfield',
        '#title' => t('MailChimp Group Name'),
        '#default_value' => variable_get($mailchimp_group_name),
        '#description' => t('The alphanumeric Interest Group name.'),
      );
      $form[$nid][$mobilecommons_id] = array(
        '#type' => 'textfield',
        '#title' => t('Mobile Commons Opt-In Path'),
        '#default_value' => variable_get($mobilecommons_id),
        '#description' => t("The numeric Mobilecommons opt-in path."),
      );
    }
  }

  return system_settings_form($form);
}
