<?php

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
