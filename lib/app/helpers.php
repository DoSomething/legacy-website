<?php

if (! function_exists('app')) {
  /**
   * Get the available application services array.
   *
   * @param  string $service
   * @return mixed
   */
  function app($service = NULL) {
    $app = $GLOBALS['app'];

    if (is_null($service)) {
      return $app;
    }

    if (isset($app[$service])) {
      return $app[$service];
    }

    // @TODO: Maybe throw an Exception instead?
    return NULL;
  }
}
