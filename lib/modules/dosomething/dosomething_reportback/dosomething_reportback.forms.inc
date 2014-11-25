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
  // If rbid doesn't exist, this is a create form.
  if (!isset($entity->rbid)) {
    $entity->rbid = 0;
    $submit_label = t("Submit your pic");
  }
  // Else, it's update form.
  else {
    // Output reportback images with date last updated.
    $form['header']['#markup'] =theme('reportback_form_images', array(
      'updated' => format_date($entity->updated, 'short'),
      'images' => $entity->getThemedImages('300x300'),
    ));
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
  $form['reportback_file'] = array(
    '#type' => 'file',
    '#title' => t('Upload a pic'),
    '#attributes' => array(
      'class' => array('js-image-upload'),
    ),
  );
  // Hidden fields to collect cropping information.
  $form['crop_x'] = array(
    '#type' => 'hidden',
  );
  $form['crop_y'] = array(
    '#type' => 'hidden',
  );
  $form['crop_width'] = array(
    '#type' => 'hidden',
  );
  $form['crop_height'] = array(
    '#type' => 'hidden',
  );
  $caption = NULL;
  if (isset($entity->caption)) {
    $caption = $entity->caption;
  }
  $form['caption'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#attributes' => array(
      'data-validate-required' => '',
      'placeholder' => t("Write something..."),
    ),
    '#title' => t("Caption"),
    '#default_value' => $caption,
  );
  $form['quantity'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t("Enter # here"),
      'class' => array('js-validate'),
      'data-validate' => 'positiveInteger',
      'data-validate-required' => '',
    ),
    '#element_validate' => array('element_validate_integer_positive'),
    '#title' => t("Total # of @noun @verb", array(
        '@noun' => $entity->noun,
        '@verb' => $entity->verb,
      )
    ),
    '#default_value' => $entity->quantity,
  );

  // Load helpers variables for the nid this reportback is for.
  $config = dosomething_helpers_get_variables($entity->nid);
  // If we are collecting num_participants for this node:
  if ($config['collect_num_participants']) {
    // Set default label for num_participants form element.
    $label_default = t("Total # of people participated");
    // Check for the num_participants_label variable.
    $var_name = 'dosomething_reportback_num_participants_label';
    $label = variable_get($var_name, $label_default);
    $form['num_participants'] = array(
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

  $form['why_participated'] = array(
    '#type' => 'textarea',
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t("Write something..."),
      'class' => array('js-validate'),
      'data-validate' => 'reportbackReason',
      'data-validate-required' => '',
    ),
    '#title' => t('Why is this important to you?'),
    '#default_value' => $entity->why_participated,
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => $submit_label,
    ),
  );
  return $form;
}

/**
 * Validation callback for dosomething_reportback_form().
 */
function dosomething_reportback_form_validate($form, &$form_state) {
  // If user session no longer exists:
  if (!user_is_logged_in()) {
    // Tell them that.
    drupal_set_message(t("You are no longer logged in. Please log in."), 'error');
    // Redirect to the original node.
    // Without this, the user is redirected to the confirmation page.
    drupal_goto('node/' . $form_state['values']['nid']);
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
    $account = user_load_by_name($form_state['values']['username']);
    $values['uid'] = $account->uid;
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
  dosomething_reportback_save($values);

  // Redirect to confirmation.
  if (!$is_admin_form) {
    $redirect = dosomething_campaign_get_confirmation_path($values['nid']);
    $form_state['redirect'] = $redirect;
  }
}

/**
 * Validates file uploaded to form and sets in $form_state[storage].
 */
function dosomething_reportback_form_validate_file($form, &$form_state) {
  // Validate upload.
  $file = file_save_upload('reportback_file', array(
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
      form_set_error('reportback_file', t('There was an error. Please try again.'));
    }
  }
  // If this is a new reportback form, file is mandatory.
  elseif ($form_state['values']['rbid'] == 0) {
    form_set_error('reportback_file', t('Please upload an image.'));
  }
}

/**
 * Saves file from form into file_managed with permanent status.
 */
function dosomething_reportback_form_save_file(&$form_state) {
  // If nothing set in storage, exit.
  if (!isset($form_state['storage']['file'])) return;

  // Retrieve file from storage.
  $file = $form_state['storage']['file'];
  // We are done with the file, remove it from storage.
  unset($form_state['storage']['file']);
  // Make the storage of the file permanent.
  $file->status = FILE_STATUS_PERMANENT;
  file_save($file);
  // @TODO - only if cropping is active.
  // Grab cropping information.
  $x = $form_state['values']['crop_x'];
  $y = $form_state['values']['crop_y'];
  $width = $form_state['values']['crop_width'];
  $height = $form_state['values']['crop_height'];
  // Load the image.
  $image = image_load($file->uri);
  // Crop the image.
  dosomething_reportback_image_crop($image, $x, $y, $width, $height);
  return $file;
}

// Function to crop image.
function dosomething_reportback_image_crop($image, $x, $y, $width, $height) {
  // Crop the image.
  $result = image_crop($image, $x, $y, $width, $height);
  // Save the image.
  // @TODO - this saves the new cropped image over the original one. Eventually we want to save it as a separate image.
  image_save($image);
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

/**
 * Build the dosomething_reportback_gallery_form.
 *
 * Borrowed liberally from the Examples Tabledrag module.
 * @see https://api.drupal.org/api/examples/tabledrag_example!tabledrag_example_simple_form.inc/7
 *
 * @return array
 *   A form array set for theming by theme_dosomething_reportback_gallery_form()
 */
function dosomething_reportback_gallery_form($form, $form_state, $node) {
  $nid = $node->nid;
  // Identify that the elements in 'gallery_items' are a collection, to
  // prevent Form API from flattening the array when submitted.
  $form['gallery_items']['#tree'] = TRUE;

  $result = dosomething_reportback_get_gallery_vars($nid, 'thumbnail');
  foreach ($result as $item) {
    $id = $item['flagging_id'];
    $link_args = array('query' => array('destination' => 'node/' . $nid . '/gallery'));
    // Unflag the file fid.
    $unflag_path = 'flag/confirm/unflag/promoted/' . $item['fid'];
    // Link to the reportback rbid.
    $reportback_path = 'reportback/' . $item['rbid'];

    $form['gallery_items'][$id] = array(
      'image' => array(
        '#markup' => $item['image'],
      ),
      'caption' => array(
        '#type' => 'textarea',
        '#default_value' => $item['caption']['value'],
        '#rows' => 3,
      ),
      'view_reportback' => array(
        '#markup' => l(t('View reportback'), $reportback_path),
      ),
      'unpromote' => array(
        '#markup' => l(t('Remove'), $unflag_path, $link_args),
      ),
      'weight' => array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#default_value' => $item['weight'],
        '#delta' => 10,
        '#title_display' => 'invisible',
      ),
    );
  }
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save')
  );
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    // Kinda hacky to use arg() here but this is staff only form.
    '#href' => 'node/' . arg(1). '/gallery',
  );
  return $form;
}

