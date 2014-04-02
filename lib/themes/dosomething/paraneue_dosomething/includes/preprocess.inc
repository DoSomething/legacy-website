<?php

/**
 * Implements theme_preprocess_page().
 */
function paraneue_dosomething_preprocess_page(&$vars) {
  $vars['logo'] = $vars['base_path'] . NEUE_PATH . '/assets/images/ds-logo.png';

  $vars['navigation'] = theme('navigation');
  $vars['footer'] = theme('footer');
}


/**
 * Implements theme_preprocess_user_profile().
 */
function paraneue_dosomething_preprocess_user_profile(&$variables) {
  // krumo($variables);
  // May delete this function if processing output content in the module.
}
