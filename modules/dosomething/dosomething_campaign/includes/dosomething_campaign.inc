<?php

/**
 * @file
 * Provides classes for the Campaign Entity.
 */


/**
 * Our Campaign entity class.
 */
class CampaignEntity extends Entity {
  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'campaign/' . $this->identifier());
  }
}

/**
 * Our custom controller for the dosomething_campaign type.
 *
 * We're choosing to extend the controller provided by the entity module so that we'll have
 * full CRUD support for CampaignEntities.
 */
class CampaignEntityController extends EntityAPIController {

  /**
   * Overrides buildContent() method.
   *
   * Adds campaign column values into campaign entity's render.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    // Get the columns defined in the dosomething_campaign table:
    module_load_install('dosomething_campaign');
    $schema = dosomething_campaign_schema();
 
    // Add them into the render array:
    foreach ($schema['dosomething_campaign']['fields'] as $key => $value) {
      $build[$key] = array(
        '#type' => 'markup',
        '#markup' => $entity->{$key},
        '#prefix' => '<div>' . $key . ': ',
        '#suffix' => '</div>',
      );      
    }

    // @todo: If pitch page, add the signup button:
    return $build;
  }

  /**
   * Overrides save() method.
   *
   * Populates created, updated, and uid automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $current_timestamp = REQUEST_TIME;
    if (isset($entity->is_new)) {
      $entity->created = $current_timestamp;
      global $user;
      $entity->uid = $user->uid;
    }
    $entity->changed = $current_timestamp;
    return parent::save($entity, $transaction);
  }
}

/**
 * Our custom controller for the admin ui.
 */
class CampaignEntityUIController extends EntityDefaultUIController {

  /**
   * Generates the render array for a overview table for arbitrary entities
   * matching the given conditions.
   *
   * @param $conditions
   *   An array of conditions as needed by entity_load().

   * @return Array
   *   A renderable array.
   */
  public function overviewTable($conditions = array()) {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $this->entityType);
    $query->propertyOrderBy('changed', 'DESC');

    // Add all conditions to query.
    foreach ($conditions as $key => $value) {
      $query->propertyCondition($key, $value);
    }

    if ($this->overviewPagerLimit) {
      $query->pager($this->overviewPagerLimit);
    }

    $results = $query->execute();

    $ids = isset($results[$this->entityType]) ? array_keys($results[$this->entityType]) : array();
    $entities = $ids ? entity_load($this->entityType, $ids) : array();

    $rows = array();
    foreach ($entities as $entity) {
      // Add additional columns for table rows:
      $rows[] = $this->overviewTableRow($conditions, entity_id($this->entityType, $entity), $entity, array(
        format_date($entity->changed, 'short'),
        )
      );
    }

    $render = array(
      '#theme' => 'table',
      // Add additional columns for table header:
      '#header' => $this->overviewTableHeaders($conditions, $rows, array(t('Updated'))),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }

  /**
   * Generates the table headers for the overview table.
   */
  protected function overviewTableHeaders($conditions, $rows, $additional_header = array()) {
    $header = $additional_header;
    array_unshift($header, t('Title'));
    if (!empty($this->entityInfo['exportable'])) {
      $header[] = t('Status');
    }
    // Add operations with the right colspan.
    $header[] = array('data' => t('Operations'), 'colspan' => $this->operationCount());
    return $header;
  }
}
