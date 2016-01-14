<?php

class CampaignTransformer extends Transformer {

  /**
   * Display collection of the specified resource.
   *
   * @param  array  $parameters Filter parameters to limit collection based on specific criteria.
   *  - ids (string)
   *  - staff_pick (string|bool)
   *  - mobile_app (string|bool)
   *  - mobile_app_date (string)
   *  - term_ids (string)
   *  - count (int)
   *  - random (string|bool)
   *  - page (int)
   *  - cache (string|bool)
   * @return array
   */
  public function index($parameters) {
    $filters = $this->setFilters($parameters);

    $cache = new ApiCache;

    $campaigns = $cache->get('campaigns', $parameters);

    try {
      if (!$campaigns) {
        $campaigns = Campaign::find($filters, 'full');

        $cache->set('campaigns', $parameters, $campaigns);
      }
      else {
        $campaigns = $campaigns->data;
      }

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
  }

  /**
   * Display the specified resource.
   *
   * @param string $id Campaign id.
   * @return array
   */
  public function show($id) {
    try {
      $campaign = Campaign::get($id, 'full');
      $campaign = services_resource_build_index_list($campaign, 'campaigns', 'id');
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return [
      'data' => $this->transform(array_pop($campaign)),
    ];
  }

  /**
   * Transform data and build out response.
   *
   * @param object $item Single Campaign object of retrieved data.
   * @return array
   */
  protected function transform($item) {
    $data = [];

    $data += $this->transformCampaign($item);

    return $data;
  }

  /**
   * @param  array $parameters
   * @return array
   */
  private function setFilters($parameters) {
    $filters = [
      'nid' => $this->formatData($parameters['ids']),
      'type' => 'campaign',
      'staff_pick' => (bool) $parameters['staff_pick'],
      'mobile_app' => (bool) $parameters['mobile_app'],
      'mobile_app_date' => $parameters['mobile_app_date'],
      'term_id' => $this->formatData($parameters['term_ids']),
      'count' => (int) $parameters['count'] ?: 25,
      'random' => $parameters['random'],
      'page' => (int) $parameters['page'],
    ];

    $filters['offset'] = $this->setOffset($filters['page'], $filters['count']);

    return $filters;
  }

}
