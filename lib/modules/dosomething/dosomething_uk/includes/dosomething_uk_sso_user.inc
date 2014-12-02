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
   * A boolean determines whether the user agreed to receive e-mail newsletter.
   *
   * Optional.
   *
   * @var boolean
   */
  private $contactable;

  // ---------------------------------------------------------------------
  // Constructor and factories

  /**
   * Builds UK SSO user using an associative array.
   *
   * @param array $data
   *   An associative array containing:
   *   - first_name: The first name of the user.
   *   - last_name: The last name of the user.
   *   - password: The email of the user.
   *   - postcode: The password of the user.
   *   - email: The postcode of the user.
   *   - dob: A DateTime object or DateTime-complaint string representing
   *     user's birthdate.
   *   - phone: (optional) The phone number consistent with
   *     UK phone number format.
   *
   * @return static
   */
  public static function fromArray($data) {
    if (is_string($data['dob'])) {
      $data['dob'] = new DateObject($data['dob']);
    }

    $instance = new self(
      $data['email'],
      $data['password'],
      $data['first_name'],
      $data['dob'],
      (isset($data['phone_number']) ? $data['phone_number'] : FALSE)
    );

    // Set UK-specific fields.
    $instance->last_name   = $data['last_name'];
    $instance->postcode    = $data['postcode'];
    $instance->screen_name = strtolower($instance->getFirstName()) . time();

    $contactable = isset($data['contactable']) ? (bool) $data['contactable']
                                               : FALSE;
    $instance->contactable = $contactable;
    return $instance;
  }

  // ---------------------------------------------------------------------
  // Public: methods

  public function toRemotePostFieldsArray()
  {
    // -- Required user data. --
    $fields = array(
      'first_name'  => $this->getFirstName(),
      'last_name'   => $this->getLastName(),
      'dob'         => $this->getDob()->format(self::SIGNUP_BIRTHDATE_FORMAT),
      'postcode'    => $this->getPostcode(),
      'email'       => $this->getEmail(),
      'screen_name' => $this->getScreenName(),
      'password'    => $this->getPassword(),
    );

    // Must be the same as user's password.
    $fields['password_confirmation'] = $this->getPassword();

    // -- Optional user data. --
    // User's agreement to the email newsletter.
    if ($this->isContactable()) {
      $fields['contactable'] = 1;
    }
    // User's mobile phone number.
    if ($this->getPhoneNumber()) {
      $fields['phone_number'] = $this->getPhoneNumber();
    }

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

  // ---------------------------------------------------------------------
  // Public: field accessors

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
