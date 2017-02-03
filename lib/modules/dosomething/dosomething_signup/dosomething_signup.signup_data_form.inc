<?php
/**
 * @file
 * Code for dosomething_signup_data_form functionality.
 */
define('DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN', '[submitted]');

/**
 * Returns the dosomething_signup_data_form values for a given $nid.
 *
 * @param int $nid
 *   The node nid of the signup_data_form record to check.
 *
 * @return mixed
 *   An array of the signup data form values if exists, NULL if doesn't exist.
 */
function dosomething_signup_get_signup_data_form_info($nid) {
  return db_select('dosomething_signup_data_form', 's')
    ->fields('s')
    ->condition('nid', $nid)
    ->execute()
    ->fetchAssoc();
}

/**
 * Form constructor to configure a signup_data_form for a given $node.
 *
 * @param object $node
 *   The loaded node to save the signup data form configuration for.
 */
function dosomething_signup_node_signup_data_form($form, &$form_state, $node) {
  $nid = $node->nid;
  $values = dosomething_signup_get_signup_data_form_info($nid);
  $fieldset = 'signup_data_form';
  $prefix = $fieldset . '_';
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );
  $form[$fieldset] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup Data Form'),
    '#weight' => 60,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form[$fieldset][$prefix . 'status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect additional signup data'),
    '#default_value' => $values['status'],
  );
  $form[$fieldset]['config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration'),
    '#weight' => 60,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    // Config fieldset should only be visible if the status field is checked.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'status"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config'][$prefix . 'required'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prompt after signup'),
    '#default_value' => $values['required'],
    '#description' => t('If checked, the form modal will be displayed after the user first signs up.'),
  );
  $form[$fieldset]['config'][$prefix . 'competition_signup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Competition Signup'),
    '#default_value' => $values['competition_signup'],
    '#description' => t('If checked, when the user submits this form, they will be entered into a competition'),
  );
  $form[$fieldset]['config'][$prefix . 'required_allow_skip'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow skip'),
    '#default_value' => $values['required_allow_skip'],
    '#description' => t('If checked, the form modal will provide a Skip button when the user is first prompted.'),
    // Should only be visible if form is required.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'required"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config'][$prefix . 'prevent_old_people_submit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent Old People from submitting'),
    '#default_value' => $values['prevent_old_people_submit'],
    '#description' => t('If checked, Old People will be unable to submit the form.'),
  );
  $form[$fieldset]['config'][$prefix . 'old_people_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Old People copy'),
    '#default_value' => $values['old_people_copy'],
    '#description' => t('The copy displayed in the modal form for Old People.'),
    // Should only be visible if old peeps can't submit.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'prevent_old_people_submit"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config'][$prefix . 'custom_social_share_signup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Custom Share Modal'),
    '#default_value' => $values['custom_social_share_signup'],
    '#description' => t('If checked, the custom social share modal will be enabled after a user signs up.'),
  );
  $form[$fieldset]['config'][$prefix . 'link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => $values['link_text'],
    '#description' => t('This is label of the link in "Stuff You Need" which opens the form modal.'),
  );
  $form[$fieldset]['config'][$prefix . 'submit_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Submit Button Text'),
    '#default_value' => $values['submit_text'],
    '#description' => t('This will be used as the label of the submit button.'),
  );
  $form[$fieldset]['config'][$prefix . 'skip_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Skip button text'),
    '#default_value' => $values['skip_text'],
    '#description' => t('This will be used as the lable of the skip button.'),
  );
  $form[$fieldset]['config'][$prefix . 'form_header'] = array(
    '#type' => 'textfield',
    '#title' => t('Form header'),
    '#default_value' => $values['form_header'],
    '#description' => t('This is the headline that appears in the form modal.'),
  );
  $form[$fieldset]['config'][$prefix . 'form_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Form copy'),
    '#default_value' => $values['form_copy'],
    '#description' => t('This is the copy that appears above the form elements.'),
  );
  // Create fieldset to group configuration of the actual form elements.
  $form[$fieldset]['config']['elements'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form Elements'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form[$fieldset]['config']['elements'] [$prefix . 'collect_user_address'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect User address'),
    '#default_value' => $values['collect_user_address'],
    '#description' => t('If checked, collect the User address and save to profile.'),
  );
  $shipment_item_options = array();
  if (module_exists('dosomething_shipment')) {
    $shipment_item_options = dosomething_shipment_get_item_options();
  }
  $form[$fieldset]['config']['elements'] [$prefix . 'shipment_item'] = array(
    '#type' => 'select',
    '#title' => t('Select Shipment Item'),
    '#options' => $shipment_item_options,
    '#default_value' => $values['shipment_item'],
    '#description' => t('When the User submits the form, a User Shipment will be created for this Item.'),
    // Why_signedup label should only be visible if collect_user_address is checked.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'collect_user_address"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config']['elements'] [$prefix . 'collect_user_school'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect User school'),
    '#default_value' => $values['collect_user_school'],
    '#description' => t('If checked, collect the User school and save to profile.'),
  );
  $form[$fieldset]['config']['elements'] [$prefix . 'school_not_affiliated_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Not Affiliated Label'),
    '#default_value' => $values['school_not_affiliated_label'],
    '#description' => t('Checkbox label for if a user is not affiliated with a school.'),
    // Label should only be visible if collect_user_school is checked.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'collect_user_school"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config']['elements'] [$prefix . 'school_not_affiliated_confirm_msg'] = array(
    '#type' => 'textfield',
    '#title' => t('Not Affiliated Confirmation Message'),
    '#default_value' => $values['school_not_affiliated_confirm_msg'],
    '#description' => t('Confirmation message if a user selects not affiliated with school.'),
    // Label should only be visible if collect_user_school is checked.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'collect_user_school"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config']['elements'] [$prefix . 'collect_why_signedup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect Signup reason'),
    '#default_value' => $values['collect_why_signedup'],
    '#description' => t('If checked, collect the reason why the User signed up for the campaign.'),
  );
  $form[$fieldset]['config']['elements'][$prefix . 'why_signedup_label'] = array(
    '#type' => 'textarea',
    '#title' => t('Signup Reason Label'),
    '#default_value' => $values['why_signedup_label'],
    '#description' => t('This is the label for the field which collects the signup reason. e.g. <em>Tell us why you would like to receive Thumb Socks for Thumb Wars</em>.'),
    // Why_signedup label should only be visible if collect_why_signedup is checked.
    '#states' => array(
      'visible' => array(
        ':input[name="' . $prefix . 'collect_why_signedup"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form[$fieldset]['config'][$prefix . 'confirm_msg'] = array(
    '#type' => 'textarea',
    '#title' => t('Confirmation message'),
    '#default_value' => $values['confirm_msg'],
    '#description' => t('This is the message displayed after the user submits the form.'),
  );
  $form[$fieldset]['config'][$prefix . 'form_submitted_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Form submitted copy'),
    '#default_value' => $values['form_submitted_copy'],
    '#description' => t('This is the copy that will appear if a user views the form again after submitting. <p>You can use ' . DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN .' to display the time the user submitted the form, e.g. <em>You submitted this form on ' . DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN . ', your banner should arrive within 2 weeks from then!</em></p>'),
  );
  $form[$fieldset]['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    ),
  );
  return $form;
}

