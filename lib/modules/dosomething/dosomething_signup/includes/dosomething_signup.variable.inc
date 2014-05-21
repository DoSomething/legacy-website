<?php

/**
 * @file
 * Provides custom variable get and set functions for DoSomething Signup.
 */

/**
 * Returns value of given Signup variable name for given entity id/type.
 */
function dosomething_signup_variable_get($entity_id, $name, $entity_type = 'node') {
  return db_select('dosomething_signup_variable', 'v')
    ->fields('v', array('value'))
    ->condition('entity_id', $entity_id)
    ->condition('entity_type', $entity_type)
    ->condition('name', $name)
    ->execute()
    ->fetchField(0);
}

/**
 * Sets a given Signup variable name and value for given entity id/type.
 */
function dosomething_signup_variable_set($entity_id, $name, $value, $entity_type = 'node') {
  // If an empty string was passed:
  if (empty($value)) {
    // Delete the record.
    dosomething_signup_variable_del($entity_id, $name, $entity_type);
    return;
  }
  try {
     // Adds or updates variable value for variable $name and given $entity.
    return db_merge('dosomething_signup_variable')
      ->key(array(
          'entity_type' => $entity_type,
          'entity_id' => $entity_id,
          'name' => $name,
        ))
      ->fields(array(
          'entity_type' => $entity_type,
          'entity_id' => $entity_id,
          'name' => $name,
          'value' => $value,
      ))
      ->execute();
  }
  catch (Exception $e) {
    // Keep message general in case a user ever sees it.
    drupal_set_message(t("There was an error processing your request."));
    // Log the error.
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
}

/**
 * Deletes dosomething_signup_variable record for given entity type, id , and variable name.
 */
function dosomething_signup_variable_del($entity_id, $name, $entity_type = 'node') {
  return db_delete('dosomething_signup_variable')
    ->condition('entity_id', $entity_id)
    ->condition('entity_type', $entity_type)
    ->condition('name', $name)
    ->execute();
}
