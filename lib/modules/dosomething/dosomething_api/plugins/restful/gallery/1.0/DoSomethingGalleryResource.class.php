<?php

/**
 * @file
 * Contains DoSomethingGalleryResource.
 */

class DoSomethingGalleryResource extends \RestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $public_fields['id'] = [
      'property' => 'fid',
    ];
    // @todo: Look into files as resources to get URLs.
    // $public_fields['fid'] = array(
    //   'property' => 'fid',
    // );
    $public_fields['status'] = [
      'property' => 'status',
    ];
    // The campaign id is taken from a join query, as it exists on reportback table.
    $public_fields['campaign'] = [
      'property' => 'campaign',
      'column_for_query' => 'dosomething_reportback.nid',
    ];

    return $public_fields;
  }

  /**
   * Overrides \RestfulDataProviderDbQuery::getQuery().
   *
   * Join with the terms table.
   */
  protected function getQuery() {
    $query = parent::getQuery();

    $query->innerJoin('dosomething_reportback', 'dosomething_reportback', 'dosomething_reportback_file.rbid = dosomething_reportback.rbid');

    // Explicitly set the alias of the column, so it will match the public field
    // name.
    $query->addField('dosomething_reportback', 'nid', 'campaign');

    return $query;
  }

}
