<?php

/**
 * Signup Transformer Class
 */
class SignupTransformer extends Transformer {

  /**
   * @param array $parameters Any parameters obtained from query string.
   * @return array
   */
  public function index($parameters) {
    $filters = $this->setFilters($parameters);

    try {
      $signups = Signup::find($filters);
      $signups = services_resource_build_index_list($signups, 'signups', 'id');
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return [
      'data' => $this->transformCollection($signups),
    ];
  }

  /**
   * Display the specified resource.
   *
   * @param string $id Signup id.
   * @return array
   */
  public function show($id) {
    try {
      $signup = Signup::get($id);
      $signup = services_resource_build_index_list([$signup], 'signup', 'id');
      $signup = array_pop($signup);
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return [
      'data' => $this->transform($signup),
    ];
  }

  /**
   * Transform data and build out response.
   *
   * @param object $signup Single object of retrieved data.
   * @return array
   */
  protected function transform($item) {
    $item = $item[0];
    $data = [];

    $data += $this->transformSignup($item);

    // $data['campaign'] = $this->transformCampaign((object) $item->campaign);

    // $data['user'] = $this->transformUser((object) $item->user);

    return $data;
  }

  /**
   * Set the filters based on request URL parameters.
   *
   * @param  array  $parameters
   * @return array
   */
  private function setFilters($parameters) {
    $filters = [
      // 'sid' => dosomething_helpers_format_data($parameters['ids']),
      'user' => dosomething_helpers_format_data($parameters['user']),
      'nid' => dosomething_helpers_format_data($parameters['campaigns']),
    ];

    // Unset False boolean values that affect the query builder.
    if (!$filters['random']) {
      unset($filters['random']);
    }

    return $filters;
  }

}
