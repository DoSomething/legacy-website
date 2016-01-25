<?php

/**
 * @file
 * Provides form constructors for the DoSomething Reportback module.
 */


/**
 * Form constructor for a reportback create/update form.
 *
 * @param object $entity
 *   A reportback entity to create or update.
 *
 * @ingroup forms
 */
function dosomething_reportback_form($form, &$form_state, $entity = NULL) {
  if (!$entity) {
    $entity = entity_create('reportback', array(
      'uid' => NULL,
      'noun' => 'Nouns',
      'verb' => 'verbed',
      'quantity' => NULL,
      'why_participated' => NULL,
    ));
  }

  // Admin form elements:
  $paths = array('reportback', 'admin');
  if (user_access('edit any reportback') && in_array(arg(0), $paths)) {
    $form['nid'] = array(
      '#type' => 'entity_autocomplete',
      '#title' => t('Node'),
      '#description' => t("The node this reportback was submitted for."),
      '#entity_type' => 'node',
      '#bundles' => array('campaign'),
      '#required' => TRUE,
      '#default_value' => $entity->nid,
    );
    if (!empty($entity->uid)) {
      $account = user_load($entity->uid);
      $username = $account->name;
    }
    else {
      $username = NULL;
      drupal_set_title(t("Add reportback"));
    }
    $form['username'] = array(
      '#type' => 'textfield',
      '#title' => t('User'),
      '#description' => t("The user that submitted this reportback."),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => $username,
    );
  }


  // Reportback Submissions container.
  $form['reportback_submissions'] = array(
    '#type' => 'container',
    '#id' => 'reportback-submissions',
    '#attributes' => array(
      'class' => array(
        'reportback__submissions',
      ),
    ),
  );

  $form['reportback_submissions']['reportback_item'] = array(
    '#weight' => 5,
    '#type' => 'file',
    '#theme_wrappers' => array(),
    '#attributes' => array(
      'class' => array(
        'js-image-upload'
      ),
    ),
  );

  // If rbid doesn't exist, this is a create form.
  if (!isset($entity->rbid)) {
    $entity->rbid = 0;

    $form['reportback_submissions']['reportback_item']['#attributes']['is_supersized'] = TRUE;

    $submit_label = t("Submit your pic");
  }

  // Else, it's an update form.
  else {
    // Output reportback images with date last updated.
    $form['reportback_submissions']['reportback_item']['#attributes']['is_supersized'] = FALSE;

    $reportback_submissions_data = array();
    // Specify number of prior reportbacks to retrieve, including the latest one to show prominently.
    $reportback__submissions_count = 5;

    foreach ($entity->fids as $index => $fid) {
      $reportback_submissions_data[$index] = reportback_file_load($fid);
      $reportback_submissions_data[$index]->image = dosomething_image_get_themed_image_by_fid($fid, '400x400');
    }

    $reportback_prior_submissions = array_reverse($reportback_submissions_data);
    $reportback_prior_submissions = array_slice($reportback_prior_submissions, 0, $reportback__submissions_count);
    $reportback_latest_submission = array_shift($reportback_prior_submissions);

    $form['reportback_submissions']['reportback_latest_submission'] = array(
      '#weight' => 0,
      '#markup' => theme('reportback_latest_submission', array(
        'reportback' => $reportback_latest_submission,
      )),
    );

    if ($reportback_prior_submissions) {
      $form['reportback_submissions']['reportback_prior_submissions'] = array(
        '#weight' => 10,
        '#markup' => theme('reportback_prior_submissions', array(
          'updated' => format_date($entity->updated, 'short'),
          'reportbacks' => $reportback_prior_submissions,
        )),
      );
    }

    $submit_label = t("Update submission");
  }


  $form['rbid'] = array(
    '#type' => 'hidden',
    '#default_value' => $entity->rbid,
    // Prevent this element from rendering in the browser.
    '#access' => FALSE,
  );

  if (!isset($form['nid'])) {
    $form['nid'] = array(
      '#type' => 'hidden',
      '#default_value' => $entity->nid,
      // Prevent this element from rendering in the browser.
      '#access' => FALSE,
    );
  }

  // Hidden fields to collect cropping information.
  $form['reportback_submissions']['crop_x'] = array(
    '#weight' => 20,
    '#type' => 'hidden',
    '#default_value' => 0,
  );
  $form['reportback_submissions']['crop_y'] = array(
    '#weight' => 21,
    '#type' => 'hidden',
    '#default_value' => 0,
  );
  $form['reportback_submissions']['crop_width'] = array(
    '#weight' => 22,
    '#type' => 'hidden',
    '#default_value' => 480,
  );
  $form['reportback_submissions']['crop_height'] = array(
    '#weight' => 23,
    '#type' => 'hidden',
    '#default_value' => 480,
  );
  $form['reportback_submissions']['crop_rotate'] = array(
    '#weight' => 24,
    '#type' => 'hidden',
    '#default_value' => 0,
  );

  $form['divider'] = array(
    '#markup' => '<hr class="divider inline-alt-background-color">',
  );

  // Reportback Inputs container.
  $form['reportback_inputs'] = array(
    '#type' => 'container',
    '#id' => 'reportback-inputs',
    '#attributes' => array(
      'class' => array(
        'reportback__inputs',
      ),
    ),
  );

  $caption = NULL;

  if (isset($reportback_latest_submission)) {
    $caption = isset($reportback_latest_submission->caption) ? $reportback_latest_submission->caption : t('DoSomething? Just did!');
  }

  $form['reportback_inputs']['caption'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#attributes' => array(
      'data-validate' => 'caption',
      'data-validate-required' => '',
      'placeholder' => t('60 characters or less'),
      'maxlength' => '60',
    ),
    '#title' => t("Caption"),
    '#default_value' => $caption,
  );

  $form['reportback_inputs']['quantity'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t("Enter # here"),
      'class' => array('js-validate'),
      'data-validate' => 'positiveInteger',
      'data-validate-required' => '',
    ),
    '#element_validate' => array('dosomething_reportback_validate_quantity'),
    '#title' => t("Total # of @noun @verb", array(
        '@noun' => $entity->noun,
        '@verb' => $entity->verb,
      )
    ),
    '#default_value' => $entity->quantity,
  );

  // Load helpers variables for the nid this reportback is for.
  $config = dosomething_helpers_get_variables('node', $entity->nid);
  // If we are collecting num_participants for this node:
  if ($config['collect_num_participants']) {
    // Set default label for num_participants form element.
    $label_default = t("Total # of people participated");
    // Check for the num_participants_label variable.
    $var_name = 'dosomething_reportback_num_participants_label';
    $label = t(variable_get($var_name, $label_default));
    $form['reportback_inputs']['num_participants'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#attributes' => array(
        'placeholder' => t("Enter # here"),
        'class' => array('js-validate'),
        'data-validate' => 'positiveInteger',
        'data-validate-required' => '',
      ),
      '#element_validate' => array('element_validate_integer_positive'),
      '#title' => $label,
      '#default_value' => $entity->num_participants,
    );
  }

  $form['reportback_inputs']['why_participated'] = array(
    '#type' => 'textarea',
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t("Write something..."),
      'class' => array('js-validate'),
      'data-validate' => 'reportbackReason',
      'data-validate-required' => '',
    ),
    '#title' => t('Why is this campaign important to you?'),
    '#default_value' => $entity->why_participated,
  );

  $form['reportback_inputs']['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => $submit_label,
      // Unique scenario with container around the form-actions so need to set
      // button class here specifically.
      '#attributes' => array(
        'class' => array(
          'button form-submit'
        ),
      ),
    ),
  );

  return $form;
}

