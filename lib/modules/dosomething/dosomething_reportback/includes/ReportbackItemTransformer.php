<?php

class ReportbackItemTransformer extends ReportbackTransformer {

  private $accessibleStatuses = ['promoted', 'approved'];

  /**
   * @param  array $parameters Any parameters obtained from query string.
   * @return array
   */
  public function index($parameters) {
    $filters = $this->setFilters($parameters);

    try {
      $reportbackItems = ReportbackItem::find($filters);
      $reportbackItems = services_resource_build_index_list($reportbackItems, 'reportback-items', 'id');
      $total = $this->getTotalCount($filters);
    }
    catch (Exception $error) {
      // @TODO: Potentially log error to watchdog.
      return [
        'data' => [],
      ];
    }

    return [
      'meta' => [
        'pagination' => $this->paginate($total, $filters, 'reportback-items'),
      ],
      'data' => $this->transformCollection($reportbackItems),
    ];
  }

  /**
   * Display the specified resource.
   *
   * @param  string $id Resource id.
   * @return array
   */
  public function show($id) {
    try {
      $reportbackItem = ReportbackItem::get($id);
      $reportbackItem = $this->removeUnauthorizedResults($reportbackItem);
      $reportbackItem = services_resource_build_index_list($reportbackItem, 'reportback-items', 'id');
    }
    catch (Exception $error) {
      if ($error->getMessage() === 'Access denied.') {
        http_response_code('403');
      }
      else {
        http_response_code('404');
      }

      return [
        'error' => [
          'message' => $error->getMessage(),
        ],
      ];
    }

    return [
      'data' => $this->transform(array_pop($reportbackItem)),
    ];
  }

  /**
   * Transform data and build out response.
   *
   * @param  object $item Single object of retrieved data.
   * @return array
   */
  protected function transform($item) {
    $data = [];

    $data += $this->transformReportbackItem($item);

    $data['reportback'] = $this->transformReportback((object) $item->reportback);

    $data['campaign'] = $this->transformCampaign((object) $item->campaign);

    $data['user'] = $this->transformUser((object) $item->user);

    return $data;
  }

  /**
   * Set the filters based on request URL parameters.
   *
   * @param  array $parameters
   * @return array
   */
  private function setFilters($parameters) {
    $filters = [
      'nid' => dosomething_helpers_format_data($parameters['campaigns']),
      'status' => $this->removeUnauthorizedStatuses(dosomething_helpers_format_data($parameters['status'])),
      'exclude' => dosomething_helpers_format_data($parameters['exclude']),
      'count' => (int) $parameters['count'] ?: 25,
      'page' => (int) $parameters['page'],
      'random' => dosomething_helpers_convert_string_to_boolean($parameters['random']),
      'load_user' => dosomething_helpers_convert_string_to_boolean($parameters['load_user']),
    ];

    $filters['offset'] = $this->setOffset($filters['page'], $filters['count']);

    if ($filters['exclude'] && !is_array($filters['exclude'])) {
      $filters['exclude'] = [$filters['exclude']];
    }

    // Unset False boolean values that affect the query builder.
    if (!$filters['random']) {
      unset($filters['random']);
    }

    return $filters;
  }

  /**
   * Remove requested Reportback Item statuses based on user permission.
   * @param  mixed $statuses
   * @return mixed
   */
  private function removeUnauthorizedStatuses($statuses) {
    if (user_access('view any reportback')) {
      return $statuses;
    }

    if (!is_array($statuses)) {
      $statuses = [$statuses];
    }

    $statuses = array_intersect($this->accessibleStatuses, $statuses);

    if (!$statuses) {
      return FALSE;
    }

    if (count($statuses) === 1) {
      return array_shift($statuses);
    }

    return $statuses;
  }

  /**
   * Remove Reportback Items with unauthorized statuses based on user permission.
   *
   * @param  array $data
   * @return mixed
   * @throws Exception
   */
  private function removeUnauthorizedResults($data) {
    if (!$data) {
      throw new Exception('No reportback items data found.');
    }

    if (user_access('view any reportback')) {
      return $data;
    }

    foreach ($data as $index => $item) {
      if (!in_array($item->status, $this->accessibleStatuses)) {
        unset($data[$index]);
      }
    }

    if(!$data) {
      throw new Exception('Access denied.');
    }
  }
}