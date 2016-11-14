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
  public function postReportback($data) {
    $response = $this->post('reportbacks', $data);

    return $response;
  }

  /**
   * Send a PUT request of the updated reportback to be saved in Rogue.
   *
   * @param string $baseurl
   * @param array $data
   * @return object|false
   */
  public function updateReportback($data) {
    $response = $this->put('items', $data);

    return $response;
  }
}
