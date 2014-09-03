<?php

/**
 * A http client.
 */
class DosomethingUkSsoImpersonator {


  // ---------------------------------------------------------------------
  // Class constants

  // Login form settings.
  const LOGIN_PATH         = '/user_sessions';
  const LOGIN_CONTENT_TYPE = 'application/x-www-form-urlencoded';

  // Login form fields.
  const LOGIN_FIELD_AUTH          = 'user_session';
  const LOGIN_FIELD_AUTH_LOGIN    = 'email';
  const LOGIN_FIELD_AUTH_PASSWORD = 'password';

  // Access settings.
  const HEADER_ACCEPT = 'application/xml';
  const SESSION_NAME  = 'user_credentials';

  // Other.
  const USER_AGENT  = 'Drupal (+https://www.dosomething.org/)';
  const LOGGER_NAME = 'DosomethingUkSsoImpersonator';


  // ---------------------------------------------------------------------
  // Instance variables

  /**
   * [$url description]
   * @var string
   */
  private $url;

  /**
   * [$session description]
   * @var string
   */
  private $session;

  /**
   * [$user description]
   * @var string
   */
  private $user;

  /**
   * [$last description]
   * @var string
   */
  private $last;


  // ---------------------------------------------------------------------
  // Constructor and factories

  /**
   * Constructs a DosomethingUkSsoImpersonator object.
   */
  public function __construct()
  {
    $this->url      = variable_get('dosomething_uk_oauth_url');
    $this->session = FALSE;
    $this->user    = FALSE;
    $this->last    = new stdClass();
  }

  /**
   * Returns remotely authorized impersonator.
   *
   * @param string $login
   *   The login of the remote user.
   * @param string $password
   *   The password of the remote user.
   *
   * @return static
   */
  public static function login($login, $password) {
    $instance = new self();
    $instance->impersonateRemoteUser($login, $password);
    return $instance;
  }

  // ---------------------------------------------------------------------
  // Public: field accessors

  public function isLoggedIn()
  {
    return (bool) $this->session;
  }

  // ---------------------------------------------------------------------
  // Public: remote API calls

  public function getRemote($path)
  {
    if (!$this->isLoggedIn()) {
      return FALSE;
    }
    $response = drupal_http_request($this->apiPath($path), $this->defaults());
    $this->last = $response;
    return $response;
  }

  public function acceptRemoteOAuth($path)
  {
    if (!$this->isLoggedIn()) {
      return FALSE;
    }
    $result = FALSE;
    $response = $this->getRemote($path);

    // Validate result.
    // Success condition: `201 Created`.
    // Failure condition: everything, but `201 Created`.
    if (isset($response->code) && $response->code == 201) {
      $result = TRUE;
    }
    return $result;
  }

  public function impersonateRemoteUser($login, $password)
  {
    // Reset previous authorization.
    $this->user    = FALSE;
    $this->session = FALSE;

    // Fill in the login form for the user.
    $form_data = array(
      self::LOGIN_FIELD_AUTH => array(
        self::LOGIN_FIELD_AUTH_LOGIN    => $login,
        self::LOGIN_FIELD_AUTH_PASSWORD => $password,
      ),
    );

    // Encoding is performed per RFC 1738 and
    // the application/x-www-form-urlencoded media type,
    // which implies that spaces are encoded as plus (+) signs.
    $data = http_build_query($form_data);

    // Prepare request options.
    $options = $this->defaults(array(
      'method'  => 'POST',
      'headers' => array('Content-Type' => self::LOGIN_CONTENT_TYPE),
      'data'    => $data,
    ));

    // Send the login form.
    // Important: turn off following redirects automatically.
    $response = drupal_http_request($this->apiPath(self::LOGIN_PATH), $options);

    // An error occurred while executing the request.
    if (isset($response->error)) {
      // Don't log 500, it's expected on unsuccessful logins.
      if ($response->code != 500) {
        self::log('Unexpected error during login request: %s', $response->error);
      }
      return $this;
    }

    // Login is  **successful** when:
    //   - Session cookie must be set to string. Session cookie name
    //     is defined in `self::SESSION_NAME` Example:
    //     `Set-Cookie: user_credentials=49c71c9ff59ebdd24708e45b9610ebed1eef9d13c9de97edfe540c823d91b20eab46eb8824fd9426e7ead35be3d03b16b6113a7c1eef37c7c1716ac4df9fe035%3A%3A294880; path=/`
    if (isset($response->headers) && !empty($response->headers['set-cookie'])) {
      $cookies_string = $response->headers['set-cookie'];
      $this->session = $this->findSessionTokenInCookies($cookies_string);
      if ($this->isLoggedIn()) {
        $this->user = $login;
      }
    }

    // Indirect evidences of the successful login:
    //   - HTTP response is `302 Found`
    //   - HTTP header `Status` is equal `302` and/or not `500`
    //   - HTTP header `Location` is equal the callback URL `return_to`,
    //     if provided

    // Be aware that when `Accept` header not specified, HTTP response for
    // **unsuccessful** login will be inconsistent `200 OK`.

    return $this;
  }

  // ---------------------------------------------------------------------
  // Private: utilities

  private function findSessionTokenInCookies($cookies_string) {
    // Find session cookie.
    // Split cookie set strings:
    $cookies = explode(',', $cookies_string);
    foreach ($cookies as $cookie_arguments_string) {
      // Split cookie `name=value` pair from cookie path and other parameters.
      $cookie_arguments = explode(';', $cookie_arguments_string, 2);

      // Cookie `name=value` parameter is always the first.
      $cookie_name_value_string = reset($cookie_arguments);
      if (!$cookie_name_value_string) {
        continue;
      }

      // Split name and value.
      $cookie_name_value = explode('=', $cookie_name_value_string, 2);
      if (count($cookie_name_value) != 2) {
        continue;
      }
      list($name, $value) = $cookie_name_value;

      // Return cookie value when the name is correct.
      if ($name == self::SESSION_NAME && !empty($value)) {
        return urldecode($value);
      }
    }
    return FALSE;
  }

  private function defaults($options = array()) {
    $defaults = array(
      'max_redirects' => 0,
      'headers' => array(
        'Accept'       => self::HEADER_ACCEPT,
        'User-Agent'   => self::USER_AGENT,
      ),
    );
    if ($this->isLoggedIn()) {
      $session = array(self::SESSION_NAME => $this->session);
      $defaults['headers']['Cookie'] = http_build_query($session);
    }
    return  array_replace_recursive($options, $defaults);
  }

  private function apiPath($path) {
    return $this->url . $path;
  }

  private static function log($message, $error)
  {
    $variables = array();
    if (!empty($error)) {
      $variables['%s'] = $error;
    }
    watchdog(self::LOGGER_NAME, $message, $variables, WATCHDOG_NOTICE);
  }

  private static function logExeption(Exception $e)
  {
    watchdog_exception(self::LOGGER_NAME, $e);
  }

  // ---------------------------------------------------------------------

}
