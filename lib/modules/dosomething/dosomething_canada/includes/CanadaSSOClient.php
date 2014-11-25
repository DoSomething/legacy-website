<?php
/**
 * @file SSO client for DS Canada.
 */

/**
 * Class CanadaSSOClient
 * @package Dosomething
 */
class CanadaSSOClient {

  // ---------------------------------------------------------------------
  // Class constants

  // Login form settings.
  const ENDPOINT_LOGIN = '/login';
  const ENDPOINT_USERS = '/users';

  // Login form fields.
  const LOGIN_FIELD_AUTH_LOGIN    = 'email';
  const LOGIN_FIELD_AUTH_PASSWORD = 'password';

  // Post form settings.
  const POST_CONTENT_TYPE  = 'application/x-www-form-urlencoded';
  const POST_HEADER_ACCEPT = 'application/json';
  const POST_USER_AGENT    = 'Drupal (+https://www.dosomething.org/)';

  // Other.
  const LOGGER_NAME   = 'CanadaSSOClient';

  // ---------------------------------------------------------------------
  // Instance variables

  /**
   * @var string Base URL of the SSO service.
   */
  private $ssoUrl;

  /**
   * @var string SSO credentials: App ID.
   */
  private $ssoAppid;

  /**
   * @var string SSO credentials: App key.
   */
  private $ssoAppkey;

  /**
   * SSO API version, for the base URL.
   *
   * @var string
   */
  private $ssoVersion = '1';

  /**
   * Last response.
   *
   * @var string|false
   */
  private $last_result;

  /**
   * Expected error messages provided in the last result.
   *
   * @var array|false
   */
  private $error_messages;

  // ---------------------------------------------------------------------
  // Constructor and factories

  /**
   * Constructor: requires URL, app ID, and app key for the SSO service.
   *
   * @param $sso_url
   * @param $sso_appid
   * @param $sso_appkey
   */
  public function __construct($sso_url, $sso_appid, $sso_appkey)
  {
    $this->ssoUrl    = $sso_url;
    $this->ssoAppid  = $sso_appid;
    $this->ssoAppkey = $sso_appkey;

    $this->last_result    = FALSE;
    $this->error_messages = FALSE;
  }

  // ---------------------------------------------------------------------
  // Public: remote API calls

  /**
   * Submit to login endpoint. If successful, loads user data
   * into CanadaSSOClient::user.
   *
   * @param $email
   * @param $password
   * @return array
   */
  public function login($email, $password)
  {

    $params = array(
      self::LOGIN_FIELD_AUTH_LOGIN    => $email,
      self::LOGIN_FIELD_AUTH_PASSWORD => $password,
    );
    $this->get(self::ENDPOINT_LOGIN, $params);
    return $this->getUser();
  }

  /**
   * Use a local, existing user to register a user via the API.
   *
   * @param string $email
   * @param string $password
   * @param stdClass $user
   * @return boolean
   */
  public function propagateLocalUser($user)
  {
    $params = get_object_vars($user);
    $this->post(self::ENDPOINT_USERS, $params);
    return $this->getUser();
  }

  // ---------------------------------------------------------------------
  // Public: getters

  public function getErrorMessages()
  {
    return $this->error_messages;
  }

  // ---------------------------------------------------------------------
  // Private: utilities

  /**
   * Construct base URL for all requests, including API version.
   *
   * @return string
   */
  private function getBaseURL()
  {
    return $this->ssoUrl . '/' . $this->ssoVersion;
  }

