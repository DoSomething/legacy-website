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
    $public_fields['file'] = array(
      'property'          => 'fid',
      'process_callbacks' => array(
        array($this, 'fileProcess'),
      ),
      // // This will add 3 image variants in the output.
      'image_styles' => array('100x100', '300x300'),
    );
    return $public_fields;
  }
  /**
   * Process callback, Remove Drupal specific items from the image array.
   *
   * @param array $value
   *   The image array.
   *
   * @return array
   *   A cleaned image array.
   */
  protected function imageProcess($value) {
    if (static::isArrayNumeric($value)) {
      $output = array();
      foreach ($value as $item) {
        $output[] = $this->imageProcess($item);
      }
      return $output;
    }
    return array(
      'id'       => $value['fid'],
      'self'     => file_create_url($value['uri']),
      'filemime' => $value['filemime'],
      'filesize' => $value['filesize'],
      'width'    => $value['width'],
      'height'   => $value['height'],
      'styles'   => $value['image_styles'],
    );
  }

  protected function fileProcess($value) {
    // This feels wrong because you'd expect the file entity to be loaded already.
    $value = (array) file_load($value);
    return array(
      'id'       => $value['fid'],
      'self'     => file_create_url($value['uri']),
      'filemime' => $value['filemime'],
      'filesize' => $value['filesize'],
      'width'    => $value['width'],
      'height'   => $value['height'],
      'styles'   => $value['image_styles'],
    );
  }

}
