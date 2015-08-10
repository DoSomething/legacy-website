<?php

/**
 *  Implements hook_drush_command
 */
function dosomething_user_drush_command() {
  $items = array(
    'update-users-country' => array(
      'description' => 'Update country users address on DS affiliates.',
    ),
  );
  return $items;
}

/**
 * Callback for cancel-us-users command.
 *
 * Update country users address on DS affiliates.
 */
function drush_dosomething_user_update_users_country() {
  if (!dosomething_settings_is_affiliate()) {
    return t("Available only on affiliates.");
  }
  $lock = variable_get('dosomething_user_update_users_country_lock', FALSE);
  if ($lock) {
    return t("Waiting for previous operation to complete.");
  }
  variable_set('dosomething_user_update_users_country_lock', TRUE);
  // Determine counrty code.
  $country_code = dosomething_settings_get_affiliate_country_code();
  // Find not anonymous users…
  $query = db_select('users', 'u')->fields('u', array('uid'));
  $query->condition('u.uid', 0, '<>');
   // …with incorrect country…
  $query->leftJoin(
    'field_data_field_address', 'f',
    'f.entity_id = u.uid'
  );
  $where = db_or()
  ->condition(
    'f.field_address_country',
    $country_code,
    '<>'
  )
  // …or with no county set…
  ->isNull('f.entity_id', NULL);
  $query->condition($where);
  // Load sandbox data.
  $sandbox = variable_get('dosomething_user_update_users_country_sandbox');
  if (!isset($sandbox['total'])) {
    $sandbox['current'] = 0;
    $sandbox['total'] = $query->countQuery()->execute()->fetchField();
  }
  if (!$sandbox['total']) {
    variable_del('dosomething_user_update_users_country_lock');
    return t("All users has been fixed.");
  }
  // There are more than on and a half million users, we better keep it easy.
  $batch_size = 1000;
  $users = $query->range(0, $batch_size)->execute()->fetchAllKeyed(0, 0);
  $count = count($users);
  // Update a batch of users.
  if ($count > 0) {
    $users = user_load_multiple(array_keys($users));
    foreach ($users as $account) {
      $account->field_address[LANGUAGE_NONE][0]['country'] = $country_code;
      user_save($account);
    }
  }
  // Track progress.
  $sandbox['current'] += $count;
  // Sandbox #finished must be 1 when batch is finished.
  $sandbox['#finished'] = ($sandbox['current'] / $sandbox['total']);
  // Set status message on success.
  if ($sandbox['#finished'] === 1) {
    variable_del('dosomething_user_update_users_country_lock');
    variable_del('dosomething_user_update_users_country_sandbox');
    return t('Updated !total user accounts.',
             array('!total' => $sandbox['total']));
  }
  // Save the sandbox.
  variable_set('dosomething_user_update_users_country_lock', FALSE);
  variable_set('dosomething_user_update_users_country_sandbox', $sandbox);
  return t('Updated !current of !total user accounts.',
           array('!current' => $sandbox['current'],
                 '!total'   => $sandbox['total']));
}
