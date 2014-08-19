<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for DoSomething Signup specific variables.
 */
function dosomething_reward_admin_config_form($form, &$form_state) {

  $form['rb_count'] = array(
    '#type' => 'fieldset',
    '#title' => t('Reportback Count'),
    '#collapsible' => TRUE,
  );
  $var_name = 'dosomething_reward_enable_reportback_count';
  $form['rb_count'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Reportback Count Rewards'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("When checked, users can earn a Reportback Count Reward."),
  );
  $form['rb_count']['page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Redeem Page'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['rb_count']['form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Redeem Form'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $var_name = 'dosomething_reward_redeem_page_header';
  $form['rb_count']['page'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Redeem Page Header'),
    '#description' => t("Redeem Page content header."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_page_copy';
  $form['rb_count']['page'][$var_name] = array(
    '#type' => 'textarea',
    '#title' => t('Redeem Page Copy'),
    '#description' => t("Redeem Page content copy."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_page_image';
  $form['rb_count']['page'][$var_name] = array(
    '#type' => 'entity_autocomplete',
    '#title' => t('Redeem Page Image'),
    '#description' => t("Redeem Page content image."),
    '#entity_type' => 'node',
    '#bundles' => array('image'),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_link';
  $form['rb_count']['page'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Redeem Form Link Text'),
    '#description' => t("Link text that opens the Redeem Form modal."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_header';
  $form['rb_count']['form'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Redeem Form Header'),
    '#description' => t("Header text of the Redeem Form modal."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_copy';
  $form['rb_count']['form'][$var_name] = array(
    '#type' => 'textarea',
    '#rows' => 4,
    '#title' => t('Redeem Form Copy'),
    '#description' => t("Copy displayed in the Redeem Form modal."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_button_text';
  $form['rb_count']['form'][$var_name] = array(
    '#type' => 'textfield',
    '#title' => t('Redeem Form Button Label'),
    '#description' => t("Label displayed on the Redeem Form submit button."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $var_name = 'dosomething_reward_redeem_form_confirm_msg';
  $form['rb_count']['form'][$var_name] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Redeem Form Confirmation Message'),
    '#description' => t("Message displayed after submitting the Redeem Form."),
    '#required' => TRUE,
    '#default_value' => variable_get($var_name),
  );

  $form['log'] = array(
    '#type' => 'fieldset',
    '#title' => t('Logging'),
  );
  $var_name = 'dosomething_reward_log';
  $form['log'][$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Rewards.'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("Logs Reward activity. This should be disabled on production."),
  );

  return system_settings_form($form);
}
