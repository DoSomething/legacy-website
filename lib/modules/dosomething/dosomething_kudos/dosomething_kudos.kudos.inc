<?php


/**
 * Class Kudos
 */
class Kudos extends Transformer {

  public function index($parameters) {
    return $parameters;
  }


  public function show($id) {
    return 'class show item';
  }


  /**
   * Create Kudos single or multiple records for a reportback.
   *
   * @param $parameters array
   * @return array Array containing id of each Kudos record created in database.
   */
  public function create($parameters) {
    $records = array();

    $values = array(
      'fid' => $parameters['fid'],
      'uid' => $parameters['uid'],
    );

    foreach($parameters['tids'] as $id) {
      $values['tid'] = $id;

      $records[] = dosomething_kudos_create($values);
    }

    return $records;
  }


  public function destroy($id) {
    return dosomething_kudos_destroy($id);
  }


  public function transform() {
    return 'autobots transform!';
  }

}