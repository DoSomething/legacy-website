<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermTags.
 */

class DoSomethingTermsResource extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides \RestfulEntityBaseTaxonomyTerm::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['vocabulary_id'] = array(
      'property' => 'vocabulary',
    );

    return $public_fields;
  }

}