/**
 * Validates node signup_data_form values.
 */
function dosomething_signup_node_signup_data_form_validate(&$form, &$form_state) {
  $values = $form_state['values'];
  $prefix = 'signup_data_form_';
  // If signup data form is enabled:
  if ($values[$prefix . 'status'] == 1) {
    // Confirm_msg is mandatory.
    $confirm_msg = $prefix . 'confirm_msg';
    if (empty($values[$confirm_msg])) {
      form_set_error($confirm_msg, t('Signup Data Form Confirmation message is mandatory.'));
    }
  }
}

/**
 * Saves node signup_data_form values into dosomething_signup_data_form.
 */
function dosomething_signup_node_signup_data_form_submit(&$form, &$form_state) {
  $values = $form_state['values'];
  $nid = $values['nid'];
  $prefix = 'signup_data_form_';
  // Use db_merge to either insert or update existing record for $nid.
  db_merge('dosomething_signup_data_form')
    ->key(array('nid' => $nid))
    ->fields(array(
        'status' => $values[$prefix . 'status'],
        'required' => $values[$prefix . 'required'],
        'required_allow_skip' => $values[$prefix . 'required_allow_skip'],
        'competition_signup' => $values[$prefix . 'competition_signup'],
        'custom_social_share_signup' => $values[$prefix . 'custom_social_share_signup'],
        'link_text' => $values[$prefix . 'link_text'],
        'submit_text' => $values[$prefix . 'submit_text'],
        'skip_text' => $values[$prefix . 'skip_text'],
        'form_header' => $values[$prefix . 'form_header'],
        'form_copy' => $values[$prefix . 'form_copy'],
        'form_submitted_copy' => $values[$prefix . 'form_submitted_copy'],
        'confirm_msg' => $values[$prefix . 'confirm_msg'],
        'collect_user_address' => $values[$prefix . 'collect_user_address'],
        'collect_user_school' => $values[$prefix . 'collect_user_school'],
        'collect_why_signedup' => $values[$prefix . 'collect_why_signedup'],
        'why_signedup_label' => $values[$prefix . 'why_signedup_label'],
        'prevent_old_people_submit' => $values[$prefix . 'prevent_old_people_submit'],
        'old_people_copy' => $values[$prefix . 'old_people_copy'],
        'shipment_item' => $values[$prefix . 'shipment_item'],
        'school_not_affiliated_label' => $values[$prefix . 'school_not_affiliated_label'],
        'school_not_affiliated_confirm_msg' => $values[$prefix . 'school_not_affiliated_confirm_msg'],
    ))
    ->execute();
}

