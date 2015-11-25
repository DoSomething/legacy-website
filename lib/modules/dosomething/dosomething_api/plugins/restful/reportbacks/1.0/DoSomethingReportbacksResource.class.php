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

    $public_fields['created'] = array(
      'property' => 'created',
    );

    $public_fields['updated'] = array(
      'property' => 'updated',
    );

    $public_fields['quantity'] = array(
      'property' => 'quantity',
    );

    $public_fields['why_participated'] = array(
      'property' => 'why_participated',
    );

    $public_fields['campaign'] = array(
      'property'  => 'nid',
       'resource' => array(
          'campaign' => 'campaigns',
        ),
    );

    $public_fields['user'] = array(
      'property'  => 'uid',
       'resource' => array(
          'user' => 'users',
        ),
    );

    return $public_fields;
  }
}
