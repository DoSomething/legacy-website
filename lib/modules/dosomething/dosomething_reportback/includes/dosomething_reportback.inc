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
   * Override construct to set calculated properties.
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
      $this->noun = $this->getNodeSingleTextValue('field_reportback_noun');
      $this->verb = $this->getNodeSingleTextValue('field_reportback_verb');
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
   * Return all data for reportback files and their promoted flags (if they exist).
   */
  public function getReportbackFileData() {
    $file_data = array();

    // Query for all reportback file records.
    $result = db_select($this->files_table, 'f')
      ->fields('f')
      ->condition('rbid', $this->rbid)
      ->execute()
      ->fetchAll();

    // Loop through $result to add any promoted flaggings:
    foreach ($result as $delta => $record) {
      $file_data[$delta] = $record;
      $file_data[$delta]->promoted = $this->getPromotedFlagging($record->fid);
    }

    return $file_data;
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
   * Returns reportback's "flagged_reportback" Flagging entity if exists.
   */
  public function getFlaggedFlagging() {
    // If a flagged_reportback flagging entity exists for this reportback:
    if ($result = flag_get_entity_flags('reportback', $this->rbid, 'flagged_reportback')) {
      return flagging_load($result[0]->flagging_id);
    }
    return NULL;
  }

  /**
   * Returns "promoted" Flagging entity for given $fid if exists.
   */
  public function getPromotedFlagging($fid) {
    if ($result = flag_get_entity_flags('file', $fid, 'promoted')) {
      return flagging_load($result[0]->flagging_id);
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
    return db_insert($this->files_table)
      ->fields(array(
          'rbid' => $this->rbid,
          'fid' => $values->fid,
          'caption' => $values->caption,
          'remote_addr' => dosomething_helpers_ip_address(),
        ))
      ->execute();
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
      $file = file_load($fid);
      file_delete($file);
    }
    // Delete the files table rows.
    db_delete($this->files_table)
      ->condition('rbid', $this->rbid)
      ->execute();
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

    // If this reportback has been flagged:
    if ($flagging = $entity->getFlaggedFlagging()) {
      $wrapper = entity_metadata_wrapper('flagging', $flagging);
      $flagged_time = format_date($flagging->timestamp, 'short');
      $flagged_reason = implode(', ', $wrapper->field_flagged_reason->value());
      $flagged_copy = 'Flagged on ' . $flagged_time . ' as ' . $flagged_reason . '.';
      drupal_set_message($flagged_copy, 'warning');
    }

    // Load user to get username.
    $account = user_load($entity->uid);
    $build['username'] = array(
      '#prefix' => '<p>',
      '#markup' => 'User: ' . l($account->name, 'user/' . $account->uid),
      '#suffix' => '</p>',
    );
    $build['node_title'] = array(
      '#prefix' => '<p>',
      '#markup' => 'Node: ' . l($entity->node_title, 'node/' . $entity->nid . '/reportbacks'),
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
    // Output Reportback Files.
    $rows = array();
    $header = array(
      t('Fid'),
      t('Image'),
      t('Caption'),
      t('IP'),
      t('Created'),
      NULL,
    );
    foreach ($entity->getReportbackFileData() as $delta => $record) {
      $fid = $record->fid;
      $image = dosomething_image_get_themed_image_by_fid($fid, 'thumbnail');
      $file = file_load($fid);
      $file_url = file_create_url($file->uri);
      $file_link = l($fid, $file_url);
      $image = l($image, $file_url, array('html' => TRUE));
      $created = format_date($file->timestamp, 'short');
      $promoted = NULL;
      // If file has been promoted:
      if ($flagging = $record->promoted) {
        $caption = $flagging->field_image_description[LANGUAGE_NONE][0]['safe_value'];
        $promoted = "Promoted on " . format_date($flagging->timestamp, 'short');
        $promoted .= $caption;
      }
      $rows[] = array(
        $file_link,
        $image,
        $record->caption,
        $record->remote_addr,
        $created,
        $promoted,
      );
    }
    $build['reportback_files'] = array(
      '#theme' => 'table',
      '#prefix' => '<h3>Files</h3>',
      '#header' => $header,
      '#rows' => $rows,
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
    // If the entity uid doesnt belong to current user:
    if ($entity->uid != $user->uid) {
      // And current user can't edit any reportback:
      if (!user_access('edit any reportback')) {
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
    foreach ($ids as $id) {
      $rb = reportback_load($id);
      $rb->insertLog('delete');
    }
    parent::delete($ids, $transaction);
  }
}
