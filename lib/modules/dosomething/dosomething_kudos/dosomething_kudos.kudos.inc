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


  public function create() {
    return 'class create item';
  }


  public function delete() {
    return 'class delete item';
  }


  protected function transform($object) {
    return 'autobots transform!';
  }

}