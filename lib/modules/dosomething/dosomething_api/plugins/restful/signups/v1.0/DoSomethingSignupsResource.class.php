<?php

/**
 * @file
 * Contains DoSomethingSignupsResource.
 */
class DoSomethingSignupsResource extends RestfulEntityBase {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['created'] = array(
      'property' => 'timestamp',
    );

    // $public_fields['campaign'] = array(
    //   'property' => 'nid',
    //    'resource' => array(
    //       'campaign' => 'campaigns',
    //     ),
    // );

    // $public_fields['user'] = array(
    //   'property' => 'uid',
    //    'resource' => array(
    //       'user' => 'users',
    //     ),
    // );

    // $public_fields['source'] = array(
    //   'property' => 'source',
    // );

    return $public_fields;
  }
}
