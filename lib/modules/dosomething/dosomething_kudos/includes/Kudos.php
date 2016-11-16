<?php

class Kudos extends Entity {

  protected $entity;

  /**
   * Approved reactions that are accessible and viewable.
   * Edit this array to allow for additional kudos reactions across the platform.
   *
   * @var array
   */
  protected static $approved_reactions = ['heart'];

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
   *
   * @return array
   */
  public static function getApprovedReactions() {
    return static::$approved_reactions;
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

    if ($full && module_exists('dosomething_northstar')) {
      $northstar_user = dosomething_northstar_get_user($data->uid, 'drupal_id');
    }

    $this->user = [
      'drupal_id' => data_get($northstar_user, 'drupal_id'),
      'id' => data_get($northstar_user, '_id'),
      'first_name' => data_get($northstar_user, 'first_name'),
      'last_name' => data_get($northstar_user, 'last_name'),
      'photo' => data_get($northstar_user, 'photo'),
      'country' => data_get($northstar_user, 'country'),
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
