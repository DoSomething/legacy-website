<?php

/**
 * Implements hook_js_alter().
 */
function paraneue_dosomething_js_alter(&$js) {
  $html5shiv = NEUE_PATH . '/bower_components/dist/html5shiv.js';
  $js['html5shiv'] = drupal_js_defaults();
  $js['html5shiv']['data'] = $html5shiv;
  $js['html5shiv']['scope'] = 'header';
  $js['html5shiv']['group'] = -100;
  $js['html5shiv']['browsers'] = array('IE' => 'lte IE 8');
  $js['html5shiv']['type'] = 'file';
  $js['html5shiv']['every_page'] = TRUE;
  $js['html5shiv']['weight'] = -50;
}

?>
