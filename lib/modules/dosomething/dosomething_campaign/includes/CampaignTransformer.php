<?php

/**
 * Campaign Transformer Class
 */
class CampaignTransformer extends Transformer {

  /**
   * @param $parameters
   *
   * @return array
   */
  public function index($parameters) {
    $filters = [
      'nid' => $this->formatData($parameters['ids']),
      // @TODO: 'type' allows for us to later consider potential to select from regular or SMS campaigns
      'type' => 'campaign',
      'staff_pick' => $parameters['staff_pick'],
      'mobile_app' => $parameters['mobile_app'],
      'term_id' => $this->formatData($parameters['term_ids']),
      'count' => (int) $parameters['count'] ?: 25,
      'random' => $parameters['random'],
      'page' => (int) $parameters['page'],
    ];

    $filters['offset'] = $this->setOffset($filters['page'], $filters['count']);

    $query = dosomething_campaign_get_campaigns_query_result($filters, $filters['count'], $filters['offset']);

    if (!$query) {
      return [
        'error' => [
          'message' => 'These are not the campaigns you are looking for.',
        ]
      ];
    }

    $campaigns = [];
    foreach ($query as $item) {
      $campaigns[] = Campaign::get($item->nid);
    }
    $campaigns = services_resource_build_index_list($campaigns, 'campaigns', 'id');
    $total = dosomething_campaign_get_campaign_query_count($filters);

    return [
      'pagination' => $this->paginate($total, $filters, 'campaigns'),
      'retrieved_count' => count($campaigns),
      'data' => $this->transformCollection($campaigns),
    ];
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
      $campaign = Campaign::get($id);
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
