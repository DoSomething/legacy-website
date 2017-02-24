<?php

/**
 * @file
 * Northstar OpenID Connect client.
 */

class OpenIDConnectClientNorthstar extends OpenIDConnectClientBase {

  /**
   * Overrides OpenIDConnectClientBase::settingsForm().
   */
  public function settingsForm() {
    $form = parent::settingsForm();

    // @TODO: Store public key here.

    return $form;
  }

  /**
   * Overrides OpenIDConnectClientBase::getEndpoints().
   */
  public function getEndpoints() {
    $url = NORTHSTAR_URL;

    return [
      'authorization' => $url . '/authorize',
      'token' => $url . '/v2/auth/token',
      'userinfo' => $url . '/v2/auth/info',
    ];
  }

  /**
   * Creates a state token and stores it in the session for later validation.
   *
   * @return string
   *   A state token that later can be validated to prevent request forgery.
   */
  public function createStateToken() {
    // If we already have a state token, don't overwrite it.
    if (empty($_SESSION['openid_connect_state'])) {
      $_SESSION['openid_connect_state'] = openid_connect_create_state_token();
    }

    return $_SESSION['openid_connect_state'];
  }

  /**
   * Get the URL for the authorization page.
   *
   * @param string $scope
   * @return string
   */
  public function getAuthorizeUrl($scope = 'openid email')
  {
    $redirect_uri = OPENID_CONNECT_REDIRECT_PATH_BASE . '/' . $this->name;
    $url_options = [
      'query' => [
        'response_type' => 'code',
        'client_id' => $this->getSetting('client_id'),
        'redirect_uri' => url($redirect_uri, ['absolute' => TRUE]),
        'referrer_uri' => $_SERVER['HTTP_REFERER'],
        'scope' => $scope,
        'state' => $this->createStateToken(),
      ],
    ];
    $endpoints = $this->getEndpoints();

    return url($endpoints['authorization'], $url_options);
  }

  /**
   * Redirect to the authorization page.
   * Overrides OpenIDConnectClientBase::authorize().
   *
   * @param string $scope
   */
  public function authorize($scope = 'openid email') {
    $authorize_url = $this->getAuthorizeUrl($scope);

    // Clear $_GET['destination'] because we need to override it.
    unset($_GET['destination']);

    drupal_goto($authorize_url);
  }

  /**
   * Overrides OpenIDConnectClientBase::retrieveIDToken().
   */
  public function retrieveTokens($authorization_code) {
    $redirect_uri = OPENID_CONNECT_REDIRECT_PATH_BASE . '/' . $this->name;

    $post_data = [
      'grant_type' => 'authorization_code',
      'client_id' => $this->getSetting('client_id'),
      'client_secret' => $this->getSetting('client_secret'),
      'redirect_uri' => url($redirect_uri, ['absolute' => TRUE]),
      'code' => $authorization_code,
    ];

    $request_options = [
      'method' => 'POST',
      'data' => drupal_http_build_query($post_data),
      'timeout' => 15,
      'headers' => ['Content-Type' => 'application/x-www-form-urlencoded'],
    ];

    $endpoints = $this->getEndpoints();
    $response = drupal_http_request($endpoints['token'], $request_options);

    if (! empty($response->error) || $response->code != 200) {
      openid_connect_log_request_error(__FUNCTION__, $this->name, $response);
      return FALSE;
    }

    $response_data = drupal_json_decode($response->data);

    return [
      'id_token' => $response_data['access_token'], // id_token
      'access_token' => $response_data['access_token'],
      'refresh_token' => $response_data['refresh_token'],
      'expire' => REQUEST_TIME + $response_data['expires_in'],
    ];
  }

  /**
   * Overrides OpenIDConnectClientBase::decodeIdToken().
   */
  public function decodeIdToken($id_token) {
    // @TODO: Verify JWT using public key.
    return parent::decodeIdToken($id_token);
  }

  /**
   * Overrides OpenIDConnectClientBase::retrieveUserInfo().
   */
  public function retrieveUserInfo($access_token) {
    $base = parent::retrieveUserInfo($access_token);

    // Parse birthdate to timestamp, if provided.
    if (! empty($base['data']['birthdate'])) {
      $base['data']['birthdate'] = strtotime($base['data']['birthdate']);
    }

    if (! $base) {
      return null;
    }

    $userinfo = $base['data'];

    // @HACK: Ensure we have a valid local Drupal account.
    // The `openid_connect` module won't merge a Northstar user to an existing local
    // user account, so we need to make sure that's done before continuing to auth.
    if (! empty($userinfo['id'])) {
      $id = $userinfo['id'];
      $account = openid_connect_user_load_by_sub($id, $this->getName());

      // If the account doesn't exist but email or mobile does, link the existing account!
      if (! $account && $existingEmail = user_load_by_mail($userinfo['email'])) {
        dosomething_northstar_save_id_field($existingEmail->uid, $base);
      } else if (! $account && $existingMobile = dosomething_user_get_user_by_mobile($userinfo['phone_number'])) {
        dosomething_northstar_save_id_field($existingMobile->uid, $base);
      }
    }

    return $userinfo;
  }
}
