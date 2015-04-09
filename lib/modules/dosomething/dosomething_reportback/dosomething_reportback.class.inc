<?php

/**
 * Class Reportback
 */
class Reportback {

  /**
   * @param array $parameters Any parameters obtained from query string.
   * @return array
   */
  public function index($parameters) {
    // Load Services module to use its index_query functions.
    module_load_include('inc', 'services', 'services.module');

    // @TODO: Need to flesh this out. Temporarily disabled.
    // $query = dosomething_reportback_get_reportbacks_query_result();
    // $reportbacks = services_resource_build_index_list($query, 'reportbacks', 'rbid');
    $reportbacks = null;

    if (! $reportbacks) {
      return array(
        'error' => array(
          'message' => 'These are not the reportbacks you are looking for.',
        ),
      );
    }

    return array(
      'data' => $reportbacks,
    );
  }


  /**
   * @param string $id Resource id.
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
  private function transform($reportback) {
    $data = array();

    // Main Reportback Item data
    $data += array(
      'id' => $reportback->rbid,
      'created_at' => $reportback->created,
      'updated_at' => $reportback->updated,
      'flagged' => (int) $reportback->flagged ? TRUE : FALSE,
    );

    if ($reportback->why_participated) {
      $data['why_participated'] = $reportback->why_participated;
    }

    if ($reportback->items) {
      $itemsData = array();
      $items = $this->getItems($reportback->items);

      foreach($items as $item) {
        $itemsData[] = array(
          'id' => $item->fid,
          'caption' => $item->caption,
          'uri' => $item->uri,
          'status' => $item->status,
          'media' => array(
            'uri' => dosomething_image_get_themed_image_url_by_fid($item->fid, '480x480'),
            'type' => 'image',
          ),
          'review' => array(
            'timestamp' => $item->timestamp,
          ),
        );
      }

      $data['items'] = $itemsData;
    }


    // Campaign Data
    $data += array(
      'campaign' => array(
        'id' => $reportback->nid,
        'title' => $reportback->title,
      ),
    );

    // User data
    $data += array(
      'user' => array(
        'id' => $reportback->uid
      ),
    );

    // @TODO: http://php.net/manual/en/control-structures.foreach.php
    // Referenced in other code, would be good to potentially address
    // with use of foreach above.

    return $data;
  }


  /**
   * @param $ids
   * @return array
   */
  protected function getItems($ids) {
    $filters = array(
      'fid' => $this->formatIds($ids),
    );

    $query = dosomething_reportback_get_reportback_files_query_result($filters);

    return services_resource_build_index_list($query, 'reportback-items', 'fid');
  }
}