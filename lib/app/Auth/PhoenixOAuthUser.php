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
 * @property object $user
 */
class PhoenixOAuthUser implements NorthstarUserContract {

  /**
   * PhoenixOAuthUser constructor.
   *
   * @param $user
   */
  public function __construct($uid) {
    $this->id = dosomething_user_get_northstar_id($uid);
    $this->user = user_load($uid);
    $this->role = 'user'; // Hardcoding this is acceptable in Phoenix for now.
  }

  /**
   * Get the Northstar ID for the user.
   *
   * @return string|null
   */
  public function getNorthstarIdentifier() {
    return $this->id;
  }

  /**
   * Save the Northstar ID for the user.
   *
   * @return void
   */
  public function setNorthstarIdentifier($id) {
    $this->id = $id;

    openid_connect_connect_account('northstar', $id);
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
    if (empty($this->user)) {
      return null;
    }

    $access_token = dosomething_user_get_field('field_access_token', $this->user);
    $refresh_token = dosomething_user_get_field('field_refresh_token', $this->user);
    $expires = dosomething_user_get_field('field_access_token_expiration', $this->user);
    if (empty($access_token) || empty($refresh_token) || empty($expires)) {
      return null;
    }

    return new AccessToken([
      'resource_owner_id' => $this->getNorthstarIdentifier(),
      'access_token' => $access_token,
      'refresh_token' => $refresh_token,
      'expires' => $expires,
      'role' => $this->getRole(),
    ]);
  }

  /**
   * Save the access token for the user.
   *
   * @param AccessToken $token
   * @return void
   */
  public function setOAuthToken(AccessToken $token) {
    $edit = [];

    dosomething_user_set_fields($edit, [
      'access_token' => $token->getToken(),
      'refresh_token' => $token->getRefreshToken(),
      'access_token_expiration' => $token->getExpires(),
    ]);

    user_save($this->user, $edit);
  }

  /**
   * Clear the access token for the user.
   *
   * @return void
   */
  public function clearOAuthToken() {
    $edit = [];

    dosomething_user_set_fields($edit, [
      'access_token' => null,
      'refresh_token' => null,
      'access_token_expiration' => null,
    ]);

    user_save($this->user);
  }
}
