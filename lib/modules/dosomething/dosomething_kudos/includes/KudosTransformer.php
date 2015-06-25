  <?php

class KudosTransformer extends Transformer {

  /**
   * @param $parameters
   *
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
          'message' => 'No kudos results found.',
        ]
      ];
    }

    $kudos = [];
    foreach ($results as $id) {
      $kudos[] = Kudos::get($id);
    }

//    die(print_r($kudos));

    return [
      'data' => $this->transformCollection($kudos),
    ];
  }


  /**
   * @param $id
   *
   * @return array
   */
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
   * @param $id
   *
   * @return array
   */
  public function delete($id) {
    try {
      $record = (new KudosController)->delete([$id]);
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => 'There was an error deleting the specified kudos record.',
        ],
      ];
    }

    if ($record) {
      return [
        'success' => [
          'message' => 'Kudos record successfully deleted.',
        ]
      ];
    }

    return [
      'error' => [
        'message' => 'The specified kudos record id is not valid.',
      ],
    ];
  }


  /**
   * @param object $kudos
   *
   * @return array
   */
  protected function transform($kudos) {
    return $kudos;
  }

}
