<?php

/**
 * @file
 * Provides form constructors for the DoSomething Reportback module.
 */

/**
 * Form constructor to add additional reportback field to given $node.
 *
 * For now, this only supports adding one additional reportback field to a node.
 */
function dosomething_reportback_node_reportback_field_form($form, &$form_state, $node) {
  $nid = $node->nid;
  // Load existing reportback_field config info.
  $values = dosomething_reportback_get_reportback_field_info($nid);
  $fieldset = 'reportback_field';
  $prefix = $fieldset . '_';
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );
  $form[$fieldset] = array(
    '#type' => 'fieldset',
    '#title' => t('Reportback Fields'),
    '#weight' => 60,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form[$fieldset][$prefix . 'status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add additional reportback field'),
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
  $form[$fieldset]['config'][$prefix . 'name'] = array(
    '#type' => 'textfield',
    '#title' => t('Field name'),
    '#default_value' => $values['name'],
  );
  // If a name value is set:
  if (isset($values['name']) && !empty($values['name'])) {
    // Don't allow editing.
    $form[$fieldset]['config'][$prefix . 'name']['#disabled'] = TRUE;
  }
  $form[$fieldset]['config'][$prefix . 'label'] = array(
    '#type' => 'textfield',
    '#title' => t('Field label'),
    '#default_value' => $values['label'],
  );
  $form[$fieldset]['config'][$prefix . 'type']= array(
     '#type' => 'select',
     '#title' => t('Field type'),
     '#options' => array(
        'radios' => t('Yes/No'),
        'textarea' => t('Textarea'),
     ),
     '#default_value' => $values['type'],
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
 * Saves node reportback_field values into dosomething_reportback_field table.
 */
function dosomething_reportback_node_reportback_field_form_submit(&$form, &$form_state) {
  $values = $form_state['values'];
  $nid = $values['nid'];
  $prefix = 'reportback_field_';
  // Use db_merge to either insert or update existing record for $nid / $name.
  db_merge('dosomething_reportback_field')
    ->key(array('nid' => $nid, 'name' => $values[$prefix . 'name']))
    ->fields(array(
        'status' => $values[$prefix . 'status'],
        'label' => $values[$prefix . 'label'],
        'type' => $values[$prefix . 'type'],
    ))
    ->execute();
  drupal_set_message(t("Reportback field configuration saved."));
}

/**
 * Returns a Form API element based on given entity values.
 *
 * @param array $rb_field
 *   The field array as per returned by a loaded reportback $entity->field.
 *
 * @return array
 *   An array to use as a form element.
 */
function dosomething_reportback_get_reportback_field_form_element($rb_field) {
  $element = array(
    '#title' => $rb_field['label'],
    '#type' => $rb_field['type'],
    '#required' => TRUE,
  );
  if ($element['#type'] == 'radios') {
    // Hardcoded for now until we take on Github issue #1710.
    $element['#options'] = array(
      1 => t('Yes'),
      0 => t('No'),
    ); 
  }
  // If a value exists for the entity:
  if (isset($rb_field['value'])) {
    // Set it as the default value.
    $element['#default_value'] = $rb_field['value'];
  }
  return $element;
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
