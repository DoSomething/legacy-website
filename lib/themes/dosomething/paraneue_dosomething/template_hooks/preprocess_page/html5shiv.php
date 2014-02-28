<?php

  $html5shiv = array(
    '#type' => 'markup',
    '#markup' => '<!--[if lte IE 8]> <script type="text/javascript" src="' . NEUE_PATH . '/bower_components/dist/html5shiv.js' . '"></script> <![endif]-->'
  );

  drupal_add_html_head($html5shiv, 'html5shiv');

?>
