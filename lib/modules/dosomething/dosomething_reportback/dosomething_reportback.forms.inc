<?php

/**
 * @file
 * Provides form constructors for the DoSomething Reportback module.
 */

/**
 * Adds form elements to given node $form to add additional reportback field.
 *
 * For now, this only supports adding one additional reportback field to a node.
 *
 * Note there is no submit form element returned.
 * This function is always called from within a node edit form.
 */
function _dosomething_reportback_node_reportback_field_form(&$form, &$form_state) {
  $nid = $form['nid']['#value'];
  $values = dosomething_reportback_get_reportback_field_info($nid);
  $fieldset = 'reportback_field';
  $prefix = $fieldset . '_';
  // Set an additional submit handler to save the dosomething_reportback_field values.
  $form['#submit'][] = 'dosomething_reportback_node_reportback_field_form_submit';
  // Create fieldset to collect signup data form values.
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
     // Only support radios for now.
     '#options' => array(
        'radios' => t('Radios'),
     ),
     '#default_value' => $values['type'],
  );
  $form[$fieldset]['config'][$prefix . 'options'] = array(
    '#type' => 'textarea',
    '#title' => t('Field options'),
    '#default_value' => $values['options'],
  );
}

/**
 * Saves node reportback_field values into dosomething_reportback_field table.
 */
function dosomething_reportback_node_reportback_field_form_submit(&$form, &$form_state) {
  $nid = $form['nid']['#value'];
  $values = $form_state['values'];
  $prefix = 'reportback_field_';
  // Use db_merge to either insert or update existing record for $nid / $name.
  db_merge('dosomething_reportback_field')
    ->key(array('nid' => $nid, 'name' => $values[$prefix . 'name']))
    ->fields(array(
        'status' => $values[$prefix . 'status'],
        'label' => $values[$prefix . 'label'],
        'type' => $values[$prefix . 'type'],
        'options' => $values[$prefix . 'options'],
    ))
    ->execute();
}

/**
 * Returns a Form API element based on given dosomething_reportback_field values.
 *
 * @param array $config
 *   The dosomething_reportback_value record.
 * @param string $value
 *   Optional. The user value (if exists).
 */
function dosomething_reportback_get_reportback_field_form_element($config, $value = '') {
  $element = array(
    '#title' => $config['label'],
    '#type' => $config['type'],
    '#required' => TRUE,
  );
  // @todo. Make this dynamic. Hardcoded for now, for Comeback Clothes.
  $element['#options'] = array(
    1 => t('Yes'),
    0 => t('No'),
  );
  if (!empty($value)) {
    $element['#default_value'] = $value;
  }
  return $element;
}
