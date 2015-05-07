<?php

abstract class Transformer {

  public function __construct() {
    // Load Services module to use its index_query functions in subclass methods.
    module_load_include('inc', 'services', 'services.module');
  }

}