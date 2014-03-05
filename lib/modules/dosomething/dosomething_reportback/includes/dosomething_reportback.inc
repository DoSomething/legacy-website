<?php

/**
 * @file
 * Provides classes for the Reportback Entity.
 */

/**
 * Our Reportback entity class.
 */
class ReportbackEntity extends Entity {
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
    return db_select('dosomething_reportback_file', 'rbf')
      ->fields('rbf', array('fid'))
      ->condition('rbid', $this->rbid)
      ->execute()
      ->fetchCol();
  }

  /**
   * Inserts given fid into dosomething_reportback_files table for this entity.
   */
  public function insertFid($fid) {
    return db_insert('dosomething_reportback_file')
      ->fields(array(
        'rbid' => $this->rbid,
        'fid' => $fid,
        ))
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
    if (isset($entity->is_new)) {
      $entity->created = $now;
    }
    $entity->updated = $now;
    return parent::save($entity, $transaction);
  }
}
