<?php

namespace Phoenix\Drupal;

interface ModuleControllerInterface
{

  public function moduleLoadInclude($type, $module, $name = NULL);

}
