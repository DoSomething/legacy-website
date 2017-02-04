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
  $form['dosomething_reportback_display_permalink_share'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable sharing on the permalink page.'),
    '#default_value' => variable_get('dosomething_reportback_display_permalink_share', FALSE),
    '#description' => t("Displays the permalink share form/copy"),
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
  $promoted_options = array(
    'photo' => t('Good photo'),
    'quote' => t('Good quote'),
    'sponsored' => t('Good for sponsor'),
    'impact' => t('High impact')
  );

  // Provide options to update the rotation of the image.
  $rotate_options = array(
    '90' => 90,
    '180' => 180,
    '270' => 270,
    '360' => 360,
  );

  $params = array(
    'status' => $status,
  );

  // Display mode for rendering each Reportback File.
  $view_mode = 'full';

  // If we are viewing a reportback entity:
  if (isset($entity->rbid) && arg(1) === 'reportback') {
    $params['rbid'] = $entity->rbid;
    // If viewing a Reportback, don't repeat the Reportback details in each file.
    $view_mode = 'teaser';
  }
  elseif (isset($entity->nid)) {
    $params['nid'] = $entity->nid;
  }
  elseif (isset($entity->tid)) {
    $params['tid'] = $entity->tid;
  }

  $form['view_mode'] = array(
    '#type' => 'hidden',
    '#value' => $view_mode,
  );

  $page_size = 25;
  if (isset($_GET['pagesize'])) {
    $limit = $_GET['pagesize'];
    if (is_numeric($limit) || $limit < 100) {
      $page_size = $limit;
    }
  }

  $params['order'] = 'asc';
  $params['count'] = $page_size;

  // Get the DatabaseQuery to loop through.
  $result = dosomething_reportback_get_reportback_items_query($params);

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
    '#markup' => t("Total: @total Reportback Images", array(
      '@num' => $page_size,
      '@total' => $total,
    )) . $page_size_copy,
  );

  foreach ($result as $record) {
    $rb_path = 'admin/reportback/' . $record->rbid;
    // @TODO: temporarily disable pre-approved to unblock campaigns team from reviewing reportbacks.
    // Refs #4797
    // $status = 'approved';
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
        '#default_value' => $status ?: '',
      ),
      'promoted_reason' => array(
        '#type' => 'checkboxes',
        '#options' => $promoted_options,
      ),
      'flagged_reason' => array(
        '#type' => 'checkboxes',
        '#options' => $flagged_options,
      ),
      'delete' => array(
        '#type' => 'checkbox',
        '#title' => t("Delete this image"),
      ),
      // Provide an option to rotate the image.
      'rotate' => array(
        '#type' => 'radios',
        '#title' => t('Rotate (CW)'),
        '#options' => $rotate_options,
      )
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
  $user = dosomething_helpers_get_current_user();

  $rb_files = $form_state['values']['rb_files'];
  if (empty($rb_files) || !is_array($rb_files)) {
    return;
  }

  $updates_to_send_to_rogue = [];
  foreach ($rb_files as $fid => $values) {
    $kudos = [
      'fid' => $fid,
      'uid' => $user->drupal_id,
      // @TODO: use array_pop(Kudos::getApprovedReactions()) once new Kudos refactor is fully approved.
      'tid' => dosomething_kudos_get_term_id_by_name('heart'),
      'created' => time(),
    ];

    $rbf = reportback_file_load($fid);

    if ($values['status'] === 'promoted') {
      dosomething_reportback_set_promote_flag_reasons($values, 'promoted_reason');
    }
    elseif ($values['status'] === 'flagged') {
      dosomething_reportback_set_promote_flag_reasons($values, 'flagged_reason');
    }

    // Write the review data.
    $save = $rbf->review($values);

    if (!$save) {
      form_set_error(t("An error has occurred."));
    }

    // Save kudos reaction from admin on RB item.
    if ($values['status'] === 'promoted' || $values['status'] === 'approved' || $values['status'] === 'excluded') {
      $record = (new KudosController)->create($kudos);
    }

    // Rotate the original image, if a rotation option was selected.
    if ($values['rotate']) {
      // Load the file.
      $file = file_load($fid);
      // Create an image object.
      $image = image_load($file->uri);
      // Rotate the image.
      image_rotate($image, $values['rotate'], 0xffffff);
      // Save.
      image_save($image);
      // Flush the image style cache for this image so they update with the new image.
      image_path_flush($image->source);
    }

    // Check to see if Rogue feature flag is enabled.
    if (variable_get('rogue_collection', FALSE)) {
      $rogue_item_id = dosomething_rogue_get_by_file_id($fid);
      // If there is a rogue_item_id in the dosomething_rogue_reportbacks table, send update to Rogue.
      if ($rogue_item_id[0]->rogue_event_id) {
        if ($values['status'] === 'promoted' || $values['status'] === 'approved' || $values['status'] === 'excluded') {
          $rogue_status = 'accepted';
        } else {
          $rogue_status = 'rejected';
        }

        $data = [
          'rogue_event_id' => $rogue_item_id[0]->rogue_event_id,
          'status' => $rogue_status,
          'event_type' => 'review_photo',
        ];

        $updates_to_send_to_rogue[] = $data;
      }
    }
  }

  // Send updates to Rogue.
  if (variable_get('rogue_collection', FALSE)) {
    $response = dosomething_rogue_update_rogue_reportback_items($updates_to_send_to_rogue);

    if ($response->code != 201) {
      drupal_set_message(print_r($response->code, TRUE) . ' ' . print_r($response->status_message, TRUE), 'warning');
    } else {
      drupal_set_message(t("Updated."));
    }
  }
}

