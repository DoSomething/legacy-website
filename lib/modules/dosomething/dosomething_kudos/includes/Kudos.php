<?php

class Kudos extends Entity {

  protected $entity;

  public $id;
  public $reportback_item;
  public $term;
  public $user;


  /**
   * @param array $values
   *
   * @throws Exception
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'kudos');
  }


  /**
   * Override default Entity class method and specify custom URI.
   *
   * @return array
   */
  protected function defaultUri() {
    return [
      'path' => 'kudos/' . $this->identifier(),
    ];
  }


  /**
   * @param $id
   *
   * @return static
   */
  public static function get($id) {
    $kudos = new static();
    $kudos->load($id);

    return $kudos;
  }


  /**
   * @param $id
   */
  public function load($id) {
    $entity = entity_load('kudos', [$id]);
    $keys = array_keys($entity);

    $this->entity = $entity[$keys[0]];
    $this->id = $this->entity->kid;

    // Taxonomy Term
    $this->term = $this->getTaxonomyTerm($this->entity->tid);

    // User
    $user = ['id' => $this->entity->uid];
    $this->user = (object) $user;

    // Reportback Item
    $reportback_item = ['id' => $this->entity->fid];
    $this->reportback_item = (object) $reportback_item;
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
