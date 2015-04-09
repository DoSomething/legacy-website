<?php

/**
 * Class Reportback Item
 */
class ReportbackItem {

  /**
   * @param array $parameters Any parameters obtained from query string.
   * @return array
   */
  public function index($parameters) {
    // Load Services module to use its index_query functions.
    module_load_include('inc', 'services', 'services.module');

    $filters = array(
      'nid' => $this->formatIds($parameters['campaigns']),
      'status' => $parameters['status'],
      'count' => $parameters['count'] ?: 25,
    );
    // @TODO: Logic update!
    // Not ideal that this is NULL instead of FALSE but due to how logic happens in query function. But it could be updated!
    // Logic currently checks for isset() instead of just boolean, so won't change until endpoints switched.
    $filters['random'] = $parameters['random'] === 'true' ? TRUE : NULL;

    $query = dosomething_reportback_get_reportback_files_query_result($filters, $filters['count']);
    $reportbackItems = services_resource_build_index_list($query, 'reportback-items', 'fid');

    if (! $reportbackItems) {
      return array(
        'error' => array(
          'message' => 'These are not the reportback items you are looking for.',
        ),
      );
    }

    return array(
      'total_retrieved' => count($reportbackItems),
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
   * @param string $ids Single or multiple comma separated ids.
   * @return string or array
   */
  protected function formatIds($ids) {
    $idsArray = explode(',', $ids);

    if (count($idsArray) > 1) {
      return $idsArray;
    }

    return $ids;
  }


  /**
   * @param array $items Collection of item objects retrieved data.
   * @return array
   */
  private function transformCollection($items) {
    return array_map([$this, 'transform'], $items);
  }


  /**
   * @param object $item Single object of retrieved data.
   * @return array
   */
  private function transform($item) {
    $data = array();

    // Main Reportback Item data
    $data += array(
      'id' => $item->fid,
      'caption' => $item->caption,
      'uri' => $item->uri,
      'media' => array(
        'uri' => dosomething_image_get_themed_image_url_by_fid($item->fid, '480x480'),
        'type' => 'image',
      ),
      'review' => array(
        'timestamp' => $item->timestamp,
      ),
    );

    if ($item->status) {
      $data['status'] = $item->status;
    }


    // Reportback Parent Data
    $data += array(
      'reportback' => array(
        'id' => $item->rbid,
        'flagged' => (int) $item->flagged ? TRUE : FALSE,
        'quantity' => (int) $item->quantity,
      ),
    );

    if ($item->why_participated) {
      $data['reportback']['why_participated'] = $item->why_participated;
    }


    // Campaign data
    $data += array(
      'campaign' => array(
        'id' => $item->nid,
        'title' => $item->title
      ),
    );


    // User data
    $data += array(
      'user' => array(
        'id' => $item->uid
      ),
    );

    return $data;
  }

}