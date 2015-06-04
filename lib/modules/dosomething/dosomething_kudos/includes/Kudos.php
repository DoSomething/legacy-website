<?php

class Kudos extends Entity {

  public $id;
  protected $entity;

  protected function defaultUri() {
    return [
      'path' => 'kudos/' . $this->identifier(),
    ];
  }

  public function __construct(array $values = array()) {
    parent::__construct($values, 'kudos');
  }

  public static function get($id) {
    $kudos = new static();
    $kudos->load($id);

    return $kudos;
  }


  public function load($id) {
    $entity = entity_load('kudos', [$id]);
    $keys = array_keys($entity);

    $this->entity = $entity[$keys[0]];
    $this->id = $this->entity->kid;
    $this->term_id = $this->entity->tid;
    $this->reportbackitem_id = $this->entity->fid;

    $user = ['id' => $this->entity->uid];
    $this->user = (object) $user;
  }

}
