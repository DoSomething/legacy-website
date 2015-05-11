<?php

/**
 * Class Reportback
 */
class ReportbackTransformer extends Transformer {

  /**
   * Calculate total number of Reportback items for the specified campaigns by
   * each status requested.
   *
   * @param array $parameters Query parameters.
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
   *
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
   * @param string $id Resource id.
   *
   * @return array
   */
  public function show($id) {

    $params = array();
    $params['rbid'] = $id;

    $query = dosomething_reportback_get_reportbacks_query_result($params);
    $reportback = services_resource_build_index_list($query, 'reportback', 'rbid');
    // @TODO: Above returns object with null properties if no results, should return null or false.

    if (! $reportback) {
      return array(
        'error' => array(
          'message' => 'Reportback does not exist.',
        ),
      );
    }

    return array(
      'data' => $this->transform($reportback[0]),
    );
  }


  /**
   * @param object $reportback Single object of retrieved data.
   *
   * @return array
   */
  protected function transform($reportback) {
    $data = array();

    // Main Reportback data
    $data += $this->transformReportback($reportback);

    // Campaign Data
    $data += $this->transformCampaignData($reportback);

    // User data
    $data += $this->transformUserData($reportback);

    // @TODO: http://php.net/manual/en/control-structures.foreach.php
    // Referenced in other code, would be good to potentially address
    // with use of foreach above.

    return $data;
  }

}