<?php

/**
 * @file
 * Provides classes for the Fact Entity.
 */


/**
 * Our Fact entity class.
 */
class FactEntity extends Entity {
  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'fact/' . $this->identifier());
  }
}

/**
 * Our custom controller for the dosomething_fact type.
 *
 * We're choosing to extend the controller provided by the entity module so that
 * we'll have full CRUD support for FactEntities.
 */
class FactEntityController extends EntityAPIController {

  /**
   * Overrides buildContent() method.
   *
   * Adds Fact column values into Fact entity's render.
   */
  public function buildContent($entity, $view_mode = 'action', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    $build['fact'] = array(
      '#type' => 'markup',
      '#markup' => $entity->fact,
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
    $build['source'] = array(
      '#type' => 'markup',
      '#markup' => $entity->source,
      '#prefix' => 'Source: <p>',
      '#suffix' => '</p>',
    );
    $build['url_source'] = array(
      '#type' => 'markup',
      '#markup' => l($entity->url_source, $entity->url_source, array('attributes' => array('target' => '_blank'))),
    );
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
class FactEntityUIController extends EntityDefaultUIController {

  /**
   * Generates render array for overview table for arbitrary entities.
   *
   * @param array $conditions
   *   Conditions as needed by entity_load().
   *
   * @return array
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
