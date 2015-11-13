<?php

class CampaignTransformer extends Transformer {

  /**
   * Display collection of the specified resource.
   *
   * @param array $parameters Filter parameters to limit collection based on specific criteria.
   *  - ids (string)
   *  - staff_pick (bool)
   *  - mobile_app (bool)
   *  - mobile_app_date (string)
   *  - term_ids (string)
   *  - count (int)
   *  - random (bool)
   *  - page (int)
   * @return array
   */
  public function index($parameters) {
    $cache = new ApiCache;
    $campaigns = $cache->get('campaigns', $parameters);

    if (!$campaigns) {
      $something = $cache->set('campaigns', $parameters, 'poopie doopie doo');
      print_r(gettype($something));
    }

//    $campaigns = $campaigns ? $campaigns : 'nay';

    print_r($campaigns);
    die();




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


    print_r($parameters);
    print_r($filters);
    die();

    //cache_set($cid, $data, $bin = 'cache', $expire = CACHE_PERMANENT)
    //cache_set('northstar_user_info_' . $id, $northstar_user_info, 'cache_northstar_user_info', REQUEST_TIME + 60*60*24);
    // cache_get($cid, $bin = 'cache')
    //$northstar_user_info = cache_get('northstar_user_info_' . $id, 'cache_northstar_user_info');

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
      return array(
        'error' => array(
          'message' => $error->getMessage(),
        ),
      );
    }

    return array(
      'data' => $this->transform(array_pop($campaign)),
    );
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

}
