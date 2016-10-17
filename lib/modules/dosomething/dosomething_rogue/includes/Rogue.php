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
   * Send a POST request of the reportback to be saved in Rogue.
   *
   * @param string $baseurl
   * @param array $data
   * @return object|false
   */
  public function postReportback($baseurl, $data) {
    $response = $this->post(ROGUE_API_URL . '/' . ROGUE_API_VERSION . '/' . $baseurl, $data);

    return $response;
  }

  /**
   * Send a PUT request of the updated reportback to be saved in Rogue.
   *
   * @param string $baseurl
   * @param array $data
   * @return object|false
   */
  public function updateReportback($baseurl, $data) {
    $response = $this->put(ROGUE_API_URL . '/' . ROGUE_API_VERSION . '/' . $baseurl, $data);

    return $response;
  }
}
