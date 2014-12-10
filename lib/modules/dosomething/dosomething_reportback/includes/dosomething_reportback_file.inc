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

  /**
   * Sets the Reportback File status column and Reviewer details.
   */
  public function review($status, $source = NULL) {
    global $user;
    $this->status = $status;
    $this->reviewer = $user->uid;
    $this->reviewed = REQUEST_TIME;
    // Default source as the current URL path of page being viewed.
    $this->review_source = current_path();
    // If source was passed:
    if ($source) {
      // Store that instead.
      $this->review_source = check_plain($source);
    }
    // Save the reviewed properties.
    return entity_save('reportback_file', $this);
  }
}

/**
 * Our custom controller for the dosomething_reportback type.
 */
class ReportbackFileEntityController extends EntityAPIController {

}
