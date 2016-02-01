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
   * Build out the instantiated Signup class object with supplied data.
   *
   * @param $data
   */
  private function build($data, $full = false) {
    global $user;
    $northstar_user = (object) [];

    $this->id = $data->sid;
    $this->created_at = $data->signup_data_form_timestamp;
    $this->campaign = Campaign::get($data->nid);
    $this->campaign_run = $data->run_nid;

    if ($full) {
      $northstar_response = dosomething_northstar_get_northstar_user($data->uid);
      $northstar_response = json_decode($northstar_response);

      if ($northstar_response && !isset($northstar_response->error)) {
        $northstar_user = array_shift($northstar_response->data);
      }
    }

    $this->user = [
      'drupal_id' => $data->uid,
      'id' => dosomething_helpers_isset($northstar_user, '_id'),
      'first_name' => dosomething_helpers_isset($northstar_user, 'first_name'),
      'last_name' => dosomething_helpers_isset($northstar_user, 'last_name'),
    ];
  }
}
