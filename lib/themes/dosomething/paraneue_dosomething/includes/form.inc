<?php

/**
 * Configures defaults for all forms.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_base(&$form, &$form_state, $form_id) {
  // Add `.btn` to all form submit buttons.
  $form['actions']['submit']['#attributes']['class'][] = 'btn';
}

