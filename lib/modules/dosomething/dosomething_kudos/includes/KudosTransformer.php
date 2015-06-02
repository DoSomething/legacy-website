<?php

class KudosTransformer extends Transformer {

  /**
   * @param $parameters
   * @return array
   */
  public function index($parameters) {
    $filters = [
      'reportbackitem_id' => $this->formatData($parameters['reportbackitem_ids']),
      'count' => (int) $parameters['count'],
    ];

    $results = dosomething_kudos_get_kudos_query($filters, $filters['count']);

    if (!$results) {
      return [
        'error' => [
          'message' => 'No kudos for you. Move along.',
        ]
      ];
    }

    $entity = entity_load('kudos', ['1']);

    return $entity;

//    $kudos = [];
//    foreach ($results as $item) {
//      $kudos[] = Kudos::get($item);
//    }
//
//    return [
//      'data' => $kudos,
//    ];
  }


  public function show($id) {
    return 'class show item';
  }


  public function create() {
    return 'class create item';
  }


  public function delete() {
    return 'class delete item';
  }


  protected function transform($object) {
    return 'autobots transform!';
  }

}
