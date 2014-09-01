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
   *
   * @var string
   */
  private $screen_name;

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

  // ---------------------------------------------------------------------
  // Private: utilities


  // ---------------------------------------------------------------------

}
