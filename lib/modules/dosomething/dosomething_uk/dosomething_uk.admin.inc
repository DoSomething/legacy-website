<?php

// -----------------------------------------------------------------------
// Forms

/**
 * Provides system settings form for DoSomething UK OAuth integration settings.
 *
 * @return array
 *   The system settings form.
 */
function dosomething_uk_admin_settings() {
  $form = array();

  // Required OAuth setting variables.
  $api_url    = variable_get('dosomething_uk_oauth_url', '');
  $api_key    = variable_get('dosomething_uk_oauth_key', '');
  $api_secret = variable_get('dosomething_uk_oauth_secret', '');

  // Verify if all required OAuth setting variables present.
  $enabled = !empty($api_url) && !empty($api_key) && !empty($api_secret);
  $status_text = $enabled ? t('Enabled') : t('Disabled');

  // Fieldset.
  $form['dosomething_uk_oauth'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('OAuth settings'),
    '#description' => t('Status: %status.', array('%status' => $status_text)),
  );
  $form_oauth = &$form['dosomething_uk_oauth'];

  // Required OAuth setting fields.
  $form_oauth['dosomething_uk_oauth_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('OAuth Host URL'),
    '#default_value' => $api_url,
    '#required'      => TRUE,
    '#attributes'    => array(
      'placeholder' => 'https://api.twitter.com'
    ),
    '#description'   => 'No trailing slash or /oauth path needed.',
  );
  $form_oauth['dosomething_uk_oauth_key'] = array(
    '#type'          => 'textfield',
    '#title'         => t('OAuth Key'),
    '#default_value' => $api_key,
    '#required'      => TRUE,
  );
  $form_oauth['dosomething_uk_oauth_secret'] = array(
    '#type'          => 'textfield',
    '#title'         => t('OAuth Secret'),
    '#default_value' => $api_secret,
    '#required'      => TRUE,
  );

  // Optional OAuth setting fields.
  $api_callback = variable_get('dosomething_uk_oauth_callback', '');
  $form_oauth['dosomething_uk_oauth_callback'] = array(
    '#type'          => 'textfield',
    '#title'         => t('OAuth Callback URL'),
    '#default_value' => $api_callback,
  );

  return system_settings_form($form);
}

// -----------------------------------------------------------------------
