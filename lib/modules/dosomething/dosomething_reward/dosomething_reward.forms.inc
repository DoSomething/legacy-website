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

  $form['id'] = array(
    '#type' => 'hidden',
    '#default_value' => $reward->id,
    // Prevent this element from rendering in the browser.
    '#access' => FALSE,
  );

  // Add Address form fields.
  dosomething_user_address_form_element($form, $form_state);

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
 * Submit callback for dosomething_reportback_form().
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
  drupal_set_message(t($msg));
}

/**
 * Form constructor for a Reward Redeem form.
 *
 * @param object $reward
 *   The Reward entity to redeem.
 *
 * @ingroup forms
 */
function dosomething_reward_form($form, &$form_state, $reward) {
  $form['id'] = array(
    '#type' => 'hidden',
    '#default_value' => $reward->id,
    // Prevent this element from rendering in the browser.
    '#access' => FALSE,
  );
  $form['uid'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t("User uid"),
    '#size' => 10,
    '#default_value' => $reward->uid,
  );
  $form['created'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t("Created"),
    '#size' => 10,
    '#description' => t("Unix timestamp when Reward was created."),
    '#default_value' => $reward->created,
  );
  $form['redeemed'] = array(
    '#type' => 'textfield',
    '#title' => t("Redeemed"),
    '#size' => 10,
    '#description' => t("Unix timestamp when Reward was created."),
    '#default_value' => isset($reward->redeemed) ? $reward->redeemed : NULL,
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    ),
  );
  return $form;
}

/**
 * Submit callback for dosomething_reward_form().
 */
function dosomething_reward_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $reward = reward_load($values['id']);
  $reward->uid = $values['uid'];
  $reward->created = $values['created'];
  if (empty($values['redeemed'])) {
    $values['redeemed'] = NULL;
  }
  $reward->redeemed = $values['redeemed'];
  $reward->save();
  drupal_set_message(t("Updated."));
}
