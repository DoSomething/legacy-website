<?php

/**
 * Represents UK SSO user.
 */
class DosomethingUkSsoUser extends DosomethingUserRemote {

  // ---------------------------------------------------------------------
  // Class constants

  // Remote user.
  const SIGNUP_CONTAINER        = 'user';
  const SIGNUP_BIRTHDATE_FORMAT = 'd/m/Y';


  // Local drupal user.
  const REGISTRATION_SOURCE = 'dosomething_uk';

  // ---------------------------------------------------------------------
  // Instance variables

  /**
   * The first name.
   *
   * @var string
   */
  private $first_name;

  /**
   * The last name.
   *
   * @var string
   */
  private $last_name;

  /**
   * The postcode.
   *
   * Must be a valid UK postcode.
   *
   * @var string
   */
  private $postcode;

  /**
   * A DateTime object representing user's birthdate.
   *
   * @var DateTime
   */
  private $dob;

  /**
   * The screen name.
   *
   * UK SSO unique user's sting identifier.
   * Must be between 4 and 20 chars, must be unique to the SSO.
   * Generated automatically.
   *
   * @var string
   */
  private $screen_name;

  /**
   * The mobile phone number.
   *
   * Optional, defaults to FALSE.
   * The phone number must be valid UK phone number.
   *
   * @var string
   */
  private $phone_number;

  /**
   * A boolean determines whether the user agreed to receive e-mail newsletter.
   *
   * Optional.
   *
   * @var boolean
   */
  private $contactable;

  // ---------------------------------------------------------------------
  // Constructor

  /**
   * Builds UK SSO user using an associative array.
   *
   * @param array $data
   *   An associative array containing:
   *   - email: The postcode of the user.
   *   - password: The email of the user.
   *   - first_name: The first name of the user.
   *   - last_name: The last name of the user.
   *   - postcode: The password of the user.
   *   - dob: A DateTime object or DateTime-complaint string representing
   *     user's birthdate.
   *   - phone_number: (optional) The phone number consistent with
   *     UK phone number format.
   *   - contactable: (optional) A boolean determines whether the user agreed to
   *     receive e-mail newsletter.
   */
  public function __construct($data)
  {
    parent::__construct($data['email'], $data['password']);

    if (is_string($data['dob'])) {
      $data['dob'] = new DateObject($data['dob']);
    }
    // Set UK-specific fields.
    $this->first_name = $data['first_name'];
    $this->last_name  = $data['last_name'];
    $this->postcode   = $data['postcode'];
    $this->dob        = $data['dob'];
    $this->screen_name = strtolower($this->getFirstName()) . time();

    // Optional fields.
    $this->phone_number = FALSE;
    if (isset($data['phone_number'])) {
      $this->phone_number = $data['phone_number'];
    }

    $this->contactable = FALSE;
    if (isset($data['contactable']) && is_bool($data['contactable'])) {
      $this->contactable = $data['contactable'];
    }
  }

  // ---------------------------------------------------------------------
  // Public: methods

  public function toRemotePostFieldsArray()
  {
    $fields = $this->toArray();

    // Must be 1 to indicate acceptance of the terms & conditions of vInspired.
    // You should make sure to present these terms to the user.
    $fields['terms'] = 1;

    // Wrap form keys in 'user' array.
    // Must be like that due to the OAuth library limitations.
    $result = array();
    foreach ($fields as $key => $value) {
      $fixed_key = self::SIGNUP_CONTAINER . '[' . $key . ']';
      $result[$fixed_key] = $value;
    }
    return $result;
  }

  /**
   * Converts object to a compatible array.
   *
   * @see __construct()
   *
   * @return array
   */
  public function toArray() {
    // -- Required user data. --
    $data = array(
      'first_name'  => $this->getFirstName(),
      'last_name'   => $this->getLastName(),
      'dob'         => $this->getDob()->format(self::SIGNUP_BIRTHDATE_FORMAT),
      'postcode'    => $this->getPostcode(),
      'email'       => $this->getEmail(),
      'screen_name' => $this->getScreenName(),
      'password'    => $this->getPassword(),
    );

    // Must be the same as user's password.
    $data['password_confirmation'] = $this->getPassword();

    // -- Optional user data. --
    // User's agreement to the email newsletter.
    if ($this->isContactable()) {
      $data['contactable'] = 1;
    }
    // User's mobile phone number.
    if ($this->getPhoneNumber()) {
      $data['phone_number'] = $this->getPhoneNumber();
    }
    return $data;
  }

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
   *
   *   The number is consistent with UK phone number format. It could be either
   *   the international format starting with the UK telephone country code +44
   *   or local formatted number with the country code omitted.
   *
   *   Refer to Wikipedia article "Telephone numbers in the United Kingdom"
   *   http://en.wikipedia.org/wiki/Telephone_numbers_in_the_United_Kingdom
   *   for more details.
   */
  public function getPhoneNumber()
  {
    return $this->phone_number;
  }

  /**
   * Returns the postcode.
   *
   * @return string
   */
  public function getPostcode()
  {
    return $this->postcode;
  }

  /**
   * Returns the screen name.
   *
   * @return string
   */
  public function getScreenName()
  {
    return $this->screen_name;
  }

  /**
   * Determines whether the user agreed to receive e-mail newsletter.
   *
   * This field is optional for new users and defaults to FALSE.
   *
   * @return boolean
   */
  public function isContactable()
  {
    return $this->contactable;
  }

  // ---------------------------------------------------------------------

}
