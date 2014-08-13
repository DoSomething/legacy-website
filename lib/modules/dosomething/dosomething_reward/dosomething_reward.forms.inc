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
  $shirt_options = dosomething_shipment_get_shirt_options();
  $size_options = dosomething_shipment_get_shirt_size_options();

  $form['id'] = array(
    '#type' => 'hidden',
    '#default_value' => $reward->id,
    // Prevent this element from rendering in the browser.
    '#access' => FALSE,
  );

  // Add Address form fields.
  dosomething_user_address_form_element($form, $form_state);

  $form['item_header'] = array(
    '#markup' => t("Your Shirt"),
  );
  $form['item'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#title' => t("Your Shirt style"),
    '#options' => $shirt_options,
  );
  $form['item_option'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t("Your Shirt Size"),
    '#options' => $size_options,
  );

  $form['item_additional_header'] = array(
    '#markup' => t("Your Friend's Shirt"),
  );
  $form['item_additional'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#title' => t("Your Friend's Shirt style"),
    '#options' => $shirt_options,
  );
  $form['item_additional_option'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t("Your Friend's Shirt Size"),
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

/**
 * Form constructor for a Delete Reward form.
 *
 * @param object $reward
 *   The Reward entity to delete.
 *
 * @ingroup forms
 */
function dosomething_reward_delete_form($form, &$form_state, $reward) {
  $form['id'] = array(
    '#type' => 'hidden',
    '#default_value' => $reward->id,
    '#access' => FALSE,
  );
  $help = "As staff, you may delete your Reward (id: @id) for testing.  The corresponding Shipment record will also be deleted if the Reward has been redeemed.";
  $form['help'] = array(
    '#markup' => t($help, array('@id' => $reward->id)),
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t("Delete Reward"),
    ),
  );
  return $form;
}

/**
 * Submit callback for dosomething_reward_delete_form().
 */
function dosomething_reward_delete_form_submit($form, &$form_state) {
  entity_delete('reward', $form_state['values']['id']);
  drupal_set_message(t("Reward deleted."));
}
