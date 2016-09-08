<?php

class SignupException extends Exception {

  /**
   * Create new instance of the SignupException class.
   *
   * @param string         $message
   * @param integer        $code
   * @param Exception|null $previous
   */
  public function __construct($message, $code = 0, Exception $previous = null) {
    parent::__construct($message, $code, $previous);
  }

  /**
   * Get debugging information regarding the exception.
   *
   * @return array
   */
  public function getDebug() {
    return [
      'file' => $this->getFile(),
      'line' => $this->getLine(),
    ];
  }

}
