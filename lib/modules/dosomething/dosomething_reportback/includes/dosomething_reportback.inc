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
      ->key(array('rbid' => $this->rbid, 'name' => $name))
      ->fields(array(
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
    // Load user to get username.
    $account = user_load($entity->uid);
    $build['username'] = array(
      '#type' => 'markup',
      '#markup' => l($account->name, 'user/' . $account->uid),
    );

    $build['node_title'] = array(
      '#type' => 'markup',
      '#markup' => l($entity->node_title, 'node/' . $entity->nid),
    );
    foreach ($entity->getThemedImages('300x300') as $delta => $image) {
      $build['file_' . $delta] = array(
        '#type' => 'markup',
        '#markup' => $image,
      );
    }
    $build['quantity_count'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->quantity),
    );
    $build['quantity_label'] = array(
      '#type' => 'markup',
      '#markup' => $entity->noun . ' ' . $entity->verb,
    );
    // If entity has an active reportback field:
    if (isset($entity->field) && $entity->field['status']==1) {
      $build['reportback_field_label'] = array(
        '#type' => 'markup',
        '#markup' => $entity->field['label'],
      );
      if (isset($entity->field['value'])) {
        $build['reportback_field_value'] = array(
          '#type' => 'markup',
          '#markup' => $entity->field['value'],
        );
      }
    }
    $build['why_participated'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->why_participated),
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
