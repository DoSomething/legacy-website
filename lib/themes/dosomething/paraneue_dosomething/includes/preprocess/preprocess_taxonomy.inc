<?php

/**
 * Implements template_preprocess_taxonomy_term().
 */
function paraneue_dosomething_preprocess_taxonomy_term(&$vars) {
  // Source to append to Campaign Gallery links.
  $source = 'taxonomy/term/' . $vars['tid'];
  $vars['campaign_gallery'] = paraneue_dosomething_get_campaign_gallery($vars['campaigns'], $source, TRUE);

  // Adds sponsor logos.
  paraneue_dosomething_preprocess_field_partners($vars);
  // Adds $partner_info and $formatted_partners variables.
  dosomething_helpers_preprocess_partners_vars($vars);
  if (isset($vars['partner_info'])) {
    $vars['modals'] = theme('modal_links', array('modals' =>
      array(
        'partner_info' => $vars['partner_info'],
        'issue' => $vars['term']->name,
      ),
    ));
  }
  paraneue_dosomething_add_info_bar($vars);
}
