<?php

/**
 * Override theme_breadrumb().
 *
 * Print breadcrumbs as a list, with separators.
 */
function paraneue_dosomething_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    $breadcrumbs = '<nav class="breadcrumbs"><ul>';

    $count = count($breadcrumb) - 1;
    foreach ($breadcrumb as $key => $value) {
      if ($count != $key) {
        $breadcrumbs .= '<li>' . $value . '</li>';
      }
      else{
        $breadcrumbs .= '<li>' . $value . '</li>';
      }
    }
    $breadcrumbs .= '</ul></nav>';

    return $breadcrumbs;
  }
}


function paraneue_dosomething_theme() {
  return array(

    'footer' => array(
      'template' => 'footer',
      'path' => PARANEUE_DS_PATH . '/templates/system/partials',
    ),

    'navigation' => array(
      'template' => 'navigation',
      'path' => PARANEUE_DS_PATH . '/templates/system/partials',
    ),

    'thumbnail' => array(
      'template' => 'thumbnail',
      'path' => PARANEUE_DS_PATH . '/templates/home/partials',
    ),
  );
}
