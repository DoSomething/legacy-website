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
