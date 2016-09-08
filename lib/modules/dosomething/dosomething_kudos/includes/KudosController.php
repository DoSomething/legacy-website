<?php

class KudosController extends EntityAPIController {

  public function __construct() {
    parent::__construct('kudos');
  }

  /**
   * Overrides create() method in EntityAPIController.
   *
   * Allows for custom return of boolean values.
   *
   * @param array $values
   * @return bool
   *
   * @throws Exception
   */
  public function create(array $values = []) {

    $duplicate = $this->get($values);

    // Only save the record if it is unique on fid, uid, and tid
    if (empty($duplicate)) {
      $kudos = parent::create($values);

      $record = $this->save($kudos);
    }

    if ($record) {
      // For ~reasons~ the entity save doesn't return the entity
      // So we need to query for the record and return it.
      $kudo = $this->get($values);
      return $kudo;
    }

    return FALSE;
  }

  /**
   * Overrides get() method in EntityAPIController.
   *
   * @param $values
   *
   * @return object
   */
  public function get($values) {
    return db_select('dosomething_kudos', 'k')
      ->fields('k')
      ->condition('fid', $values['fid'], '=')
      ->condition('uid', $values['uid'], '=')
      ->condition('tid', $values['tid'], '=')
      ->execute()
      ->fetchAssoc();
  }

  /**
   * Overrides delete() method in EntityAPIController.
   *
   * The parent delete() method does not provide suitable return values to allow
   * for logic for API response and knowing whether delete failed or succeeded.
   * Provides better feedback for API by returning values in either of the returns:
   * - Returns FALSE if invalid $ids provided or not found when
   * load() attempted.
   * - Returns TRUE if record successfully deleted.
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
