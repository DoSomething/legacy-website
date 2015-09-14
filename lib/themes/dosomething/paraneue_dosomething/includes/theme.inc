<?php

/**
 * Override theme_menu_local_tasks().
 *
 * Use Forge waypoints pattern for admin menu.
 */
function paraneue_dosomething_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<ul class="waypoints">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<ul class="waypoints">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Override theme_menu_local_task().
 *
 * Use Forge waypoints pattern for admin menu.
 */
function paraneue_dosomething_menu_local_task($variables) {
  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }

  return '<li' . (!empty($variables['element']['#active']) ? ' class="is-active"' : '') . '>' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

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

    // Register theme functions for Forge patterns.
    'paraneue_figure' => array(
      'template' => 'figure',
      'path' => PARANEUE_DS_PATH . '/templates/system/patterns',
    ),

    'paraneue_media' => array(
      'template' => 'media',
      'path' => PARANEUE_DS_PATH . '/templates/system/patterns',
      'variables' => array(
        'content' => NULL,
      ),
    ),

    'paraneue_photo' => array(
      'template' => 'photo',
      'path' => PARANEUE_DS_PATH . '/templates/system/patterns',
    ),

    'paraneue_tile' => array(
      'template' => 'tile',
      'path' => PARANEUE_DS_PATH . '/templates/system/patterns',
    ),

    'paraneue_gallery' => array(
      'template' => 'gallery',
      'path' => PARANEUE_DS_PATH . '/templates/system/patterns',
    ),
  );
}
