<?php

/**
 * Adds html5shiv script for IE8 users.
 *
 * Implements hook_preprocess_page().
 */
function paraneue_dosomething_preprocess_page_html5shiv(&$vars, $hook) {
  $html5shiv = array(
    '#type' => 'markup',
    '#markup' => '<!--[if lte IE 8]> <script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/html5shiv/3.7/html5shiv.js"></script> <![endif]-->'
  );

  drupal_add_html_head($html5shiv, 'html5shiv');
}
