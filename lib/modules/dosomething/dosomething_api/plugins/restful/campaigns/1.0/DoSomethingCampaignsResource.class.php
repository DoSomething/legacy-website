<?php

/**
 * @file
 * Contains DoSomethingCampaignsResource.
 */
class DoSomethingCampaignsResource extends RestfulEntityBaseNode {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['call_to_action'] = array(
      'property' => 'field_call_to_action',
    );
    $public_fields['faq'] = array(
      'property' => 'field_faq',
    );
    $public_fields['tags'] = array(
      'property' => 'field_tags',
    );
    return $public_fields;
  }
}
