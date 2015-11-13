<?php

class ApiCache {

  public function get($endpoint, $parameters) {
    $id = $this->generate_id($endpoint, $parameters);

    return cache_get($id, 'dosomething_api_cache');
  }


  public function set($endpoint, $parameters, $data) {
    $id = $this->generate_id($endpoint, $parameters);

    return cache_set($id, $data, 'dosomething_api_cache', REQUEST_TIME + 60);
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
