<?php

/**
 * @file
 * Contains DoSomethingReportbackItemsResource.
 */
class DoSomethingReportbackItemsResource extends RestfulEntityBase {

  /**
   * Overrides RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['file'] = [
      'property' => 'fid',
      // 'resource' => array(
      //   'file' => 'files',
      // ),
     'resource' => [
        'file' => [
          'name' => 'files',
          'full_view' => FALSE,
        ],
      ],
    ];
    $public_fields['caption'] = [
      'property' => 'caption',
    ];
    $public_fields['reportback'] = [
      'property' => 'rbid',
      'resource' => [
        'reportback' => 'reportbacks',
      ],
    ];

    return $public_fields;
  }
}
