<?php
/**
 * @file
 * Helper functions for dosomething_taxonomy functionality.
 */


/**
 * Creates a taxonomy term with the given name if it doesn't already exist.
 * @return term object
 */
function dosomething_taxonomy_create_term($name, $vocabulary_machine_name) {
  if ($vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_machine_name)) {
    $vid = $vocabulary->vid;
    $existing_tid = dosomething_taxonomy_get_tid_from_name($name, $vid);

    $term = new stdClass();

    $term->name = $name;
    $term->vid = $vid;

    if($existing_term) {
      $term->tid = $existing_tid;
    }

    taxonomy_term_save($term);
    return $term;
  }
}

/**
 * Helper function to dynamically get the tid from the term_name
 * Source: https://api.drupal.org/comment/18909#comment-18909
 *
 * @param $term_name Term name
 * @param $vid ID of the vocabulary to search the term in
 *
 * @return Term ID of the found term or else FALSE
 */
function dosomething_taxonomy_get_tid_from_name($term_name, $vid) {
  $tree = taxonomy_get_tree($vid);
  foreach ($tree as $term) {
    if ($term->name == $term_name) {
      return $term;
    }
  }

  return FALSE;
}
