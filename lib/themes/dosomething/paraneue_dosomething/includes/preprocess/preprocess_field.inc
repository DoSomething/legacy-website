<?php

/**
 * Preprocesses the field_partners variable, if exists.
 */
function paraneue_dosomething_preprocess_field_partners(&$vars) {
  $vars['partners'] = dosomething_taxonomy_get_partners_data($vars['field_partners']);
  $vars['sponsor_logos'] = paraneue_dosomething_get_sponsor_logos($vars['partners']);
}
