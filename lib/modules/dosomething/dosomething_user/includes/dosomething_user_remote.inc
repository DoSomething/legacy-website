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
   * The first name.
   *
   * @var string
   */
  private $first_name;

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

  /**
   * A DateTime object representing user's birthdate.
   *
   * @var DateTime
   */
  private $dob;

  /**
   * The mobile phone number.
   *
   * Optional, defaults to FALSE.
   *
   * @var string
   */
  private $phone_number;


  // ---------------------------------------------------------------------
  // Constructor and factories

  /**
   * Constructs a DosomethingUserRemote object.
   *
   * @param string $email
   *   The email of the user.
   * @param string $password
   *   The password of the user.
   * @param string $first_name
   *   The first name of the user.
   * @param string $phone_number
   *   (Optional) The phone number of the user.
   */
  public function __construct($email, $password, $first_name, DateTime $dob,
                              $phone_number = FALSE)
  {
    // Required fields.
    $this->email        = $email;
    $this->password     = $password;
    $this->first_name   = $first_name;
    $this->dob          = $dob;
    $this->phone_number = $phone_number;
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
   * Returns the first name.
   *
   * @return string
   */
  public function getFirstName()
  {
    return $this->first_name;
  }

  /**
   * Returns the last name.
   *
   * @return string
   */
  public function getLastName()
  {
    return $this->last_name;
  }

  /**
   * Returns the email.
   *
   * @return string
   */
  public function getEmail()
  {
    return $this->email;
  }


  /**
   * Returns DateTime object of the user's date of birth.
   *
   * @return DateTime
   */
  public function getDob()
  {
    return $this->dob;
  }

  /**
   * Returns the 'Y-m-d' string representaion of the user's date of birth.
   *
   * @return string
   */
  public function getDobString()
  {
    return $this->dob->format(DATE_FORMAT_DATE);
  }

  /**
   * Gets the mobile phone number.
   *
   * This field is optional for new users.
   *
   * @return string|false
   *   The mobile phone number or FALSE when the number is not available.
   */
  public function getPhoneNumber()
  {
    return $this->phone_number;
  }

  /**
   * Gets the user's country.
   *
   * @return string.
   *   Current affiliate's country.
   */
  public function getCountry()
  {
    return dosomething_settings_get_affiliate_country_code();
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
