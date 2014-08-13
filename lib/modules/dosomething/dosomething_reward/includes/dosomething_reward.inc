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
    if (DOSOMETHING_REWARD_LOG) {
      watchdog('dosomething_reward', 'Redeem time @time', array(
        '@time' => $time,
      ));
    }
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
        'item' => $values['item'],
        'item_option' => $values['item_option'],
        'item_additional' => $values['item_additional'],
        'item_additional_option' => $values['item_additional_option'],
      ));
      if (DOSOMETHING_REWARD_LOG) {
        watchdog('dosomething_reward', 'Shipment entity_create: @entity', array(
          '@entity' => json_encode($shipment),
        ));
      }
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
    if (DOSOMETHING_REWARD_LOG) {
      watchdog('dosomething_reward', 'Save: @entity', array(
        '@entity' => json_encode($entity),
      ));
    }
  }

  /**
   * Overrides delete() method.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    if (DOSOMETHING_REWARD_LOG) {
      watchdog('dosomething_reward', 'Delete reward: @ids', array(
        '@ids' => json_encode($ids),
      ));
    }
    parent::delete($ids, $transaction);
    foreach ($ids as $id) {
      // Check if a Shipment exists for this Reward.
      $shipment = dosomething_shipment_get_shipment_id_by_entity('reward', $id);
      if ($shipment) {
        if (DOSOMETHING_REWARD_LOG) {
          watchdog('dosomething_reward', 'Delete shipment: @entity', array(
            '@entity' => json_encode($shipment),
          ));
        }
        // Delete it.
        entity_delete('shipment', $shipment->id);
      }
    }
  }
}
