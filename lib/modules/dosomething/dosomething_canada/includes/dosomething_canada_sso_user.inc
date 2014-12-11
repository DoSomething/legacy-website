<?php

/**
* Constructs DosomethingCanadaSsoUser from different sources.
*/
class DosomethingCanadaSsoUserFactory implements DosomethingUserRemoteFactory {

  /**
   * Construct DosomethingCanadaSsoUser from local form values.
   *
   * @return DosomethingCanadaSsoUser
   */
  public function fromFormValues(Array $form, Array &$form_state)
  {
    // -- Required user data. --
    $values = &$form_state['values'];
    $user_data = array(
      'email'     => $values['mail'],
      'password'  => $values['pass'],
      'firstName' => $values['field_first_name'][LANGUAGE_NONE][0]['value'],
      'dob'       => $values['field_birthdate'][LANGUAGE_NONE][0]['value'],
    );

    // -- Optional user data. --
    if (!empty($values['field_mobile']['und'][0])) {
      $user_data['mobile'] = $values['field_mobile']['und'][0]['value'];
    }
    return new DosomethingCanadaSsoUser($user_data);
  }

  /**
   * Construct DosomethingCanadaSsoUser from local user.
   *
   * @return DosomethingCanadaSsoUser
   */
  public function fromLocalUser($local_account, $password = NULL)
  {
    $user_data = array(
      'email'     => $local_account->mail,
      'firstName' => $local_account->field_first_name['und'][0]['value'],
      'dob'       => $local_account->field_birthdate['und'][0]['value'],
    );

    if (!empty($password)) {
      $user_data['password'] = $password;
    }

    if (!empty($local_account->field_mobile['und'][0]['value'])) {
      $user_data['mobile'] = $local_account->field_mobile['und'][0]['value'];
    }

    return new DosomethingCanadaSsoUser($user_data);
  }

  /**
   * Construct DosomethingCanadaSsoUser from remote user data.
   *
   * @return DosomethingCanadaSsoUser
   */
  public function fromRemoteData($remote_user_data)
  {
    $user_data = array(
      'email'     => $remote_user_data->Email,
      'firstName' => $remote_user_data->Name,
      'dob'       => $remote_user_data->DOB,
    );

    // -- Optional user data. --
    if (!empty($remote_user_data->Phone)) {
      $user_data['mobile'] = $remote_user_data->Phone;
    }

    return new DosomethingCanadaSsoUser($user_data);
  }

}

/**
 * Represents Canada SSO user.
 */
class DosomethingCanadaSsoUser extends DosomethingUserRemote {

  // ---------------------------------------------------------------------
  // Class constants

  // Remote user.
  const SIGNUP_BIRTHDATE_FORMAT = DATE_FORMAT_DATETIME;

  // Local drupal user.
  const REGISTRATION_SOURCE = 'dosomething_canada';

  // ---------------------------------------------------------------------
  // Instance variables

  /**
   * The full name.
   *
   * @var string
   */
  private $firstName;

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
   * The phone number must be valid Canadian phone number.
   *
   * @var string
   */
  private $mobile;

  /**
   * The users login name.
   *
   * Canada SSO unique user's sting identifier.
   * Generated automatically on the remote side.
   *
   * @var string
   */
  private $username;


  // ---------------------------------------------------------------------
  // Constructor

  /**
   * Builds Canada SSO user using an associative array.
   *
   * @param array $data
   *   An associative array containing:
   *   - email: The postcode of the user.
   *   - password: The email of the user.
   *   - firstName: The first name of the user.
   *   - dob: A DateTime object or DateTime-complaint string representing
   *     user's birthdate.
   *   - mobile: (optional) The phone number consistent with
   *     Canadian phone number format.
   *   - username: (optional) Generated automatically on the remote side.
   */
  public function __construct($data)
  {
    if (empty($data['password'])) {
      $data['password'] = FALSE;
    }
    parent::__construct($data['email'], $data['password']);

    if (is_string($data['dob'])) {
      $data['dob'] = new DateObject($data['dob']);
    }
    // Set Canada-specific fields.
    $this->firstName = $data['firstName'];
    $this->dob       = $data['dob'];

    // Optional fields.
    $this->mobile = FALSE;
    if (isset($data['mobile'])) {
      $this->mobile = $data['mobile'];
    }

    $this->username = FALSE;
    if (isset($data['username'])) {
      $this->username = $data['username'];
    }
  }

  // ---------------------------------------------------------------------
  // Public: methods

  public function toRemotePostFieldsArray()
  {
    $fields = $this->toArray();
    return $fields;
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
      'email'       => $this->getEmail(),
      'password'    => $this->getPassword(),
      'firstName'   => $this->getFirstName(),
      'dob'         => $this->getDob()->format(self::SIGNUP_BIRTHDATE_FORMAT),
    );

    // User's mobile phone number.
    if ($this->getMobile()) {
      $data['mobile'] = $this->getMobile();
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
    return $this->firstName;
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
   *   The number is consistent with Canadian phone number format.
   */
  public function getMobile()
  {
    return $this->mobile;
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
  public function getUsername()
  {
    return $this->username;
  }

  // ---------------------------------------------------------------------

}
