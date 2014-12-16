<?php
/**
 * @file
 * Code for dosomething_reportback admin functionality.
 */

/**
 * Form constructor for Reportback admin config form.
 *
 * @see dosomething_reportback_menu()
 */
function dosomething_reportback_admin_config_form($form, &$form_state) {
  $form['dosomething_reportback_is_crop_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Reportback Cropping.'),
    '#default_value' => variable_get('dosomething_reportback_is_crop_enabled', FALSE),
    '#description' => t("Allows users to crop their own Reportback images."),
  );
  $form['dosomething_reportback_is_generate_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Dummy Reportback Generation.'),
    '#default_value' => variable_get('dosomething_reportback_is_generate_enabled', FALSE),
    '#description' => t("Allows admins to generate Lorem ipsum Reportbacks."),
  );
  $form['dosomething_reportback_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log Reportbacks.'),
    '#default_value' => variable_get('dosomething_reportback_log', FALSE),
    '#description' => t("Logs Reportback activity. This should be disabled on production."),
  );
  return system_settings_form($form);
}

/**
 * Form constructor for generating dummy Reportbacks.
 *
 * @see dosomething_reportback_menu()
 */
function dosomething_reportback_admin_generate_form($form, &$form_state) {
  $form['help'] = array(
    '#markup' => t("Submitting this form will generate Lorem ipsum Reportbacks for your account."),
  );
  $form['nid'] = array(
    '#type' => 'entity_autocomplete',
    '#title' => t('Campaign'),
    '#description' => t("Select the campaign to generate reportbacks for."),
    '#entity_type' => 'node',
    '#bundles' => array('campaign'),
    '#required' => TRUE,
  );
   $form['num'] = array(
     '#type' => 'select',
     '#title' => t('Number of reportbacks'),
     '#required' => TRUE,
     '#options' => array(
        5 => t('5'),
        10 => t('10'),
        15 => t('15'),
        20 => t('20'),
        25 => t('25'),
     ),
     '#default_value' => 15,
   );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t("Submit"),
    ),
  );
  return $form;
}

/**
 * Form submit callback for dosomething_reportback_admin_generate_form.
 */
function dosomething_reportback_admin_generate_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  dosomething_reportback_generate($values['nid'], $values['num']);
  drupal_set_message(t("Generated %num dummy reportbacks.", array('%num' => $values['num'])));
}

/**
 * Form to set the status of Reportback Files.
 *
 * @param string $status
 *   (optional) The Reportback File status to filter by.
 */
function dosomething_reportback_files_form($form, &$form_state, $status = NULL, $entity = NULL) {
  // Identify that the elements in 'rb_files' are a collection, to
  // prevent Form API from flattening the array when submitted.
  $form['rb_files']['#tree'] = TRUE;
  $status_options = dosomething_reportback_get_file_status_options();
  $flagged_options = array(
    'irrelevant' => t('Irrelevant'),
    'inappropriate' => t('Inappropriate'),
    'unrealistic' => t('Unrealistic quantity'),
    'delete' => t('Delete this image'),
  );

  $params = array(
    'status' => $status,
  );
  if (isset($entity->nid)) {
    $params['nid'] = $entity->nid;
  }
  elseif (isset($entity->tid)) {
    $params['tid'] = $entity->tid;
  }
  $page_size = 25;
  if (isset($_GET['pagesize'])) {
    $limit = $_GET['pagesize'];
    if (is_numeric($limit) || $limit < 100) {
      $page_size = $limit;
    }
  }
  $result = dosomething_reportback_get_reportback_files_query(0, $params, $page_size);

  foreach ($result as $record) {
    $preview = dosomething_reportback_file_preview($record);
    $rb_path = 'reportback/' . $record->rbid;
    $form['rb_files'][$record->fid] = array(
      'preview' => array(
        '#markup' => $preview,
      ),
      'date' => array(
        '#markup' => l(format_date($record->timestamp, 'short'), $rb_path),
      ),
      'quantity' => array(
        '#markup' => $record->quantity,
      ),
      'node' => array(
        '#markup' => l($record->title, 'node/'. $record->nid),
      ),
      'fid' => array(
        '#type' => 'hidden',
        '#value' => $record->fid,
      ),
      'status' => array(
        '#type' => 'radios',
        '#title' => t('Status'),
        '#required' => TRUE,
        '#options' => $status_options,
        '#default_value' => $record->status,
      ),
      'flagged_reason' => array(
        '#type' => 'checkboxes',
        '#options' => $flagged_options,
      ),
    );
  }
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save')
  );
  return $form;
}

/**
 * Form submit callback for dosomething_reportback_files_form_submit.
 */
function dosomething_reportback_files_form_submit($form, &$form_state) {
  $rb_files = $form_state['values']['rb_files'];
  if (empty($rb_files) || !is_array($rb_files)) {
    return;
  }
  foreach ($rb_files as $fid => $item) {
    $rbf = reportback_file_load($fid);
    $save = $rbf->review($item['status']);
    if (!$save) {
      form_set_error(t("An error has occurred."));
    }
  }
  drupal_set_message(t("Updated."));
}

/**
 * Themes the dosomething_reportback_files_form constructor.
 */
function theme_dosomething_reportback_files_form($variables) {
  $form = $variables['form'];
  $rb_files = element_children($form['rb_files']);
  $path = drupal_get_path('module', 'dosomething_reportback');
  drupal_add_js ($path . "/js/reportback_review_form.js");
  // If no results, just return form.
  if (empty($rb_files)) {
    return t("Inbox zero! There are no Reportbacks to review.");
  }

  // Initialize the variable which will store our table rows.
  $rows = array();
  foreach ($rb_files as $fid) {
    $rows[] = array(
      'data' => array(
        // Add the columns defined in the form.
        drupal_render($form['rb_files'][$fid]['date']),
        drupal_render($form['rb_files'][$fid]['preview']),
        drupal_render($form['rb_files'][$fid]['quantity']),
        drupal_render($form['rb_files'][$fid]['node']),
        drupal_render($form['rb_files'][$fid]['status']) . '<div class="flag-form"><hr />' . drupal_render($form['rb_files'][$fid]['flagged_reason']) . '</div>',
      ),
    );
  }
  $header = array(
    t('Submitted'),
    NULL,
    t('Quantity'),
    t('Campaign'),
    t('Op'),
  );
  // We can render our tabledrag table for output.
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
  // And then render any remaining form elements (such as our submit button).
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Returns markup for a Reportback File preview.
 *
 * @todo Move this into a tpl file.
 */
function dosomething_reportback_file_preview($record) {
  $img = dosomething_image_get_themed_image_by_fid($record->fid, '300x300');
  $info = $img . '<p><strong>' . check_plain($record->caption) . '</strong></p>';
  $info .= l($record->mail, 'user/' . $record->uid);
  $info .= '<hr />' . check_plain($record->why_participated);
  return $info;
}
