<?php

use DoSomething\Gateway\Common\RestApiClient;
use DoSomething\Gateway\ForwardsTransactionIds;

class Rogue extends RestApiClient {
  use ForwardsTransactionIds;

  public function postReportback($url, $data) {
    return $this->post($url, $data);
  }
}
