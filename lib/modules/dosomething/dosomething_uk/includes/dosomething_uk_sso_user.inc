<?php

/**
 * Represents UK SSO user.
 */
class DosomethingUkSsoUser {

  // ---------------------------------------------------------------------
  // Class constants

  // Remote user.
  const SIGNUP_FORM_CONTAINER        = 'user';
  const SIGNUP_FORM_BIRTHDATE_FORMAT = 'd/m/Y';


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
  // Constructor and factories

  /**
   * Constructs a DosomethingUkSsoUser object.
   *
   * @param string $first_name
   *   The first name of the user.
   * @param string $last_name
   *   The last name of the user.
   * @param string $email
   *   The email of the user.
   * @param string $password
   *   The password of the user.
   * @param string $postcode
   *   The postcode of the user.
   * @param DateTime $dob
   *   A DateTime object representing user's birthdate.
   */
  public function __construct($first_name, $last_name, $email, $password,
                              $postcode, DateTime $dob)
  {
    // Required fields.
    $this->first_name = $first_name;
    $this->last_name  = $last_name;
    $this->password   = $password;
    $this->postcode   = $postcode;
    $this->email      = $email;
    $this->dob        = $dob;

    // Defaults for optional fields.
    $this->contactable = FALSE;
    $this->phone_number = FALSE;

    // Figured from reals generated screen names on UK SSO.
    $this->screen_name = strtolower($this->first_name) . time();
  }

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
   *   - dob: A DateTime object representing user's birthdate.
   *
   * @return static
   */
  public static function fromArray($data) {
    $instance = new self(
      $data['first_name'],
      $data['last_name'],
      $data['email'],
      $data['password'],
      $data['postcode'],
      $data['dob']
    );
    return $instance;
  }

  // ---------------------------------------------------------------------
  // Public: methods

  public function toFormFields()
  {
    // -- Required user data. --
    $fields = array(
      'first_name'  => $this->first_name,
      'last_name'   => $this->last_name,
      'dob'         => $this->dob->format(self::SIGNUP_FORM_BIRTHDATE_FORMAT),
      'postcode'    => $this->postcode,
      'email'       => $this->email,
      'screen_name' => $this->screen_name,
      'password'    => $this->password,
    );

    // Must be the same as user's password.
    $fields['password_confirmation'] = $this->password;

    // -- Optional user data. --
    // User's agreement to the email newsletter.
    if ($this->contactable) {
      $fields['contactable'] = 1;
    }
    // User's mobile phone number.
    if ($this->phone_number) {
      $fields['phone_number'] = $this->phone_number;
    }

    // Must be 1 to indicate acceptance of the terms & conditions of vInspired.
    // You should make sure to present these terms to the user.
    $fields['terms'] = 1;

    // Wrap form keys in 'user' array.
    // Must be like that due to the OAuth library limitations.
    $result = array();
    foreach ($fields as $key => $value) {
      $fixed_key = self::SIGNUP_FORM_CONTAINER . '[' . $key . ']';
      $result[$fixed_key] = $value;
    }
    return $result;
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
   * Returns the email.
   *
   * @return string
   */
  public function getEmail()
  {
    return $this->email;
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
   * Returns the date of birth.
   *
   * @return string
   */
  public function getDob()
  {
    return $this->dob;
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
  // Public: field mutators

  /**
   * Sets the mobile phone number.
   *
   * @param string
   *   $phone_number The phone number consistent with UK phone number format.
   *
   * @return $this
   */
  public function setPhoneNumber($phone_number)
  {
    $this->phone_number = $phone_number;
    return $this;
  }

  /**
   * Sets user's agreement for newsletter e-mails.
   *
   * @param boolean
   *   $contactable A boolean correspondent to the user's agreement.
   *
   * @return $this
   */
  public function setContactable($contactable)
  {
    $this->contactable = $contactable;
    return $this;
  }

  // ---------------------------------------------------------------------
  // Private: utilities


  // ---------------------------------------------------------------------

}
