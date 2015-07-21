<?php

class Kudos extends Entity {

  protected $entity;

  public $id;
  public $term;
  public $reportback_item;
  public $user;


  /**
   * @param array $values
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
   * Convenience method to retrieve a single or multiple kudos from supplied id(s).
   *
   * @param string|array $ids Single id or array of ids of Kudos to load.
   * @return array
   * @throws Exception
   */
  public static function get($ids) {
    $kudosItems = [];

    if (!is_array($ids)) {
      $ids = [$ids];
    }

    $results = entity_load('kudos', $ids);

    if (!$results) {
      throw new Exception('No kudos data found.');
    }

    foreach($results as $items) {
      $kudos = new static;
      $kudos->build($items);

      $kudosItems[] = $kudos;
    }

    return $kudosItems;
  }


  /**
   * Convenience method to retrieve kudos based on supplied filters.
   *
   * @param array $filters
   * @return array
   * @throws Exception
   */
  public static function find(array $filters = []) {
    $kudosItems = [];

    $results = dosomething_kudos_get_kudos_query($filters);
    $results = entity_load('kudos', $results);

    if (!$results) {
      throw new Exception('No kudos data found.');
    }

    foreach($results as $item) {
      $kudos = new static;
      $kudos->build($item);

      $kudosItems[] = $kudos;
    }

    return $kudosItems;
  }


  /**
   * Build out the instantiated Kudos class object with supplied data.
   *
   * @param $data
   */
  private function build($data) {
    $this->id = $data->kid;
    $this->term = $this->getTaxonomyTerm($data->tid);
    $this->user = [
      'id' => $data->uid,
    ];
    $this->reportback_item = [
      'id' => $data->fid,
    ];
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
