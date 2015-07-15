<?php

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
   *
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
      'nid' => $this->formatData($parameters['campaigns']),
      'status' => $parameters['status'],
      'count' => $parameters['count'] ?: 25,
    );

    // @TODO: Logic update!
    // Not ideal that this is NULL instead of FALSE but due to how logic happens in original query function. It should be updated!
    // Logic currently checks for isset() instead of just boolean, so won't change until endpoints switched.
    $filters['random'] = $parameters['random'] === 'true' ? TRUE : NULL;

    // @TODO: Need to flesh this out. Temporarily disabled.
    // $query = dosomething_reportback_get_reportbacks_query_result($filters, $filters['count']);
    // $reportbacks = services_resource_build_index_list($query, 'reportbacks', 'rbid');
    $reportbacks = null;

    if (!$reportbacks) {
      return array(
        'error' => array(
          'message' => 'Temporarily unavailable... These are not the reportbacks you are looking for.',
        ),
      );
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
//      $reportback = Reportback::get(['1000', '650']);
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return array(
//      'data' => $this->transform($reportback),
      'data' => $reportback,
    );
  }


  /**
   * @param object $reportback Single object of retrieved data.
   * @return array
   */
  protected function transform($reportback) {
    $data = array();

    $data += $this->transformReportback($reportback);

//    $data['campaign'] = $this->transformCampaign(Campaign::get($reportback->nid));

    $data['user'] = $this->transformUser($reportback);

    return $data;
  }

}
