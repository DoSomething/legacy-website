<?php

class Kudos extends Entity {

  public $id;
  public $entity;

//  protected function defaultUri() {
//    return [
//      'path' => 'kudos/' . $this->identifier(),
//    ];
//  }

  public function __construct(array $values = array()) {
    parent::__construct($values, 'kudos');
  }

  public static function get($id) {
    $kudos = new static();
    $kudos->load($id);

    return $kudos;
  }


  public function load($id) {
    $this->id = $id;
    $this->entity = entity_load('kudos', [$id]);
  }

}
