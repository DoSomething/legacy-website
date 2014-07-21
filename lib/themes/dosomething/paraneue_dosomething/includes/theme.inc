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

    'campaign_creator' => array(
      'template' => 'campaign-creator',
      'path' => PARANEUE_DS_PATH . '/templates/campaign/partials',
    ),

    'footer' => array(
      'template' => 'footer',
      'path' => PARANEUE_DS_PATH . '/templates/system/partials',
      'variables' => array(
        'social' => array(
          'facebook' => 0,
          'twitter' => 0,
          'instagram' => 0,
          'tumblr' => 0,
          'youtube' => 0,
        )
      )
    ),

    'header' => array(
      'template' => 'header',
      'path' => PARANEUE_DS_PATH . '/templates/system/partials',
    ),

    'info_bar' => array(
      'template' => 'info-bar',
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
