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

  public function setup(Array $form, Array &$form_state) {
    $this->email         = $form_state['values']['name'];
    $this->password      = $form_state['values']['pass'];
    $this->local_account = dosomething_user_get_user_by_email($this->email);
    $this->sso           = dosomething_canada_get_sso();
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
    $remote_account = $this->sso->login($this->email, $this->password);
    if (!$remote_account) {
      // NOTE: By this point user already passed local authentication?
      // The only users that exist locally but not remotely should be admin
      // accounts that were created before SSO integration. These should be
      // created remotely as well.
      $local_account = dosomething_canada_create_sso_user(
        $this->email,
        $this->password,
        $this->local_account
      );
      $this->sso->propagateLocalUser($local_account);
    }
    $this->remote_account = $remote_account;
    return TRUE;
  }

  public function getRemoteUser() {
    $this->remote_account = $this->sso->login($this->email, $this->password);
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
      'country'                  => dosomething_settings_get_affiliate_country_code(),
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
