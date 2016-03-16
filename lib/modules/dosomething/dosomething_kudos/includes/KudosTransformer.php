<?php

module_load_include('php', 'dosomething_api', 'includes/Transformer');

class KudosTransformer extends Transformer {

  /**
   * Display collection of the specified resource.
   *
   * @param array $parameters Filter parameters to limit collection based on specific criteria.
   *  - fid (string|array)
   *  - count (int)
   * @return array
   */
  public function index($parameters) {
    $filters = [
      'fid' => $this->formatData($parameters['reportbackitem_ids']),
      'count' => (int) $parameters['count'],
    ];

    try {
      $kudos = Kudos::find($filters);
      $kudos = services_resource_build_index_list($kudos, 'kudos', 'id');
    }
    catch (Exception $error) {
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    $data = $this->transformCollection($kudos);
    $data = dosomething_kudos_sort($data, 'full');

    return [
      'kudos' => [
        'data' => $data,
      ]
    ];
  }

  /**
   * Display the specified resource.
   *
   * @param string $id Kudos id.
   * @return array
   */
  public function show($id) {
    try {
      $kudos = Kudos::get($id);
      $kudos = services_resource_build_index_list($kudos, 'kudos', 'id');
    }
    catch (Exception $error) {
      http_response_code('404');
      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return [
      'data' => $this->transform(array_pop($kudos)),
    ];
  }

  /**
   * @param $parameters
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
   * Transform data and build out response.
   *
   * @param object $item Single Kudos object of retrieved data.
   * @return array
   */
  protected function transform($item) {
    $data = [];

    $data += $this->transformKudos($item);

    return $data;
  }

}
