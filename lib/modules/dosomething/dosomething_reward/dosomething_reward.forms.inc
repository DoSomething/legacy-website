<?php
/**
 * @file
 * Provides form constructors for the DoSomething Reward module.
 */

/**
 * Form constructor for a Reward Redeem form.
 *
 * @param object $reward
 *   The Reward entity to redeem.
 *
 * @ingroup forms
 */
function dosomething_reward_redeem_form($form, &$form_state, $reward) {
  $submit_label = t("Redeem");
  $size_options = array(
    'S' => t('S'), 
    'M' => t('M'),
    'L' => t('L'),
  );
  $form['id'] = array(
    '#type' => 'hidden',
    '#default_value' => $entity->id,
    // Prevent this element from rendering in the browser.
    '#access' => FALSE,
  );
  $form['size'] = array(
    '#type' => 'radios',
    '#title' => t('T-Shirt size'),
    '#options' => $size_options,
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => $submit_label,
    ),
  );
  return $form;
}

/**
 * Validation callback for dosomething_reportback_form().
 */
function dosomething_reward_redeem_form_submit($form, &$form_state) {
  // If user session no longer exists:
  if (!user_is_logged_in()) {
    // Tell them that.
    drupal_set_message(t("You are no longer logged in. Please log in."), 'error');
  }
  $reward = entity_load_single('reward', $form_state['values']['id']);
  $reward->redeem();
  drupal_set_message(t("Reward redeemed!"));
}
