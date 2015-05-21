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
