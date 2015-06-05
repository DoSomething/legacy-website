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

}


// SCRAPS
///**
// * @param $parameters
// * @return array  IDs of newly created records.
// * @throws Exception
// */
//function dosomething_kudos_create($parameters) {
//  $records = array();
//
//  $values = array(
//    'fid' => $parameters['fid'],
//    'uid' => $parameters['uid'],
//  );
//
//  foreach($parameters['tids'] as $id) {
//    $values['tid'] = $id;
//
//    $records[] = db_insert('dosomething_kudos')->fields($values)->execute();
//  }
//
//  return $records;
//}
//
//
///**
// * Delete a specified Kudos record.
// *
// * @param $kid
// * @return DatabaseStatementInterface
// */
//function dosomething_kudos_delete($kid) {
//  return db_delete('dosomething_kudos')->condition('kid', $kid)->execute();
//}
