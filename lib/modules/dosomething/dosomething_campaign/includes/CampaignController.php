<?php

class CampaignController {

  /**
   * Update the specified Campaign in storage.
   *
   * @param  int  $id
   * @return void
   */
  function update($id) {
    cache_clear_all('campaigns_api_request', 'cache_dosomething_api', TRUE);
    cache_clear_all('ds_campaign_' . $id, 'cache_dosomething_campaign', TRUE);
  }

}
