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
   * @param  string  $data Single or multiple comma separated data items.
   * @return mixed
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
   * @param  array   $data
   *   An associative array of pagination parameters:
   *   - total: (int) Complete total number of available data items found.
   *   - per_page: (int) Total number of data items to show per page.
   *   - current_page: (int) Current page number.
   *   - total_pages: (int) Total number of pages available.
   * @param  array   $filters
   * @param  string  $endpoint Endpoint for building URI.
   * @return mixed
   */
  protected function getNextPageUri($data, $filters, $endpoint) {
    $uri = $this->getPathParameters($filters, $endpoint);

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
   * @param  array   $data
   *   An associative array of pagination parameters:
   *   - total: (int) Complete total number of available data items found.
   *   - per_page: (int) Total number of data items to show per page.
   *   - current_page: (int) Current page number.
   *   - total_pages: (int) Total number of pages available.
   * @param  array   $filters An associative array of current location parameters.
   * @param  string  $endpoint Endpoint for building URI.
   * @return mixed
   */
  protected function getPrevPageUri($data, $filters, $endpoint) {
    $uri = $this->getPathParameters($filters, $endpoint);

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
   * @param  array   $filters
   * @param  string  $endpoint
   * @return string
   */
  protected function getPathParameters($filters, $endpoint) {
    $path = services_resource_uri([$endpoint]) . '?';
    $filters = dosomething_helpers_unset_array_keys($filters, ['offset', 'page']);
    $parameters = dosomething_helpers_convert_filters_to_url_parameters($filters);
    $pieces = [];

    foreach ($parameters as $key => $value) {
      $pieces[] = $key . '=' . $value;
    }

    $path .= implode('&', $pieces);

    return $path;
  }

  /**
   * Get metadata for pagination of response data.
   *
   * @param  int     $total Complete total number of items found.
   * @param  array   $filters
   *   An associative array of query parameters and values:
   *   - nid: (array) Campaign ids.
   *   - status: (array) Reportback statuses to retrieve.
   *   - count: (int) Number of items to show per page.
   *   - page: (int) Current page number.
   *   - offset: (int) Number of items displayed from prior pages.
   *   - random: (boolean) Whether to retrieve a random assortment of data items.
   * @param  string  $endpoint
   * @return array
   */
  protected function paginate($total, $filters, $endpoint) {
    $data = [];

    $data['total'] = $total;
    $data['per_page'] = $filters['count'];
    $data['current_page'] = (isset($filters['page']) && $filters['page'] > 0) ? (int) $filters['page'] : 1;
    $data['total_pages'] = ceil($data['total'] / $data['per_page']);
    $data['prev_uri'] = $this->getPrevPageUri($data, $filters, $endpoint);
    $data['next_uri'] = $this->getNextPageUri($data, $filters, $endpoint);

    return $data;
  }

  /**
   * Get the offset for requests based on specified page number and count of items.
   *
   * @param  int  $page Current page number.
   * @param  int  $count Number of items per page.
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
   * @param object  $object Single object of retrieved data.
   */
  abstract protected function transform($object);

  /**
   * For collection of data to transform, run each item in collection
   * through a specified method.
   *
   * @param array $items Collection of item objects retrieved data.
   * @param string $method Name of method to use on each array item.
   * @return array
   */
  protected function transformCollection($items, $method = 'transform') {
    return array_map([$this, $method], $items);
  }

  /**
   * Transform Campaign data and prepare for API response.
   *
   * @param  object  $data
   *   An object containing properties of Campaign data:
   *   - id: (string)
   *   - title: (string)
   *   - tagline: (string)
   *   - created_at: (string)
   *   - update_at: (string)
   *   - time_commitment: (float)
   *   - status: (string)
   *   - cover_image: (array)
   *   - staff_pick: (bool)
   *   - facts: (array)
   *   - solutions: (array)
   *   - causes: (array)
   *   - action_types: (array)
   *   - issue: (string)
   *   - tags: (array)
   *   - timing: (array)
   *   - services: (array)
   *   - reportback_info: (array)
   *   - mobile_app: (array)
   * @return array
   */
  protected function transformCampaign($data) {
    $output = [
      'id' => isset($data->id) ? $data->id : $data->nid,
      'title' => $data->title,
      'campaign_runs' => $data->campaign_runs,
      'language' => $data->language,
      'translations' => $data->translations,
    ];

    // If an instance of Campaign class, then there is much
    // more information that can be obtained.
    if ($data instanceof Campaign) {

      // Show all properties for "full" display.
      if ($data->display === 'full') {
        // print_r($data);
        // die();
        $output['tagline'] = $data->tagline;

        $output['created_at'] = $data->created_at;

        $output['updated_at'] = $data->updated_at;

        $output['status'] = $data->status ? $data->status : 'active';

        $output['time_commitment'] = $data->time_commitment;

        // $output['type'] = $data->type; //@TODO: Should type be included? Consider there is an SMS Campaign type...

        foreach ($data->cover_image as $key => $image) {
          if (!is_null($image)) {
            $output['cover_image'][$key] = $this->transformMedia($image, 'square');
          } else {
            $output['cover_image'][$key] = NULL;
          }
        }

        $output['staff_pick'] = $data->staff_pick;

        $output['facts']['problem'] = $data->facts['problem'] ? $data->facts['problem']['fact'] : NULL;
        $output['facts']['solution'] = $data->facts['solution'] ? $data->facts['solution']['fact'] : NULL;
        $output['facts']['sources'] = $data->facts['sources'] ? $data->facts['sources'] : NULL;

        $output['solutions'] = $data->solutions;

        $output['pre_step_header'] = $data->pre_step_header;
        $output['promoting_tips'] = $data->promoting_tips;

        $output['latest_news'] = $data->latest_news;

        $output['causes'] = $data->causes;

        $output['action_types'] = $data->action_types;

        $output['issue'] = $data->issue;

        $output['tags'] = $data->tags;

        $output['timing']['high_season'] = $data->timing['high_season'];
        $output['timing']['low_season'] = $data->timing['low_season'];

        $output['services'] = $data->services;

        $output['mobile_app']['dates'] = $data->mobile_app['dates'];
      }

      $output['reportback_info'] = $data->reportback_info;

      if (isset($data->uri)) {
        $output['uri'] = $data->uri;
      }

    }

    return $output;
  }

  /**
   * Transform Kudos data and prepare for API response.
   *
   * @param  object  $data A Kudos object containing the following properties:
   *  - id: (string)
   *  - term: (array)
   *  - reportback_item: (array)
   *  - user: (array)
   *  - uri: (string)
   * @return array
   */
  protected function transformKudos($data) {
    $output = [
      'id' => $data->id,
      'term' => $data->term,
      'reportback_item' => $data->reportback_item,
      'user' => $data->user,
      'uri' => $data->uri,
    ];

    return $output;
  }

  /**
   * Transform Media data and prepare for API response.
   *
   * @param  array  $data
   * @param  mixed  $aspect_ratio
   * @return mixed
   */
  protected function transformMedia($data, $aspect_ratio = NULL) {
    if ($data['type'] === 'image') {
      $output = [];

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
   * @param  object  $data Standard object or Reportback object.
   *   An object containing properties of Reportback data:
   *   - id: (string) The Reportback id.
   *   - created_at: (string) Date Reportback was created.
   *   - updated_at: (string) Date Reportback was updated.
   *   - quantity: (int) Quantity declared for Reportback.
   *   - why_participated: (string) Reason for participating.
   *   - flagged: (int) Status whether Reportback has been flagged.
   *   - reportback_items: (string) Comma separated list of Reportback Item ids for specified Reportback.
   * @return array
   */
  protected function transformReportback($data) {
    $output = [
      'id' => $data->id,
      'created_at' => $data->created_at,
      'updated_at' => $data->updated_at,
      'quantity' => $data->quantity,
    ];

    if (!isset($data->uri)) {
      $output['uri'] = services_resource_uri(['reportbacks', $data->id]);
    }
    else {
      $output['uri'] = $data->uri;
    }

    if ($data instanceof Reportback) {
      $output['why_participated'] = $data->why_participated;
      $output['flagged'] = $data->flagged;

      try {
        $items = ReportbackItem::get($data->reportback_items);
        $items = services_resource_build_index_list($items, 'reportback-items', 'id');
      }
      catch (Exception $error) {
        $items = [];
      }

      $items = $this->transformCollection($items, 'transformReportbackItem');

      $output['reportback_items'] = [
        'total' => count($items),
        'data' => $items,
      ];
    }

    return $output;
  }

  /**
   * Transform Reportback Item data and prepare for API response.
   *
   * @param  object  $data
   *   A Reportback Item object containing following properties:
   *   - id: (string) Reportback Item id.
   *   - status: (string) Reportback Item status.
   *   - caption: (string) Reportback Item caption.
   *   - uri: (string) API URI for Reportback Item data.
   *   - media: (array) Reportback Item media.
   *   - created_at: (string) Date Reportback Item was created.
   *   - kudos: (array) Ids of kudos for Reportback Item.
   * @return array
   */
  protected function transformReportbackItem($data) {
    $output = [
      'id' => $data->id,
      'status' => $data->status,
      'caption' => $data->caption,
      'uri' => $data->uri,
      'media' => $data->media,
      'created_at' => $data->created_at,
    ];

    $kudos = $data->kudos ?: [];
    try {
      $kudos = Kudos::get($kudos);
      $kudos = dosomething_kudos_sort($kudos);
    }
    catch (Exception $error) {
      $kudos = [];
    }

    $output['kudos']['data'] = $kudos;

    return $output;
  }

  /**
   * Transform user data and prepare for API response.
   *
   * @param  object  $data
   *   An object containing properties of User data:
   *   - uid: (int) User id.
   * @return array
   */
  protected function transformUser($data) {
    return [
      'id' => $data->id,
      'first_name' => $data->first_name,
      'last_initial' => $data->last_initial,
      'photo' => $data->photo,
      'country' => $data->country,
    ];
  }

}