/**
 * Custom validation function for the quantity field so we can trim
 * values of whitespace before validation is run.
 */
function dosomething_reportback_validate_quantity($element, &$form_state) {
  // Remove whitespace.
  $value = trim($element['#value']);

  // Implementation of element_validate_integer_positive.
  if ($value !== '' && (!is_numeric($value) || intval($value) != $value || $value <= 0)) {
    form_error($element, t('%name must be a positive integer.', array('%name' => $element['#title'])));
  }
}

/**
 * Validation callback for dosomething_reportback_form().
 */
function dosomething_reportback_form_validate($form, &$form_state) {
  if (empty($form_state['values']['nid'])) {
    drupal_acess_denied();
    return FALSE;
  }
  $campaign_id = $form_state['values']['nid'];

  // If user session no longer exists:
  if (!user_is_logged_in()) {
    // Tell them that.
    drupal_set_message(t("You are no longer logged in. Please log in."), 'error');
    // Redirect to the original node.
    // Without this, the user is redirected to the confirmation page.
    drupal_goto('node/' . $campaign_id);
  }

  // If user isn't signed up for the campaign.
  if (!dosomething_user_is_staff() && !dosomething_signup_exists($campaign_id)) {
    drupal_set_message(t("You must be signed up for this campaign first."), 'error');
    drupal_goto('node/' . $campaign_id);
  }

  // Validate uploaded file.
  dosomething_reportback_form_validate_file($form, $form_state);
}

/**
 * Submit callback for dosomething_reportback_form().
 */
