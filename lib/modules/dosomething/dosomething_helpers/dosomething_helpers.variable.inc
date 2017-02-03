<?php

/**
 * @file
 * Code for Dosomething Helpers variable functionality.
 */

function dosomething_helpers_variable_form($form, &$form_state, $node) {
  $vars = dosomething_helpers_get_variables('node', $node->nid);

  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $node->nid,
  );
  $form['custom_social_sharing'] = [
    '#type' => 'fieldset',
    '#title' => t('Custom Social Sharing'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];
  $form['custom_social_sharing']['social_share_unique_link'] = [
    '#type' => 'checkbox',
    '#title' => t('Create unique social share links for each user.'),
    '#description' => t("If set, unique social share links will be created using user's id."),
    '#default_value' => $vars['social_share_unique_link'],
  ];
  $form['custom_social_sharing']['social_share_custom_text'] = [
    '#type' => 'textfield',
    '#title' => t('Custom social share language'),
    '#description' => t("Custom text to share with the social links."),
    '#default_value' => $vars['social_share_custom_text'],
    '#attributes' => array(
      'maxlength' => '140',
    ),
  ];
  $form['custom_social_sharing']['social_share_custom_description'] = [
    '#type' => 'textarea',
    '#title' => t('Custom social share description'),
    '#description' => t("Custom description to share with social links."),
    '#default_value' => $vars['social_share_custom_description'],
    '#size' => 20,
  ];
  $form['custom_social_sharing']['share_image_nid'] = [
    '#type' => 'textfield',
    '#title' => t('Photo nid'),
    '#description' => t("The nid of the photo to be shared on social media. After you upload a photo, you will be redirected to a url like dosomething.org/image/2480. The final number is the nid (2480 in this example)."),
    '#default_value' => $vars['share_image_nid'],
    '#attributes' => array(
      'maxlength' => '140',
    ),
  ];
  $form['custom_social_sharing']['custom_facebook_copy'] = [
    '#type' => 'textarea',
    '#title'=> t('Custom Facebook copy'),
    '#description' => t("Custom Facebook copy to populate Facebook share. If blank, copy will default to the problem statement."),
    '#default_value' => $vars['custom_facebook_copy'],
    '#size' => 20,
  ];
  $form['custom_social_sharing']['custom_twitter_copy'] = [
    '#type' => 'textfield',
    '#title' => t('Custom Twitter copy'),
    '#description' => t("Custom Twitter copy to populate Twitter share. If blank, copy will default to the problem statement."),
    '#default_value' => $vars['custom_twitter_copy'],
    '#attributes' => [
      'maxlength' => '140',
    ],
  ];
  $form['custom_social_sharing']['custom_tumblr_copy'] = [
    '#type' => 'textarea',
    '#title'=> t('Custom Tumblr copy'),
    '#description' => t("Custom Tumblr copy to populate Tumblr share. If blank, copy will default to the problem statement."),
    '#default_value' => $vars['custom_tumblr_copy'],
    '#size' => 20,
  ];
  $form['custom_social_sharing']['show_social_share_link'] = [
    '#type' => 'checkbox',
    '#title' => t('Visible custom social share link'),
    '#default_value' => $vars['show_social_share_link'],
    '#description' => t('If checked, the custom social share link will be visible in a gray padded box for the user to copy and paste.'),
  ];
  $form['styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Styles'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['styles']['sponsor_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Sponsor color'),
    '#description' => t('Hex color value for sponsor brand to apply to headings.'),
    '#default_value' => $vars['sponsor_color'],
    '#field_prefix' => '#',
    '#size' => 6,
    '#attributes' => array(
      'maxlength' => '6',
    ),
  );
  $form['styles']['alt_background_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Alternate background color'),
    '#description' => t('Hex color value to use as background color for <strong>Prove It</strong> section (or <strong>Do It</strong> section on SMS).'),
    '#default_value' => $vars['alt_background_color'],
    '#field_prefix' => '#',
    '#size' => 6,
    '#attributes' => array(
      'maxlength' => '6',
    ),
  );
  $form['styles']['alt_text_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Alternate text color'),
    '#description' => t('Hex color value to use as text color for <strong>Prove It</strong> section (or <strong>Do It</strong> section on SMS).'),
    '#default_value' => $vars['alt_text_color'],
    '#field_prefix' => '#',
    '#size' => 6,
    '#attributes' => array(
      'maxlength' => '6',
    ),
  );
  $form['styles']['alt_image_campaign_cover_nid'] = array(
    //@todo: Node reference autocomplete.
    '#type' => 'textfield',
    '#title' => t('Alternate header image nid'),
    '#description' => t('An Image Node nid to display in the page header.'),
    '#default_value' => $vars['alt_image_campaign_cover_nid'],
    '#size' => 6,
  );
  $form['styles']['signup_form_submit_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Signup form button label'),
    '#description' => t('Overrides the label on the Signup Form button.'),
    '#default_value' => $vars['signup_form_submit_label'],
    '#size' => 20,
  );
  if (module_exists('dosomething_shipment')) {
    $form['shipment'] = array(
      '#type' => 'fieldset',
      '#title' => t('Shipment Form'),
      '#description' => t("If set, a modal is provided to create a User Shipment for this node."),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['shipment']['shipment_item'] = array(
      '#type' => 'select',
      '#title' => t('Select Shipment Item'),
      '#options' => dosomething_shipment_get_item_options(),
      '#empty_option' => '',
      '#default_value' => $vars['shipment_item'],
    );
    $form['shipment']['shipment_form_link_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Shipment Form Link Text'),
      '#default_value' => $vars['shipment_form_link_text'],
      '#size' => 20,
    );
    $form['shipment']['shipment_form_header'] = array(
      '#type' => 'textfield',
      '#title' => t('Shipment Form Header'),
      '#default_value' => $vars['shipment_form_header'],
      '#size' => 20,
    );
    $form['shipment']['shipment_form_copy'] = array(
      '#type' => 'textarea',
      '#title' => t('Shipment Form Copy'),
      '#default_value' => $vars['shipment_form_copy'],
      '#size' => 20,
    );
    $form['shipment']['shipment_form_submit_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Submit Button Label'),
      '#default_value' => $vars['shipment_form_submit_label'],
      '#size' => 20,
    );
    $form['shipment']['shipment_form_confirm_msg'] = array(
      '#type' => 'textarea',
      '#title' => t('Confirmation Message'),
      '#default_value' => $vars['shipment_form_confirm_msg'],
      '#size' => 20,
    );
    $form['shipment']['shipment_form_submitted_copy'] = array(
      '#type' => 'textarea',
      '#title' => t('Form Submitted Copy'),
      '#default_value' => $vars['shipment_form_submitted_copy'],
      '#size' => 20,
    );
    $form['shipment']['shipment_form_prevent_old_people_submit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Prevent Old People from submitting'),
      '#default_value' => $vars['shipment_form_prevent_old_people_submit'],
      '#description' => t('If checked, Old People will be unable to submit the form.'),
    );
    $form['shipment']['shipment_form_old_people_copy'] = array(
      '#type' => 'textarea',
      '#title' => t('Old People Copy'),
      '#default_value' => $vars['shipment_form_old_people_copy'],
      '#description' => t('The copy displayed in the modal form for Old People.'),
      '#states' => array(
        'visible' => array(
          ':input[name="shipment_form_prevent_old_people_submit"]' => array('checked' => TRUE),
        ),
      ),
    );
  }

  // Magic Link
  $form['magic_link'] = [
    '#type' => 'fieldset',
    '#title' => t('Magic Link'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];
  $form['magic_link']['magic_link_copy'] = [
    '#type' => 'textfield',
    '#title' => t('Magic Link Copy'),
    '#description' => t('Custom text to explain the magic link. The magic link will bring the user to the web version of the site and log them in automatically.'),
    '#default_value' => $vars['magic_link_copy'],
    '#attributes' => array(
      'maxlength' => '140',
    ),
  ];

  // Onboarding
  $form['onboarding'] = [
    '#type' => 'fieldset',
    '#title' => t('Onboarding'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];
  $form['onboarding']['disable_onboarding'] = [
    '#type' => 'checkbox',
    '#title' => t('Disable onboarding'),
    '#description' => t('Suggested for campaigns with irregular signup process like voter reg.'),
    '#default_value' => $vars['disable_onboarding']
  ];

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => 'Save',
    ),
  );

  // Affiliate Configurations
  $form['affiliate_configurations'] = [
    '#type' => 'fieldset',
    '#title' => t('Affiliate Configurations'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];
  $form['affiliate_configurations']['messaging_opt-in'] = [
    '#type' => 'fieldset',
    '#title' => t('Messaging Opt-in'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];
  $affiliate_form = &$form['affiliate_configurations']['messaging_opt-in'];

  $affiliate_form['affiliate_opt_in_toggle'] = [
    '#type' => 'checkbox',
    '#title' => t('Affiliate Opt-in enabled?'),
    '#default_value' => $vars['affiliate_opt_in_toggle'],
    '#description' => t('If checked, this campaign shows a toggle for adding a user to affiliate marketing emails when signing up.'),
    '#disabled' => FALSE,
  ];
  $affiliate_form['affiliate_opt_in_toggle_label'] = [
    '#type' => 'textfield',
    '#title' => t('Affiliate Opt-in Checkbox Toggle Label'),
    '#default_value' => $vars['affiliate_opt_in_toggle_label'] ? $vars['affiliate_opt_in_toggle_label'] : 'Also sign me up for messages from our partner',
    '#description' => t('The copy to show next to the checkbox.'),
    '#disabled' => FALSE,
  ];
  $affiliate_form['affiliate_opt_in_toggle_information_label'] = [
    '#type' => 'textfield',
    '#title' => t('Affiliate Opt-in More Information Label'),
    '#default_value' => $vars['affiliate_opt_in_toggle_information_label'],
    '#description' => t('The copy to indicate the "more information" link.'),
    '#disabled' => FALSE,
  ];
  $affiliate_form['affiliate_opt_in_toggle_information_message'] = [
    '#type' => 'textarea',
    '#title' => t('Affiliate Opt-in More Information Message'),
    '#default_value' => $vars['affiliate_opt_in_toggle_information_message'],
    '#description' => t('The copy to explain what the affiliate opt-in is for.'),
    '#disabled' => FALSE,
  ];

  return $form;
}

function dosomething_helpers_variable_form_submit(&$form, &$form_state) {
  // List of fields that should be sanitized.
  $fields_to_sanitize = array(
    'sponsor_color',
    'alt_background_color',
    'alt_text_color',
  );

  form_state_values_clean($form_state);
  $values = $form_state['values'];

  // Store hidden nid.
  $nid = $values['nid'];
  // Remove from values.
  unset($values['nid']);

  foreach($fields_to_sanitize as $field) {
    if (array_key_exists($field, $values)) {
      strip_tags($values[$field]);
    }
  }
  // Loop through all remaining values:
  foreach ($values as $name => $value) {
    // Save to the variable table.
    dosomething_helpers_set_variable('node', $nid, $name, $value);
  }
  drupal_set_message("Updated.");
}

/**
 * Returns array of all variable names.
 */
function dosomething_helpers_get_variable_names() {
  return [
    'alt_bg_fid',
    'sponsor_color',
    'affiliate_opt_in_toggle',
    'affiliate_opt_in_toggle_label',
    'affiliate_opt_in_toggle_information_label',
    'affiliate_opt_in_toggle_information_message',
    'alt_background_color',
    'alt_text_color',
    'alt_image_campaign_cover_nid',
    'collect_num_participants',
    'count_approved',
    'count_excluded',
    'count_flagged',
    'count_pending',
    'count_promoted',
    'custom_facebook_copy',
    'custom_tumblr_copy',
    'custom_twitter_copy',
    'disable_onboarding',
    'enable_voter_registration',
    'magic_link_copy',
    'mobilecommons_opt_in_path',
    'mobilecommons_friends_opt_in_path',
    'progress',
    'registration_form_copy',
    'share_image_nid',
    'shipment_form_confirm_msg',
    'shipment_form_copy',
    'shipment_form_header',
    'shipment_form_link_text',
    'shipment_form_old_people_copy',
    'shipment_form_prevent_old_people_submit',
    'shipment_form_submit_label',
    'shipment_form_submitted_copy',
    'shipment_item',
    'show_social_share_link',
    'signup_count',
    'signup_form_submit_label',
    'sms_game_mp_story_id',
    'sms_game_mp_story_type',
    'social_share_custom_description',
    'social_share_custom_text',
    'social_share_unique_link',
  ];
}

/**
 * Returns array of all dosomething_helper_variable records for a given $node.
 *
 * @return array
 *   Keyed by the variable name.
 */
function dosomething_helpers_get_variables($entity_type, $entity_id) {
  // Initialize array with NULL defaults.
  foreach (dosomething_helpers_get_variable_names() as $name) {
    $vars[$name] = NULL;
  }
  // Query for variable records for given $node.
  $result = db_select('dosomething_helpers_variable', 'v')
    ->fields('v')
    ->condition('entity_id', $entity_id)
    ->condition('entity_type', $entity_type)
    ->execute()
    ->fetchAll();
  foreach ($result as $record) {
    $vars[$record->name] = $record->value;
  }
  return $vars;
}

/**
 * Returns value of given $nid's $name variable.
 *
 * @return
 *   String if variable exists, FALSE if not.
 */
function dosomething_helpers_get_variable($entity_type, $entity_id, $var_name) {
  return db_select('dosomething_helpers_variable', 'v')
    ->fields('v', array('value'))
    ->condition('entity_id', $entity_id)
    ->condition('entity_type', $entity_type)
    ->condition('name', $var_name)
    ->execute()
    ->fetchField(0);
}

/**
 * Sets a given dosomething_helper variable $name to $value for given $node.
 *
 * @param string $entity_type
 *   The type of entity to store a value for, e.g. "node", "taxonomy_term"
 * @param int $entity_id
 *   The primary identifier of the entity.
 * @param string $var_name
 *   The name of the variable to store for the entity.
 * @param mixed $value
 *   The value to save for the variable. Will be stored as a string.
 */
function dosomething_helpers_set_variable($entity_type, $entity_id, $var_name, $value) {
  // If a value is present:
  if (!empty($value) || $value === 0) {
    db_merge('dosomething_helpers_variable')
        ->key(array(
            'entity_type' => $entity_type,
            'entity_id' => $entity_id,
            'name' => $var_name,
          ))
        ->fields(array(
            'entity_type' => $entity_type,
            'entity_id' => $entity_id,
            'name' => $var_name,
            'value' => $value,
           ))
        ->execute();
  }
  // Else delete the value, to prevent storing an empty value.
  else {
    db_delete('dosomething_helpers_variable')
      ->condition('entity_id', $entity_id)
      ->condition('entity_type', $entity_type)
      ->condition('name', $var_name)
      ->execute();
  }
}

/**
 * Export form for designating data to be exported.
 */
function dosomething_helpers_exports_form($form, &$form_state, $node) {
  $campaign = Campaign::get($node->nid);

  $form['exports'] = [
    '#type' => 'fieldset',
    '#title' => t('Exports'),
    '#description' => t('Export data associated with this campaign.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];
  $form['exports']['export_affiliate_messaging_optins'] = [
    '#type' => 'checkbox',
    '#title' => t('Export CSV of users that opted to receive affiliate messaging.'),
    '#default_value' => FALSE,
  ];
  $form['campaign_title'] = array(
    '#type' => 'hidden',
    '#value' => $campaign->title,
    '#access' => TRUE,
  );
  $form['campaign_id'] = array(
    '#type' => 'hidden',
    '#value' => $campaign->id,
    '#access' => TRUE,
  );
  $form['campaign_run_id'] = array(
    '#type' => 'hidden',
    '#value' => $campaign->campaign_runs['current']['en']['id'],
    '#access' => TRUE,
  );
  $form['exports']['actions'] = [
    '#type' => 'actions',
    'submit' => [
      '#type' => 'submit',
      '#value' => 'Export',
    ],
  ];

  return $form;
}

/**
 * Export form submit handler.
 * @todo form added, but functionality is forthcoming... stay tuned!
 */
function dosomething_helpers_exports_form_submit(&$form, &$form_state) {
  $data = [];
  $values = $form_state['values'];

  if ($values['export_affiliate_messaging_optins']) {
    $fields = ['campaign_id', 'campaign_run_id', 'northstar_id', 'first_name', 'email', 'mobile'];

    $data['affiliate_messaging_optins']['filename'] = 'Messaging Optins For '.$values['campaign_title'].'.csv';

    $data['affiliate_messaging_optins']['column_names'] = $fields;

    $data['affiliate_messaging_optins']['items'] = db_select('dosomething_campaign_affiliate_opt_ins', 'optins')
      ->fields('optins', $fields)
      ->condition('campaign_id', $values['campaign_id'])
      ->condition('campaign_run_id', $values['campaign_run_id'])
      ->execute()
      ->fetchAll();
  }

  if ($data) {
    // Selected data will export as CSV and process exit()s.
    dosomething_helpers_export_csv($data);
  }

  form_set_error('dosomething_helpers_export_error', 'Please make sure to select one or more items to export!');
}

/**
 * Displays a node's relevant signup variables.
 */
function dosomething_helpers_third_party_variable_form($form, &$form_state, $node) {
  $nid = $node->nid;
  $form['optins'] = array(
    '#type' => 'fieldset',
    '#title' => t('Third Party Service Opt-ins'),
    '#description' => t('Custom campaign opt-in values.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // SMS Games have different variables.
  if (dosomething_campaign_get_campaign_type($node) == 'sms_game') {
    $value = dosomething_helpers_get_variable('node', $nid, 'mobilecommons_opt_in_path');
    $form['optins']['mobilecommons'] = array(
      '#type' => 'textfield',
      '#title' => t('Mobilecommons Alpha Opt-in Path'),
      '#default_value' => $value,
      '#disabled' => TRUE,
    );
    $value = dosomething_helpers_get_variable('node', $nid, 'mobilecommons_friends_opt_in_path');
    $form['optins']['mobilecommons_friends'] = array(
      '#type' => 'textfield',
      '#title' => t('Mobilecommons Beta Opt-in Path'),
      '#default_value' => $value,
      '#disabled' => TRUE,
    );
  }
  else {
    $value = dosomething_helpers_get_variable('node', $nid, 'mailchimp_grouping_id');
    $form['optins']['mailchimp_grouping_id'] = array(
      '#type' => 'textfield',
      '#title' => t('MailChimp Grouping ID'),
      '#default_value' => $value,
      '#disabled' => TRUE,
    );
    $value = dosomething_helpers_get_variable('node', $nid, 'mailchimp_group_name');
    $form['optins']['mailchimp_group_name'] = array(
      '#type' => 'textfield',
      '#title' => t('MailChimp Group Name'),
      '#default_value' => $value,
      '#disabled' => TRUE,
    );
    $value = dosomething_helpers_get_variable('node', $nid, 'mobilecommons_opt_in_path');
    $form['optins']['mobilecommons'] = array(
      '#type' => 'textfield',
      '#title' => t('MobileCommons Opt-in Path'),
      '#default_value' => $value,
      '#disabled' => TRUE,
    );
  }

  // No submit button, this is a read only form.
  return $form;
}
