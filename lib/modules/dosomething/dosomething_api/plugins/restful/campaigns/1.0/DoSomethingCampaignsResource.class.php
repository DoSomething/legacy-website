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

    $public_fields['type'] = [
      'property' => 'field_campaign_type',
    ];

    $public_fields['status'] = [
      'property' => 'field_campaign_status',
    ];

    $public_fields['call_to_action'] = [
      'property' => 'field_call_to_action',
    ];

    $public_fields['cover_image'] = [
      'property' => 'field_image_campaign_cover',
      'resource' => [
        'image' => 'assets',
      ],
    ];

    $public_fields['primary_cause'] = [
      'property' => 'field_primary_cause',
      'resource' => [
        'cause' => 'terms',
      ],
    ];

    $public_fields['cause'] = [
      'property' => 'field_cause',
      'resource' => [
        'cause' => 'terms',
      ],
    ];

    $public_fields['primary_action_type'] = [
      'property' => 'field_primary_action_type',
      'resource' => [
        'action_type' => 'terms',
      ],
    ];

    $public_fields['action_type'] = [
      'property' => 'field_action_type',
      'resource' => [
        'action_type' => 'terms',
      ],
    ];

    $public_fields['cause'] = [
      'property' => 'field_cause',
      'resource' => [
        'cause' => 'terms',
      ],
    ];

    $public_fields['issue'] = [
      'property' => 'field_issue',
      'resource' => [
        'issue' => 'terms',
      ],
    ];
    $public_fields['tags'] = [
      'property' => 'field_tags',
      'resource' => [
        'tags' => 'terms',
      ],
    ];

    $public_fields['call_to_action'] = [
      'property' => 'field_call_to_action',
    ];

    $public_fields['faq'] = [
      'property' => 'field_faq',
    ];
    return $public_fields;
  }
}
