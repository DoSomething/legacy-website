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
    // @TODO: Build these from Northstar module settings.
    $url = 'http://northstar.dev:8000';

    return [
      'authorization' => $url . '/authorize',
      'token' => $url . '/v2/auth/token',
      'userinfo' => $url . '/v1/profile',
    ];
  }

  /**
   * Implements OpenIDConnectClientInterface::decodeIdToken().
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
    if ($base) {
      return $base['data'];
    }

    return null;
  }
}