/**
 * Set flagged and promoted reasons.
 * @param array values
 *   Form values submission array
 * @param string $reason_type
 *  Either flagged_reason or promoted_reason
 */
function dosomething_reportback_set_promote_flag_reasons(&$values, $reason_type) {
    // Loop through the reason values:
    foreach ($values[$reason_type] as $reason_key => $reason_value) {
      // Form sends unchecked as a 0.
      if (!is_string($reason_value)) {
        unset($values[$reason_type][$reason_key]);
      }
    }

    // Overwrite reasons with the new concatenated string.
    $values[$reason_type] = implode(', ', $values[$reason_type]);
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
    $view = entity_view('reportback_item', array($rbf->fid => $rbf), $view_mode);
    $promote_form = drupal_render($form['rb_files'][$fid]['promoted_reason']);
    $flag_form = drupal_render($form['rb_files'][$fid]['flagged_reason']);
    $flag_form .= drupal_render($form['rb_files'][$fid]['delete']);
    $rows[] = array(
      'data' => array(
        // Add the columns defined in the form.
        drupal_render($form['rb_files'][$fid]['date']),
        drupal_render($form['rb_files'][$fid]['node']),
        drupal_render($form['rb_files'][$fid]['rotate']),
        drupal_render($view),
        '<h3>' . drupal_render($form['rb_files'][$fid]['quantity']) . '</h3>',
        drupal_render($form['rb_files'][$fid]['status']) . '<div class="flag-form"><hr />' . $flag_form . '</div>' .  drupal_render($form['rb_files'][$fid]['status']) . '<div class="promote-form"><hr />' . $promote_form . '</div>',

      ),
    );
  }
  $header = array(
    t('Submitted'),
    t('Campaign'),
    t('Rotate (CW)'),
    NULL,
    t('Quantity'),
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
  $output = '';
  $status_values = dosomething_reportback_get_file_status_values();
  $params = ['type' => 'campaign'];

  $header = array(t('Title'));
  foreach ($status_values as $status) {
    $header[] = t($status);
  }

  $tables = array();
  $tables['node']['title'] = t("Campaigns");
  $tables['node']['url'] = 'node/';
  $tables['node']['results'] = dosomething_campaign_get_campaigns_query_result($params, 'all');

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

  return $output;
}
