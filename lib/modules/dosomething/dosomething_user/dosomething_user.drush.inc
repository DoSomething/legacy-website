<?php

/**
 *  Implements hook_drush_command
 */
function dosomething_user_drush_command() {
  $items = array(
    'cancel-us-users' => array(
      'description' => 'Removes US users from DS affiliates.',
    ),
  );
  return $items;
}

/**
 * Callback for cancel-us-users command.
 *
 * Removes US users from DS affiliates.
 */
function drush_dosomething_user_cancel_us_users() {
  if (!dosomething_settings_is_affiliate()) {
    return t("Available only on affiliates.");
  }

  // Find users…
  $query = db_select('users', 'u')->fields('u', array('uid'));

  // …registered before the international release (2014-09-03 23:00:00 UTC)…
  $date = new DateTime('2014-09-03T23:00:00Z');
  $where = db_or()
  ->condition(
    'u.created',
    $date->getTimestamp(),
    '<'
  );
  $query->condition($where);

  // …and not staff…
  $staff_roles = array(
    user_role_load_by_name('administrator')->rid,
    user_role_load_by_name('editor')->rid,
  );
  $query->leftJoin('users_roles', 'r', 'r.uid = u.uid');
  $where = db_or()
  ->condition('r.rid', $staff_roles, 'not IN')
  // …or don't have any role assigned…
  ->isNull('r.uid', NULL);
  $query->condition($where);
  // …and not the anonymous.
  $query->condition('u.uid', 0, '<>');

  // Load sandbox data.
  $sandbox = variable_get('dosomething_user_cancell_us_users_sandbox');
  if (!isset($sandbox['total'])) {
    $sandbox['current'] = 0;
    $sandbox['total'] = $query->countQuery()->execute()->fetchField();
  }

  if (!$sandbox['total']) {
    return t("User cleansing has finished.");
  }

  // There are more than on and a half million users, we better keep it easy.
  $batch_size = 1000;
  $users = $query->range(0, $batch_size)->execute()->fetchAllKeyed(0, 0);
  $count = count($users);

  // Delete a batch of users.
  if ($count > 0) {
    user_delete_multiple(array_keys($users));
  }

  // Track progress.
  $sandbox['current'] += $count;

  // Sandbox #finished must be 1 when batch is finished.
  $sandbox['#finished'] = ($sandbox['current'] / $sandbox['total']);

  // Set status message on success.
  if ($sandbox['#finished'] === 1) {
    variable_del('dosomething_user_cancell_us_users_sandbox');
    return t('Canceled !total user accounts.',
             array('!total' => $sandbox['total']));
  }

  // Save the sandbox.
  variable_set('dosomething_user_cancell_us_users_sandbox', $sandbox);
  return t('Canceled !current of !total user accounts.',
           array('!current' => $sandbox['current'],
                 '!total'   => $sandbox['total']));
}
