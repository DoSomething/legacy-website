<?php

class ApiCache {

  /**
   * Clear a specified item from cache.
   *
   * @param  mixed  $id
   * @param  mixed  $action
   * @param  mixed  $parameters
   * @return bool
   */
  function clear($id = NULL, $action = NULL, $parameters = NULL) {
    if (!$id) {
      if ($action && $parameters) {
        $id = $this->generate_id($action, $parameters);
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
   * @param  string  $action
   * @param  array   $parameters
   * @return mixed
   */
  public function get($action, $parameters) {
    $id = $this->generate_id($action, $parameters);

    $cache = cache_get($id, 'cache_dosomething_api');

    if ($cache) {
      if (isset($parameters['cache']) && !dosomething_helpers_convert_string_to_boolean($parameters['cache'])) {
        $this->clear($id);

        return FALSE;
      }

      // Temporary cache expire is equal to -1.
      // Permanent cache expire is equal to 0.
      if ($cache->expire > 0 && $cache->expire < REQUEST_TIME) {
        $this->clear($id);

        return FALSE;
      }
    }

    return $cache;
  }

  /**
   * Set data in cache for 24 hours with id based on endpoint and URL parameters.
   *
   * @param  string  $action
   * @param  array   $parameters
   * @param  mixed   $data
   * @param  mixed   $expiration
   * @return bool
   */
  public function set($action, $parameters, $data, $expiration = NULL) {
    if (isset($parameters['cache']) && !dosomething_helpers_convert_string_to_boolean($parameters['cache'])) {
      return FALSE;
    }

    $id = $this->generate_id($action, $parameters);

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
   * @param  string  $action
   * @param  array   $parameters
   * @return string
   */
  private function generate_id($action, $parameters) {
    if (is_array($parameters) && isset($parameters['cache'])) {
      unset($parameters['cache']);
    }

    $id = $action . '_api_request' . $this->stringify($parameters);

    watchdog('dosomething_api', $id, [], WATCHDOG_DEBUG);

    return $id;
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

    if (!is_array($parameters)) {
      if (is_int(intval($parameters))) {
        $parameters = ['id' => $parameters];
      }
    }

    // Remove empty values from array.
    $items = array_filter($parameters);

    foreach ($items as $key => $value) {
      $string .= '|' . $key . '=' . $value;
    }

    return $string;
  }
}
