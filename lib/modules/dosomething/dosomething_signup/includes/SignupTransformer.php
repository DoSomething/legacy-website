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
      $signup = services_resource_build_index_list($signup, 'signups', 'id');
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
    // print_r($item);
    // die();
    if (is_array($item)) {
      $item = $item[0];
    }

    $campaign = (object) $item->campaign;
    $current_run = $campaign->campaign_runs['current']['en']['id'];

    if ($item->campaign_run == $current_run) {
      $current = true;
    }
    
    $data = [];

    $data += $this->transformSignup($item, $current);

    $data['campaign'] = $this->transformCampaign((object) $item->campaign);

    $data['reportbacks'] = $this->transformReportback((object) $item->reportbacks);

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
    ];

    return $filters;
  }
}