  /**
   * Execute an API call and return results.
   *
   * @param string $uri Request URI, not including the base URL.
   * @param string $method HTTP request type; defaults to GET.
   * @param array $data Request data as an associative array.
   * @throws Exception
   * @return bool
   */
  private function execute($uri, $method = 'GET', $data)
  {
    // Reset last result.
    $this->last_result    = FALSE;
    $this->error_messages = FALSE;

    // Prepare request options.
    $data = http_build_query($data);
    $url  = $this->getBaseURL() . $uri;
    $options = $this->defaults(array('method' => $method));

    if ($method === 'POST') {
      // Adjustments for POST.
      $options['headers']['Content-Type'] = self::POST_CONTENT_TYPE;
      $options['data'] = $data;
    }
    elseif ($method === 'GET') {
      // Adjustments for GET.
      $url .= '?' . $data;
    }

    // Call the remote endpoint.
    $response = drupal_http_request($url, $options);

    // Evaluate results.
    $success_codes = array(200, 201);
    if (!$response->code || !in_array($response->code, $success_codes)) {
      // An error occurred while executing the request.
      $this->processResponseErrorMessages($response);
      if (!$this->error_messages) {
        // Abnormal response: unexpected HTTP code or no body.
        self::log("Execution error for: %s", $response->error);
      }
      return FALSE;
    }

    $this->last_result = $response;
    return TRUE;
  }

/**
 * Convenience method to execute a GET request.
 *
 * @param string $uri
 * @param array $data
 * @return bool
 */
  private function get($uri, $data)
  {
    return $this->execute($uri, 'GET', $data);
  }

  /**
   * Convenience method to execute a POST request.
   *
   * @param string $uri
   * @param array $data
   * @return bool
   */
  private function post($uri, $data)
  {
    return $this->execute($uri, 'POST', $data);
  }

  /**
   * Convenience method decode user recieved in the last request.
   *
   * @return array
   *  The user decoded.
   */
  private function getUser()
  {
    if (!$this->last_result || empty($this->last_result->data)) {
      return FALSE;
    }

    $user = json_decode($this->last_result->data);
    if (!$user) {
      return FALSE;
    }

    return $user;
  }

  /**
   * Prepare request options based on the defaults.
   *
   * @param  array  $options
   *   Request options to extend.
   *
   * @return array
   *   The array of merged defaults and the options provided.
   */
  private function defaults($options = array())
  {
    $defaults = array(
      'max_redirects' => 0,
      'headers' => array(
        'Accept'               => self::POST_HEADER_ACCEPT,
        'User-Agent'           => self::POST_USER_AGENT,
        'X-TiG-Application-Id' => $this->ssoAppid,
        'X-TiG-REST-API-Key'   => $this->ssoAppkey,
      ),
    );
    return array_replace_recursive($options, $defaults);
  }

  /**
   * Parse expected error messages from HTTP response.
   *
   * @param  object $response
   *   The result of drupal_http_request().
   *
   * @return  bool
   *   Whether the parsing was successful.
   */
  private function processResponseErrorMessages($response) {
    // RFC 2616 states that all unknown HTTP codes must be treated the same as the
    // base code in their class.
    // @see drupal_http_request().
    // Allow the following HTTP codes:
    // - 422 Unprocessable Entity
    $allowed_http_codes = array(400);
    if (!in_array($response->code, $allowed_http_codes)) {
      return FALSE;
    }

    if (!$response || empty($response->data)) {
      return FALSE;
    }

    // Decode HTTP response body text.
    $response_data = json_decode($response->data);
    if (!$response_data) {
      return FALSE;
    }

    if (empty($response_data->error_messages)) {
      return FALSE;
    }

    $this->error_messages = (array) $response_data->error_messages;
    return TRUE;
  }

  /**
   * Logs unexpected errors to Drupal log instance.
   *
   * @param  string $message
   *   The text of custom error message.
   * @param  string $error
   *   The text of unexpected error. Replaces `%s` in the custom error.
   *
   * @return NULL
   */
  private static function log($message, $error)
  {
    $variables = array();
    if (!empty($error)) {
      $variables['%s'] = $error;
    }
    watchdog(self::LOGGER_NAME, $message, $variables, WATCHDOG_NOTICE);
  }

  // ---------------------------------------------------------------------

}
