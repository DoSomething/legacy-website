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
