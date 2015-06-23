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
   *   - id: (string)
   *   - title: (string)
   *   - tagline: (string)
   *   - created_at: (string)
   *   - update_at: (string)
   *   - time_commitment: (float)
   *   - cover_image: (array)
   *   - staff_pick: (bool)
   *   - facts: (array)
   *   - solutions: (array)
   *   - causes: (array)
   *   - action_types: (array)
   *   - issue: (string)
   *   - tags: (array)
   *
   * @return array
   */
  protected function transformCampaign($data, $display = 'teaser') {
    $output = array(
      'id' => isset($data->id) ? $data->id : $data->nid,
      'title' => $data->title,
    );

    if ($data instanceof Campaign) {
      if ($display === 'full') {

        $output['tagline'] = $data->tagline;
        $output['created_at'] = $data->created_at;
        $output['updated_at'] = $data->updated_at;
        $output['time_commitment'] = $data->time_commitment;
        // $output['type'] = $data->type; //@TODO: Should type be included? Consider there is an SMS Campaign type...

        if ($data->status) {
          // @TODO: Should the status default to "active"?
          $output['status'] = $data->status;
        }

        if ($data->cover_image) {
          foreach ($data->cover_image as $key => $image) {
            if (!is_null($image)) {
              $output['cover_image'][$key] = $this->transformMedia($image, 'square');
            }
          }
        }

        $output['staff_pick'] = $data->staff_pick;

        if ($data->facts['problem']) {
          $output['facts']['problem'] = $data->facts['problem']['fact'];
        }

        if ($data->facts['solution']) {
          $output['facts']['solution'] = $data->facts['solution']['fact'];
        }

        if ($data->facts['sources']) {
          $output['facts']['sources'] = $data->facts['sources'];
        }

        if ($data->solutions['copy']) {
          $output['solutions']['copy'] = $data->solutions['copy'];
        }

        if ($data->solutions['support_copy']) {
          $output['solutions']['support_copy'] = $data->solutions['support_copy'];
        }

        if ($data->causes['primary']) {
          $output['causes']['primary'] = $data->causes['primary'];
        }

        if ($data->causes['secondary']) {
          $output['causes']['secondary'] = $data->causes['secondary'];
        }

        if ($data->action_types['primary']) {
          $output['action_types']['primary'] = $data->action_types['primary'];
        }

        if ($data->action_types['secondary']) {
          $output['action_types']['secondary'] = $data->action_types['secondary'];
        }

        if ($data->issue) {
          $output['issue'] = $data->issue;
        }

        if ($data->tags) {
          $output['tags'] = $data->tags;
        }

        if ($data->timing['high_season']) {
          $output['timing']['high_season'] = $data->timing['high_season'];
        }

        if ($data->timing['low_season']) {
          $output['timing']['low_season'] = $data->timing['low_season'];
        }
      }

      if ($data->reportback_info['copy']) {
        $output['reportback_info']['copy'] = $data->reportback_info['copy'];
      }

      if ($data->reportback_info['confirmation_message']) {
        $output['reportback_info']['confirmation_message'] = $data->reportback_info['confirmation_message'];
      }

      if ($data->reportback_info['noun']) {
        $output['reportback_info']['noun'] = $data->reportback_info['noun'];
      }

      if ($data->reportback_info['verb']) {
        $output['reportback_info']['verb'] = $data->reportback_info['verb'];
      }

    }

    return $output;
  }


  /**
   * Transform Media data and prepare for API response.
   *
   * @param array $data
   * @param string|null $aspect_ratio
   * @return array|null
   */
  protected function transformMedia($data, $aspect_ratio = NULL) {
    if ($data['type'] === 'image') {
      $output = array();

      $output['uri'] = $data['sizes'][$aspect_ratio]['uri'];

      foreach ($data['sizes'] as $key => $size) {
        if (isset($size['uri'])) {
          $output['sizes'][$key]['uri'] = $size['uri'];
        }
      }

      $output['type'] = $data['type'];
      $output['dark_background'] = $data['dark_background'];

      return $output;
    }

    if ($data['type'] === 'video') {
      // @TODO: include video transformation code here!
    }

    return NULL;
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

      $output['reportback_items'] = array(
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
      'id' => isset($data->id) ? $data->id : $data->uid,
    );
  }

}
