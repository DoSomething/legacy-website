<?php

/**
 * @file
 * Contains \DoSomethingFilesResource.
 */

class DoSomethingFilesResource extends RestfulEntityBase {
  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['created'] = array(
      'property' => 'timestamp',
    );
    // $public_fields['uri'] = array(
    //   'property' => 'uri',
    //   'process_callbacks' => array(
    //     array(array($this, 'getImageUris'), array(array('thumbnail', 'medium', 'large'))),
    //     array($this, 'imageProcess'),
    //   ),
    //   'image_styles' => array('thumbnail', 'medium', 'large'),
    // );
    return $public_fields;
  }
}
