<?php
/**
 * @file
 * Code for dosomething_signup_data_form functionality.
 */

/**
 * Returns the dosomething_signup_data_form values for a given $nid.
 *
 * @param int $nid
 *   The node nid of the signup_data_form record to check.
 *
 * @return mixed
 *   An array of the signup data form values if exists, NULL if doesn't exist.
 */
function dosomething_signup_get_signup_data_form_info($nid) {
  return db_select('dosomething_signup_data_form', 's')
    ->fields('s')
    ->condition('nid', $nid)
    ->execute()
    ->fetchAssoc();
}

/**
 * Adds form elements to given node $form to store nid signup_data_form values.
 *
 * Note there is no submit form element returned.
 * This function is always called from within a node edit form. 
 */
function dosomething_signup_node_signup_data_form(&$form, &$form_state) {
  $nid = $form['nid']['#value'];
  $values = dosomething_signup_get_signup_data_form_info($nid);
  // Set an additional submit handler to save the signup_data_form values.
  $form['#submit'][] = 'dosomething_signup_node_signup_data_form_submit';
  $form['signup_data_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup Data Form'),
    '#weight' => 60,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['signup_data_form']['signup_data_form_status'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Collect additional signup data'),
    '#default_value' => $values['status'],
  );
}

/**
 * Saves node signup_data_form values into dosomething_signup_data_form.
 */
function dosomething_signup_node_signup_data_form_submit(&$form, &$form_state) {
  $nid = $form['nid']['#value'];
  $values = $form_state['values'];
  // Use db_merge to either insert or update existing record for $nid.
  db_merge('dosomething_signup_data_form')
    ->key(array('nid' => $nid))
    ->fields(array(
        'status' => $values['signup_data_form_status'],
    ))
    ->execute();
}
