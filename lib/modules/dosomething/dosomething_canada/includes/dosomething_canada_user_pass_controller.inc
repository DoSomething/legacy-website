<?php

/**
 * Canada User Pass Controller.
 */
class DosomethingCanadaUserPassController implements ExternalAuthUserPassController {

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function ensure_local_user_exists(Array $form, Array &$form_state) {
    if (empty($form_state['values']['name'])) {
      return FALSE;
    }
    $this->sso = dosomething_canada_get_sso();
    $remote_account = $this->sso->getUserByEmail($form_state['values']['name']);

    if (!$remote_account) {
      return FALSE;
    }

    // Sent random password.
    $remote_account->setPassword(user_password());
    $remote_account->saveAsLocal();
    return TRUE;
  }

  // ---------------------------------------------------------------------

}
