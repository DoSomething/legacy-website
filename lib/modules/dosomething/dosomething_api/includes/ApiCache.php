<?php

class ApiCache {

  /**
   * @param  string  $endpoint  Type of resource based on endpoint.
   * @param  array   $parameters  The URL parameters passed that define the request.
   * @return mixed
   */
  public function get($endpoint, $parameters) {
    $id = $this->generate_id($endpoint, $parameters);

    $cache = cache_get($id, 'cache_dosomething_api');

    if ($cache && $cache->expire < REQUEST_TIME) {
      cache_clear_all($id, 'cache_dosomething_api');

      return FALSE;
    }

    return $cache;
  }


  /**
   * @param  string  $endpoint
   * @param  array   $parameters
   * @param  mixed   $data
   * @return bool
   *
   * @todo: not ideal that Drupal doesn't return anything concrete from the cache_set() function.
   */
  public function set($endpoint, $parameters, $data) {
    $id = $this->generate_id($endpoint, $parameters);

    cache_set($id, $data, 'cache_dosomething_api', REQUEST_TIME + 60);

    return TRUE;
  }


  /**
   * @param  string  $endpoint
   * @param  array   $parameters
   * @return string
   */
  private function generate_id($endpoint, $parameters) {
    return $endpoint . '_api_request' . $this->stringify($parameters);
  }


  /**
   * @param  array  $parameters
   * @return string
   * @todo: may want to allow passing nested array instead of one-dimensional array.
   */
  private function stringify($parameters) {
    $string = '';
    $items = array_filter($parameters);

    foreach ($items as $key => $value) {
      $string .= '|' . $key . '=' . $value;
    }

    return $string;
  }
}
