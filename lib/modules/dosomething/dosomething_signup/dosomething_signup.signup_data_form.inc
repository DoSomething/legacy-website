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
