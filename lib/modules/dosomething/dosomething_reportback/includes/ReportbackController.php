<?php

/**
* Our custom controller for the dosomething_reportback type.
*/
class ReportbackController extends EntityAPIController {

/**
* Overrides buildContent() method.
*
* Adds Reportback properties into Reportback entity's render.
*/
public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
$build = parent::buildContent($entity, $view_mode, $langcode, $content);

// Load review form for the Reportback.
module_load_include('inc', 'dosomething_reportback', 'dosomething_reportback.admin');
$review_form = drupal_get_form('dosomething_reportback_files_form', NULL, $entity);

// If this reportback has been flagged:
if ($entity->flagged) {
$flagged_copy = 'Flagged as ' . $entity->flagged_reason . '.';
drupal_set_message($flagged_copy, 'warning');
}

// Load user to get username.
$account = user_load($entity->uid);
$build['username'] = array(
'#prefix' => '<p>',
  '#markup' => l($account->mail, 'user/' . $account->uid),
  '#suffix' => '</p>',
);
$build['node_title'] = array(
'#prefix' => '<p>',
  '#markup' => l($entity->node_title, 'node/' . $entity->nid),
  '#suffix' => '</p>',
);
$quantity_label = $entity->noun . ' ' . $entity->verb;
$build['quantity_count'] = array(
'#prefix' => '<p>',
  '#markup' => 'Quantity: <strong>' . check_plain($entity->quantity) . '</strong> ' . $quantity_label,
  '#suffix' => '</p>',
);
if ($entity->num_participants) {
$build['num_participants'] = array(
'#prefix' => '<p>',
  '#markup' => '# of Participants: <strong>' . $entity->num_participants . '</strong> ',
  '#suffix' => '</p>',
);
}
$build['why_participated'] = array(
'#prefix' => '<p>',
  '#markup' => 'Why participated:<br />' . check_plain($entity->why_participated),
  '#suffix' => '</p>',
);

$build['reportback_files'] = array(
'#markup' => drupal_render($review_form),
);

// Output Reportback Log.
$rows = array();
$header = array('Submitted', 'Op', 'Uid', 'Files', 'IP', 'Quantity', 'Why Participated');
foreach ($entity->getReportbackLog() as $delta => $record) {
$submitted = format_date($record->timestamp, 'short');
$why = check_plain($record->why_participated);
$rows[] = array($submitted, $record->op, $record->uid, $record->files, $record->remote_addr, $record->quantity, $why);
}
$build['reportback_log'] = array(
'#theme' => 'table',
'#prefix' => '<h3>Change Log</h3>',
'#header' => $header,
'#rows' => $rows,
);
return $build;
}

/**
* Overrides save() method.
*
* Populates created and uid automatically.
*/
public function save($entity, DatabaseTransaction $transaction = NULL) {
  global $user;
  $now = REQUEST_TIME;
  $op = 'update';
  if (isset($entity->is_new)) {
    $entity->created = $now;
    $op = 'insert';
  }
  $entity->updated = $now;
  if (DOSOMETHING_REPORTBACK_LOG) {
    watchdog('dosomething_reportback', 'save:' . json_encode($entity));
  }

  // Make sure a uid exists.
  if (!isset($entity->uid)) {
    return FALSE;
  }
  // If the entity uid doesn't belong to current user:
  if ($entity->uid != $user->uid) {
    // And current user can't edit any reportback:
    if (!user_access('edit any reportback') && !drupal_is_cli()) {
      watchdog('dosomething_reportback', "Attempted uid override for @reportback by User @uid",
      array(
      '@reportback' => json_encode($entity),
      '@uid' => $user->uid,
      ), WATCHDOG_WARNING);
      return FALSE;
    }
  }

  parent::save($entity, $transaction);

  // If a file fid exists:
  if (isset($entity->fid)) {
    // Add it into the reportback files.
    $entity->createReportbackFile($entity);
  }
  // Log the write operation.
  $entity->insertLog($op);

  // If this was an insert:
  if ($op == 'insert') {
    // Send Message Broker request.
    if (module_exists('dosomething_mbp')) {
      dosomething_reportback_mbp_request($entity);
    }
    if (module_exists('dosomething_reward')) {
      // Check for Reportback Count Reward.
      dosomething_reward_reportback_count($entity);
    }
  }

}

/**
* Overrides delete() method.
*/
public function delete($ids, DatabaseTransaction $transaction = NULL) {
// Log deletions.
foreach ($ids as $rbid) {
$rb = reportback_load($rbid);
$rb->insertLog('delete');
$rb->deleteFiles();
}
parent::delete($ids, $transaction);
}
}
