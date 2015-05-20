<?php

abstract class Transformer {

  public function __construct() {
    // Load Services module to use its index_query functions in subclass methods.
    module_load_include('inc', 'services', 'services.module');
  }


  /**
   * Format a string of comma separated data items into an array, or
   * if a single item, return it without formatting.
   *
   * @param string $data Single or multiple comma separated data items.
   *
   * @return string or array
   */
  protected function formatData($data) {
    $array = explode(',', $data);

    if (count($array) > 1) {
      return $array;
    }

    return $data;
  }


  /**
   * Get the URI for the next page in the collection of data.
   *
   * @param array $data
   *   An associative array of pagination parameters:
   *   - total: (int) Complete total number of available data items found.
   *   - per_page: (int) Total number of data items to show per page.
   *   - current_page: (int) Current page number.
   *   - total_pages: (int) Total number of pages available.
   * @param array $parameters
   * @param string $endpoint Endpoint for building URI.
   *
   * @return null|string
   */
  protected function getNextPageUri($data, $parameters, $endpoint) {
    $uri = $this->getPathParameters($parameters, $endpoint);

    $next = $data['current_page'] + 1;

    if ($next <= $data['total_pages']) {
      return $uri . '&page=' . $next;
    }
    else {
      return NULL;
    }
  }


  /**
   * Get the URI for the previous page in the collection of data.
   *
   * @param array $data
   *   An associative array of pagination parameters:
   *   - total: (int) Complete total number of available data items found.
   *   - per_page: (int) Total number of data items to show per page.
   *   - current_page: (int) Current page number.
   *   - total_pages: (int) Total number of pages available.
   * @param array $parameters An associative array of current location parameters.
   * @param string $endpoint Endpoint for building URI.
   *
   * @return null|string
   */
  protected function getPrevPageUri($data, $parameters, $endpoint) {
    $uri = $this->getPathParameters($parameters, $endpoint);

    $prev = $data['current_page'] - 1;

    if ($prev > 0) {
      return $uri . '&page=' . $prev;
    }
    else {
      return NULL;
    }
  }


  /**
   * Extract the path parameters passed and recreate the query string.
   *
   * @param array $parameters
   *   An associative array of query parameters and values for building URI:
   *   - nid: (array) Campaign ids.
   *   - status: (array) Reportback statuses to retrieve.
   *   - count: (int) Number of items to show per page.
   *   - page: (int) Current page number.
   *   - offset: (int) Number of items displayed from prior pages.
   *   - random: (boolean) Whether to retrieve a random assortment of data items.
   * @param string $endpoint Endpoint for building URI.
   *
   * @return string
   */
  protected function getPathParameters($parameters, $endpoint) {
    $path = services_resource_uri(array($endpoint));
    $path .= '.json?';

    if (isset($parameters['nid'])) {
      $path .= '&campaigns=' . implode(',', (array) $parameters['nid']);
    }

    if (isset($parameters['status'])) {
      $path .= '&status=' . implode(',', (array) $parameters['status']);
    }

    if (isset($parameters['count'])) {
      $path .= '&count=' . implode(',', (array) $parameters['count']);
    }

    return $path;
  }


  /**
   * Retrieve Reportback Items by the specified id(s).
   *
   * @param string $ids Comma separated list of Reportback Item ids.
   *
   * @return array
   */
  protected function getReportbackItems($ids) {
    $filters = array(
      'fid' => $this->formatData($ids),
    );

    // Obtaining all Reportback items.
    $query = dosomething_reportback_get_reportback_files_query_result($filters, 'all');

    return services_resource_build_index_list($query, 'reportback-items', 'fid');
  }


  /**
   * Get metadata for pagination of response data.
   *
   * @param int $total Complete total number of items found.
   * @param array $parameters
   *   An associative array of query parameters and values:
   *   - nid: (array) Campaign ids.
   *   - status: (array) Reportback statuses to retrieve.
   *   - count: (int) Number of items to show per page.
   *   - page: (int) Current page number.
   *   - offset: (int) Number of items displayed from prior pages.
   *   - random: (boolean) Whether to retrieve a random assortment of data items.
   * @param string $endpoint
   *
   * @return array
   */
  protected function paginate($total, $parameters, $endpoint) {
    $data = array();

    $data['total'] = $total;
    $data['per_page'] = $parameters['count'];
    $data['current_page'] = (isset($parameters['page']) && $parameters['page'] > 0) ? (int) $parameters['page'] : 1;
    $data['total_pages'] = ceil($data['total'] / $data['per_page']);

    $prevUri = $this->getPrevPageUri($data, $parameters, $endpoint);
    $nextUri = $this->getNextPageUri($data, $parameters, $endpoint);

    $data['prev_uri'] = $prevUri;
    $data['next_uri'] = $nextUri;

    return $data;
  }


  /**
   * Get the offset for requests based on specified page number and count of items.
   *
   * @param int $page Current page number.
   * @param int $count Number of items per page.
   *
   * @return int
   */
  protected function setOffset($page, $count) {
    if ($page > 0 ) {
      $page -= 1;
    }

    return $page * $count;
  }


  /**
   * Transform data and prepare for API response.
   *
   * @param object $object Single object of retrieved data.
   */
  abstract protected function transform($object);


  /**
   * For collection of data to transform, run each item in collection
   * through a specified method.
   *
   * @param array $items Collection of item objects retrieved data.
   * @param string $method Name of method to use on each array item.
   *
   * @return array
   */
  protected function transformCollection($items, $method = 'transform') {
    return array_map(array($this, $method), $items);
  }


