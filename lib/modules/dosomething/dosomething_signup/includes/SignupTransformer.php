<?php

module_load_include('php', 'dosomething_api', 'includes/Transformer');

class SignupTransformer extends Transformer {

  /**
   * Calculate total number of Signups by each status requested.
   *
   * @param  array  $filters
   * @return int
   */
  protected function getTotalCount($filters) {
    return dosomething_signup_get_signup_total_by_filters($filters);
  }

  /**
   * @param array $parameters Any parameters obtained from query string.
   * @return array
   */
  public function index($parameters) {
    $filters = $this->setFilters($parameters);
    try {
      $signups = Signup::find($filters);
      $signups = services_resource_build_index_list($signups, 'signups', 'id');
      $total = $this->getTotalCount($filters);
    }
    catch (Exception $error) {
      return [
        'data' => [],
      ];
    }

    return [
      'meta' => [
        'pagination' => $this->paginate($total, $filters, 'signups'),
      ],
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
      $signup = services_resource_build_index_list($signup, 'signups', 'id');
      $signup = array_pop($signup);
    }
    catch (Exception $error) {
      http_response_code('404');
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
    if (is_array($item)) {
      $item = $item[0];
    }

    $data = [];

    if (is_null($item->campaign)) {
      $data['campaign'] = null;
    }
    else {
      $campaign = (object) $item->campaign;
      $current_run = $campaign->campaign_runs['current']['en']['id'];
      $current = ($item->campaign_run == $current_run);

      $data += $this->transformSignup($item, $current);
      $data['campaign'] = $this->transformCampaign((object) $item->campaign);
    }

    if (is_null($item->reportback)) {
      $data['reportback'] = null;
    }
    else {
      $data['reportback'] = $this->transformReportback((object) $item->reportback);
    }

    if (is_null($item->user)) {
      $data['user'] = null;
    }
    else {
      $data['user'] = $this->transformUser((object) $item->user);
    }

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
      'user' => dosomething_helpers_format_data($parameters['user']),
      'campaigns' => dosomething_helpers_format_data($parameters['campaigns']),
      'count' => (int) $parameters['count'] ?: 25,
      'page' => (int) $parameters['page'],
      'competition' => $parameters['competition'] ?: NULL,
    ];

    return $filters;
  }
}
