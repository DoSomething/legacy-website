<?php

/**
 * @file
 * Module settings UI.
 */

/**
 * Configuration form
 */
function dosomething_mbp_config_form($form, &$form_state) {

  $form['configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Producer Configuration')
  );
  $form['configuration']['message_broker_producer_application_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Application ID'),
    '#required' => TRUE,
    '#default_value' => variable_get('message_broker_producer_application_id', -1),
  );
  $form['configuration']['dosomething_mbp_mandrill_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Mandrill Key'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_mbp_mandrill_key', ''),
  );

  if (variable_get('message_broker_producer_application_id', -1) == -1) {
    drupal_set_message('The current application ID is undefined. Typically this
      would be the country code for the affiliate site or "US" for the United
      States. Update the value on the ' . l('message_broker_producer', 'admin/config/services/message-broker-producer/mq-settings') .
      ' module or below.', 'error');
  }
  else {

    if (($mandrill_templates = dosomething_mbp_get_mandrill_template_options(variable_get('message_broker_producer_application_id', -1))) == -1) {
      drupal_set_message('Templates assigned to the "' . variable_get('message_broker_producer_application_id') .
        '" country code in Mandrill were not found. Create templates for each of
        the transaction types (User Registration, Password Rest, Campaign Signup
        and Campaign Reportback.',
        'error');
    }
    else {

      $form['configuration']['dosomething_mbp_log'] = array(
        '#type' => 'checkbox',
        '#title' => t('Log Message Broker Producer requests.'),
        '#default_value' => variable_get('dosomething_mbp_log', FALSE),
        '#description' => t("This should be disabled on production."),
      );
      $form['dosomething_mbp_templates'] = array(
        '#type' => 'fieldset',
        '#title' => t('Transactional Templates')
      );
      $current_application_markup = t('Current Application ID: "') . variable_get('message_broker_producer_application_id', '') . t('" as defined in the message_broker_producer') . l(t('Producer Configuration settings.'), 'admin/config/services/message-broker-producer/mq-settings') . t(' Producer Configuration settings or above in the configuration settings.');
      $form['dosomething_mbp_templates']['dosomething_mbp_current_application'] = array(
        '#markup' => $current_application_markup,
      );
      $form['dosomething_mbp_templates']['dosomething_mbp_user_register_template'] = array(
        '#type' => 'select',
        '#title' => t('User Registration'),
        '#empty_option' =>t('-- Select Mandrill Template --'),
        '#options' => $mandrill_templates['select'],
        '#default_value' => variable_get('dosomething_mbp_user_register_template') . '_' . variable_get('message_broker_producer_application_id'),
        '#description' => 'The Mandrill template to use for User Registration transactional messages.',
        '#required' => TRUE,
        '#weight' => 70,
      );
      $form['dosomething_mbp_templates']['dosomething_mbp_user_password_template'] = array(
        '#type' => 'select',
        '#title' => t('Password Reset'),
        '#options' => $mandrill_templates['select'],
        '#default_value' => variable_get('dosomething_mbp_user_password_template', '') . '_' . variable_get('message_broker_producer_application_id'),
        '#description' => 'The Mandrill template to use for Password Reset transactional messages.',
        '#required' => TRUE,
        '#weight' => 80,
      );
      $form['dosomething_mbp_templates']['dosomething_mbp_campaign_signup_template'] = array(
        '#type' => 'select',
        '#title' => t('Campaign Signup'),
        '#empty_option' =>t('-- Select Mandrill Template --'),
        '#options' => $mandrill_templates['select'],
        '#default_value' => variable_get('dosomething_mbp_campaign_signup_template') . '_' . variable_get('message_broker_producer_application_id'),
        '#description' => 'The Mandrill template to use for Campaign Signup transactional messages.',
        '#required' => TRUE,
        '#weight' => 90,
      );
      $form['dosomething_mbp_templates']['dosomething_mbp_campaign_group_signup_template'] = array(
        '#type' => 'select',
        '#title' => t('Campaign Group Signup'),
        '#empty_option' =>t('-- Select Mandrill Template --'),
        '#options' => $mandrill_templates['select'],
        '#default_value' => variable_get('dosomething_mbp_campaign_group_signup_template', '') . '_' . variable_get('message_broker_producer_application_id'),
        '#description' => 'The Mandrill template to use for Campaign Group Signup transactional messages.',
        '#required' => TRUE,
        '#weight' => 90,
      );
      $form['dosomething_mbp_templates']['dosomething_mbp_campaign_reportback_template'] = array(
        '#type' => 'select',
        '#title' => t('Campaign Reportback'),
        '#empty_option' =>t('-- Select Mandrill Template --'),
        '#options' => $mandrill_templates['select'],
        '#default_value' => variable_get('dosomething_mbp_campaign_reportback_template') . '_' . variable_get('message_broker_producer_application_id'),
        '#description' => 'The Mandrill template to use for Campaign Reportback transactional messages.',
        '#required' => TRUE,
        '#weight' => 100,
      );
    }

  }

  return system_settings_form($form);
}