/**
 * Theme callback for the theme_dosomething_reportback_gallery_form form.
 *
 * The theme callback will format the $form data structure into a table and
 * add our tabledrag functionality.
 *
 * @return array
 *   The rendered tabledrag form
 *
 */
function theme_dosomething_reportback_gallery_form($variables) {
  $form = $variables['form'];
  $gallery_items = element_children($form['gallery_items']);

  // If no results, just return form.
  if (empty($gallery_items)) {
    return t("No reportback images have been added to the gallery.");
  }

  // Initialize the variable which will store our table rows.
  $rows = array();
  foreach ($gallery_items as $id) {
    $form['gallery_items'][$id]['weight']['#attributes']['class'] = array('gallery-item-weight');
    $rows[] = array(
      'data' => array(
        // Add the columns defined in the form.
        drupal_render($form['gallery_items'][$id]['image']),
        drupal_render($form['gallery_items'][$id]['caption']),
        drupal_render($form['gallery_items'][$id]['view_reportback']),
        drupal_render($form['gallery_items'][$id]['unpromote']),
        drupal_render($form['gallery_items'][$id]['weight']),
      ),
      'class' => array('draggable'),
    );
  }
  $header = array(t('Image'), t('Caption'), NULL, NULL, NULL);
  $table_id = 'gallery-items-table';
  // We can render our tabledrag table for output.
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));
  // And then render any remaining form elements (such as our submit button).
  $output .= drupal_render_children($form);
  // Drupal magic time.
  drupal_add_tabledrag($table_id, 'order', 'sibling', 'gallery-item-weight');

  return $output;
}

/**
 * Submit callback for the dosomething_reportback_gallery_form.
 *
 * Updates the 'weight' field for each flagging record, taking into
 * account that item's new order after the drag and drop actions have been
 * performed.
 */
function dosomething_reportback_gallery_form_submit($form, &$form_state) {
  foreach ($form_state['values']['gallery_items'] as $id => $item) {
    $flagging = flagging_load($id);
    $flagging->field_weight[LANGUAGE_NONE][0]['value'] = $item['weight'];
    $flagging->field_image_description[LANGUAGE_NONE][0]['value'] = $item['caption'];
    flagging_save($flagging);
  }
  // Update gallery cache.
  // @todo Delete specific cache entry for this nid, not all.
  dosomething_reportback_cache_clear_all();
  drupal_set_message(t("Gallery updated."));
}

/**
 * Additional submit callback for the flag_confirm form for Reportbacks.
 *
 * Deletes the reportback's files if delete_files was checked.
 */
function dosomething_reportback_flag_confirm_submit($form, &$form_state) {
  $reportback = reportback_load($form_state['values']['entity_id']);
  // Value is either flag or unflag.
  $op = $form['action']['#value'];
  // Sets value as "flagged" or "unflagged".
  $op .= 'ged';
  // If the "Delete files" element is checked:
  if (isset($form_state['values']['delete_files']) && $form_state['values']['delete_files'] === 1) {
    $reportback->deleteFiles();
    $op = 'flagged_delete_files';
  }
  // Log the flag operation.
  $reportback->insertLog($op);
}
