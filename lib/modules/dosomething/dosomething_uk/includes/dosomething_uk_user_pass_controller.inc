<?php

/**
 * UK User Pass Controller.
 */
class DosomethingUkUserPassController implements ExternalAuthUserPassController {

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function ensure_local_user_exists(Array $form, Array &$form_state) {
    return TRUE;
  }

  // ---------------------------------------------------------------------

}
