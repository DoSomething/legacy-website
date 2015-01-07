<?php

/**
 * Canada Registration Controller.
 */
class DosomethingCanadaProfileSyncController implements ExternalAuthProfileSyncController {

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
   *
   * @var CanadaSSOClient
   */
  private $sso;

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function setup(Array $form, Array &$form_state) {
    $this->sso = dosomething_canada_get_sso();

    // Create SSO user.
    $user_factory = new DosomethingCanadaSsoUserFactory();

    // Disable email change to prevent account hijacking on the remote server.
    $values = &$form_state['values'];
    if ($form_state['user']->mail !== $values['mail']) {
      form_set_error('mail', t('Email change is disabled.'));
      return FALSE;
    }

    $this->remote_account = $user_factory->fromFormValues($form, $form_state);
  }

  public function sync() {
    if (!$this->remote_account) {
      return FALSE;
    }
    return $this->sso->update($this->remote_account);
  }

  /**
   * Maps remote error messages to local fields.
   *
   * @todo Map and assign fields.
   */
  public function processRemoteErrors(Array $form) {
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
