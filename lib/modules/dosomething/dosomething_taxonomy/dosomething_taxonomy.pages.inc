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
  // This code is somewhat lifted from contrib module:
  // @see https://www.drupal.org/project/disable_term_node_listings
  drupal_set_title($term->name);
  return taxonomy_term_view($term, 'full');
}
