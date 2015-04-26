<?php

/**
 * @file
 * Contains DoSomethingAssetsResource.
 */
class DoSomethingAssetsResource extends RestfulEntityBaseNode {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
    $public_fields['landscape'] = array(
      'property' => 'field_image_landscape',
      'process_callbacks' => array(
        array($this, 'imageProcess'),
      ),
      // This will add 3 image variants in the output.
      // No idea what we need here
      'image_styles' => array('100x100', '550x300', '720x310'),
    );
    $public_fields['square'] = array(
      'property' => 'field_image_square',
      'process_callbacks' => array(
        array($this, 'imageProcess'),
      ),
      // This will add 3 image variants in the output.
      'image_styles' => array('100x100', '300x300', '768x768'),
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
      'id' => $value['fid'],
      // @todo This should direct to the new files resource.
      'self' => file_create_url($value['uri']),
      // 'filemime' => $value['filemime'],
      // 'filesize' => $value['filesize'],
      // 'width' => $value['width'],
      // 'height' => $value['height'],
      'styles' => $value['image_styles'],
    );
  }
}
