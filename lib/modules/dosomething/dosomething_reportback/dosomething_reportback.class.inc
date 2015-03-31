<?php

/**
 * Class Reportback
 */
class Reportback {

  public function index($page)
  {
    return [
      'data' => 'something',
      'page' => (int) $page,
    ];
  }


  public function show($id)
  {
    return [
      'data' => $id
    ];
  }

}