<?php
/**
 * @file
 * Admin page callback for the DoSomething SMS module.
 */

/**
 * Builds and returns the Optimizely Add/Update form.
 * If there are only 3 arguments in the path it builds the add form and it adds a record.
 * Otherwise it builds the update form where the fourth argument is the record ID in
 * in the optimizely table.
 */
function dosomething_sms_settings_form() {

  $form = array();

  $form['configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration of DoSomething.org SMS cron()'),
  );

  $form['configuration']['dosomething_sms_cron_enable'] = array(
    '#type' => 'radios',
    '#title' => t('Cron Status'),
    '#options' => array(
      TRUE => t('Enabled'),
      FALSE => t('Disabled'),
    ),
    '#default_value' => variable_get('dosomething_sms_cron_enable', FALSE),
    '#weight' => 10,
  );

  $form['configuration']['dosomething_sms_cron_interval'] = array(
    '#type' => 'select',
    '#title' => t('Cron interval'),
    '#description' => t('Time after which cron_example_cron will respond to a processing request.'),
    '#default_value' => variable_get('dosomething_sms_cron_interval', 60 * 60 * 24 * 7),
    '#options' => array(
      60 * 60 => t('1 hour'),
      60 * 60 * 24 * 1 => t('1 day'),
      60 * 60 * 24 * 2 => t('2 days'),
      60 * 60 * 24 * 5 => t('5 days'),
      60 * 60 * 24 * 7 => t('1 week'),
      60 * 60 * 24 * 7 * 2 => t('2 weeks'),
      60 * 60 * 24 * 7 * 4 => t('4 weeks'),
    ),
    '#weight' => 20,
  );

  // Where to send the report
  $form['configuration']['dosomething_sms_cron_recipients'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Recipients'),
    '#description' => t('Seperate email addresses with commas.'),
    '#default_value' => variable_get('dosomething_sms_cron_recipients', 'dlee@dosomething.org'),
    '#size' => 60,
    '#maxlength' => 256,
    '#required' => TRUE,
    '#weight' => 30,
  );

  $form['status'] = array(
    '#type' => 'fieldset',
    '#title' => t('DoSomething.org SMS Cron Status'),
  );

  // Run job every interval (week by default)
  $interval = variable_get('dosomething_sms_cron_interval', 60 * 60 * 24 * 7);
  $next_run = variable_get('dosomething_sms_cron_next_execution', REQUEST_TIME);

  $form['status']['dosomething_sms_cron_status'] = array(
    '#type' => 'markup',
    '#markup' => '<ul><li>'. t('The next run is scheduled for '. date('l - j F Y - g:i:s', $next_run)) . '</li>',
  );

  $form['status']['dosomething_sms_cron_test'] = array(
    '#type' => 'markup',
    '#markup' => '<li>'. t('Run ') .'<strong>' . l(t('test cron'), 'admin/config/dosomething/dosomething_sms/cron_test') . '</strong>'. t(' job.') .'</li></ul>',
  );

  return system_settings_form($form);

}
