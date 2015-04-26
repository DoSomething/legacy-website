<?php

/**
 * @file
 * Contains DoSomethingUsersResource.
 */

class DoSomethingUsersResource extends RestfulEntityBaseUser {

  /**
   * Overrides \RestfulEntityBaseUser::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
    // unset($public_fields['self']);
    $public_fields['first_name'] = array(
      'property' => 'field_first_name',
    );
    // picture doesn't work without some tweaks
    // https://github.com/RESTful-Drupal/restful/issues/353#issuecomment-80144333
    return $public_fields;
  }
}
