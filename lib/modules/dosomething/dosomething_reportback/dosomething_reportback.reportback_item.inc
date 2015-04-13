<?php

/**
 * Class Reportback Item
 */
class ReportbackItem extends ReportbackTransformer {

  /**
   * @param array $parameters Any parameters obtained from query string.
   * @return array
   */
  public function index($parameters) {
    // @TODO: add validation method to Transformer
    // Need to make sure that certain query parameters passed are
    // validated to a specific data type (eg: nid needs to be an int)
    $filters = array(
      'nid' => $this->formatData($parameters['campaigns']),
      'status' => $this->formatData($parameters['status']),
      'count' => $parameters['count'] ?: 25,
    );
    // @TODO: Logic update!
    // Not ideal that this is NULL instead of FALSE but due to how logic happens in original query function. It should be updated!
    // Logic currently checks for isset() instead of just boolean, so won't change until endpoints switched.
    $filters['random'] = $parameters['random'] === 'true' ? TRUE : NULL;

    $query = dosomething_reportback_get_reportback_files_query_result($filters, $filters['count']);
    $reportbackItems = services_resource_build_index_list($query, 'reportback-items', 'fid');

    if (!$reportbackItems) {
      return array(
        'error' => array(
          'message' => 'These are not the reportback items you are looking for.',
        ),
      );
    }

    return array(
      'total' => $this->countData($filters),
      'data' => $this->transformCollection($reportbackItems),
    );
  }


  /**
   * @param string $id Resource id.
   * @return array
   */
  public function show($id) {
    $params = array();
    $params['fid'] = $id;

    $query = dosomething_reportback_get_reportback_files_query_result($params);
    $reportbackItem = services_resource_build_index_list($query, 'reportback-items', 'fid');

    return array(
      'data' => $this->transform($reportbackItem[0]),
    );
  }


  /**
   * @param object $item Single object of retrieved data.
   * @return array
   */
  protected function transform($item) {
    $data = array();

    // Main Reportback Item data
    $data += $this->transformReportbackItemData($item);

    // Reportback Parent Data
    $data['reportback'] = $this->transformReportback($item);

    // Campaign data
    $data += $this->transformCampaignData($item);

    // User data
    $data += $this->transformUserData($item);

    return $data;
  }

}