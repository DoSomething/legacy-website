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
  $form['item']['#prefix'] = '<div data-validate="shirt_style" data-validate-required>';
  $form['item']['#suffix'] = '</div>';
  $form['item']['#title'] = '<div class="label">' . t("Your Shirt Style") . '</div>';
  $form['item_additional']['#attributes']['class'][] = $class_name;
  $form['item_additional']['#prefix'] = '<div data-validate="shirt_style" data-validate-required>';
  $form['item_additional']['#suffix'] = '</div>';
  $form['item_additional']['#title'] = '<div class="label">' . t("Your Friend's Shirt Style") . '</div>';
  $form['item_header']['#markup'] = '<h3>' . t('Your Shirt') . '</h3>';
  $form['item_additional_header']['#markup'] = '<h3>' . t("Your Friend's Shirt") . '</h3>';
  $form['item_option']['#attributes'] = array(
    'data-validate' => 'shirt_size',
    'data-validate-required' => '',
  );
  $form['item_additional_option']['#attributes'] = array(
    'data-validate' => 'shirt_size',
    'data-validate-required' => '',
  );
}
