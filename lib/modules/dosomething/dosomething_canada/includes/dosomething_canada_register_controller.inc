<?php

/**
 * Canada Registration Controller.
 *
 * @todo: Implement registration.
 */
class DosomethingCanadaRegisterController implements ExternalAuthRegisterController {

  // ---------------------------------------------------------------------
  // Instance variables

  /**
   * The registration form.
   */
  private $account_values;

  /**
   * The SSO controller.
   */
  private $sso;

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function setup(Array $form, Array &$form_state) {
    $this->account_values = $form_state['values'];
    $this->sso = dosomething_canada_get_sso();
    return $this;
  }

  public function signup() {
    $local_user = new stdClass();
    $local_user->email    = $this->account_values['mail'];
    $local_user->password = $this->account_values['pass'];

    if (!empty($this->account_values['field_birthdate']['und'][0])) {
      $local_user->dob = $this->account_values['field_birthdate']['und'][0]['value'];
    }

    if (!empty($this->account_values['field_mobile']['und'][0])) {
      $local_user->mobile = $this->account_values['field_mobile']['und'][0]['value'];
    }

    if (!empty($this->account_values['field_first_name']['und'][0])) {
      $local_user->firstName = $this->account_values['field_first_name']['und'][0]['value'];
    }

    if (!empty($this->account_values['field_last_name']['und'][0])) {
      $local_user->lastName = $this->account_values['field_last_name']['und'][0]['value'];
    }

    $result = FALSE;
    try {
      $result = $this->sso->propagateLocalUser($local_user);
    } catch (Exception $e) {
      return FALSE;
    }
    return $result;
  }

  public function processSignupErrors(Array $form) {
    // SSO returned unexpected errors with no much to local fields.
    if (!form_get_errors()) {
      form_set_error('form', t('Unknown error during response parsing.'));
    }
  }

  // ---------------------------------------------------------------------

}
