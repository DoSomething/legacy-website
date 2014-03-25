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
function _dosomething_signup_node_signup_data_form(&$form, &$form_state) {
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
  $form[$fieldset][$prefix . 'confirm_msg'] = array(
    '#type' => 'textarea', 
    '#title' => t('Confirmation message'),
    '#default_value' => $values['confirm_msg'],
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
        'confirm_msg' => $values[$prefix . 'confirm_msg'],
        'collect_user_address' => $values[$prefix . 'collect_user_address'],
        'collect_user_birthdate' => $values[$prefix . 'collect_user_mobile'],
        'collect_user_birthdate' => $values[$prefix . 'collect_user_birthdate'],
    ))
    ->execute();
}

/**
 * Form constructor for a user signup data form.
 *
 * @param int $nid
 *   The node which the signup data form is rendered on.
 */
function dosomething_signup_user_signup_data_form($form, &$form_state, $nid) {
  $config = dosomething_signup_get_signup_data_form_info($nid);
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );
  $form['header'] = array(
    '#prefix' => '<h3>',
    '#markup' => $config['form_header'],
    '#suffix' => '</h3>',
  );
  $form['copy'] = array(
    '#prefix' => '<p>',
    '#markup' => $config['form_copy'],
    '#suffix' => '</p>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $label,
    '#attributes' => array(
      'class' => array(
        'btn',
        'large',
      ),
    ),
  );
  return $form;
}

/**
 * Form submit handler for dosomething_signup_user_signup_data_form().
 */
function dosomething_signup_user_signup_data_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $config = dosomething_signup_get_signup_data_form_info($values['nid']);
  // Update signup record.
  dosomething_signup_update_signup_data($values);
  // Display the signup_data_form's confirm_msg field.
  drupal_set_message($config['confirm_msg']);
}

/**
 * Saves signup_form_data to the relevant signup.
 */
function dosomething_signup_update_signup_data($values) {
  // Find the relevant signup sid to update.
  $sid = dosomething_signup_exists($values['nid']);
  try {
    db_update('dosomething_signup')
    ->fields(array(
      'signup_data_form_timestamp' => REQUEST_TIME,
    ))
    ->condition('sid', $sid)
    ->execute();  
    return TRUE;
  }
  catch (Exception $e) {
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
  return FALSE;
}
