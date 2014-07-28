<?php
/**
 * @file
 * Helper functions for dosomething_taxonomy functionality.
 */


/**
 * Creates a taxonomy term with the given name if it doesn't already exist.
 * @return term object
 */
function dosomething_taxonomy_create_term_once($name, $vocabulary_machine_name) {
  if ($vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_machine_name)) {
    $vid = $vocabulary->vid;
    $existing_term = dosomething_taxonomy_get_term_from_name($name, $vid);

    $term = new stdClass();

    $term->name = $name;
    $term->vid = $vid;

    if($existing_term) {
      $term->tid = $existing_term;
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
function dosomething_taxonomy_get_term_from_name($term_name, $vid) {
  $tree = taxonomy_get_tree($vid);
  foreach ($tree as $term) {
    if ($term->name == $term_name) {
      return $term;
    }
  }

  return FALSE;
}

/**
 * Creates a vocabulary with the given machine name if it doesn't already exist.
 * Otherwise, update the existing vocabulary with the new name.
 * @return vocabulary object
 */
function dosomething_taxonomy_create_vocabulary_once($name, $machine_name) {
  $vocabulary = new stdClass();
  $vocabulary->name = $name;
  $vocabulary->machine_name = $machine_name;

  if($existing_vocabulary = taxonomy_vocabulary_machine_name_load($machine_name)) {
    $vocabulary->vid = $existing_vocabulary->vid;
  }

  taxonomy_vocabulary_save($vocabulary);
  return $vocabulary;
}
