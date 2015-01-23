<?php

/**
 * Represents UK Local user.
 */
class DosomethingUkLoginController implements ExternalAuthLoginController {

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
   *
   * @var DosomethingUkSsoUser
   */
  private $remote_account;

  /**
   * The SSO controller.
   *
   * @var DosomethingUkSsoController
   */
  private $sso;

  // ---------------------------------------------------------------------
  // Public: interface implementation

  public function setup(Array $form, Array &$form_state) {
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
    // Check whether the user is already authorized on SSO.
    $this->sso = DosomethingUkSsoController::initForLocalUser($this->local_account->uid);
    if ($this->sso->remoteUserAdmitted()) {
      // Todo: update local password and/or profile data.
      return TRUE;
    }

    // Todo: try to create remote user based on local.
    return TRUE;
  }

  public function getRemoteUser() {
    $this->sso = DosomethingUkSsoController::init()->authorizeRemoteRedirect();

    $url = $this->sso->getAuthorizationUrl(TRUE, TRUE);
    if (!$url) {
      throw new Exception('Unexpected login error: request token.');
    }

    // Impersonate remote user logged into SSO.
    $impersonator = DosomethingUkSsoImpersonator::login($this->email, $this->password);

    if (!$impersonator->isLoggedIn()) {
      // Todo: link to forgot password page.
      // Remote login failed: wrong credentials.
      return FALSE;
    }

    // Accept OAuth authorization impersonating SSO user.
    if (!$impersonator->acceptRemoteOAuth($url)) {
      // Todo: session expired.
      // @see /includes/form.inc:1173
      throw new Exception('The form has become outdated.');
    }

    // Retrieve SSO user data.
    $sso_user = $this->sso->authorizeAccessToken()->getRemoteUser();
    if (!$sso_user) {
      throw new Exception('Unexpected login error: request token.');
    }
    $this->remote_account = $sso_user;
    $this->remote_account->setPassword($this->password);
    return $this->remote_account;
  }

  /**
   * Create new local user based on remote SSO user during login.
   *
   * @return object|false
   *   A fully-loaded $user object upon successful save or FALSE.
   */
  public function createFromRemote() {
    $account = $this->remote_account->saveAsLocal();
    if (!$account) {
      return;
    }

    $this->local_account = $account;
    $this->sso->authorizeUserAccess($this->local_account->uid);
    return $this->local_account;
  }

  // ---------------------------------------------------------------------

}
