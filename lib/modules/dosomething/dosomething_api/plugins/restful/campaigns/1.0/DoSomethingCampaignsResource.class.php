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

    $public_fields['type'] = array(
      'property' => 'field_campaign_type',
    );

    $public_fields['status'] = array(
      'property' => 'field_campaign_status',
    );

    $public_fields['call_to_action'] = array(
      'property' => 'field_call_to_action',
    );

    $public_fields['on_mobile_app'] = array(
      'property' => 'field_on_mobile_app',
    );

    // This is so wtf.
    // If I name it as 'cover_image' it doesn't work.
    // If I name it as just 'image' it works.
    $public_fields['image'] = array(
      'property' => 'field_image_campaign_cover',
       'resource' => array(
          'image' => 'assets',
        ),
    );

    $public_fields['primary_cause'] = array(
      'property' => 'field_primary_cause',
       'resource' => array(
          'cause' => 'terms',
        ),
    );

    $public_fields['cause'] = array(
      'property' => 'field_cause',
       'resource' => array(
          'cause' => 'terms',
        ),
    );

    $public_fields['primary_action_type'] = array(
      'property' => 'field_primary_action_type',
       'resource' => array(
          'action_type' => 'terms',
        ),
    );

    $public_fields['action_type'] = array(
      'property' => 'field_action_type',
       'resource' => array(
          'action_type' => 'terms',
        ),
    );

    $public_fields['cause'] = array(
      'property' => 'field_cause',
       'resource' => array(
          'cause' => 'terms',
        ),
    );

    $public_fields['issue'] = array(
      'property' => 'field_issue',
       'resource' => array(
          'issue' => 'terms',
        ),
    );
    $public_fields['tags'] = array(
      'property' => 'field_tags',
       'resource' => array(
          'tags' => 'terms',
        ),
    );

    $public_fields['call_to_action'] = array(
      'property' => 'field_call_to_action',
    );

    $public_fields['faq'] = array(
      'property' => 'field_faq',
    );
    return $public_fields;
  }
}
