<?php

/**
 * Canada Login Controller.
 */
class DosomethingCanadaLoginController implements ExternalAuthLoginController {

  // ---------------------------------------------------------------------
  // Instance variables

  /**
   * The email of the user.
   *
   * @var string
   */
  private $email;

  /**
   * The password of the user.
   *
   * @var string
   */
  private $password;

  /**
   * The fully-loaded $user object.
   *
   * @var object
   */
  private $local_account;

  /**
   * The remote user object.
   */
  private $remote_account;

  /**
   * The SSO controller.
   */
  private $sso;

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function setup(Array $form_state) {
    $this->email    = $form_state['values']['name'];
    $this->password = $form_state['values']['pass'];
    $this->local_account  = dosomething_user_get_user_by_email($this->email);
    return $this;
  }

  // Check whether local account exists.
  public function loginExists() {
    return (bool) $this->local_account;
  }

  /**
   * Processes existing user during login.
   *
   * @return boolean
   *   Whether the processing was successful.
   */
  public function loginExistingUser() {

    // Check whether remote account with requested email exists:
    try {
      $this->sso = dosomething_canada_get_sso();

      if ($this->sso->authenticate($this->email, $this->password)) {
        $this->remote_account = $this->sso->getRemoteUser();
      }
    }
    catch (Exception $e) {

      // The only users that exist locally but not remotely should be admin
      // accounts that were created before SSO integration. These should be
      // created remotely as well.
      $this->sso->propagateLocalUser(
        $this->email,
        $this->password,
        dosomething_canada_create_sso_user($this->email, $this->password, $this->local_account)
      );
    }
    return TRUE;
  }

  public function getRemoteUser() {
    $this->sso = dosomething_canada_get_sso();

    if ($this->sso->authenticate($this->email, $this->password)) {
      $this->remote_account = $this->sso->getRemoteUser();
    }
    return $this->remote_account;
  }

  /**
   * Create new local user based on remote SSO user during login.
   *
   * @return object|false
   *   A fully-loaded $user object upon successful save or FALSE.
   */
  public function createFromRemote() {
    $edit = array(
      'mail'    => $this->email,
      'name'    => $this->email,
      'pass'    => $this->password,
      'status'  => 1,
      'created' => REQUEST_TIME,
    );

    $dob = new DateObject($this->remote_account->DOB);
    $fields = array(
      'birthdate'                => $dob->format(DATE_FORMAT_DATE),
      'first_name'               => $this->remote_account->Name,
      'user_registration_source' => DOSOMETHING_CANADA_USER_SOURCE,
    );
    dosomething_user_set_fields($edit, $fields);

    try {
      $account = user_save('', $edit);
    }
    catch (Exception $e) {
      watchdog_exception(DOSOMETHING_CANADA_WATCHDOG, $e);
      return FALSE;
    }

    $this->local_account = $account;
    return $this->local_account;
  }

  // ---------------------------------------------------------------------

}
