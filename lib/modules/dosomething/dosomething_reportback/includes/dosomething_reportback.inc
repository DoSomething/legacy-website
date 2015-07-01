<?php

/**
 * @file
 * Provides classes for the Reportback Entity.
 */

/**
 * Our Reportback entity class.
 */
class ReportbackEntity extends Entity {
  protected $files_table = 'dosomething_reportback_file';
  protected $log_table = 'dosomething_reportback_log';

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'reportback/' . $this->identifier());
  }

  /**
   * Overrides construct to set calculated properties.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);
    $this->fids = array();
    // If this is a new entity, rbid may not be set.
    if (isset($this->rbid)) {
      $this->fids = $this->getFids();
    }
    // If a reportback nid exists:
    if (isset($this->nid)) {
      // Set properties found on the reportback's node nid.
      $this->node_title = $this->getNodeTitle();

      if (module_exists('dosomething_campaign_run')) {
        // Check if this reportback is associated with Campaign Run node.
        if ($parent_nid = dosomething_campaign_run_get_parent_nid($this->nid)) {
          // Use the Campaign node nid instead of the Run nid.
          $this->nid = $parent_nid;
        }
      }

      $this->noun = $this->getNodeSingleTextValue('field_reportback_noun');
      $this->verb = $this->getNodeSingleTextValue('field_reportback_verb');
      $this->quantity_label = $this->noun . ' ' . $this->verb;
    }
  }

  /**
   * Return all fids from dosomething_reportback_files table for this entity.
   */
  public function getFids() {
    return db_select($this->files_table, 'f')
      ->fields('f', array('fid'))
      ->condition('rbid', $this->rbid)
      ->execute()
      ->fetchCol();
  }

  /**
   * Return all data from dosomething_reportback_log table for this entity.
   */
  public function getReportbackLog() {
    return db_select($this->log_table, 'l')
      ->fields('l')
      ->condition('rbid', $this->rbid)
      ->execute()
      ->fetchAll();
  }

  /**
   * Returns the node title of the $entity->nid.
   */
  public function getNodeTitle() {
    $result = db_select('node', 'n')
      ->fields('n', array('title'))
      ->condition('nid', $this->nid)
      ->execute()
      ->fetchCol();
    if ($result) {
      return $result[0];
    }
    return NULL;
  }

  /**
   * Returns a single text value for a given $field_name for the $entity->nid.
   */
  public function getNodeSingleTextValue($field_name) {
    $result = db_select('field_data_' . $field_name, 'f')
      ->fields('f', array($field_name . '_value'))
      ->condition('entity_id', $this->nid)
      ->condition('entity_type', 'node')
      ->execute()
      ->fetchCol();
    if ($result) {
      return $result[0];
    }
    return NULL;
  }

  /**
   * Inserts given fid into dosomething_reportback_files table for this entity.
   *
   * @param object $values
   *   Values to write to a dosomething_reportback_file record.
   */
  public function createReportbackFile($values) {
    if (!isset($values->caption)) {
      $values->caption = NULL;
    }
    // Default status should be pending:
    $status = 'pending';
    // If this reportback has been flagged already:
    if ($this->flagged) {
      $status = 'flagged';
    }
    $reportback_file = entity_create('reportback_file', array(
      'rbid' => $this->rbid,
      'fid' => $values->fid,
      'caption' => $values->caption,
      'remote_addr' => dosomething_helpers_ip_address(),
      'status' => $status,
    ));
    return $reportback_file->save();
  }

  /**
   * Logs current entity values with given $op string.
   */
  public function insertLog($op) {
    global $user;
    // Store global uid, in rare case this is staff editing a reportback record.
    $uid = $user->uid;
    // If there is no uid, it's because this is a mobile submission.
    if ($uid == 0) {
      // Use the uid on the reportback entity instead.
      $uid = $this->uid;
    }
    // If deleting, store current time.
    if ($op == 'delete') {
      $timestamp = REQUEST_TIME;
    }
    // Else use the entity's updated property.
    else {
      $timestamp = $this->updated;
    }
    try {
      // Grab file fids to keep as a record.
      $fids = $this->getFids();
      // Log the entity values into the log table.
      $id = db_insert($this->log_table)
        ->fields(array(
          'rbid' => $this->rbid,
          'uid' => $uid,
          'op' => $op,
          'timestamp' => $timestamp,
          'quantity' => $this->quantity,
          'why_participated' => $this->why_participated,
          'files' => implode(',', $fids),
          'num_files' => count($fids),
          'remote_addr' => dosomething_helpers_ip_address(),
        ))
        ->execute();
    }
    catch (Exception $e) {
      watchdog('dosomething_reportback', $e, array(), WATCHDOG_ERROR);
    }
  }

  /**
   * Returns array of themed images for this Reportback.
   */
  public function getThemedImages($style) {
    $images = array();
    if (!module_exists('dosomething_image')) return $images();

    foreach ($this->fids as $fid) {
      $images[] = dosomething_image_get_themed_image_by_fid($fid, $style);
    }
    return $images;
  }

  /**
   * Deletes the Reportback files.
   */
  public function deleteFiles() {
    // Loop through the reportback files:
    foreach ($this->getFids() as $fid) {
      $rbf = reportback_file_load($fid);
      $rbf->delete();
    }
  }

  /**
   * Flags or promotes the reportback, and adds reasons.
   *
   * @param string $status
   *   The status of the reprotback file (approved, flagged, excluded, promoted)
   * @param array $values
   *   Array storing values for flagged/promoted reasons.
   */
  public function setFlaggedPromoted($status = NULL, $values = NULL) {
    if ($status === 'flagged') {
      $this->flagged = 1;
      $this->flagged_reason = $values['flagged_reason'] ?: NULL;
    }
    elseif ($status === 'promoted') {
      $this->promoted = 1;
      $this->promoted_reason = $values['promoted_reason'] ?: NULL;
    }
    else {
      $this->flagged = 0;
      $this->promoted = 0;
    }
    return entity_save('reportback', $this);
  }

}

/**
 * Our custom controller for the dosomething_reportback type.
 */
class ReportbackEntityController extends EntityAPIController {

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
