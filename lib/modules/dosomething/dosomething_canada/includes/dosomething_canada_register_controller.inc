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

  /**
   * Maps remote error messages to local fields.
   *
   * @todo Map and assign fields.
   * @todo Fix message 'Sorry, but vinspired is only for 14 to 25 year olds'
   */
  public function processSignupErrors(Array $form) {
    if ($error_messages = $this->sso->getErrorMessages()) {
      foreach ($error_messages as $field_name => $field_errors) {
          foreach ($field_errors as $error) {
          $human_name = ucwords(preg_replace('/[^\da-z]/i', ' ', $field_name));
          $error_text = $human_name . ': ' . $error;
          form_set_error($field_name, $error_text);
        }
      }
    }

    // SSO returned unexpected errors with no much to local fields.
    if (!form_get_errors()) {
      form_set_error('form', t('Unknown error during response parsing.'));
    }
  }

  // ---------------------------------------------------------------------

}
