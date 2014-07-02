<?php

/**
 * @file
 * Code for Dosomething Helpers variable functionality.
 */

function dosomething_helpers_variable_form($form, &$form_state, $node) {
  $vars = dosomething_helpers_get_variables($node->nid);
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $node->nid,
  );
  $form['styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Styles'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['styles']['alt_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Alt color'),
    '#description' => t('Hex value to use for headlines.'),
    '#default_value' => $vars['alt_color'],
    '#field_prefix' => '#',
    '#size' => 6,
  );
  $form['styles']['alt_bg_fid'] = array(
    '#type' => 'textfield',
    '#title' => t('Alt BG File fid'),
    '#description' => t('File fid to display for BG pattern.'),
    '#default_value' => $vars['alt_bg_fid'],
    '#size' => 6,
  );
  $form['styles']['alt_image_campaign_cover_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Alt header Image nid'),
    '#description' => t('An Image Node nid to display in the page header.'),
    '#default_value' => $vars['alt_image_campaign_cover_nid'],
    '#size' => 6,
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => 'Save',
    ),
  );
  return $form;
}

function dosomething_helpers_variable_form_submit(&$form, &$form_state) {
  form_state_values_clean($form_state);
  $values = $form_state['values'];
  // Store hidden nid.
  $nid = $values['nid'];
  // Remove from values.
  unset($values['nid']);
  $node = node_load($nid);
  // Loop through all remaining values:
  foreach ($values as $name => $value) {
    // Save to the variable table.
    dosomething_helpers_set_variable($node, $name, $value);

  }
}

function dosomething_helpers_get_default_variables() {
  return array(
    'alt_bg_fid' => NULL,
    'alt_color' => NULL,
    'alt_image_campaign_cover_nid' => NULL,
  );
}

/**
 * Returns array of all dosomething_helper_variable records for a given $node.
 *
 * @return array
 *   Keyed by the variable name.
 */
function dosomething_helpers_get_variables($nid) {
  $vars = array();
  // Query for variable records for given $node.
  $result = db_select('dosomething_helpers_variable', 'v')
    ->fields('v')
    ->condition('entity_id', $nid)
    ->condition('entity_type', 'node')
    ->execute()
    ->fetchAll();
  foreach ($result as $record) {
    $vars[$record->name] = $record->value;
  }
  return array_merge(dosomething_helpers_get_default_variables(), $vars);
}

/**
 * Sets a given dosomething_helper variable $name to $value for given $node.
 */
function dosomething_helpers_set_variable($node, $name, $value) {
  // If a value is present:
  if (!empty($value)) {
    db_merge('dosomething_helpers_variable')
        ->key(array('entity_type' => 'node', 'entity_id' => $node->nid, 'name' => $name))
        ->fields(array(
            'entity_type' => 'node',
            'bundle' => $node->type,
            'entity_id' => $node->nid,
            'name' => $name,
            'value' => $value,
        ))
        ->execute();
  }
  // Else delete the value, to prevent storing an empty value.
  else {
    db_delete('dosomething_helpers_variable')
      ->condition('entity_id', $node->nid)
      ->condition('entity_type', 'node')
      ->condition('name', $name)
      ->execute();
  }
}
