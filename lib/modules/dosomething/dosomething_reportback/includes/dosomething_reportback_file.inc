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
    return array('path' => 'rb/' . $this->identifier());
  }

  /**
   * Overrides construct to set calculated properties.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);
    $this->caption = check_plain($this->caption);
  }

  public function getImage() {
    return dosomething_image_get_themed_image_by_fid($this->fid, '300x300');
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
  /**
   * Overrides buildContent() method.
   *
   * Adds Reportback properties into Reportback entity's render.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    global $user;
    $reportback = reportback_load($entity->rbid);

    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    $author = user_load($reportback->uid);
    $build['image'] = array(
      '#markup' => $entity->getImage(),
    );
    $build['caption'] = array(
      '#prefix' => '<p><strong>',
      '#markup' => $entity->caption,
      '#suffix' => '</strong></p>',
    );
    $build['username'] = array(
      '#prefix' => '<p>',
      '#markup' => l($author->mail, 'user/' . $author->uid),
      '#suffix' => '</p>',
    );
    $build['quantity'] = array(
      '#prefix' => '<p>',
      '#markup' => $reportback->quantity . ' ' . $reportback->quantity_label,
      '#suffix' => '</p>',
    );
    $build['why'] = array(
      '#prefix' => '<p>',
      '#markup' => $reportback->why_participated,
      '#suffix' => '</p>',
    );
    if (!empty($entity->reviewed)) {
      $reviewer = user_load($entity->reviewer);
      $build['reviewed'] = array(
        '#prefix' => '<p>',
        '#markup' => '<strong>' . ucfirst($entity->status) . '</strong> ' . format_date($entity->reviewed, 'short') .' by ' . $reviewer->mail,
        '#suffix' => '</p>',
      );
    }
    return $build;
  }

}
