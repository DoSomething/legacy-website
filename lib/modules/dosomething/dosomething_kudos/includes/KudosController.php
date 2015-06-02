<?php

class KudosController extends EntityAPIController {

  public function create(array $values = []) {

  }


  public function delete($ids) {

  }


  public function save($entity) {

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