/**
 * Form constructor for a user signup data form.
 *
 * @param object $signup
 *   The signup entity to save additional data to.
 */
function dosomething_signup_user_signup_data_form($form, &$form_state, $signup) {
  // Load signup data form config to determine what form elements we need.
  $config = dosomething_signup_get_signup_data_form_info($signup->nid);
  $form['sid'] = array(
    '#type' => 'hidden',
    '#value' => $signup->sid,
    '#access' => FALSE,
  );
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $signup->nid,
    '#access' => FALSE,
  );
  $form['run_nid'] = array(
    '#type' => 'hidden',
    '#value' => $signup->run_nid,
    '#access' => FALSE,
  );

  // If custom social share signup is turned on, use the $config['form_header'] from signup data form.
  if ($config['custom_social_share_signup']) {
    $form['header'] = array(
      '#prefix' => '<div class="modal__block"><h2 class="heading">',
      '#markup' => dosomething_helpers_get_variable('node', $signup->nid, 'social_share_custom_text'),
      '#suffix' => '</h2></div>',
    );
  } else {
    $form['header'] = array(
      '#prefix' => '<div class="modal__block"><h2 class="heading">',
      '#markup' => $config['form_header'],
      '#suffix' => '</h2></div>',
    );
  }

  // If the user has submitted form already:
  if (($timestamp = $signup->signup_data_form_timestamp) && $signup->signup_data_form_response == 1) {
    // Get filtered form_submitted_copy.
    $copy = dosomething_signup_filter_form_submitted_copy($config['form_submitted_copy'], $timestamp);
    // Display the form submitted copy:
    $form['submitted_copy'] = array(
      '#prefix' => '<div class="modal__block"><p>',
      '#markup' => $copy,
      '#suffix' => '</p></div>',
    );
    // Return form as is (without a submit button).
    return $form;
  }

  $form['copy'] = array(
    '#prefix' => '<div class="modal__block"><p>',
    '#markup' => $config['form_copy'],
    '#suffix' => '</p></div>',
  );

  // Container for form elements
  $form['elements'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('modal__block'),
    ),
  );

  // If we are collecting User address:
  if ($config['collect_user_address']) {
    dosomething_user_address_form_element($form['elements'], $form_state);
    if (isset($config['shipment_item'])) {
      // Store the shipment item to create.
      $form['shipment_item'] = array(
        '#type' => 'hidden',
        '#value' => $config['shipment_item'],
        '#access' => FALSE,
      );
    }
  }

  // If we are collecting User school:
  if ($config['collect_user_school']) {
    $form['school_finder'] = array(
      '#prefix' => '<div class="modal__block">',
      '#suffix' => '</div>',
      '#type' => 'fieldset',
      '#attributes' => array(
        'data-validate' => 'school_finder',
        'data-validate-required' => 'true',
      ),
    );

    $administrative_area = dosomething_user_get_address_administrative_area_options();

    $form['school_finder']['school_administrative_area'] = array(
      '#type' => 'select',
      '#options' => $administrative_area['options'],
      '#title' => t("Select @label", array(
        '@label' => $administrative_area['title'],
      )),
      '#attributes' => array(
        'data-validate' => 'state',
      ),
    );

    $form['school_finder']['school_id'] = array(
      '#type' => 'hidden',
      '#title' => t("School ID"),
    );

    $form['school_finder']['school_name'] = array(
      // Used for front-end autocomplete.
      '#type' => 'markup',
      '#title' => t("School Name"),
      '#markup' => '<div class="form-item"><input type="search" class="text-field -search js-schoolfinder-search" placeholder="' . t('Find your school by name...') . '"></div><ul class="schoolfinder-results js-schoolfinder-results"></ul>',
    );

    $school_help_text = t(variable_get('dosomething_user_school_finder_help_text'));
    if ($school_help_text) {
      $school_help_text = check_markup($school_help_text, 'markdown');
    }
    else {
      $school_help_text = '<p>Here are some tricks to help you find your school:</p><ol><li>Abbreviations. If "St. Mary\'s" doesn\'t work, try "Saint Mary\'s" and vice versa. Same with JFK vs. John F. Kennedy.</li><li>You need to search for a specific school, not a whole district.</li></ol><p>';
    }
    $form['school_finder']['help_link'] = array(
      // Used for front-end autocomplete.
      '#type' => 'markup',
      '#prefix' => '<a href="#" class="secondary js-schoolfinder-help">',
      '#markup' => t("Need help locating your school?"),
      '#suffix' => '</a></p>',
    );
    $contact_link = t("Still having issues? !contact with your school name and @state.", array(
      '!contact' => '<a href="#" data-modal-href="#modal-contact-form">' . t("Contact us") . '</a> ',
      '@state' => lcfirst($administrative_area['title']),
    ));
    $form['school_finder']['help_text'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="schoolfinder-help with-lists js-schoolfinder-help-content" style="display: none;">',
      '#markup' => $school_help_text . $contact_link,
      '#suffix' => '</div>',
    );

    $label = $config['school_not_affiliated_label'];
    if (empty($label)) {
      $label = t("I am not affiliated with a school.");
    }

    $form['school_finder']['school_not_affiliated'] = array(
      '#type' => 'checkbox',
      '#title' => $label,
    );

    $form['school_finder']['school_not_affiliated_confirm_msg'] = array(
      '#type' => 'item',
      '#prefix' => '<div class="js-school-not-affiliated-confirmation fade-in-up checkbox-validation-message" style="display: none;">',
      '#markup' => $config['school_not_affiliated_confirm_msg'],
      '#suffix' => '</div>',
    );

    $form['#validate'][] = 'dosomething_signup_user_signup_data_form_validate_school';
  }

  // If we are collecting why_signedup:
  if ($config['collect_why_signedup']) {
    // Add it as a form element.
    $form['elements']['why_signedup'] = array(
      '#type' => 'textarea',
      '#required' => TRUE,
      '#title' => $config['why_signedup_label'],
      '#attributes' => array(
        'data-validate' => 'why_signedup',
        'data-validate-required' => '',
      ),
    );
  }

  $form['actions'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="modal__block"><div class="form-actions">',
    '#suffix' => '</div></div>',
  );

