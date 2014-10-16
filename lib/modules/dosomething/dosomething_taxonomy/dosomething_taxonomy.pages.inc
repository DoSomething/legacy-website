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
  $campaigns = array();
  $size = '400x400';
  foreach ($view->result as $delta => $record) {
    $campaign_vars = dosomething_campaign_get_campaign_block_vars($record->nid, $size, $source);
    $campaigns[] = theme('campaign_block', $campaign_vars);
  }
  $build['campaigns'] = array(
    '#theme' => 'item_list',
    '#items' => $campaigns,
  );
  return $build;
}
