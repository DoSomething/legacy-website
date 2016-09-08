<?php

require_once 'SignupException.php';

class UniqueSignupException extends SignupException {

  /**
   * Create new instance of the UniqueSignupException class.
   *
   * @param string         $message
   * @param integer        $code
   * @param Exception|null $previous
   */
  public function __construct($message, $code = 0, Exception $previous = null) {

    $message = 'A record for this combination of user, campaign and campaign run already exists.';

    $code = 422;

    parent::__construct($message, $code, $previous);
  }

}
