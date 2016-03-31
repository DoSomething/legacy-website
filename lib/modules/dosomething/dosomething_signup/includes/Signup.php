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

    $results = dosomething_signup_get_signups_query(['sid' => $ids]);

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
   * Build out the instantiated Signup class object with supplied data.
   *
   * @param $data
   */
  private function build($data) {
    $this->id = $data->sid;
    $this->created_at = $data->timestamp;

    $user = user_load($data->uid);
    $this->user = [
      'id' => dosomething_helpers_isset($data, 'field_northstar_id_value'),
      'first_name' => dosomething_helpers_extract_field_data($user->field_first_name),
      'last_initial' => dosomething_helpers_extract_field_data($user->field_last_name),
      'photo' => $user->picture,
      'country' => dosomething_helpers_extract_field_data($user->field_address),
    ];

    try {
      $this->campaign = Campaign::get($data->nid);
    }
    catch (Exception $error) {
      $this->campaign = null;
    }

    $this->campaign_run = $data->run_nid;

    // Only send to Reportback::get if there is a rbid.
    if (isset($data->rbid) && is_numeric($data->rbid)) {
      // Catch error if a reportback is not found.
      // Reportback will not be returned if it hasn't yet been reviewed.
      try {
        $this->reportback = Reportback::get($data->rbid);
      } catch (Exception $e) {
        $this->reportback = null;
      }
    }
    else {
      $this->reportback = null;
    }
  }
}
