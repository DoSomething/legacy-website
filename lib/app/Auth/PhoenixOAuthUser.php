<?php

namespace Phoenix\Auth;

use DoSomething\Gateway\Contracts\NorthstarUserContract;
use League\OAuth2\Client\Token\AccessToken;

/**
 * @property string $northstar_id
 * @property string $access_token
 * @property string $access_token_expiration
 * @property string $refresh_token
 * @property string $role
 */
class PhoenixOAuthUser implements NorthstarUserContract {
  /**
   * Get the Northstar ID for the user.
   *
   * @return string|null
   */
  public function getNorthstarIdentifier() {
    return $this->northstar_id;
  }

  /**
   * Save the Northstar ID for the user.
   *
   * @return void
   */
  public function setNorthstarIdentifier($id) {
    $this->northstar_id = $id;
  }

  /**
   * Save the user's Northstar role locally.
   *
   * @return void
   */
  public function setRole($role) {
    $this->role = $role;
  }

  /**
   * Get the user's Northstar role.
   *
   * @return string
   */
  public function getRole() {
    return $this->role;
  }

  /**
   * Get the access token for the user.
   *
   * @return AccessToken|null
   */
  public function getOAuthToken() {
    return new AccessToken([
      'resource_owner_id' => $this->getNorthstarIdentifier(),
      'access_token' => $this->access_token,
      'refresh_token' => $this->refresh_token,
      'expires' => $this->access_token_expiration,
      'role' => $this->role,
    ]);
  }

  /**
   * Save the access token for the user.
   *
   * @param AccessToken $token
   * @return void
   */
  public function setOAuthToken(AccessToken $token) {
    $this->access_token = $token->getToken();
    $this->access_token_expiration = $token->getExpires();
    $this->refresh_token = $token->getRefreshToken();
    $this->role = $token->getValues()['role'];
  }

  /**
   * Clear the access token for the user.
   *
   * @return void
   */
  public function clearOAuthToken() {
    $this->access_token = null;
    $this->access_token_expiration = null;
    $this->refresh_token = null;
  }
}
