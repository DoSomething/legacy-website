<?php

/**
 * @file
 * Provides classes for the Reportback File Entity.
 */

/**
 * Our Reportback File entity class.
 */
class ReportbackFileEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'rbf/' . $this->identifier());
  }

}

/**
 * Our custom controller for the dosomething_reportback type.
 */
class ReportbackFileEntityController extends EntityAPIController {

}
