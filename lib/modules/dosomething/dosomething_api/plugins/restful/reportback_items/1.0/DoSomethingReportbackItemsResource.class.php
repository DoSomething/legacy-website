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

    $public_fields['file'] = array(
      'property' => 'fid',
      // 'resource' => array(
      //   'file' => 'files',
      // ),
     'resource' => array(
        'file' => array(
          'name'      => 'files',
          'full_view' => FALSE,
        ),
      ),
    );
    $public_fields['caption'] = array(
      'property' => 'caption',
    );
    $public_fields['reportback'] = array(
      'property' => 'rbid',
      'resource' => array(
        'reportback' => 'reportbacks',
      ),
    );

    return $public_fields;
  }
}
