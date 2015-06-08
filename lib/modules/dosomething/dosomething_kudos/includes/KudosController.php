<?php

class KudosController extends EntityAPIController {

  public function __construct() {
    parent::__construct('kudos');
  }

  /**
   * Overrides create() method in EntityAPIController
   *
   * @param array $values
   * @return bool
   *
   * @throws Exception
   */
  public function create(array $values = []) {
    $values += ['is_new' => TRUE];

    $kudos = new Kudos($values);

    $record = $this->save($kudos);

    if ($record) {
      return TRUE;
    }

    return FALSE;
  }


  /**
   * Overrides delete() method in EntityAPIController.
   * Provides better feedback for API.
   *
   * @param $ids
   * @param DatabaseTransaction $transaction
   *
   * @return string
   * @throws Exception
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    $entities = $ids ? $this->load($ids) : FALSE;

    if (!$entities) {
      return FALSE;
    }
    $transaction = isset($transaction) ? $transaction : db_transaction();

    try {
      $ids = array_keys($entities);

      db_delete($this->entityInfo['base table'])
        ->condition($this->idKey, $ids, 'IN')
        ->execute();

      if (isset($this->revisionTable)) {
        db_delete($this->revisionTable)
          ->condition($this->idKey, $ids, 'IN')
          ->execute();
      }
      // Reset the cache as soon as the changes have been applied.
      $this->resetCache($ids);

      foreach ($entities as $id => $entity) {
        $this->invoke('delete', $entity);
      }
      // Ignore slave server temporarily.
      db_ignore_slave();
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception($this->entityType, $e);
      throw $e;
    }

    return TRUE;
  }
}