// if enable custom share modal is on, do not show this submit button.
  if (! $config['custom_social_share_signup']) {
    $submit_label = ($config['submit_text']) ? t($config['submit_text']) : t('Submit');
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => $submit_label,
      '#attributes' => array(
        'class' => array(
          'button',
        ),
      ),
    );
  }

  // @todo Hacky solution to deal with form elements when no elements added and eliminate empty container added.
  // @see https://github.com/DoSomething/phoenix/pull/5809
  if (count($form['elements']) <= 2) {
    unset($form['elements']);
  }

  return $form;
}

/**
 * Form submit handler for dosomething_signup_user_signup_data_form().
 */
function dosomething_signup_user_signup_data_form_submit($form, &$form_state) {
  global $user;
  $values = $form_state['values'];
  // Load signup_data_form record to gather relevant config and confirm_msg.
  $config = dosomething_signup_get_signup_data_form_info($values['nid']);
  if ($config['collect_user_address']) {
    // Update user address.
    dosomething_user_save_address_values($values);
    if (isset($values['item'])) {
      // Create a shipment entity for this signup.
      $shipment = entity_create('shipment', array(
        'uid' => $user->uid,
        'entity_type' => 'signup',
        'entity_id' => $values['sid'],
        'item' => $values['item'],
        'item_option' => $values['item_option'],
      ));
      // Save the shipment entity.
      $shipment->save();
    }
  }
  if ($config['collect_user_school']) {
    dosomething_user_save_school_id($values['school_id']);
  }
  // Update signup record.
  dosomething_signup_update_signup_data($values, $config);
  // If this is a competition sign up, send it to gladiator.
  if ($config['competition_signup'] && module_exists('dosomething_gladiator')) {
    dosomething_gladiator_send_user_to_gladiator($user, $values);
  }
  // Display the signup_data_form's confirm_msg field.
  drupal_set_message($config['confirm_msg']);
}

