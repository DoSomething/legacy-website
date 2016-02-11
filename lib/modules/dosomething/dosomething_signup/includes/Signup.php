<?php

class Signup extends Entity {

  protected $entity;

  public $id;

  /**
   * @param array $values
   * @throws Exception
   */
  public function __construct(array $values = []) {
    parent::__construct($values, 'signup');
  }

  /**
   * Override default Entity class method and specify custom URI.
   *
   * @return array
   */
  protected function defaultUri() {
    return [
      'path' => 'signups/' . $this->identifier(),
    ];
  }

  /**
   * Convenience method to retrieve a single or multiple signups from supplied id(s).
   *
   * @param string|array $ids Single id or array of ids of Signups to retrieve.
   * @return array
   * @throws Exception
   */
  public static function get($ids) {
    $signups = [];

    if (!is_array($ids)) {
      $ids = [$ids];
    }

    $results = entity_load('signup', $ids);

    if (!$results) {
      throw new Exception('No signup data found.');
    }

    foreach($results as $item) {
      $signup = new static;
      $signup->build($item, TRUE);

      $signups[] = $signup;
    }

    return $signups;
  }

  /**
   * Convenience method to retrieve signups based on supplied filters.
   *
   * @param array $filters
   * @return array
   * @throws Exception
   */
  public static function find(array $filters = []) {
    $signups = [];

    $results = dosomething_signup_get_signups_query($filters);
    print_r($results);
    die();
    
    // $results = entity_load('signup', $results);

    // if (!$results) {
    //   throw new Exception('No signup data found.');
    // }

    // foreach($results as $item) {
    //   $signup = new static;
    //   $signup->build($item, TRUE);

    //   $signups[] = $signup;
    // }

    // return $signups;
  }

  /**
   * Build out the instantiated Signup class object with supplied data.
   *
   * @param $data
   */
  private function build($data) {
    print_r($data);
    die();

    $this->id = $data->sid;
    $this->created_at = $data->timestamp;
    $this->campaign = Campaign::get($data->nid);
    $this->campaign_run = $data->run_nid;
    $this->reportbacks = Reportback::get($data->rbid);

    // $reportbacks = dosomething_reportback_filter_reportbacks_by_signups($data->run_nid, $data->sid);

    if (count($reportbacks) < 2) {
      $reportbacks = $reportbacks[0];
    }

    try {
      $this->reportbacks = Reportback::get($rbid);
    } catch (Exception $e) {
    }
  }
}
