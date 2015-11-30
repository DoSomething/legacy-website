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

    $public_fields['created'] = [
      'property' => 'timestamp',
    ];

    $public_fields['campaign'] = [
      'property' => 'nid',
      'resource' => [
        'campaign' => [
          'name' => 'campaigns',
          'full_view' => FALSE,
        ],
      ],
    ];

    $public_fields['user'] = [
      'property' => 'uid',
      'resource' => [
        'user' => [
          'name' => 'users',
          'full_view' => TRUE,
        ],
      ],
    ];

    $public_fields['source'] = [
      'property' => 'source',
    ];

    return $public_fields;
  }
}
