<?php

/**
 * @file
 * Page callbacks for the Dosomething Taxonomy module.
 */

/**
 * Menu callback; displays all campaigns associated with a term.
 *
 * Core taxonomy_term_page loads and displays all nodes associated with a term,
 * and we don't want to display all nodes (e.g. Images, Facts).
 *
 * @param $term
 *   The taxonomy term.
 * @return
 *   The page content.
 */
function dosomething_taxonomy_term_page($term) {
  $build['description'] = array(
    '#markup' => check_markup($term->description, $term->format),
  );
  $image_size = '400x400';
  $source = 'taxonomy/term/' . $term->tid;
  // Load term's campaigns.
  $view = views_get_view('campaigns_by_term');
  $view->set_arguments(array($term->tid));
  $view->execute();
  // Render campaigns as campaign gallery.
  $build['campaigns'] = array(
    '#markup' => dosomething_campaign_get_campaign_gallery($view->result, $image_size, $source),
    '#items' => $campaigns,
  );
  return $build;
}
