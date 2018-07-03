<?php

module_load_include('php', 'dosomething_api', 'includes/Transformer');

/**
 * Reportback Transformer Class
 */
class ReportbackTransformer extends Transformer {

  /**
   * Calculate total number of Reportback items for the specified campaigns by
   * each status requested.
   *
   * @param array $parameters
   *   An associative array of query parameters:
   *   - nid: (array) Campaign ids.
   *   - status: (array) Reportback statuses to retrieve.
   * @return int Total number of reportback items.
   */
  protected function getTotalCount($parameters) {
    $total = 0;

    foreach((array) $parameters['nid'] as $id) {
      foreach((array) $parameters['status'] as $status) {
        $total += (int) dosomething_reportback_get_reportback_total_by_status($id, $status);
      }
    }

    return $total;
  }


  /**
   * @param array $parameters Any parameters obtained from query string.
   * @return array
   */
  public function index($parameters) {
    $filters = array(
      'nid' => dosomething_helpers_format_data($parameters['campaigns']),
      'status' => dosomething_helpers_format_data($parameters['status']),
      'count' => $parameters['count'] ?: 25,
    );

    // @TODO: Logic update!
    // Not ideal that this is NULL instead of FALSE but due to how logic happens in original query function. It should be updated!
    // Logic currently checks for isset() instead of just boolean, so won't change until endpoints switched.
    $filters['random'] = $parameters['random'] === 'true' ? TRUE : NULL;

    try {
      $reportbacks = Reportback::find($filters);
      $reportbacks = services_resource_build_index_list($reportbacks, 'reportbacks', 'id');
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return array(
      'data' => $this->transformCollection($reportbacks),
    );
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
      $reportback = services_resource_build_index_list($reportback, 'reportbacks', 'id');
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return array(
      'data' => $this->transform(array_pop($reportback)),
    );
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

}
