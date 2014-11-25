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

function dosomething_reportback_get_file_status_options() {
  return array(
    'approved' => 'Approved',
    'promoted' => 'Promoted',
    'excluded' => 'Excluded',
    'flagged' => 'Flagged',
  );
}

/**
 * Form to review Reportback Files.
 */
function dosomething_reportback_files_form() {
  // Identify that the elements in 'gallery_items' are a collection, to
  // prevent Form API from flattening the array when submitted.
  $form['rb_files']['#tree'] = TRUE;
  $options = dosomething_reportback_get_file_status_options();

  $result = dosomething_reportback_get_gallery_results();
  foreach ($result as $record) {
    $preview = dosomething_reportback_file_preview($record);
    $form['rb_files'][$record->fid] = array(
      'preview' => array(
        '#markup' => $preview,
      ),
      'date' => array(
        '#markup' => format_date($record->updated, 'short'),
      ),
      'quantity' => array(
        '#markup' => $record->quantity,
      ),
      'node' => array(
        '#markup' => $record->title,
      ),
      'status' => array(
        '#type' => 'radios',
        '#title' => t('Status'),
        '#required' => TRUE,
        '#options' => $options,
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
  $header = array(t('Submitted'), NULL, t('Quantity'), t('Op'), t('Campaign'));
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
 * Page callback for Admin Gallery table.
 */
function dosomething_reportback_admin_gallery_page() {
  $header = array(
    t('Submitted'),
    NULL,
    t('Quantity'),
    t('Email'),
    t('Campaign'),
  );

  $result = dosomething_reportback_get_gallery_results();
  $rows = array();

  foreach ($result as $record) {
    $img = dosomething_image_get_themed_image_by_fid($record->fid, '300x300');
    $info = $img . '<p><strong>' . $record->caption . '</strong></p>';
    $info .= '<hr />' . $record->why_participated;
    $date = format_date($record->updated, 'short');

    $rows[] = array(
      l($date, 'reportback/' . $record->rbid),
      $info,
      $record->quantity,
      l($record->mail, 'user/'. $record->uid),
      l($record->title, 'node/'. $record->nid),
    );

  }

  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
}

function dosomething_reportback_file_preview($record) {
  $img = dosomething_image_get_themed_image_by_fid($record->fid, '300x300');
  $info = $img . '<p><strong>' . $record->caption . '</strong></p>';
  $info .= l($record->mail, 'user/' . $record->uid);
  $info .= '<hr />' . $record->why_participated;
  return $info;
}
