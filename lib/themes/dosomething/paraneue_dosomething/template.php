<?php

/**
 * Implements hook_html_head_alter(). 
 */
function paraneue_dosomething_html_head_alter(&$head_elements) {

  $head_elements['dmoz_meta_tag'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'robots',
      'content' => 'NOODP'
    )
  );

  drupal_add_html_head($head_elements, 'dmoz_meta_tag');

}

?>
