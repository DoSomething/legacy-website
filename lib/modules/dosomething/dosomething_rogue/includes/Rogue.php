<?php

use DoSomething\Gateway\Common\RestApiClient;
use DoSomething\Gateway\ForwardsTransactionIds;

class Rogue extends RestApiClient {
  use ForwardsTransactionIds;

  /**
   * Get the CSRF token for the authenitcated API session.
   * The class name of the transaction framework bridge.
   *
   * @return string - token
   * @var string
   */
  private function getAuthenticationToken()
  {
    return $this->authenticate()['token'];
  }

  protected $transactionBridge = Phoenix\Auth\PhoenixTransactionBridge::class;

  /**
   * Send a POST request of the reportback to be saved in Rogue.
   *
   * @param string $url
   * @param array $data
   * @return object|false
   */
  public function postReportback($url, $data) {
    $respons = $this->post($url, $data);

    return is_null($response) ? null : $response;
  }

  /**
   * Send a PUT request of the updated reportback to be saved in Rogue.
   *
   * @param string $url
   * @param array $data
   * @return object|false
   */
  public function updateReportback($url, $data) {
    $response = $this->put($url, $data);

    return is_null($response) ? null : $response;
  }
}
