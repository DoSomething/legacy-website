<?php

/**
 * @file
 * Contains DoSomethingCampaignsResource.
 */
class DoSomethingReportbacksResource extends RestfulEntityBase {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['created'] = [
      'property' => 'created',
    ];

    $public_fields['updated'] = [
      'property' => 'updated',
    ];

    $public_fields['quantity'] = [
      'property' => 'quantity',
    ];

    $public_fields['why_participated'] = [
      'property' => 'why_participated',
    ];

    $public_fields['campaign'] = [
      'property' => 'nid',
       'resource' => [
          'campaign' => 'campaigns',
        ],
    ];

    $public_fields['user'] = [
      'property' => 'uid',
       'resource' => [
          'user' => 'users',
        ],
    ];

    return $public_fields;
  }
}
