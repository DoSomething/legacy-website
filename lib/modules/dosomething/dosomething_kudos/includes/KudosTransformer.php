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

//    $entity = entity_load('kudos', ['1']);
//    return $entity;
//    $entity = Kudos::get('1');
//    return $entity;

    $kudos = [];
    foreach ($results as $id) {
      $kudos[] = Kudos::get($id);
    }

    return [
      'data' => $this->transformCollection($kudos),
    ];
  }


  public function show($id) {
    try {
      $kudos = Kudos::get($id);
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return [
      'data' => $this->transform($kudos),
    ];
  }


  /**
   * @param $parameters
   *
   * @return array
   */
  public function create($parameters) {
    // Retain record of successfully created or failed records to report back to client.
    $records = [
      'created' => 0,
      'failed' => 0,
    ];

    $values = [
      'fid' => $parameters['fid'],
      'uid' => $parameters['uid'],
    ];

    foreach($parameters['tids'] as $id) {
      $values['tid'] = $id;

      $record = (new KudosController)->create($values);

      if ($record) {
        $records['created'] += 1;
      } else {
        $records['failed'] += 1;
      }
    }

    return $records;
  }


  /**
   * @param object $kudos
   *
   * @return array
   */
  protected function transform($kudos) {
    $data = [];

    $data['reportback_item'] = $kudos->reportback_item;

    $data['user'] = $this->transformUser($kudos->user);

    return $data;
  }

}
