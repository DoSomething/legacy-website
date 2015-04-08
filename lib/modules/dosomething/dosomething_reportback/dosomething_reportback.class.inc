<?php

/**
 * Class Reportback
 */
class Reportback {

  public function index($parameters) {
    // Load Services module to use its index_query functions.
    module_load_include('inc', 'services', 'services.module');

    $results = dosomething_reportback_get_reportbacks_query_result();
//    $reportbacks = dosomething_reportback_get_reportbacks_query_result();
//    $reportbacks = $results->fetchAssoc();
    $reportbacks = services_resource_build_index_list($results, 'reportbacks', 'rbid');
//    $query = dosomething_reportback_get_reportback_files_query_result($params, $count, $start);
//    $reportbacks = services_resource_build_index_list($query, 'reportback_files', 'fid');

    if (! $reportbacks) {
      return array(
        'error' => array(
          'message' => 'These are not the reportbacks you are looking for.',
        ),
      );
    }

    return array(
      'data' => 'something',
      'reportbacks' => $reportbacks,
    );
  }


  public function show($id) {
    $reportback = reportback_load($id);

    if (! $reportback) {
      return array(
        'error' => array(
          'message' => 'Reportback does not exist.',
        ),
      );
    }

    return array(
      'data' => $this->transform($reportback)
    );
  }


  private function transformCollection() {

  }


  private function transform($reportback) {
    $data = array(
      'id' => $reportback->rbid,
      'why_participated' => $reportback->why_participated,
      'created' => $reportback->created,
      'updated' => $reportback->updated,
      'flagged' => (int) $reportback->flagged ? TRUE : FALSE,
      'items' => null,
      'user' => array(
        'id' => $reportback->uid,
      ),
      'campaign' => array(
        'id' => $reportback->nid,
        'title' => $reportback->node_title,
        'noun' => $reportback->noun,
        'verb' => $reportback->verb,
        'quantity_label' => $reportback->quantity_label
      ),
    );

    if ($reportback->fids) {
      $items = array();
      foreach($reportback->fids as $index => $item) {
        $reportback_item = reportback_file_load($item);
        $items[] = array(
          'id' => $item,
          'caption' => $reportback_item->caption,
          'status' => $reportback_item->status,
          'review' => array(
            'timestamp' => $reportback_item->reviewed,
            'source' =>  $reportback_item->review_source,
            'user' => array(
              'id' => $reportback_item->reviewer
            )
          )
        );
      }
      $data['items'] = $items;
    }

    // @TODO: http://php.net/manual/en/control-structures.foreach.php
    // Referenced in other code, would be good to potentially address
    // with use of foreach above.

    return $data;
  }
}