<?php

namespace Phoenix\Auth;

use DoSomething\Northstar\Contracts\OAuthRepositoryContract;
use League\OAuth2\Client\Token\AccessToken;

class PhoenixOAuthRepository implements OAuthRepositoryContract {
  /**
   * Get the given authenticated user's access token.
   *
   * @return \League\OAuth2\Client\Token\AccessToken|null
   */
  public function getUserToken() {
    // @TODO: Not in use for now.
    return NULL;
  }

  /**
   * Get the OAuth client's token.
   *
   * @return \League\OAuth2\Client\Token\AccessToken|null
   */
  public function getClientToken() {
    $clientId = variable_get('dosomething_northstar_oauth_client_token_clientid', NULL);
    $accessToken = variable_get('dosomething_northstar_oauth_client_token_access_token', NULL);
    $expiration = variable_get('dosomething_northstar_oauth_client_token_expiration', NULL);

    if (empty($accessToken) || empty($expiration)) {
      return NULL;
    }

    return new AccessToken([
      'access_token' => $accessToken,
      'expires' => $expiration,
    ]);
  }

  /**
   * Save the access & refresh tokens for an authorized user.
   *
   * @param  string $userId
   * @param  string $accessToken
   * @param  string $refreshToken
   * @param  integer $expiration
   * @param  string $role
   * @return void
   */
  public function persistUserToken($userId, $accessToken, $refreshToken, $expiration, $role) {
    // @TODO: Not in use for now.
    return NULL;
  }

  /**
   * Save the access token for an authorized client.
   *
   * @param  string $clientId
   * @param  string $accessToken
   * @param  integer $expiration
   * @param  string $role
   * @return void
   */
  public function persistClientToken($clientId, $accessToken, $expiration, $role) {
    variable_set('dosomething_northstar_oauth_client_token_clientid', $clientId);
    variable_set('dosomething_northstar_oauth_client_token_access_token', $accessToken);
    variable_set('dosomething_northstar_oauth_client_token_expiration', $expiration);
  }

  /**
   * If a refresh token is invalid, request the user's credentials
   * by redirecting to the login screen.
   */
  public function requestUserCredentials() {
    // @TODO: Not in use for now.
    return NULL;
  }

  /**
   * Remove the user's token information when they log out.
   */
  public function removeUserToken($userId) {
    // @TODO: Not in use for now.
    return NULL;
  }
}
