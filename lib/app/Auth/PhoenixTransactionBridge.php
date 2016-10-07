<?php

namespace Phoenix\Auth;

use DoSomething\Gateway\Contracts\TransactionBridgeContract; // we import the transaction bridge contract
use League\OAuth2\Client\Token\AccessToken;

class PhoenixOAuthBridge implements TransactionBridgeContract {

  /**
   * Get the value of the given HTTP header.
   *
   * @return string
   */
  public function getHeader($name) {
      return drupal_get_http_header($name);
  }

  /**
   * Write a log message.
   *
   * @return void
   */
  public function log($message, array $details) {
      watchdog('Transaction', $details, NULL, WATCHDOG_INFO);
  }

}