<?php

use DoSomething\Gateway\Common\RestApiClient;
use DoSomething\Gateway\ForwardsTransactionIds;

class Rogue extends RestApiClient {
  use ForwardsTransactionIds;

  /**
   * The class name of the transaction framework bridge.
   *
   * @var string
   */
  protected $transactionBridge = Phoenix\Auth\PhoenixTransactionBridge::class;

  /**
   * Create a new Rogue API client.
   */
  // public function __construct() {
  //   $url = ROGUE_API_URL . '/' . ROGUE_API_VERSION . '/';

  //   parent::__construct($url);
  // }


  /**
   * Send a POST request of the reportback to be saved in Rogue.
   *
   * @param string $baseurl
   * @param array $data
   * @return object|false
   */
  public function postReportback($baseurl, $data) {
    // die(ROGUE_API_URL . '/' . ROGUE_API_VERSION . '/' . $baseurl);
    $response = $this->post(ROGUE_API_URL . '/' . ROGUE_API_VERSION . '/' . $baseurl, $data);

    return is_null($response) ? null : $response;
  }

  /**
   * Send a PUT request of the updated reportback to be saved in Rogue.
   *
   * @param string $baseurl
   * @param array $data
   * @return object|false
   */
  public function updateReportback($baseurl, $data) {
    $response = $this->put($url . $baseurl, $data);

    return is_null($response) ? null : $response;
  }
}
