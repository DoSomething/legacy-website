<?php

interface DosomethingUserRemoteFactory {

  /**
   * Construct DosomethingUserRemote from local form values.
   *
   * @param  array  $form
   * @param  array  &$form_state
   *
   * @return DosomethingUserRemote
   */
  public function fromFormValues(Array $form, Array &$form_state);

  /**
   * Construct DosomethingUserRemote from local user.
   *
   * @param  object  $local_account
   *
   * @return DosomethingUserRemote
   */
  public function fromLocalUser($local_account);

  /**
   * Construct DosomethingUserRemote from remote user data.
   *
   * @param  object  $remote_user_data
   *
   * @return DosomethingUserRemote
   */
  public function fromRemoteData($remote_user_data);

}

/**
 * Minimal set of user fields required to fulfill by
 * a remote user implementation.
 */
abstract class DosomethingUserRemote {

  // ---------------------------------------------------------------------
  // Class constants

  // ---------------------------------------------------------------------
  // Instance variables

  /**
   * The email.
   *
   * @var string
   */
  private $email;

  /**
   * The password.
   *
   * @var string
   */
  private $password;


  // ---------------------------------------------------------------------
  // Constructor and factories

  /**
   * Constructs a DosomethingUserRemote object.
   *
   * @param string $email
   *   The email of the user.
   * @param string $password
   *   The password of the user.
   */
  public function __construct($email, $password)
  {
    // Required fields.
    $this->email    = $email;
    $this->password = $password;
  }

  // ---------------------------------------------------------------------
  // Abstract methods

  /**
   * Serializes class to an array of POST fields to set to the remote server.
   *
   * @return array
   */
  abstract public function toRemotePostFieldsArray();


  /**
   * Saves remote user as local.
   *
   * @param  string  $password
   *   Set use
   *
   * @return bool
   */
  abstract public function saveAsLocal();

  // ---------------------------------------------------------------------
  // Public: field accessors

  /**
   * Returns the email.
   *
   * @return string
   */
  public function getEmail()
  {
    return $this->email;
  }

  // ---------------------------------------------------------------------
  // Public: field mutators

  /**
   * Sets the password.
   *
   * @param string $password
   *   The user password.
   *
   * @return static
   */
  public function setPassword($password)
  {
    $this->password = $password;
    return $this;
  }


  // ---------------------------------------------------------------------
  // Protected: field accessors

  /**
   * Gets the password.
   *
   * @return string
   *   The user password.
   */
  protected function getPassword()
  {
    return $this->password;
  }

  // ---------------------------------------------------------------------

}
