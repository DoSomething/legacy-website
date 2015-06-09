<?php

class Kudos extends Entity {

  protected $entity;

  public function __construct(array $values = array()) {
    parent::__construct($values, 'kudos');
  }

  protected function defaultUri() {
    return [
      'path' => 'kudos/' . $this->identifier(),
    ];
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

    // Taxonomy Term
    $this->term = $this->getTaxonomyTerm($this->entity->tid);

    // Reportback Item
    $reportback_item = ['id' => $this->entity->fid];
    $this->reportback_item = (object) $reportback_item;

    // User
    $user = ['id' => $this->entity->uid];
    $this->user = (object) $user;
  }


  /**
   * Get taxonomy term node data from provided id.
   * @TODO: Potentially extract code to dosomething_helpers since duplicate code with Campaign.php
   * @param $id
   *
   * @return array
   */
  protected function getTaxonomyTerm($id) {
    $data = array();

    $taxonomy = taxonomy_term_load($id);

    $data['id'] = $taxonomy->tid;
    $data['name'] = strtolower($taxonomy->name);
    return $data;
  }

}
