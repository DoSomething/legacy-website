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
  );

  $params = array(
    'status' => $status,
  );

  // Display mode for rendering each Reportback File.
  $view_mode = 'full';

  $entity_type = NULL;
  $entity_id = NULL;

  // If we are viewing a reportback entity:
  if (isset($entity->rbid) && arg(0) === 'reportback') {
    $params['rbid'] = $entity->rbid;
    // If viewing a Reportback, don't repeat the Reportback details in each file.
    $view_mode = 'teaser';
    $entity_id = $entity->rbid;
    $entity_type = 'reportback';
  }
  elseif (isset($entity->nid)) {
    $params['nid'] = $entity->nid;
    $entity_id = $entity->nid;
    $entity_type = 'node';
  }
  elseif (isset($entity->tid)) {
    $params['tid'] = $entity->tid;
    $entity_id = $entity->tid;
    $entity_type = 'taxonomy_term';
  }

  $form['view_mode'] = array(
    '#type' => 'hidden',
    '#value' => $view_mode,
  );

  if (isset($entity_type)) {
    $form['entity_type'] = array(
      '#type' => 'hidden',
      '#value' => $entity_type,
    );
    $form['entity_id'] = array(
      '#type' => 'hidden',
      '#value' => $entity_id,
    );
  }

  $page_size = 25;
  if (isset($_GET['pagesize'])) {
    $limit = $_GET['pagesize'];
    if (is_numeric($limit) || $limit < 100) {
      $page_size = $limit;
    }
  }
  // Get the DatabaseQuery to loop through.
  $result = dosomething_reportback_get_reportback_files_query_result($params, $page_size);
  // Get the total number of results.
  $total = dosomething_reportback_get_reportback_files_query_count($params);
  // If it's zero, reset the count variables.
  if (!$total) {
    $total = dosomething_reportback_get_reportback_files_query_count($params, $reset = TRUE);
  }
  $page_size_copy = '';
  if ($total > $page_size) {
    $page_size_copy = '<p>' . t("Displaying the most recent @num", array(
      '@num' => $page_size,
    )) . '</p>';
  }

  $form['count'] = array(
    '#markup' => t("Inbox: @total Reportback Images", array(
      '@num' => $page_size,
      '@total' => $total,
    )) . $page_size_copy,
  );

  foreach ($result as $record) {
    $rb_path = 'reportback/' . $record->rbid;
    $status = 'approved';
    if (isset($record->status) && $record->status != 'pending') {
      $status = $record->status;
    }
    $form['rb_files'][$record->fid] = array(
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
        '#default_value' => $status,
      ),
      'flagged_reason' => array(
        '#type' => 'checkboxes',
        '#options' => $flagged_options,
      ),
      'delete' => array(
        '#type' => 'checkbox',
        '#title' => t("Delete this image"),
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

  foreach ($rb_files as $fid => $values) {

    $rbf = reportback_file_load($fid);

    // Loop through the flagged_reason values:
    foreach ($values['flagged_reason'] as $reason_key => $reason_value) {
      // Form sends unchecked as a 0.
      if (!is_string($reason_value)) {
        unset($values['flagged_reason'][$reason_key]);
      }
    }

    // Overwrite flagged reason with the new concatenated string.
    $values['flagged_reason'] = implode(', ', $values['flagged_reason']);

    // Write the review data.
    $save = $rbf->review($values);
    if (!$save) {
      form_set_error(t("An error has occurred."));
    }

  }
  if (isset($form_state['values']['entity_type'])) {
    dosomething_reportback_reset_count($form_state['values']['entity_type'], $form_state['values']['entity_id']);
  }

  drupal_set_message(t("Updated."));
}

/**
 * Themes the dosomething_reportback_files_form constructor.
 */
function theme_dosomething_reportback_files_form($variables) {
  $form = $variables['form'];
  $view_mode = $form['view_mode']['#value'];

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
    $rbf = reportback_file_load($fid);
    $view = entity_view('reportback_file', array($rbf->fid => $rbf), $view_mode);
    $flag_form = drupal_render($form['rb_files'][$fid]['flagged_reason']);
    $flag_form .= drupal_render($form['rb_files'][$fid]['delete']);
    $rows[] = array(
      'data' => array(
        // Add the columns defined in the form.
        drupal_render($form['rb_files'][$fid]['date']),
        drupal_render($view),
        drupal_render($form['rb_files'][$fid]['quantity']),
        drupal_render($form['rb_files'][$fid]['node']),
        drupal_render($form['rb_files'][$fid]['status']) . '<div class="flag-form"><hr />' . $flag_form . '</div>',
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

  $output = '';
  if (arg(0) != 'reportback') {
    $output = drupal_render($form['count']);
  }

  // We can render our tabledrag table for output.
  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
  // And then render any remaining form elements (such as our submit button).
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Page callback which displays all Reportback Count variables.
 */
function dosomething_reportback_count_page() {
  $status_values = dosomething_reportback_get_file_status_values();

  $header = array(t('Title'));
  foreach ($status_values as $status) {
    $header[] = t($status);
  }

  $tables = array();
  $tables['node']['title'] = t("Campaigns");
  $tables['node']['url'] = 'node/';
  $tables['node']['results'] = dosomething_campaign_get_campaigns();

  $tables['taxonomy_term']['title'] = t("Cause");
  $tables['taxonomy_term']['url'] = 'taxonomy/term/';
  $tables['taxonomy_term']['results'] = array();
  $cause = taxonomy_vocabulary_machine_name_load('cause');
  if ($cause) {
    $tables['taxonomy_term']['results'] = taxonomy_get_tree($cause->vid);
  }

  foreach ($tables as $entity_type => $table) {
    $rows = array();
    foreach ($table['results'] as $record) {
      if ($entity_type === 'node') {
        $id = $record->nid;
        $title = $record->title;
      }
      else {
        $id = $record->tid;
        $title = $record->name;
      }
      $vars = dosomething_helpers_get_variables($entity_type, $id);
      ;
      // First column is a link to the entity.
      $row_values = array(l($title, $table['url'] . $id));
      // Loop through status values and set links for each.
      $i = 0;
      foreach ($status_values as $status) {
        $count = (int) $vars['count_' . $status];
        $url = $table['url'] . $id . '/rb';
        $options = array();
        if ($i > 0) {
          $url = $table['url'] . $id . '/rb/reviewed';
          $options = array('query' => array('status' => $i));
        }
        if ($count > 0) {
          $row_values[] = l($count, $url, $options);
        }
        else {
          $row_values[] = $count;
        }
        $i++;
      }
      $rows[] = $row_values;
    }
    $output .= '<h2>' . $table['title'] . '</h2>';
    $output .= theme('table', array(
      'header' => $header,
      'rows' => $rows,
    ));
  }

  if (user_access('administer modules')) {
    $reset_form = drupal_get_form('dosomething_reportback_reset_count_form');
    $output .= render($reset_form);
  }

  return $output;
}

/**
 * Form to reset all Reportback Count variables.
 */
function dosomething_reportback_reset_count_form() {
  $form['reset'] = array(
    '#type' => 'checkboxes',
    '#required' => TRUE,
    '#title' => t('Select totals to refresh'),
    '#options' => drupal_map_assoc(array(t('node'), t('taxonomy_term'))),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Refresh Totals'),
  );
  return $form;
}

/**
 * Submit handler for dosomething_reportback_reset_count_form().
 */
function dosomething_reportback_reset_count_form_submit($form, &$form_state) {
  $selected = array();
  foreach ($form_state['values']['reset'] as $entity_type => $value) {
    if ($value) {
      dosomething_reportback_reset_all($entity_type);
      $selected[] = $entity_type;
    }
  }
  drupal_set_message(t("Totals have been refreshed for @entity.", array(
    '@entity' => implode(', ', $selected),
  )));
}
