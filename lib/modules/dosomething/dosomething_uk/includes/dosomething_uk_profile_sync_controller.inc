<?php

/**
 * Canada Registration Controller.
 */
class DosomethingUkProfileSyncController implements ExternalAuthProfileSyncController {

  // ---------------------------------------------------------------------
  // Instance variables

  /**
   * The remote user object.
   *
   * @var DosomethingUkSsoUser
   */
  private $remote_account;

  /**
   * The SSO controller.
   *
   * @var DosomethingUkSsoController
   */
  private $sso;

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function setup(Array $form, Array &$form_state) {

  }

  public function sync() {
    // @todo Implement profile sync when remote API is ready.
    return TRUE;
  }

  /**
   * Maps remote error messages to local fields.
   *
   * @todo Map and assign fields.
   */
  public function processRemoteErrors(Array $form) {

  }

  // ---------------------------------------------------------------------

}
