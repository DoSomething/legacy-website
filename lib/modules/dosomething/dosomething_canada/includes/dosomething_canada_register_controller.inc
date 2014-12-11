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
   * The remote user object.
   *
   * @var DosomethingCanadaSsoUser
   */
  private $remote_account;

  /**
   * The SSO controller.
   */
  private $sso;

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function setup(Array $form, Array &$form_state) {
    $this->sso = dosomething_canada_get_sso();

    // Create SSO user.
    $user_factory = new DosomethingCanadaSsoUserFactory();
    $this->remote_account = $user_factory->fromFormValues($form, $form_state);
    return $this;
  }

  public function signup() {
    return $this->sso->signup($this->remote_account);
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
