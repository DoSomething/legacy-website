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

/**
 * Implements hook_form_FORM_ID_alter().
 */
function paraneue_dosomething_form_dosomething_reward_redeem_form_alter(&$form, &$form_state, $form_id) {
  $class_name = '-media-options';
  $form['item']['#attributes']['class'][] = $class_name;
  $form['item_additional']['#attributes']['class'][] = $class_name;
}
