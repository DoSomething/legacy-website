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
   * Override construct to set a calculated fids property.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);
    $this->fids = $this->getFids();
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
   * Inserts given fid into dosomething_reportback_files table for this entity.
   */
  public function insertFid($fid) {
    return db_insert($this->files_table)
      ->fields(array(
        'rbid' => $this->rbid,
        'fid' => $fid,
        ))
      ->execute();
  }

  /**
   * Logs current entity values with given $op string.
   */
  public function insertLog($op) {
    global $user;
    // If deleting, store current time.
    if ($op == 'delete') {
      $timestamp = REQUEST_TIME;
    }
    // Else use the entity's updated property.
    else {
      $timestamp = $this->updated;
    }
    try {
      $fids = $this->fids;
      // Log the entity values into the log table.
      $id = db_insert($this->log_table)
        ->fields(array(
          'rbid' => $this->rbid,
          'uid' => $user->uid,
          'op' => $op,
          'timestamp' => $timestamp,
          'quantity' => $this->quantity,
          'why_participated' => $this->why_participated,
          'files' => implode(',', $fids),
          'num_files' => count($fids),
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
    // Load node to output relevant reportback variables.
    $node_wrapper = entity_metadata_wrapper('node', $entity->nid);
    $build['username'] = array(
      '#type' => 'markup',
      '#markup' => l($account->name, 'user/' . $account->uid),
    );

    $build['node_title'] = array(
      '#type' => 'markup',
      '#markup' => l($node_wrapper->title->value(), 'node/' . $entity->nid),
    );
    foreach ($entity->getThemedImages('300x300') as $delta => $image) {
      $build['file_' . $delta] = array(
        '#type' => 'markup',
        '#markup' => $image,
      );
    }
    $build['quantity_count'] = array(
      '#type' => 'markup',
      '#markup' => $entity->quantity,
    );
    $build['quantity_label'] = array(
      '#type' => 'markup',
      '#markup' => $node_wrapper->field_reportback_noun->value() . ' ' . $node_wrapper->field_reportback_verb->value(),
    );
    $build['why_participated'] = array(
      '#type' => 'markup',
      '#markup' => $entity->why_participated,
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
