<?php

/**
 * Campaign Transformer Class
 */
class CampaignTransformer extends Transformer {

  public function index($parameters) {
    //
  }


  public function show($id) {
    $params = array();
    $params['nid'] = $id;

    try {
      $campaign = new Campaign($id);
      return $campaign;
    }
    catch (Exception $error) {
      return array(
        'error' => array(
          'message' => $error->getMessage(),
        ),
      );
    }



//    $campaign->load();

//    $query = dosomething_campaign_get_campaigns_query_result($params);

//    return $id;
//    return $query;
//    return node_load($id);
//    return (new Campaign($id))->getSomething();
//    return Campaign::getTags();

  }


  /**
   * @param object $campaign
   */
  protected function transform($campaign) {
    //
  }

}