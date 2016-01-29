<?php

class ApiCache {

  /**
   * Clear a specified item from cache.
   *
   * @param  mixed  $id
   * @param  mixed  $endpoint
   * @param  mixed  $parameters
   * @return bool
   */
  function clear($id = NULL, $endpoint = NULL, $parameters = NULL) {
    if (!$id) {
      if ($endpoint && $parameters) {
        $id = $this->generate_id($endpoint, $parameters);
      }
      else {
        return FALSE;
      }
    }

    cache_clear_all($id, 'cache_dosomething_api');

    return TRUE;
  }

  /**
   * Get data from cache based on id from endpoint and URL parameters.
   *
   * @param  string  $endpoint  Type of resource based on endpoint.
   * @param  array   $parameters  The URL parameters passed that define the request.
   * @return mixed
   */
  public function get($endpoint, $parameters) {
    $id = $this->generate_id($endpoint, $parameters);

    $cache = cache_get($id, 'cache_dosomething_api');

    if ($cache && !dosomething_helpers_convert_string_to_boolean($parameters['cache'])) {
      $this->clear($id);

      return FALSE;
    }

    // Temporary cache expire is equal to -1.
    // Permanent cache expire is equal to 0.
    if ($cache && $cache->expire > 0 && $cache->expire < REQUEST_TIME) {
      $this->clear($id);

      return FALSE;
    }

    return $cache;
  }

  /**
   * Set data in cache for 24 hours with id based on endpoint and URL parameters.
   *
   * @param  string  $endpoint
   * @param  array   $parameters
   * @param  mixed   $data
   * @param  mixed   $expiration
   * @return bool
   */
  public function set($endpoint, $parameters, $data, $expiration = NULL) {
    if (!dosomething_helpers_convert_string_to_boolean($parameters['cache'])) {
      return FALSE;
    }

    $id = $this->generate_id($endpoint, $parameters);

    if (is_bool($expiration) && $expiration === FALSE) {
      $expiration = CACHE_PERMANENT;
    }
    elseif (is_int($expiration)) {
      $expiration = REQUEST_TIME + (60 * 60 * $expiration);
    }
    else {
      $expiration = CACHE_TEMPORARY;
    }

    cache_set($id, $data, 'cache_dosomething_api', $expiration);

    return TRUE;
  }

  /**
   * Generate an id from resource endpoint type and URL parameters.
   *
   * @param  string  $endpoint
   * @param  array   $parameters
   * @return string
   */
  private function generate_id($endpoint, $parameters) {
    unset($parameters['cache']);

    return $endpoint . '_api_request' . $this->stringify($parameters);
  }

  /**
   * Create a concatenated string from URL parameters.
   *
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
