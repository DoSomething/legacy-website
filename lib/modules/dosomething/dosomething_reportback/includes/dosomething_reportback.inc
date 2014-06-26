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
  protected $field_data_table = 'dosomething_reportback_field_data';

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
      // Store the field configuration info.
      $this->field = dosomething_reportback_get_reportback_field_info($this->nid);
      // If existing reportback and active field:
      if (isset($this->rbid) && $this->field && $this->field['status'] == 1) {
        // Store the user value for the reportback field.
        $this->field['value'] = $this->getFieldValue($this->field['name']);
      }
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
   * Gets value from dosomething_reportback_field_data table for given $name.
   */
  public function getFieldValue($name) {
    $result = db_select($this->field_data_table, 'd')
      ->fields('d', array('value'))
      ->condition('rbid', $this->rbid)
      ->condition('name', $name)
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
   */
  public function insertFid($fid) {
    return db_insert($this->files_table)
      ->fields(array(
        'rbid' => $this->rbid,
        'fid' => $fid,
        'remote_addr' => dosomething_helpers_ip_address(),
        ))
      ->execute();
  }

  /**
   * Saves given $value into dosomething_reportback_field_data for given $name.
   */
  public function saveFieldValue($name, $value) {
    return db_merge($this->field_data_table)
      ->key(array(
          'rbid' => $this->rbid,
          'name'  => $name,
        ))
      ->insertFields(array(
          'rbid' => $this->rbid,
          'name'  => $name,
          'value' => $value,
        ))
      ->updateFields(array(
          'value' => $value,
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
      // Gather field_data to log all changes.
      $field_values = $this->field_values;
      // If a field value exists:
      if ($field_values != NULL) {
        // Serialize to store in the log table.
        $field_values = serialize($field_values);
      }
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
          'field_data' => $field_values,
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
      // If entity has an active reportback field:
    if (isset($entity->field) && $entity->field['status']==1) {
      $reportback_field_label = $entity->field['label'];
      if (isset($entity->field['value'])) {
        $build['reportback_field_value'] = array(
          '#prefix' => '<p>',
          '#markup' => $reportback_field_label . ' ' . check_plain($entity->field['value']),
          '#suffix' => '</p>',
        );
      }
    }
    $build['why_participated'] = array(
      '#prefix' => '<p>',
      '#markup' => 'Why participated:<br />' . check_plain($entity->why_participated),
      '#suffix' => '</p>',
    );
    // Output Reportback Files.
    $rows = array();
    $header = array('Fid', 'Image', 'IP', 'Created', NULL);
    foreach ($entity->getReportbackFileData() as $delta => $record) {
      $fid = $record->fid;
      $image = dosomething_image_get_themed_image_by_fid($fid, 'thumbnail');
      $file = file_load($fid);
      $file_link = l($fid, 'file/' . $fid);
      $created = format_date($file->timestamp, 'short');
      $promoted = NULL;
      // If file has been promoted:
      if ($flagging = $record->promoted) {
        $caption = $flagging->field_image_description[LANGUAGE_NONE][0]['safe_value'];
        $promoted = "Promoted on " . format_date($flagging->timestamp, 'short');
        $promoted .= $caption;
      }
      $rows[] = array($file_link, $image, $record->remote_addr, $created, $promoted);
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
    $now = REQUEST_TIME;
    $op = 'update';
    if (isset($entity->is_new)) {
      $entity->created = $now;
      $op = 'insert';
    }
    $entity->updated = $now;
    parent::save($entity, $transaction);
    // If a file fid exists:
    if (isset($entity->fid)) {
      // Add it into the reportback files.
      $entity->insertFid($entity->fid);
    }
    // If reportback field values exist:
    if (isset($entity->field_values)) {
      foreach ($entity->field_values as $name => $value) {
        $entity->saveFieldValue($name, $value);
      }
    }
    // Log the write operation.
    $entity->insertLog($op);
  }

  /**
   * Overrides delete() method.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    // Log deletions.
    foreach ($ids as $id) {
      $rb = reportback_load($ids);
      $rb->insertLog('delete');
    }
    parent::delete($ids, $transaction);
  }
}
