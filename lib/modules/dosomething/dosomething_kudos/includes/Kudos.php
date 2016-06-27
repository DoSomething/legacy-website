<?php

class Kudos extends Entity {

  protected $entity;

  /**
   * Approved reactions that are accessible and viewable.
   * Edit this array to allow for additional kudos reactions.
   * @var array
   */
  protected $approved_reactions = ['heart'];

  public $id;
  public $term;
  public $reportback_item;
  public $user;

  /**
   * @param array $values
   * @throws Exception
   */
  public function __construct(array $values = []) {
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
   * @param string|array $ids Single id or array of ids of Kudos to retrieve.
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

    foreach($results as $item) {
      $kudos = new static;
      $kudos->build($item, TRUE);

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
      $kudos->build($item, TRUE);

      $kudosItems[] = $kudos;
    }

    return $kudosItems;
  }

  /**
   * Get the approved reactions.
   * @return array
   */
  public static function getApprovedReactions() {
    $kudos = new static;

    return $kudos->approved_reactions;
  }

  /**
   * Build out the instantiated Kudos class object with supplied data.
   *
   * @param $data
   */
  private function build($data, $full = false) {
    $northstar_user = (object) [];

    $this->id = $data->kid;

    $this->term = $this->getTaxonomyTerm($data->tid);

    if ($full) {
      $northstar_response = dosomething_northstar_get_northstar_user($data->uid);
      $northstar_response = json_decode($northstar_response);

      if ($northstar_response && !isset($northstar_response->error)) {
        $northstar_user = (array) $northstar_response->data;
      }
    }

    $this->user = [
      'drupal_id' => $data->uid,
      'id' => dosomething_helpers_isset($northstar_user, '_id'),
      'first_name' => dosomething_helpers_isset($northstar_user, 'first_name'),
      'last_name' => dosomething_helpers_isset($northstar_user, 'last_name'),
      'photo' => dosomething_helpers_isset($northstar_user, 'photo'),
      'country' => dosomething_helpers_isset($northstar_user, 'country'),
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
    $data = [];

    $taxonomy = taxonomy_term_load($id);

    $data['id'] = $taxonomy->tid;
    $data['name'] = strtolower($taxonomy->name);
    return $data;
  }

}
