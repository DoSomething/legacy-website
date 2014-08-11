<?php

/**
 * @file
 * Provides classes for the Reward Entity.
 */

/**
 * Our Reward entity class.
 */
class RewardEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'reward/' . $this->identifier());
  }

  /**
   * Sets the Reward as redeemed and creates a relevant Shipment if applciable.
   */
  public function redeem($values = array()) {
    $time = REQUEST_TIME;
    // Set the Reward as redeemed.
    $this->redeemed = $time;
    $this->save();
    if ($this->reward_type == 'reportback_count') {
      // Create corresponding shipment entity for this reward.
      $shipment = entity_create('shipment', array(
        'uid' => $this->uid,
        'created' => $time,
        'entity_type' => 'reward',
        'entity_id' => $this->id,
        'shipment_type' => 'shirts',
        'shirt_size' => $values['shirt_size'],
        'shirt_size_additional' => $values['shirt_size_additional'],
      ));
      $shipment->save();
    }
  }
}

/**
 * Our custom controller for the Reward Entity type.
 */
class RewardEntityController extends EntityAPIController {

  /**
   * Overrides save() method.
   *
   * Populates created and updated automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (isset($entity->is_new)) {
      $entity->created = REQUEST_TIME;
    }
    parent::save($entity, $transaction);
  }

  /**
   * Overrides delete() method.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    parent::delete($ids, $transaction);
    foreach ($ids as $id) {
      // Check if a Shipment exists for this Reward.
      $shipment = dosomething_shipment_get_shipment_id_by_entity('reward', $id);
      if ($shipment) {
        // Delete it.
        entity_delete('shipment', $shipment->id);
      }
    }
  }
}
