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

    // -- Required user data. --
    $values = &$form_state['values'];
    $user_data = array(
      'email'     => $values['mail'],
      'password'  => $values['pass'],
      'firstName' => $values['field_first_name'][LANGUAGE_NONE][0]['value'],
      'dob'       => $values['field_birthdate'][LANGUAGE_NONE][0]['value'],
    );

    // -- Optional user data. --
    if (!empty($values['field_mobile']['und'][0])) {
      $user_data['mobile'] = $values['field_mobile']['und'][0]['value'];
    }

    // Create SSO user.
    $this->remote_account = new DosomethingCanadaSsoUser($user_data);
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
