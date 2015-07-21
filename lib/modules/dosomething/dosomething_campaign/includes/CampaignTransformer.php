<?php

class CampaignTransformer extends Transformer {

  /**
   * Display collection of the specified resource.
   *
   * @param array $parameters Filter parameters to limit collection based on specific criteria.
   *  - nid (string|array)
   *  - type (string)
   *  - staff_pick (boolean)
   *  - mobile_app (boolean)
   *  - term_id (string|array)
   *  - count (int)
   *  - random (boolean)
   *  - page (int)
   * @return array
   */
  public function index($parameters) {
    $filters = [
      'nid' => $this->formatData($parameters['ids']),
      'type' => 'campaign',
      'staff_pick' => $parameters['staff_pick'],
      'mobile_app' => $parameters['mobile_app'],
      'term_id' => $this->formatData($parameters['term_ids']),
      'count' => (int) $parameters['count'] ?: 25,
      'random' => $parameters['random'],
      'page' => (int) $parameters['page'],
    ];

    $filters['offset'] = $this->setOffset($filters['page'], $filters['count']);

    try {
      $campaigns = Campaign::find($filters, 'full');
      $campaigns = services_resource_build_index_list($campaigns, 'campaigns', 'id');
      $total = dosomething_campaign_get_campaign_query_count($filters);
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return [
      'pagination' => $this->paginate($total, $filters, 'campaigns'),
      'retrieved_count' => count($campaigns),
      'data' => $this->transformCollection($campaigns),
    ];


//    $campaigns = [];
//    foreach ($query as $item) {
//      $campaigns[] = Campaign::get($item->nid, 'full');
//    }
//    $campaigns = services_resource_build_index_list($campaigns, 'campaigns', 'id');
//    $total = dosomething_campaign_get_campaign_query_count($filters);
//
  }


  /**
   * @param $id
   *
   * @return array
   */
  public function show($id) {
    $params = array();
    $params['nid'] = $id;

    try {
      $campaign = Campaign::get($id, 'full');
    }
    catch (Exception $error) {
      return array(
        'error' => array(
          'message' => $error->getMessage(),
        ),
      );
    }

    return array(
      'data' => $this->transform($campaign),
    );
  }


  /**
   * @param object $campaign
   *
   * @return array
   */
  protected function transform($campaign) {
    $data = array();

    $data += $this->transformCampaign($campaign);

    return $data;
  }

}
