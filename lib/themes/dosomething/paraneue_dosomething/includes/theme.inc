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

/**
 * Implements hook_theme().
 */
function paraneue_dosomething_theme() {
  return array(

    'campaign_creator' => array(
      'template' => 'campaign-creator',
      'path' => PARANEUE_DS_PATH . '/templates/campaign/partials',
    ),

    'campaign_headings' => array(
      'template' => 'campaign-headings',
      'path' => PARANEUE_DS_PATH . '/templates/campaign/partials',
    ),

    'campaign_scholarship' => array(
      'template' => 'campaign-scholarship',
      'path' => PARANEUE_DS_PATH . '/templates/campaign/partials',
      'variables' => array(
        'amount' => NULL,
        'classes' => NULL,
      )
    ),

    'footer' => array(
      'template' => 'footer',
      'path' => PARANEUE_DS_PATH . '/templates/system/partials',
    ),

    'social-networks' => array(
      'template' => 'social-networks',
      'path' => PARANEUE_DS_PATH . '/templates/system/partials',
      'variables' => array(
        'container_classes' => '',
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

    'sponsor_logos' => array(
      'template' => 'sponsor-logos',
      'path' => PARANEUE_DS_PATH . '/templates/system/partials',
      'variables' => array(
        'sponsors' => NULL,
      ),
    ),

    'thumbnail' => array(
      'template' => 'thumbnail',
      'path' => PARANEUE_DS_PATH . '/templates/home/partials',
    ),

    // Register theme functions for the Neue library.
    'paraneue_media' => array(
      'template' => 'media',
      'path' => PARANEUE_DS_PATH . '/templates/system/patterns',
      'variables' => array(
        'content' => NULL,
      ),
    ),

    'paraneue_gallery_duo' => array(
      'template' => 'gallery-duo',
      'path' => PARANEUE_DS_PATH . '/templates/system/patterns',
      'variables' => array(
        'items' => NULL,
      ),
    ),

    'paraneue_gallery_triad' => array(
      'template' => 'gallery-triad',
      'path' => PARANEUE_DS_PATH . '/templates/system/patterns',
      'variables' => array(
        'items' => NULL,
      ),
    ),
  );
}
