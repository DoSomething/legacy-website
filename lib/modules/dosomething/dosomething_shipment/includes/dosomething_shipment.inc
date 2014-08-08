<?php

/**
 * @file
 * Provides classes for the Shipment Entity.
 */

/**
 * Our Shipment entity class.
 */
class ShipmentEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'shipment/' . $this->identifier());
  }
}

/**
 * Our custom controller for the Reward Entity type.
 */
class ShipmentEntityController extends EntityAPIController {

  /**
   * Overrides save() method.
   *
   * Populates created and updated automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (isset($entity->is_new)) {
      $op = 'insert';
    }
    parent::save($entity, $transaction);
  }
}