function dosomething_reportback_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  // If username field is set, this is an admin form.
  $is_admin_form = isset($form_state['values']['username']);

  // Load uid by selected username.
  if ($is_admin_form) {
    $user = user_load_by_name($form_state['values']['username']);
    $values['uid'] = $user->uid;
  }
  // Else if regular user form:
  else {
    // Store logged in user's uid.
    global $user;
    $values['uid'] = $user->uid;
  }

  // Save uploaded file.
  if ($file = dosomething_reportback_form_save_file($form_state)) {
    // Store new file's fid into values.
    $values['fid'] = $file->fid;
  }

  // Save values into reportback.
  $rid = dosomething_reportback_save($values, $user);

  // Redirect to permalink page.
  $form_state['redirect'] = array(
    'reportback/' . $rid,
    array(
      'query' => array(
        'fid' => $values['fid'],
      ),
    ),
  );

}

/**
 * Validates file uploaded to form and sets in $form_state[storage].
 */
function dosomething_reportback_form_validate_file($form, &$form_state) {
  // Validate upload.
  $file = file_save_upload('reportback_item', array(
    'file_validate_is_image' => array(),
    'file_validate_extensions' => array('png gif jpg jpeg'),
  ));
  // If the file passed validation:
  if ($file) {
    $nid = $form_state['values']['nid'];
    // Move the file into its proper destination.
    $new_dest = dosomething_reportback_get_file_dest($file->filename, $nid);
    if ($file = file_move($file, $new_dest)) {
      // Save the file for use in the submit handler.
      $form_state['storage']['file'] = $file;
    }
    else {
      form_set_error('reportback_item', t('There was an error. Please try again.'));
    }
  }
  // If this is a new reportback form, file is mandatory.
  elseif ($form_state['values']['rbid'] == 0) {
    dosomething_helpers_add_analytics_event('Reportback', 'image file too large');
    form_set_error('reportback_item', t('Please upload an image.'));
  }
}

/**
 * Saves file from form into file_managed with permanent status.
 */
function dosomething_reportback_form_save_file(&$form_state) {
  // If nothing set in storage, exit.
  if (!isset($form_state['storage']['file'])) {
    return FALSE;
  }

  // Retrieve file from storage.
  $file = $form_state['storage']['file'];

  // We are done with the file, remove it from storage.
  unset($form_state['storage']['file']);

  // Make the storage of the file permanent.
  $file->status = FILE_STATUS_PERMANENT;
  file_save($file);

  // Crop the image.
  $x = $form_state['values']['crop_x'];
  $y = $form_state['values']['crop_y'];
  $width = $form_state['values']['crop_width'];
  $height = $form_state['values']['crop_height'];
  $rotate = $form_state['values']['crop_rotate'];

  // Load the image.
  $image = image_load($file->uri);

  // Apply user crop and rotation to the image.
  dosomething_reportback_image_edit($image, $x, $y, $width, $height, $rotate);

  return $file;
}

/**
 * Rotate and crops an image based on user input.
 */
function dosomething_reportback_image_edit($image, $x, $y, $width, $height, $rotate = NULL) {
  // Rotate the image and then crop it if rotation was successful.
  if ($rotate) {
    $rotate_worked = image_rotate($image, $rotate, 0xffffff);
  }

  $result = image_crop($image, $x, $y, $width, $height);

  // Save the image, if result is successful;
  // @TODO - this saves the new cropped image over the original one. Eventually we want to save it as a separate image.
  if ($result) {
    image_save($image);
  }
}

/**
 * Form constructor for a reportback delete form.
 *
 * @param object $entity
 *   The reportback entity to delete.
 *
 * @ingroup forms
 */
function dosomething_reportback_delete_form($form, &$form_state, $entity) {
  $form['rbid'] = array(
    '#type' => 'hidden',
    '#default_value' => $entity->rbid,
  );
  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => $entity->nid,
  );
  $form['warning'] = array(
    '#markup' => t("Are you sure you want to delete this reportback?  This cannot be undone."),
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Delete'),
    ),
  );
  return $form;
}

/**
 * Submit callback for dosomething_reportback_delete_form().
 */
function dosomething_reportback_delete_form_submit($form, &$form_state) {
  $rbid = $form_state['values']['rbid'];
  // Check for user screwing with form values via browser type firebuggin' things.
  // This check will only work if the form lives only on reportback/*/delete.
  if ($rbid == arg(1)) {
    dosomething_reportback_delete_reportback($rbid);
    // Redirect back to the node that the reportback was for.
    $form_state['redirect'] = 'node/' . $form_state['values']['nid'];
    drupal_set_message(t("Reportback deleted."));
    return;
  }
  // Else, there was some rat fuckery.
  drupal_set_message(t("There was an error processing your request."));
}
