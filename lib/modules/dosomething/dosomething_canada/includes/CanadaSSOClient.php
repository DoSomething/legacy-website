<?php
/**
 * @file SSO client for DS Canada.
 */

/**
 * Class CanadaSSOClient
 * @package Dosomething
 */
class CanadaSSOClient {

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
   * @var array Authenticated user, if any.
   */
  private $user;

  /**
   * SSO API version, for the base URL.
   *
   * @var string
   */
  private $ssoVersion = '1';

  /**
   * Base URI for authentication.
   *
   * @var string
   */
  private $loginPath = '/login';

  /**
   * Base URI for non-login user methods.
   *
   * @var string
   */
  private $userPath = '/users';


  /**
   * Constructor: requires URL, app ID, and app key for the SSO service.
   *
   * @param $sso_url
   * @param $sso_appid
   * @param $sso_appkey
   */
  public function __construct($sso_url, $sso_appid, $sso_appkey)
  {
    $this->ssoUrl = $sso_url;
    $this->ssoAppid = $sso_appid;
    $this->ssoAppkey = $sso_appkey;
  }

  /**
   * Submit to login endpoint. If successful, loads user data
   * into CanadaSSOClient::user.
   *
   * @param $email
   * @param $password
   * @return bool
   */
  public function authenticate($email, $password)
  {

    if ($this->get($this->loginPath, array(
      'email' => $email,
      'password' => $password,
    )))
    {
      return TRUE;
    }

    return FALSE;
  }

  /**
   * If there was a successful authentication, this array will contain all
   * the remote user data.
   *
   * @return array
   * @throws Exception
   */
  public function getRemoteUser()
  {
    return $this->user;
  }

  /**
   * Use a local, existing user to register a user via the API.
   *
   * @param string $email
   * @param string $password
   * @param stdClass $user
   * @return boolean
   */
  public function propagateLocalUser($email, $password, $user)
  {
    $params = get_object_vars($user);

    return $this->post($this->userPath, $params);
  }

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
  private function execute($uri, $method='GET', $data)
  {
    $headers = array(
      'X-TiG-Application-Id: ' . $this->ssoAppid,
      'X-TiG-REST-API-Key: '. $this->ssoAppkey,
    );

    $url = $this->getBaseURL() . $uri;
    $query = http_build_query($data);

    if ('GET' == $method)
    {
      $url .= '?' . $query;
    }

    $curlOpts = array(
      CURLOPT_RETURNTRANSFER => true,
      CURLOPT_HEADER => true,
      CURLOPT_HTTPHEADER => $headers,
      CURLOPT_VERBOSE => true,
    );

    if ('POST' == $method)
    {
      $curlOpts[CURLOPT_POST] = true;
      $curlOpts[CURLOPT_POSTFIELDS] = $query;
    }

    $ch = curl_init($url);
    curl_setopt_array($ch, $curlOpts);

    $response = curl_exec($ch);

    $header_size = curl_getinfo($ch, CURLINFO_HEADER_SIZE);
    // $header = trim(substr($response, 0, $header_size));
    $body = trim(substr($response, $header_size));

    $responseObj = (empty($body)) ? null : json_decode($body);

    if (is_object($responseObj))
    {
      if (!empty($responseObj->error))
      {
        throw new Exception(sprintf("Execution error for %s on %s: %s", $method, $url, $responseObj->error));
      }

      $this->user = $responseObj;
      return true;
    }

    throw new Exception("Can't understand response: %s", $response);
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
}
