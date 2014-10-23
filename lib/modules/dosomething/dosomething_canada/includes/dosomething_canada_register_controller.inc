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

    // Set users address country.
    form_set_value(
      $form['field_address'],
      array(LANGUAGE_NONE => array(array(
        'postal_code' => '',
        'country'     => DOSOMETHING_CANADA_USER_COUNTRY,
      ))),
      $form_state
    );

    return $this;
  }

  public function signup() {
    $user = new stdClass();
    $user->email    = $this->account_values['mail'];
    $user->password = $this->account_values['pass'];

    if (!empty($this->account_values['field_birthdate']['und'][0])) {
      $user->dob = $this->account_values['field_birthdate']['und'][0]['value'];
    }

    if (!empty($this->account_values['field_mobile']['und'][0])) {
      $user->mobile = $this->account_values['field_mobile']['und'][0]['value'];
    }

    if (!empty($this->account_values['field_first_name']['und'][0])) {
      $user->firstName = $this->account_values['field_first_name']['und'][0]['value'];
    }

    if (!empty($this->account_values['field_last_name']['und'][0])) {
      $user->lastName = $this->account_values['field_last_name']['und'][0]['value'];
    }

    $result = FALSE;
    try {
      $result = $this->sso->propagateLocalUser($this->email, $this->password, $user);
    } catch (Exception $e) {
      return FALSE;
    }
    return $result;
  }

  public function processSignupErrors(Array $form) {}

  // ---------------------------------------------------------------------

}
