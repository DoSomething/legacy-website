<?php

/**
 * @file
 * Module settings UI.
 */

/**
 * Configuration form
 */
function dosomething_mbp_config_form($form, &$form_state) {

  if ($templates = dosomething_mbp_templates(varable_get('message_broker_producer_application_id', '')) == '') {
    drupal_set_message('WARNING: The current application ID is
      undefined. Typically this would be the country code for the affiliate
      site or "US" for the United States. Update the value on the ', 'error');
  }
  else {

    $form['dosomething_mbp_log'] = array(
      '#type' => 'checkbox',
      '#title' => t('Log Message Broker Producer requests.'),
      '#default_value' => variable_get('dosomething_mbp_log', FALSE),
      '#description' => t("This should be disabled on production."),
    );

    $form['dosomething_mbp_templates'] = array(
      '#type' => 'fieldset',
      '#title' => t('Transactional Templates')
    );

    $current_application_markup = t('Current Application ID: ') . variable_get('message_broker_producer_application_id', '') . t(' as defined in the message_broker_producer') . l(t('Producer Configuration settings.'), 'admin/config/services/message-broker-producer/mq-settings') . t(' Producer Configuration settings.');
    $form['dosomething_mbp_templates']['dosomething_mbp_current_application'] = array(
      '#markup' => $current_application_markup,
    );

    $user_registration_template = variable_get('dosomething_mbp_user_registration_template', '');
    $form['dosomething_mbp_templates']['dosomething_mbp_template_selection'] = array(
      '#type' => 'select',
      '#title' => t('User Registration'),
      '#options' => $templates['select'],
      '#default_value' => $user_registration_template,
      '#description' => 'The Mandrill template to use for User Registration.',
      '#required' => TRUE,
      '#weight' => 60,
    );

  }

  return system_settings_form($form);
}

/**
 * Format template data for presentation based on returned values from Mandrill.
 *
 * @parm string $application_ID
 *   Defined in message_broker_producer, a unique identifier of the site.
 */
function dosomething_mbp_templates($application_ID) {

  $template_data = dosomething_mbp_get_template_data($application_ID);

  foreach ($template_data as $template_slug => $template_details) {
    $templates['select'][$template_slug] = $template_details['name'];
  }

  return $templates;
}

/**
 * Gather Mandrill template details with the label specific to the affiliate
 * (target_ID).
 *
 * @parm string $application_ID
 *   Defined in message_broker_producer, a unique identifier of the site.
 */
function dosomething_mbp_get_template_data($application_ID) {

  $templates = array();

  // https://mandrillapp.com/api/docs/templates.JSON.html#method=list
  // https://mandrillapp.com/api/1.0/templates/list.json
  // "label": "example-label"

  // @todo: Include "US" in the message-broker-affiliate-<US> labeled templates
  $params = array('label' => "message-broker-affiliate-{$application_ID}");
  $mandill_templates = dosomething_mbp_mandrill_curl('/templates/list', $params);

  foreach ($mandill_templates as $mandill_template) {
    $templates[$mandill_template->slug] = array(
      'name' => $mandill_template->name,
      'subject' => $mandill_template->subject,
      'from_email' => $mandill_template->from_email,
      'from_name' => $mandill_template->from_name,
      'updated_at' => $mandill_template->updated_at,
    );
  }

  return $templates;
}

/**
 * Gather existing Mandrill templates and format results to be used in Drupal
 * seleciton form element.
 *
 * @parm array $form
 *   Array of form elements.
 * @returns array &$form_state
 *   Array of the state of the form elements.
 */
function dosomething_mbp_mandrill_curl($api_endpoint, $params) {

  $base_mandrill_url = 'http://mandrillapp.com/api/1.0';
  // Define return format
  $api_endpoint .= 'json';
  if ($key = get_variable('dosomething_mbp_mandrill_key', '') != '') {

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
    drupal_set_message('Mandrill key not set.', 'error');
  }

  return $decoded;
}