  /**
   * Transform Campaign data and prepare for API response.
   *
   * @param object $data
   *   An object containing properties of Campaign data:
   *   - nid: (string) Campaign id.
   *   - title: (string) Campaign title.
   *
   * @return array
   */
  protected function transformCampaign($data) {
    $output = array(
      'id' => $data->nid,
      'title' => $data->title,
    );

    if ($data instanceof Campaign) {
      $output['tagline'] = $data->tagline;
      $output['created_at'] = $data->created;
      $output['updated_at'] = $data->updated;
      $output['status'] = $data->status;
      $output['active_hours'] = (float) $data->active_hours;

      if ($data->cover_image) {
        $output['cover_image']['default']['uri'] = $data->cover_image['type'];
        $output['cover_image']['default']['type'] = $data->cover_image['type'];
        $output['cover_image']['default']['is_dark'] = $data->cover_image['is_dark'];
      }

      if ($data->cover_image_alt) {
        $output['cover_image']['alternate']['uri'] = $data->cover_image_alt['type'];
        $output['cover_image']['alternate']['type'] = $data->cover_image_alt['type'];
        $output['cover_image']['alternate']['is_dark'] = $data->cover_image_alt['is_dark'];
      }

      $output['facts']['problem'] = $data->fact_problem['fact'];
      $output['facts']['solution'] = $data->fact_solution['fact'];
      $output['facts']['sources'] = $data->fact_sources;

      if ($data->solution['copy']) {
        $output['solution']['copy'] = $data->solution['copy'];
      }

      if ($data->solution['support_copy']) {
        $output['solution']['support_copy'] = $data->solution['support_copy'];
      }

      if ($data->primary_cause) {
        $output['causes']['primary']['id'] = $data->primary_cause['tid'];
        $output['causes']['primary']['name'] = $data->primary_cause['name'];
      }

      if ($data->secondary_causes) {
        foreach($data->secondary_causes as $index => $cause) {
          $output['causes']['secondary'][$index]['id'] = $cause['tid'];
          $output['causes']['secondary'][$index]['name'] = $cause['name'];
        }
      }

      if ($data->primary_action_type) {
        $output['action_types']['primary']['id'] = $data->primary_action_type['tid'];
        $output['action_types']['primary']['name'] = $data->primary_action_type['name'];
      }

      if ($data->secondary_action_types) {
        foreach($data->secondary_action_types as $index => $action_type) {
          $output['action_types']['secondary'][$index]['id'] = $action_type['tid'];
          $output['action_types']['secondary'][$index]['name'] = $action_type['name'];
        }
      }

      $output['issue']['id'] = $data->issue['tid'];
      $output['issue']['name'] = $data->issue['name'];

      foreach($data->tags as $index => $tag) {
        $output['tags'][$index]['id'] = $tag['tid'];
        $output['tags'][$index]['name'] = $tag['name'];
      }

    }

    return $output;
  }



  protected function transformMedia() {

  }


  /**
   * Transform Reportback data and prepare for API response.
   *
   * @param object $data
   *   An object containing properties of Reportback data:
   *   - rbid: (string) The Reportback id.
   *   - created: (string) Date Reportback was created.
   *   - updated: (string) Date Reportback was updated.
   *   - quantity: (int) Quantity declared for Reportback.
   *   - uid: (string) User id.
   *   - why_participated: (string) Reason for participating.
   *   - flagged: (int) Status whether Reportback has been flagged.
   *   - nid: (string) Campaign id.
   *   - title: (string) Campaign title.
   *   - items: (string) Comma separated list of Reportback Item ids for specified Reportback.
   *   - uri: (string) API URI for Reportback data.
   *
   * @return array
   */
  protected function transformReportback($data) {
    $output = array(
      'id' => $data->rbid,
      'created_at' => $data->created,
      'updated_at' => $data->updated,
      'quantity' => (int) $data->quantity,
    );

    if (isset($data->why_participated)) {
      $output['why_participated'] = $data->why_participated;
    }

    if (isset($data->flagged)) {
      $output['flagged'] = (int) $data->flagged ? TRUE : FALSE;
    }

    // Reportback Child Item data
    if ($data->items) {
      $items = $this->getReportbackItems($data->items);

      $output['items'] = array(
        'total' => count($items),
        'data' => $this->transformCollection($items, 'transformReportbackItem'),
      );
    }

    return $output;
  }


  /**
   * Transform Reportback Item data and prepare for API response.
   *
   * @param object $data
   *   An object containing properties of Reportback Item data:
   *   - fid: (string) Reportback Item id.
   *   - caption: (string) Reportback Item caption.
   *   - uri: (string) API URI for Reportback Item data.
   *   - created_at: (string) Date Reportback Item was created.
   *   - status: (string) Reportback Item status.
   *
   * @return array
   */
  protected function transformReportbackItem($data) {
    $output = array(
      'id' => $data->fid,
      'caption' => !empty($data->caption) ? $data->caption : t('DoSomething? Just did!'),
      'uri' => $data->uri,
      'media' => array(
        'uri' => dosomething_image_get_themed_image_url_by_fid($data->fid, '480x480'),
        'type' => 'image',
      ),
      'created_at' => $data->timestamp,  // @TODO: Not sure if timestamp applies as created_at?
    );

    if (isset($data->status)) {
      $output['status'] = $data->status;
    }

    return $output;
  }


  /**
   * Transform user data and prepare for API response.
   *
   * @param object $data
   *   An object containing properties of User data:
   *   - uid: (int) User id.
   *
   * @return array
   */
  protected function transformUser($data) {
    return array(
      'id' => $data->uid,
    );
  }

}