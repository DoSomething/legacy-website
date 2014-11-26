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
  return system_settings_form($form);
}

/**
 * Form to set the status of Reportback Files.
 *
 * @param string $status
 *   (optional) The Reportback File status to filter by.
 */
function dosomething_reportback_files_form($form, &$form_state, $status = NULL) {
  // Identify that the elements in 'gallery_items' are a collection, to
  // prevent Form API from flattening the array when submitted.
  $form['rb_files']['#tree'] = TRUE;
  $options = dosomething_reportback_get_file_status_options();

  $result = dosomething_reportback_get_gallery_results($status);
  foreach ($result as $record) {
    $preview = dosomething_reportback_file_preview($record);
    $rb_path = 'reportback/' . $record->rbid;
    $form['rb_files'][$record->fid] = array(
      'preview' => array(
        '#markup' => $preview,
      ),
      'date' => array(
        '#markup' => l(format_date($record->updated, 'short'), $rb_path),
      ),
      'quantity' => array(
        '#markup' => $record->quantity,
      ),
      'node' => array(
        '#markup' => $record->title,
      ),
      'fid' => array(
        '#type' => 'hidden',
        '#value' => $record->fid,
      ),
      'status' => array(
        '#type' => 'radios',
        '#title' => t('Status'),
        '#required' => TRUE,
        '#options' => $options,
        '#default_value' => $record->status,
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
  foreach ($form_state['values']['rb_files'] as $id => $item) {
    $status = dosomething_reportback_update_reportback_file_status($item['fid'], $item['status']);
    if (!$status) {
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

  // If no results, just return form.
  if (empty($rb_files)) {
    return t("No results found.");
  }

  // Initialize the variable which will store our table rows.
  $rows = array();
  foreach ($rb_files as $id) {
    $rows[] = array(
      'data' => array(
        // Add the columns defined in the form.
        drupal_render($form['rb_files'][$id]['date']),
        drupal_render($form['rb_files'][$id]['preview']),
        drupal_render($form['rb_files'][$id]['quantity']),
        drupal_render($form['rb_files'][$id]['node']),
        drupal_render($form['rb_files'][$id]['status']),
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
  $info = $img . '<p><strong>' . $record->caption . '</strong></p>';
  $info .= l($record->mail, 'user/' . $record->uid);
  $info .= '<hr />' . $record->why_participated;
  return $info;
}
