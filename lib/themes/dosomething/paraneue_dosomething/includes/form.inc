<?php

/**
 * Configures defaults for all forms.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_base(&$form, &$form_state, $form_id) {
  // Add `.btn` to all form submit buttons.
  $form['actions']['submit']['#attributes']['class'][] = 'btn';
  // Check if this form needs Shirt Styles applied.
  paraneue_dosomething_form_alter_shirt_options($form, $form_state, $form_id);
}



/**
 * Checks if given $form needs Shirt Styles applied based on its $form_id.
 */
function paraneue_dosomething_form_alter_shirt_options(&$form, &$form_state, $form_id) {
  // Form IDs which need Shirt styles.
  $form_ids = array(
    'dosomething_reward_redeem_form',
    'dosomething_signup_user_signup_data_form'
  );
  // If this form is not one of the Shirt Style forms.
  if (!in_array($form_id, $form_ids)) {
    // Exit out.
    return;
  }
  // If this is the User Signup Data Form:
  if ($form_id == 'dosomething_signup_user_signup_data_form') {
    // If we aren't collecting shipment info:
    // @see dosomething_signup_user_signup_data_form().
    if (!isset($form['shipment_item'])) {
      // Don't need to preprocess anything.
      return;
    }
    // If we aren't collecting a shirt, we don't need to preprocess anything.
    if ($form['shipment_item']['#value'] != 'shirt') {
      // Exit out.
      return;
    }
    // If the form has been submitted already:
    if (isset($form['submitted_copy'])) {
      // We don't need to preprocess anything, exit.
      return;
    }
  }
  $form['item_header']['#markup'] = '<h4>' . t('Your Shirt') . '</h4>';
  // Class to be applied to the Shirt Style options.
  $shirt_style_class = 'js-media-options';
  // Attributes to be applied to the Shirt Size options.
  $shirt_size_attributes = array(
    'data-validate' => 'shirt_size',
    'data-validate-required' => '',
  );
  $form['item']['#attributes']['class'][] = $shirt_style_class;
  $shirt_style_prefix = '<div data-validate="shirt_style" data-validate-required>';
  $shirt_style_suffix = '</div>';
  $form['item']['#prefix'] = $shirt_style_prefix;
  $form['item']['#suffix'] = $shirt_style_suffix;
  $form['item']['#title'] = '<div class="label">' . t("Your Shirt Style") . '</div>';
  $form['item_option']['#attributes'] = $shirt_size_attributes;
  if (isset($form['item_additional'])) {
    $form['item_additional_header']['#markup'] = '<h4>' . t("Your Friend's Shirt") . '</h4>';
    $form['item_additional']['#attributes']['class'][] = $shirt_style_class;
    $form['item_additional']['#prefix'] = $style_prefix;
    $form['item_additional']['#suffix'] = $style_suffix;
    $form['item_additional']['#title'] = '<div class="label">' . t("Your Friend's Shirt Style") . '</div>';
    $form['item_additional_option']['#attributes'] = $shirt_size_attributes;
  }
}


/**
 * Sets customs alterations to the dosomething_payment form.
 */
function paraneue_dosomething_form_dosomething_payment_form_alter(&$form, &$form_state, $form_id) {
  // Customize field elements.
  $form['cvv']['#prefix'] = '<div class="donate--threecol">';
  $form['cvv']['#suffix'] = '</div>';
  $form['exp_month']['#prefix'] = '<div class="donate--threecol">';
  $form['exp_month']['#suffix'] = '</div>';
  $form['exp_year']['#prefix'] = '<div class="donate--threecol">';
  $form['exp_year']['#suffix'] = '</div>';
  $form['amount']['#prefix'] = '<div class="donate--twocol">';
  $form['amount']['#suffix'] = '</div>';
}
