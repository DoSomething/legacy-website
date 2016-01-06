<?php

namespace Phoenix\Drupal;

class ModuleController implements ModuleControllerInterface
{

  public function moduleLoadInclude($type, $module, $name = NULL)
  {
    return module_load_include($type, $module, $name);
  }

}
