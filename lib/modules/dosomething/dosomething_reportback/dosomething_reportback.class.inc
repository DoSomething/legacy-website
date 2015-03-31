<?php

/**
 * Class Reportback
 */
class Reportback {

  public function index()
  {
    return [
      'data' => 'something'
    ];
  }


  public function show($id) {
    return [
      'data' => $id
    ];
  }

}