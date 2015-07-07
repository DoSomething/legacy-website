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
   * Overrides to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'reportback/' . $this->rbid . '?fid=' . $this->identifier());
  }

  public function getImage($file_size = '300x300') {
    $image = dosomething_image_get_themed_image_by_fid($this->fid, $file_size);
    if (!$image) {
      return t("File removed.");
    }
    return $image;
  }
  public function getImageURL($file_size = '300x300') {
    $image = dosomething_image_get_themed_image_url_by_fid($this->fid, $file_size);
    if (!$image) {
      return t("File removed.");
    }
    return $image;
  }

  /**
   * Sets the Reportback File status and Reviewer details.
   *
   * @param array $values
   *   An associative array containing:
   *   - status (string).  Required.
   *   - source (string). The page or device the Review has been submitted from.
   *   - flagged_reason (string).
   *   - delete (integer).  If set to 1, delete the corresponding File entity.
   *
   */
  public function review($values) {
    global $user;
    if (!isset($values['status'])) {
      return FALSE;
    }
    $this->status = $values['status'];
    $this->reviewer = $user->uid;
    $this->reviewed = REQUEST_TIME;
    // Default source as the current URL path of page being viewed.
    $this->review_source = current_path();
    // If source was passed:
    if (isset($values['source'])) {
      // Store that instead.
      $this->review_source = $values['source'];
    }
    $reportback = reportback_load($this->rbid);
    $reason = NULL;

    if (isset($values['flagged_reason'])) {
      $flagged_reason = $values['flagged_reason'];
    }
    if (isset($values['promoted_reason'])) {
      $promoted_reason = $values['promoted_reason'];
    }
    $reportback->setFlaggedPromoted($this->status, $values);

    if (!empty($values['delete'])) {
      $this->deleteFile();
    }

    // Save the reviewed properties.
    return entity_save('reportback_file', $this);
  }

  /**
   * Deletes the File associated with this Reportback File.
   */
  public function deleteFile() {
    $file = file_load($this->fid);
    if ($file) {
      return file_delete($file);
    }
  }
}

