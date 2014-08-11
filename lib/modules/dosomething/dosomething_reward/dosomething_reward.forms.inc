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
  $submit_label = variable_get('dosomething_reward_redeem_form_button_text');
  $size_options = dosomething_shipment_get_shirt_size_options();

  $form['id'] = array(
    '#type' => 'hidden',
    '#default_value' => $reward->id,
    // Prevent this element from rendering in the browser.
    '#access' => FALSE,
  );

  // Add Address form fields.
  dosomething_user_address_form_element($form, $form_state);

  $form['shirt_size'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#title' => t("Your T-Shirt size"),
    '#options' => $size_options,
  );
  $form['shirt_size_additional'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#title' => t("Your friend's T-Shirt size"),
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

  $values = $form_state['values'];

  // Save User address.
  dosomething_user_save_address_values($values);

  // Redeem the reward.
  $reward = entity_load_single('reward', $values['id']);
  $reward->redeem($values);
  $msg = variable_get('dosomething_reward_redeem_form_confirm_msg');
  drupal_set_message($msg);
}
