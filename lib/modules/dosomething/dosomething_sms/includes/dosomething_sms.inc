<?php

/**
 * @file
 * Provides classes for the SMS Worfklow Entity.
 */

/**
 * Our SMSWorfklow entity class.
 */
class SMSWorkflowEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'sms-workflow/' . $this->identifier());
  }
}

/**
 * Our custom controller for the SMSWorfklow Entity type.
 */
class SMSWorkflowEntityController extends EntityAPIController {

  /**
   * Overrides save() method.
   *
   * Populates created and updated automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $time = REQUEST_TIME;
    if (isset($entity->is_new)) {
      $entity->created = $time;
    }
    $entity->updated = $time;
    parent::save($entity, $transaction);
  }
}
