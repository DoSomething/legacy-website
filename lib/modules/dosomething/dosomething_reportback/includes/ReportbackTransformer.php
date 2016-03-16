<?php

module_load_include('php', 'dosomething_api', 'includes/Transformer');

class ReportbackTransformer extends Transformer {

  /**
   * Calculate total number of Reportback items for the specified campaigns by
   * each status requested.
   *
   * @param  array  $filters
   * @return int
   */
  protected function getTotalCount($filters) {
    return dosomething_reportback_get_reportback_items_total_by_filters($filters);
  }

  /**
   * @param array $parameters Any parameters obtained from query string.
   * @return array
   */
  public function index($parameters) {
    $filters = $this->setFilters($parameters);
    try {
      $reportbacks = Reportback::find($filters);
      $reportbacks = services_resource_build_index_list($reportbacks, 'reportbacks', 'id');
      $total = $this->getTotalCount($filters);
    }
    catch (Exception $error) {
      // @TODO: Potentially log error to watchdog.
      return [
        'data' => [],
      ];
    }

    return [
      'meta' => [
        'pagination' => $this->paginate($total, $filters, 'reportbacks'),
      ],
      'data' => $this->transformCollection($reportbacks),
    ];
  }

  /**
   * Display the specified resource.
   *
   * @param string $id Resource id.
   * @return array
   */
  public function show($id) {
    try {
      $reportback = Reportback::get($id);
      $reportback = services_resource_build_index_list([$reportback], 'reportbacks', 'id');
      $reportback = array_pop($reportback);
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
      'data' => $this->transform($reportback),
    ];
  }

  /**
   * Transform data and build out response.
   *
   * @param object $reportback Single object of retrieved data.
   * @return array
   */
  protected function transform($item) {
    $data = [];

    $data += $this->transformReportback($item);

    $data['campaign'] = $this->transformCampaign((object) $item->campaign);

    $data['user'] = $this->transformUser((object) $item->user);

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
      'rbid' => dosomething_helpers_format_data($parameters['ids']),
      'nid' => dosomething_helpers_format_data($parameters['campaigns']),
      'status' => dosomething_helpers_format_data($parameters['status']),
      'count' => (int) $parameters['count'] ?: 25,
      'page' => (int) $parameters['page'],
      'random' => dosomething_helpers_convert_string_to_boolean($parameters['random']),
      'load_user' => dosomething_helpers_convert_string_to_boolean($parameters['load_user']),
      'flagged' => dosomething_helpers_convert_string_to_boolean($parameters['flagged']),
    ];

    // Unset False boolean values that affect the query builder.
    if (!$filters['random']) {
      unset($filters['random']);
    }

    return $filters;
  }

}
