<?php

/**
 * Class Reportback
 */
class Reportback extends ReportbackTransformer {

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

    // Reportback Child Item data
    if ($reportback->items) {
      $output = array();
      $items = $this->getItems($reportback->items);

      foreach($items as $item) {
        $output[] = $this->transformReportbackItemData($item);
      }

      $data['items'] = array(
        'total' => count($items),
        'data' => $output,
      );
    }

    // Campaign Data
    $data += $this->transformCampaignData($reportback);

    // User data
    $data += $this->transformUserData($reportback);

    // @TODO: http://php.net/manual/en/control-structures.foreach.php
    // Referenced in other code, would be good to potentially address
    // with use of foreach above.

    return $data;
  }


  /**
   * @param $ids
   *
   * @return array
   */
  protected function getItems($ids) {
    $filters = array(
      'fid' => $this->formatData($ids),
    );

    // Obtaining all Reportback items.
    $query = dosomething_reportback_get_reportback_files_query_result($filters, 'all');

    return services_resource_build_index_list($query, 'reportback-items', 'fid');
  }
}