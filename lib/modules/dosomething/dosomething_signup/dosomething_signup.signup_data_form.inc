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
  $fieldset = 'signup_data_form';
  $prefix = $fieldset . '_';
  // Set an additional submit handler to save the signup_data_form values.
  $form['#submit'][] = 'dosomething_signup_node_signup_data_form_submit';
  // Create fieldset to collect signup data form values.
  $form[$fieldset] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup Data Form'),
    '#weight' => 60,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form[$fieldset][$prefix . 'status'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Collect additional signup data'),
    '#default_value' => $values['status'],
  );
  $form[$fieldset][$prefix . 'link_text'] = array(
    '#type' => 'textfield', 
    '#title' => t('Link text'),
    '#default_value' => $values['link_text'],
  );
  $form[$fieldset][$prefix . 'form_header'] = array(
    '#type' => 'textfield', 
    '#title' => t('Form header'),
    '#default_value' => $values['form_header'],
  );
  $form[$fieldset][$prefix . 'form_copy'] = array(
    '#type' => 'textarea', 
    '#title' => t('Form copy'),
    '#default_value' => $values['form_copy'],
  );
  $form[$fieldset][$prefix . 'collect_user_address'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Collect user address'),
    '#default_value' => $values['collect_user_address'],
  );
  $form[$fieldset][$prefix . 'collect_user_mobile'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Collect user mobile'),
    '#default_value' => $values['collect_user_birthdate'],
  );
  $form[$fieldset][$prefix . 'collect_user_birthdate'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Collect user birthdate'),
    '#default_value' => $values['collect_user_birthdate'],
  );
}

/**
 * Saves node signup_data_form values into dosomething_signup_data_form.
 */
function dosomething_signup_node_signup_data_form_submit(&$form, &$form_state) {
  $nid = $form['nid']['#value'];
  $values = $form_state['values'];
  $prefix = 'signup_data_form_';
  // Use db_merge to either insert or update existing record for $nid.
  db_merge('dosomething_signup_data_form')
    ->key(array('nid' => $nid))
    ->fields(array(
        'status' => $values[$prefix . 'status'],
        'link_text' => $values[$prefix . 'link_text'],
        'form_header' => $values[$prefix . 'form_header'],
        'form_copy' => $values[$prefix . 'form_copy'],
        'collect_user_address' => $values[$prefix . 'collect_user_address'],
        'collect_user_birthdate' => $values[$prefix . 'collect_user_mobile'],
        'collect_user_birthdate' => $values[$prefix . 'collect_user_birthdate'],
    ))
    ->execute();
}
