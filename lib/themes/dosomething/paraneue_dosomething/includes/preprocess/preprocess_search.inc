<?php

/**
 * Preprocesses variables for the search results page.
 */
function paraneue_dosomething_preprocess_search_results(&$vars) {
  if ($search_results = $vars['results']) {
    // Theme the set of results as duo gallery.
    $vars['search_results_gallery'] = paraneue_dosomething_get_search_gallery($search_results);
  }
}

