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
    $this->user = user_load($uid);
    $this->role = 'user'; // Hardcoding this is acceptable in Phoenix for now.
  }

  /**
   * Get the Northstar ID for the user.
   *
   * @return string|null
   */
  public function getNorthstarIdentifier() {
    return $this->user->field_northstar_id[LANGUAGE_NONE][0]['value'];
  }

  /**
   * Save the Northstar ID for the user.
   *
   * @return void
   */
  public function setNorthstarIdentifier($id) {
    $this->user->field_northstar_id[LANGUAGE_NONE][0]['value'];
    user_save($this->user);
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
    return new AccessToken([
      'resource_owner_id' => $this->getNorthstarIdentifier(),
      'access_token' => dosomething_user_get_field('field_access_token', $this->user),
      'refresh_token' => dosomething_user_get_field('field_refresh_token', $this->user),
      'expires' => dosomething_user_get_field('field_access_token_expiration', $this->user),
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
    $this->user->field_access_token[LANGUAGE_NONE][0]['value'] = $token->getToken();
    $this->user->field_refresh_token[LANGUAGE_NONE][0]['value'] = $token->getRefreshToken();
    $this->user->field_access_token_expiration[LANGUAGE_NONE][0]['value'] = $token->getExpires();
    user_save($this->user);
  }

  /**
   * Clear the access token for the user.
   *
   * @return void
   */
  public function clearOAuthToken() {
    unset($this->user->field_access_token);
    unset($this->user->field_refresh_token);
    unset($this->user->field_access_token_expiration);
    user_save($this->user);
  }
}
