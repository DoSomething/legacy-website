<?php
/**
 * @file
 * Code for dosomething_global admin functionality.
 */

function dosomething_global_translation_status_form($form, &$form_state) {
  $form['campaigns']['#tree'] = TRUE;//do we need this
  // $form['#theme'] = 'translation_status_form';
  // Return all nids of nodes of type "page".
  $nids = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->fields('n', array('type'))
      ->condition('n.type', 'campaign')
      ->execute()
      ->fetchCol(); // returns an indexed array
  // Now return the node objects.
  $nodes = node_load_multiple($nids);
  foreach($nodes as $nid => $campaign) {
    $form['campaigns'][$nid] = array();
    $form['column-nid'][$nid] = array(
      '#markup' => $nid,
    );
    $lang_map = variable_get('dosomething_global_language_map', '');
    foreach ($lang_map as $lang_code => $lang) {
      $translation_exists = FALSE;
      $translation_published = FALSE;

      if (isset($campaign->translations->data[$lang_code])) {
        $translation_exists = TRUE;
        if ($campaign->translations->data[$lang_code]['status']) {
          $translation_published = TRUE;
        }
      }

      $markup_string = "Not translated";
      if ($translation_exists) {
        $markup_string = "Not published";
        if ($translation_published) {
          $markup_string = "Published";
        }
      }
      $form['column-' . $lang_code][$nid] = array(
        '#markup' => $markup_string,
      );
    }
  }
  return $form;
}

function theme_dosomething_global_translation_status_form($variables) {
}
