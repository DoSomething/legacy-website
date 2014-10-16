<?php

/**
 * Canada Registration Controller.
 *
 * @todo: Implement registration.
 */
class DosomethingCanadaRegisterController implements ExternalAuthRegisterController {

  // ---------------------------------------------------------------------
  // Instance variables

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function setup(Array $form_state) {
    return $this;
  }

  public function signup() {
    return TRUE;
  }

  public function processSignupErrors(Array $form) {}

  // ---------------------------------------------------------------------

}