/**
 * Format template data for presentation based on returned values from Mandrill.
 *
 * @parm string $application_id
 *   Defined in message_broker_producer, a unique identifier of the site.
 */
function dosomething_mbp_get_mandrill_template_options($application_id) {

  $template_data = dosomething_mbp_get_template_data($application_id);

  if (count($template_data) > 0) {
    foreach ($template_data as $template_slug => $template_details) {
      $mandrill_templates['select'][$template_slug] = $template_details['name'];
    }
  }
  else {
    $mandrill_templates = -1;
  }

  return $mandrill_templates;
}

/**
 * Gather Mandrill template details with the label specific to the affiliate
 * (target_ID).
 *
 * @parm string $application_id
 *   Defined in message_broker_producer, a unique identifier of the site.
 */
function dosomething_mbp_get_template_data($application_id) {

  $templates = array();

  // https://mandrillapp.com/api/docs/templates.JSON.html#method=list
  // https://mandrillapp.com/api/1.0/templates/list.json
  // "label": "example-label"

  // @todo: Include "US" in the message-broker-affiliate-<US> labeled templates
  $params = array('label' => "message-broker-affiliate-{$application_id}");

  $mandill_templates = dosomething_mbp_mandrill_curl('/templates/list', $params);

  if (count($mandill_templates) > 0) {
    foreach ($mandill_templates as $mandill_template) {
      $templates[$mandill_template->slug] = array(
        'name' => $mandill_template->name,
        'subject' => $mandill_template->subject,
        'from_email' => $mandill_template->from_email,
        'from_name' => $mandill_template->from_name,
        'updated_at' => $mandill_template->updated_at,
      );
    }
  }
  else {
    drupal_set_message('dosomething_mbp_get_template_data - Mandrill templates not found.', 'error');
  }

  return $templates;
}

/**
 * Gather existing Mandrill templates and format results to be used in Drupal
 * selection form element.
 *
 * @parm array $form
 *   Array of form elements.
 * @returns array &$form_state
 *   Array of the state of the form elements.
 */
function dosomething_mbp_mandrill_curl($api_endpoint, $params) {

  $decode = array();
  $base_mandrill_url = 'http://mandrillapp.com/api/1.0';
  // Define return format
  $api_endpoint .= '.json';

  if (($key = variable_get('dosomething_mbp_mandrill_key', '')) != '') {

    $params = array_merge($params, array('key' => $key));
    $json = json_encode($params);

    // Send request to Mandrill API
    $ch = curl_init();
    curl_setopt($ch,CURLOPT_URL, "{$base_mandrill_url}{$api_endpoint }");
    curl_setopt($ch,CURLOPT_POST, count($params));
    curl_setopt($ch,CURLOPT_POSTFIELDS, $json);
    curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "POST");
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type: application/json','Content-Length: ' . strlen($json)));
    $result = curl_exec($ch);
    curl_close($ch);
    $decoded = json_decode($result);
  }
  else {
    drupal_set_message('dosomething_mbp_mandrill_curl - Mandrill key not set.', 'error');
  }

  return $decoded;
}