/**
 * Validates school input in the user Signup Data Form.
 *
 * @see dosomething_signup_user_signup_data_form().
 */
function dosomething_signup_user_signup_data_form_validate_school($form, &$form_state) {
  $values = $form_state['values'];
  // If "not affiliated" is unchecked and no school has been entered:
  if ($values['school_not_affiliated'] != 1 && empty($values['school_id'])) {
    // No form submit for you.
    form_set_error('school_id', t("Please select a school."));
  }
}

/**
 * Form constructor for a user skip signup data form.
 *
 * @param object $signup
 *   The signup entity to save additional data to.
 */
function dosomething_signup_user_skip_signup_data_form($form, &$form_state, $signup) {
  $config = dosomething_signup_get_signup_data_form_info($signup->nid);
  $skip_label = ($config['skip_text']) ? t($config['skip_text']) : t('Skip');

  $form['#attributes']['class'] = ['modal__block', 'form-actions'];
  $form['sid'] = [
    '#type' => 'hidden',
    '#value' => $signup->sid,
    '#access' => FALSE,
  ];
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => $skip_label,
    '#attributes' => [
      'class' => [
        'button',
        '-tertiary',
      ],
    ],
  ];
  return $form;
}

/*
 * Form submit handler for dosomething_signup_user_skip_signup_data_form().
 */
function dosomething_signup_user_skip_signup_data_form_submit($form, &$form_state) {
  // Update signup record with response = 0.
  dosomething_signup_update_signup_data($form_state['values'], NULL, 0);
}

/**
 * Saves signup_form_data to the relevant signup record.
 *
 * @param array $values
 *   The values passed from a user signup_data_form submission.
 * @param int $response
 *   If 0, the user chose to skip the form. Else, should be 1.
 */
function dosomething_signup_update_signup_data($values, $config = NULL, $response = 1) {
  try {
    // Load the signup entity to update.
    $entity = signup_load($values['sid']);
    $entity->signup_data_form_timestamp = REQUEST_TIME;
    $entity->signup_data_form_response = $response;

    // Did the person say yes or no to the competition?
    ($config['competition_signup']) ?  $entity->competition = 1 : $entity->competition = 0;

    // If non-skip, store any additional signup data:
    if ($response) {
      if (isset($values['why_signedup'])) {
        $entity->why_signedup = $values['why_signedup'];
      }
    }
    $entity->save();
    return TRUE;
  }
  catch (Exception $e) {
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
  return FALSE;
}

/**
 * Wrapper for str_replace for usage with form_submitted_copy values.
 *
 * @param string $string
 *   The original string, which may contain the
 *   DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN string.
 * @param int $timestamp
 *   The timestamp to replace the token string with.
 *
 * @return string
 *   Original string, with token replaced with a readable $timestamp.
 */
function dosomething_signup_filter_form_submitted_copy($string, $timestamp) {
  // Custom format: January 1st.
  $submitted = format_date($timestamp, 'custom', 'F jS');
  return str_replace(DOSOMETHING_SIGNUP_DATA_FORM_TIMESTAMP_TOKEN, $submitted, $string);
}
