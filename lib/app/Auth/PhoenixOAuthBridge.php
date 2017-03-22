<?php

namespace Phoenix\Auth;

use DoSomething\Gateway\Contracts\NorthstarUserContract;
use DoSomething\Gateway\Contracts\OAuthBridgeContract;
use League\OAuth2\Client\Token\AccessToken;

class PhoenixOAuthBridge implements OAuthBridgeContract {
  /**
   * Get the ID of the logged-in-user.
   *
   * @return NorthstarUserContract|null
   */
  public function getCurrentUser() {
    $user = new PhoenixOAuthUser();
    // Grab Northstar ID and assign it here.
    return $user;
  }

  /**
   * Get a user by their Northstar Id.
   *
   * @return NorthstarUserContract|null
   */
  public function getUser($id) {
    //
  }

  /**
   * Find or create a local user with the given Northstar ID.
   *
   * @param $id
   * @return NorthstarUserContract
   */
  public function getOrCreateUser($id) {
    //
  }

  /**
   * Get the OAuth client's token.
   *
   * @return \League\OAuth2\Client\Token\AccessToken|null
   */
  public function getClientToken() {
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
   * @param \League\OAuth2\Client\Token\AccessToken $token
   * @internal param $userId - Northstar user ID
   */
  public function persistUserToken(AccessToken $token) {
    //
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
    variable_set('dosomething_northstar_oauth_client_token_access_token', $accessToken);
    variable_set('dosomething_northstar_oauth_client_token_expiration', $expiration);
  }

  /**
   * If a refresh token is invalid, request the user's credentials
   * by redirecting to the login screen.
   *
   * @return void
   */
  public function requestUserCredentials() {
    //
  }

  /**
   * Save the OAuth state token to the session.
   *
   * @param  $state
   * @return void
   */
  public function saveStateToken($state) {
    //
  }

  /**
   * Get a stored OAuth state token from the session.
   *
   * @return string
   */
  public function getStateToken() {
    //
  }

  /**
   * Create a session for the given user & access token.
   *
   * @param  NorthstarUserContract $user
   * @param  AccessToken $token
   * @return mixed
   */
  public function login(NorthstarUserContract $user, AccessToken $token) {
    //
  }

  /**
   * Destroy the current user session.
   *
   * @return mixed
   */
  public function logout() {
    //
  }

  /**
   * Convert the given relative path to an absolute URL
   * with the framework's URL generator.
   *
   * @param  string $url
   * @return string
   */
  public function prepareUrl($url) {
    //
  }
}
